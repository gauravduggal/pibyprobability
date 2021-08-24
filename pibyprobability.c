#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#define RAND_MAX 100000
#define iter 100000

int quotient(int a,int b)
{
	return a%b;
}


int min(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int max(int a, int b)
{
	if(a<b)
		return b;
	else
		return a;
}


// Returns 1 if a and b are co-primes else returns 0
int coprime_check(int a, int b)
{
	int min2 = min(a,b);
	int max2 = max(a,b); 
	if(quotient(min2,2)==0 && quotient(max2,2)==0)
		return 0;
	for(int i=3;i<=min2/2;i+=2)
	{
		if(quotient(min2,i)==0)
		{
			if(quotient(max2,i)==0)
				return 0;
		}
	}
	return 1;
}




int main()
{
	int a,b;
	srand(time(0)); //use current time as seed for random generator
    int coprimes=0;
    int cofactors=0;

	for(int i=0;i<iter;i++)
	{
		a = rand()/RAND_MAX;
		b = rand()/RAND_MAX;
		if(coprime_check(a,b)==1)
			coprimes++;
		else
			cofactors++;

	}
	printf("no of coprimes (numbers are from 1 to %d) found in %d iterations is: %d\n",INT_MAX/RAND_MAX,iter,coprimes);
	float pi = sqrt(6/(((float)coprimes)/iter));
	printf("The calculated value of PI is %f\n",pi);
	printf("The absolute error in estimated value of pi is %f\n",fabs(pi-M_PI));
	return 0;
}

