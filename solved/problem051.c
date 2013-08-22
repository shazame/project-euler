/*******************************
 * Site: Project Euler
 * Link: http://projecteuler.net/problems
 * Problem:
 * By replacing the 1st digit of *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.
 * 
 * By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.
 * 
 * Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
 * Solution by: David
 * Answer: 121313
 *
 * Comment:
 *******************************/

#include <stdio.h> 

#define SIZE_PRIME_TAB 1000000

void crible(int V[], int n){
	int i, k = 0;

	for(i = 2; i < n; i++){
		V[i] = 1;
	}

	for(i = 2; i * i <= n; i++){
		if(V[i]){
			k = i * i;
			while(k <= n){
				V[k] = 0;
				k += i;
			}
		}
	}
}

void fill_prime(int prime_tab[], const int is_prime_tab[], int size_tab){
	int i, j = 0;

	for(i = 0; i < size_tab; i++)
		if(is_prime_tab[i])
			prime_tab[j++] = i;

}

int my_pow (int n, int p){
	if (0 == p)
		return 1;
	else if (p % 2 == 0)
		return my_pow(n*n, p/2);
	else
		return n * my_pow(n, p-1);
}

/**
 * Returns an interger based on n, where some digits have been replace by digit
 *
 * @param	n		The integer to change.
 * @param	digit	An integer between 0 and 9 used to replace some digits of n.
 * @param	pos		An integer which gives the position of the digits to
 * 					replace in n. These positions are given by the binary
 * 					code of pos.
 */
int replace_digits(int n, int digit, int pos){
	
	for (int i = 0; (1 << i) <= pos; i++){
		if (pos & (1 << i)){
			n += (digit - ((n / my_pow(10, i)) % 10)) * my_pow(10, i);
		}
	}
	return n;
}

int nb_digits(int n){
	if (n < 10)
		return 1;
	else
		return 1 + nb_digits(n / 10);
}

int nb_prime_family(int n, int is_prime_tab[]){
	int pos_max = my_pow(2, nb_digits(n)-1);
	int max = 0, c = 0;
	int current_n;

	for (int i = 1; i < pos_max; i++) {
		c = 0;
		for (int j = 0; j < 10; j++){
			current_n = (n % 10) + 10 * (replace_digits(n/10, j, i));
			if (is_prime_tab[current_n] && nb_digits(current_n) == nb_digits(n)){
				c++;
			}
		}
		if (c > max){
			max = c;
		}
	}

	return max;
}

void print_prime_family(int n, int is_prime_tab[], int prime_value_fam){
	int pos_max = my_pow(2, nb_digits(n)-1);
	int c = 0;
	int current_n;

	for (int i = 1; i < pos_max; i++) {
		c = 0;
		for (int j = 0; j < 10; j++){
			current_n = (n % 10) + 10 * (replace_digits(n/10, j, i));
			if (is_prime_tab[current_n] && nb_digits(current_n) == nb_digits(n)){
				c++;
			}
		}
		if (c == prime_value_fam){
			for (int j = 0; j < 10; j++){
				current_n = (n % 10) + 10 * (replace_digits(n/10, j, i));
				if (is_prime_tab[current_n] && nb_digits(current_n) == nb_digits(n)){
					printf("%d\n", current_n);
			}
		}
		}
	}
}

int main(void){

	int is_prime_tab[SIZE_PRIME_TAB] = {0};	
	int prime_tab[SIZE_PRIME_TAB] = {0};

	crible(is_prime_tab, SIZE_PRIME_TAB);
	fill_prime(prime_tab, is_prime_tab, SIZE_PRIME_TAB);

	for (int i = 10; i < SIZE_PRIME_TAB; i++){
		if (nb_prime_family(prime_tab[i], is_prime_tab) > 7){
			printf("%d\n", prime_tab[i]);
			print_prime_family(prime_tab[i], is_prime_tab, 8);
			break;
		}
	}

	return 0;
}
