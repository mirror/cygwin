## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

pkglib_LTLIBRARIES = libcache.la

INCLUDES = -I. -I../../include -I$(srcdir)/../../include
libcache_la_SOURCES = cache.cxx cache.h cacheutil.cxx cacheutil.h log2.h
libcache_la_LDFLAGS = -module -no-undefined

pkgdata_DATA = hw-cache.txt

DEJAGNUTESTS=cache.exp cachemonkey.exp cachedocs.exp coherency.exp \
	fifo.exp flush.exp lock.exp lru.exp misaligned.exp \
	prefetch.exp random.exp refill.exp writealloc.exp writethru.exp

check-local: all
	(cd ../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)")

html_stylesheet=$(srcdir)/../component_html.xsl
include $(srcdir)/../../config/Makefile.docs
