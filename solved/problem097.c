/*******************************
 * Site: Project Euler
 * Link: http://projecteuler.net/problems
 * Problem:
 * The first known prime found to exceed one million digits was discovered in 1999, and is a Mersenne prime of the form 26972593−1; it contains exactly 2,098,960 digits. Subsequently other Mersenne primes, of the form 2p−1, have been found which contain more digits.
 * 
 * However, in 2004 there was found a massive non-Mersenne prime which contains 2,357,207 digits: 28433×27830457+1.
 * 
 * Find the last ten digits of this prime number.
 * 
 * Solution by: David
 * Answer: 8739992577
 *
 * Comment:
 *******************************/

#include <stdio.h>

unsigned long long mult_last_10_dig(unsigned long long a, unsigned long long b){
	unsigned long long ai = a % 100000;
	unsigned long long af = (a - ai) % 10000000000;
	unsigned long long bi = b % 100000;
	unsigned long long bf = (b - bi) % 10000000000;
	return (ai*bi + ai*bf + bi*af) % 10000000000;
}

unsigned long long my_pow (unsigned long long n, unsigned long long p){
	if (0 == p)
		return 1;
	else if (p % 2 == 0)
		return my_pow(mult_last_10_dig(n, n), p/2);
	else
		return mult_last_10_dig(n, my_pow(n, p-1));
}

int main(void){
	unsigned long long p = (28433 * my_pow(2, 7830457) + 1) % 10000000000;

	printf("%lld\n", p);

	return 0;
}
