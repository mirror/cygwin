/*
# mach(): all 
# output(): Done*
*/

#ifndef WORKFACTOR
#define WORKFACTOR 25
#endif


int main()
{ 
  /* Use register variables to use memory system very little. */
  register unsigned i, j = 0;
  for (i=0; i<(150000*WORKFACTOR); i++)
    j += i;
  printf ("Done (%d)\n", j);
  return 0;
}
