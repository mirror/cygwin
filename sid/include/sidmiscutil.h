// sidmiscutil.h - Useful utility classes.  -*- C++ -*-

// Copyright (C) 1999-2001 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SIDMISCUTIL_H
#define SIDMISCUTIL_H

#include <sidconfig.h>

#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cstring>
#ifdef __CYGWIN__
#include <sys/cygwin.h>
#endif


namespace sidutil
{
  // Instances of this class template function as bidirectional lookup
  // tables (bijections) for mapping objects to each other by value.
  template <class Obj1, class Obj2>
  class bijection
  {
    typedef std::map<Obj1,Obj2> forward_t;
    typedef std::map<Obj2,Obj1> backward_t;
    mutable forward_t forward;
    mutable backward_t backward;
    
  public:
    
    // Find Obj2 by Obj1.
    bool
    find(const Obj1& one, Obj2& two) const
      {
	forward_t::const_iterator it = this->forward.find(one);
	if (it != this->forward.end())
	  {
	    backward_t::const_iterator ti = this->backward.find(it->second);
	    assert (ti != this->backward.end());
	    two = it->second;
	    return true;
	  }
	else
	  return false;
      }
    
    // Find Obj1 by Obj2.
    bool
    find(const Obj2& two, Obj1& one) const
      {
	backward_t::iterator ti = this->backward.find(two);
	if (ti != this->backward.end())
	  {
	    forward_t::const_iterator it = this->forward.find(ti->second);
	    assert (it != this->forward.end());
	    one = ti->second;
	    return true;
	  }
	else
	  return false;
      }
    
    // Register Obj1<->Obj2 pair.  Both must be unique.
    void
    add (const Obj1& one, const Obj2& two)
      {
	assert (this->forward.find(one) == this->forward.end());
	this->forward[one] = two;
	assert (this->backward.find(two) == this->backward.end());
	this->backward[two] = one;
      }
    
    // Register Obj1<->Obj2 pair.  Both must be unique.
    void
    add (const Obj2& two, const Obj1& one)
      {
	this->add (one, two);
      }
    
    void
    erase_all ()
      {
	this->forward.erase(this->forward.begin(), this->forward.end());
	this->backward.erase(this->backward.begin(), this->backward.end());
      }
  };
  
  
  // This class, a possible mix-in, may be used to limit the number of
  // levels of recursion of functions.  It functions as a counter that
  // trips an assert() failure if it is made to exceed a configured
  // limit.  A limit of 0 is nonsensical and disallowed by assertion.
  class recursion_limited
  {
    friend class recursion_record;
    
    // XXX: might be nice to be signal-safe.
    int count;
    int max;
    std::string label;

  protected:
    // These functions are for use by recursion_record instances
    
    void recursion_enter ()
      {
	if (this->count <= this->max)
	  this->count ++;
	if (! ok())
	  std::cerr << label << ": recursion limit exceeded (" << this->count << ")" << std::endl;
      }
    
    void recursion_exit ()
      {
	if (this->count > 0)
	  this->count --;
	else
	  std::cerr << label << ": recursion limit underflow (" << this->count << ")" << std::endl;
      }

    bool ok () const
      {
	return (this->count >= 0 && this->count <= this->max);
      }
    
  public:
    static const unsigned default_recursion_limit = 1000;
    
    recursion_limited (const std::string& l,
		       int m = default_recursion_limit): count(0), max(m), label(l)
      {
	assert (this->max > 0);
      }
  };
  
  
  // Each instance of the recursion_record class, during its lifetime,
  // occupies one spot in a designated recursion_limited object's
  // slot.  Merely instantiate an instance of this type in any block
  // that may suffer from indefinite recursion.
  class recursion_record
  {
    recursion_limited* limiter;
    
  public:
    recursion_record (recursion_limited* l): limiter(l)
      {
	this->limiter->recursion_enter ();
      }

     bool ok () const
      {
	return (this->limiter->ok());
      }
    
    ~recursion_record ()
      {
	this->limiter->recursion_exit ();
      }
  };
  


  // The string2stream and stream2string classes may be used as
  // wrappers around string values to transmit them to/from streams.
  // Normal string stream-in operators break on word boundaries.
  // These wrappers encode arbitrary strings safely.
  // Use as follows:
  //
  // ostream o;
  // string s = "anything at all";
  // o << string2stream(s);
  //
  // istream i;
  // string s;
  // i >> stream2string(s);

  struct string2stream
  {
    const std::string& sendme;
    friend std::ostream& operator << (std::ostream& o, const string2stream& it);
  public:
    string2stream (const std::string& s): sendme(s) {}
  };
  
  
  inline std::ostream& 
  operator << (std::ostream& o, const string2stream& it)
    {
      o << '"';
      for (unsigned i=0; i<it.sendme.length(); i++)
	{
	  char c = it.sendme[i];
	  char hex[] = "0123456789ABCDEF";
	  if ((isprint(c)) && (! isspace(c)) && (c != '%'))
	    // NB: character class must not include '%' itself, and must
	    // include only chars that iostream>>std::string would consider
	    // parts of a single string.
	    o << c;
	  else
	    // print URL-encoded char
	    o << "%" << hex[(c >> 4) & 0x0f] << hex[c & 0x0f];
	}
      o << '"';
      return o;
    } 
  
  struct stream2string
  {
    std::string& parseme;
    friend std::istream& operator >> (std::istream& i, const stream2string& it);
  public:
    stream2string (std::string& s): parseme(s) {}
  };
  

  inline std::istream& 
  operator >> (std::istream& i, const stream2string& it)
    {
      std::string encoded;
      i >> encoded;
      it.parseme = "";
      
      unsigned j;
      for (j=1; j<encoded.length()-1; j++)  // ignore double-quote delimiters
	{
	  char c = encoded[j];
	  if (c != '%')
	    it.parseme += c;
	  else if (j < encoded.length() - 3) // limiting case:  "......%DD"
	    {
	      char c1 = toupper (encoded[++j]);
	      char c2 = toupper (encoded[++j]);
	      
	      // hex decoding
	      unsigned d1 = 
		(c1 >= '0' && c1 <= '9') ? (c1 - '0') :
		(c1 >= 'A' && c1 <= 'F') ? (c1 - 'A' + 10) :
		(j = encoded.length(), 0); // error: detected just before exit
	      unsigned d2 = 
		(c2 >= '0' && c2 <= '9') ? (c2 - '0') :
		(c2 >= 'A' && c2 <= 'F') ? (c2 - 'A' + 10) :
		(j = encoded.length(), 0); // error: detected just before exit
	      
	      char cc = (d1 << 4) | d2;
	      it.parseme += cc;
	    }
	  else
	    break;
	}
      
      // set flag on parse error
      if (j != encoded.length() - 1)
	i.setstate(std::ios::badbit);
      
      return i;
    } 


  // Tokenize a string.  Use given set of separator characters.
  inline std::vector<std::string> 
  tokenize (const std::string& str, const std::string& sep)
    {
      std::vector<std::string> tokens;
      std::string remainder = str;
      
      while (remainder.size() > 0)
	{
	  std::string::size_type sep_pos = remainder.find_first_of (sep);
	  if (sep_pos == std::string::npos) // no more tokens
	    {
	      tokens.push_back (remainder);
	      break;
	    }
	  else
	    {
	      tokens.push_back (remainder.substr (0, sep_pos));
	      // trim token
	      remainder = remainder.substr (sep_pos);
	      // trim to next non-separator
	      sep_pos = remainder.find_first_not_of (sep);
	      if (sep_pos == std::string::npos) // none?
		{
		  tokens.push_back ("");
		  break;
		}
	      remainder = remainder.substr (sep_pos);
	    }
	}
      return tokens;
    }


  inline std::string
  std_error_string ()
    {
      const char* error_message = "(unknown error)";
#ifdef HAVE_STRERROR
      error_message = strerror (errno);
#endif
      return std::string(error_message);
    }


  // Return a vector of directory names, where the SID_LIBRARY_PATH
  // and SID_EXEC_PREFIX environment variables are pointing.  Convert
  // all paths to POSIX form on Cygwin.
  inline std::vector<std::string>
  sid_file_search_path ()
  {
    std::vector<std::string> search_directories;

    char* slp = getenv ("SID_LIBRARY_PATH"); // run-time configuration
    if (slp)
      {
	search_directories = tokenize (slp, ":");
      }
    
    char* sep = getenv ("SID_EXEC_PREFIX"); // install-time configuration
#ifdef __CYGWIN__
    char conv_fn[PATH_MAX*2];
    if (sep)
      {
	int rc = cygwin_conv_to_full_posix_path (sep, conv_fn);
	if (rc != 0)
	  cerr << "sid_file_search_path: cygwin_conv_to_full_posix_path failed: " 
	       << std_error_string () << endl;
	else
	  sep = conv_fn;
      }
#endif
    if (!sep) sep = SID_EXEC_PREFIX; // build-time configuration
    // We really just want to get to pkgdatadir, which is $prefix/share
    // Guess exec-prefix == prefix
    std::string pkglibdir1 = std::string(sep) + std::string("/share");
    search_directories.push_back (pkglibdir1);
    // Guess exec-prefix == prefix/H-HOST
    std::string pkglibdir2 = std::string(sep) + std::string("/../share");
    search_directories.push_back (pkglibdir2);

    return search_directories;
  }


  // Look around cwd, the standard search dirs (.../sid)
  // At worst, return the given name.
  inline std::string
  find_sid_data_file (const std::string& file)
  {
    std::vector<std::string> file_path = sid_file_search_path ();
    std::vector<std::string> path;

    path.push_back (std::string("")); // no prefix
    for (unsigned i=0; i<file_path.size(); i++)
      path.push_back (file_path[i] + std::string("/sid/"));

    for (unsigned i=0; i<path.size(); i++)
      {
	const std::string& dir = path[i];
	std::string full_path = dir + file;
	
	// Try to open it.
	std::ifstream f (full_path.c_str());
	if (f.good())
	  return full_path;
      }

    return file;
  }


}

#endif // SIDMISCUTIL_H
