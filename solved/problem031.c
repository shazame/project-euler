/*******************************
 * Site: Project Euler
 * Link: http://projecteuler.net/problems
 * Problem:
 * In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
 * 
 *     1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
 * 
 * It is possible to make £2 in the following way:
 * 
 *     1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
 * 
 * How many different ways can £2 be made using any number of coins?
 * 
 * Solution by: David
 * Answer: 73682
 *
 * Comment:
 *******************************/

#include <stdio.h>

static int p[8] = {1, 2, 5, 10, 20, 50, 100, 200};

int nb_comb(int n, int i){
	if (i == 0)	
		return 1;
	if (n == 0)
		return 1;

	int s = 0;
	for (int j = 0; (j <= i) && (n >= p[j]); j++){
		s += nb_comb(n - p[j], j);
	}
	return s;
}

int main(void){

	printf("C10 : %d\n", nb_comb(200, 7));

	return 0;
}
