/*******************************
 * Site: Project Euler
 * Link: http://projecteuler.net/problems
 * Problem:
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
 * If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
 * 
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 * 
 * Evaluate the sum of all the amicable numbers under 10000.
 * 
 * Solution by: David
 * Answer: 31626
 *******************************/

#include <stdio.h>

int d(int n)
{
	int sum = 1;
	int i;

	for (i = 2; i <= n/2; i++)
	{
		if(n % i == 0)
			sum += i;
	}

	return sum;
}

int main(void)
{
	int i;
	int sum = 0;

	for (i = 2; i <= 10000; i++)
	{
		if (d(d(i)) == i && d(i) != i)
			sum += i;
	}

	printf("%d\n", sum);

	return 0;
}
