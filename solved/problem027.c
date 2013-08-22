/*******************************
 * Site: Project Euler
 * Link: http://projecteuler.net/problems
 * Problem:
 * Euler published the remarkable quadratic formula:
 * 
 * n² + n + 41
 * 
 * It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.
 * 
 * Using computers, the incredible formula  n² − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.
 * 
 * Considering quadratics of the form:
 * 
 *     n² + an + b, where |a| < 1000 and |b| < 1000
 * 
 *     where |n| is the modulus/absolute value of n
 *     e.g. |11| = 11 and |−4| = 4
 * 
 * Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
 * 
 * Solution by: David
 * Answer: -59231
 *******************************/

#include <stdio.h>

#define HIGHER_PRIME 1000
#define MAX_CONSECUTIVE_PRIME 1000

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

int isPrime(int n, int P[])
{
	int i;

	if(n < 2)
		return 0;

	for(i = 0; P[i] * P[i]  <= n; i++)
		if(n % P[i] == 0)
			return 0;

	return 1;
}

int nbPrimePoly(int a, int b, int P[])
{
	int p, nbPrime = 0;
	int i;

	for(i = 0; i < MAX_CONSECUTIVE_PRIME;  i++)
	{
		p = i * i + a * i + b;

		if(!isPrime(p, P))
			break;

		nbPrime++;
	}

	return nbPrime;
}

int main(void)
{
	int V[HIGHER_PRIME] = {0};
	int P[HIGHER_PRIME] = {0};
	int p = 0;
	int nbPrime = 0, maxConsP = 0;
	int a, aMax = 0;
	int b, bMax = 0; 

	crible(V, HIGHER_PRIME);
	fillPrime(P, V, HIGHER_PRIME);
	
	for(a = -999; a < 1000; a++)
	{
		for(b = -999; b < 1000; b++)
		{
			nbPrime = nbPrimePoly(a, b, P);

			if(nbPrime > maxConsP)
			{
				maxConsP = nbPrime;
				aMax = a;
				bMax = b;
			}
		}
	}

	printf("a : %d\nb : %d\nnbPrime :  %d\n", aMax, bMax, maxConsP);
	printf("a*b : %d\n", aMax * bMax);

	return 0;
}
