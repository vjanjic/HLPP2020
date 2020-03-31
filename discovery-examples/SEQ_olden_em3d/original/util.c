/* For copyright information, see olden_v1.0/COPYRIGHT */


#include "em3d.h"

#define EXTRA_DEBUG 0

#ifdef TORONTO
#define chatting printf
#endif

#ifdef __MINGW32__
#define srand48(x) srand(x)
#define lrand48() (rand() << 16 | rand())
#define drand48() (1.0*rand() / RAND_MAX)
#else
extern double drand48();
#endif

static int percentcheck=0,numlocal=0;

/* initialize the random number generator for a particular processor */
void init_random(int seed)
{
  if (EXTRA_DEBUG) printf("seed = %d\n", seed);
  srand48(seed);
}

/* return a random number from 0 to range-1 */
int gen_number(int range)
{
	int res = (int)lrand48() % range;
	 if (EXTRA_DEBUG) printf("res = %d\n", res);
	return res;
}

/* return a random number in [-range,range] but not zero */
int gen_signed_number(int range)
{
  int temp;

  temp = lrand48() % (2*range);  /* 0..2*range-1 */
  temp =  temp-(range);
  if (temp >= 0) temp++;
  if (EXTRA_DEBUG) printf("gen_signed_number = %d\n", temp);
  return temp;
}

/* Generate a double from 0.0 to 1.0 */
double gen_uniform_double()
{
	double res = drand48();
	 if (EXTRA_DEBUG)  printf("res = %f\n", res);
  return res;
}

int check_percent(int percent)
{

	  int retval;
	  retval=(drand48() < (double) (percent/100.0));
	  percentcheck++;
	  if (retval) numlocal++;

	  if (EXTRA_DEBUG)  printf("check_percent = %d\n", retval);

	  return retval;
}

void printstats()
{
  chatting("percentcheck=%d,numlocal=%d\n",percentcheck,numlocal);
}








