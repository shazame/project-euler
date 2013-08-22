/*******************************
 * Site: Project Euler
 * Link: http://projecteuler.net/problems
 * Problem:
 * A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 * 
 * A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
 * 
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
 * 
 * Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 * 
 * Solution by: David
 * Answer: 4179871
 *******************************/

#include <stdio.h>

#define LIMIT 28123

int div_sum(int n)
{
	int sum = 1;
	int div;

	for (div = 2; div*div < n; div++)
	{
		if (n % div == 0)
			sum += (div + n / div);
	}
	if(div*div == n)
		sum += div;

	return sum;
}

#if 1

int main(void)
{
	int isAbundant[LIMIT] = {0};
	int isAbundantSum[LIMIT] = {0};
	int sum = 0;
	int i, j;
	
	for(i = 12; i < LIMIT; i++)
	{
		if(div_sum(i) > i)
			isAbundant[i] = 1;
	}

	for(i = 24; i < LIMIT; i++)
	{
		for(j = 12; j <= i - 12; j++)
		{
			if(isAbundant[j] && isAbundant[i - j])
			{
				isAbundantSum[i] = 1;
				break;
			}
		}
	}

	for(i = 1; i < LIMIT; i++)
	{
		if(!isAbundantSum[i])
			sum += i;
	}

	printf("%d\n",  sum);

	return 0;
}
#endif

#if 0
int main(void)
{
	int isAbundantSum[LIMIT] = {0};
	int isAbundant[LIMIT] = {0};
	int sum = 0;

	for(int i = 1; i < LIMIT; i++)
	{
		if(div_sum(i) > i)
			isAbundant[i] = 1;
	}

	for(int i = 2; i < LIMIT; i++)
	{
		if(isAbundant[i])
		{
			for(int j = i; j < LIMIT; j++)
			{	
				if(isAbundant[j])
				{
					isAbundantSum[i + j] = 1;
				}
			}
		}
	}
				
	for(int i = 1; i < LIMIT; i++)
	{
		if(isAbundantSum[i] == 0)
		{
			sum += i;
			printf("%d\n", i);
		}
	}

	//printf("%d\n", sum);

	return 0;
}
#endif
