/*******************************
 * Site: Project Euler
 * Link: http://projecteuler.net/problems
 * Problem:
 * A positive fraction whose numerator is less than its denominator is called a proper fraction.
 * For any denominator, d, there will be d−1 proper fractions; for example, with d = 12:
 * 1/12 , 2/12 , 3/12 , 4/12 , 5/12 , 6/12 , 7/12 , 8/12 , 9/12 , 10/12 , 11/12 .
 * 
 * We shall call a fraction that cannot be cancelled down a resilient fraction.
 * Furthermore we shall define the resilience of a denominator, R(d), to be the ratio of its proper fractions that are resilient; for example, R(12) = 4/11 .
 * In fact, d = 12 is the smallest denominator having a resilience R(d) < 4/10 .
 * 
 * Find the smallest denominator d, having a resilience R(d) < 15499/94744
 * Solution by: David
 * Answer:
 *
 * Comment :
 *******************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_P 1000000

double resilience(int d)
{
	int *isResilient = malloc(sizeof(int) * (d - 1));
	int i, k = 0;
	int nbResilient = 1;

	assert(isResilient != NULL);

	// On considère au début que tous les fractions sont irreductibles
	for(i = 0; i < d - 1; i++)
		isResilient[i] = 1;

	// Si le numérateur divise le dénominateur alors la fraction est réductible 
	// et toutes les fractions ayant un numérateur multiple de celui-ci également
	for(i = 2; i < d; i++)
	{
		if(d % i == 0)
		{
			if(isResilient[i - 1])
			{
				for(k = i; k < d; k += i)
					isResilient[k - 1] = 0;
			}
		}
		else
			if(isResilient[i - 1])
				nbResilient++;
	}

	free(isResilient);

	return (double)nbResilient / (d - 1);
}

//////////////
//
void crible(int V[], int n)
{
	int i = 1, k = 0;

	for(i = 1; i < n; i++)
	{
		V[i] = 1;
	}

	for(i = 2; i * i <= n; i++)
	{
		if(V[i - 1])
		{
			k = i * i;
			while(k <= n)
			{
				V[k - 1] = 0;
				k += i;
			}
		}
	}
}

void fillPrime(int P[], int V[], int n)
{
	int i, j = 0;

	for(i = 0; i < n; i++)
		if(V[i])
			P[j++] = i + 1;

}
//
/////////////////

double resilience2(int d, int P[])
{
	int nbResilient = d - 1;
	int i;

	for(i = 0; P[i] < d; i++)
	{
		if(d % P[i] == 0)
			nbResilient -= (d - 1) / P[i];
	}

	return (double)nbResilient / (d - 1);
}

int main(void)
{
	int d;

#if 1
	for(d = 2; resilience(d) >= ((double)15499 / 94744); d++)
		;

	printf("%d\n", d);
#else

	double r = 0;

/*
	int V[MAX_P] = {0};
	int P[MAX_P] = {0};
	crible(V, MAX_P);
	fillPrime(P, V, MAX_P);
*/
	for(d = 2; d < 300; d++)
	{
		//if(d % 2 != 0 && d % 3 != 0 && d % 5 != 0)
		//{
		r = resilience(d);
		printf("%d : %lf\n", d, r);

		//printf("%d : %lf | %lf\n", d, r, resilience2(d, P));
		//}
	}

#endif
	return 0;
}
