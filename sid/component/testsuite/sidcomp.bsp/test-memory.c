/*
# mach(): all 
# output(): Done*
*/

#ifndef WORKFACTOR
#define WORKFACTOR 25
#endif

int q;

int main()
{
  volatile unsigned* p = & q;
  register unsigned i;
  for(i=0; i<(10000*WORKFACTOR); i++)
    {
       (*p) = 0;  /* 1 */
       (*p) = 0;
       (*p) = 0;
       (*p) = 0;
       (*p) = 0;
       (*p) = 0;
       (*p) = 0;
       (*p) = 0;
       (*p) = 0;
       (*p) = 0;
       (*p) = 0;
       (*p) = 0;
       (*p) = 0;
       (*p) = 0;
       (*p) = 0;
       (*p) = 0;
       (*p) = 0;
       (*p) = 0;
       (*p) = 0;
       (*p) = 0;  /* 20 */
    }
  printf ("Done (%d)\n", i);
}

