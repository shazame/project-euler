/*******************************
 * Site: Project Euler
 * Link: http://projecteuler.net/problems
 * Problem:
 * A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
 * 
 *     1/2	= 	0.5
 *     1/3	= 	0.(3)
 *     1/4	= 	0.25
 *     1/5	= 	0.2
 *     1/6	= 	0.1(6)
 *     1/7	= 	0.(142857)
 *     1/8	= 	0.125
 *     1/9	= 	0.(1)
 *     1/10= 	0.1
 * 
 * Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
 * 
 * Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
 * 
 * Solution by: David
 * Answer: 983
 *******************************/

#include <stdio.h>
#define MAX 1000

#define OPTIMIZE 1

int appartient(int tab[], int el, int size)
{
	int i;
#if OPTIMIZE
	for(i = 0; i < 10; i++)
#else
	for(i = 0; i < size; i++)
#endif	
	{
		if(tab[i] == el)
			return i;
	}

	return -1;
}

void afficher_cycle(int numerateur, int denominateur)
{
	
	int reste = numerateur;
	int quotient = reste * 10 / denominateur;
	int tab[MAX] = {0};
	int size = 0;

	while(appartient(tab, reste, size) == -1)
	{
		tab[size++] = reste;
		printf("%d", quotient);
		reste = (reste * 10) % denominateur;
		quotient = reste * 10 / denominateur;
	}
	printf("\n");
}

int taille_cycle(int numerateur, int denominateur)
{
	
	int reste = numerateur;
	int tab[MAX] = {0};
	int size = 0;

	while(appartient(tab, reste, MAX) == -1)
	{
		tab[size++] = reste;
		reste = (reste * 10) % denominateur;
	}

	return size - appartient(tab, reste, MAX);
}

int main(void)
{
	int max = 0;
	int d, t;
	int d_max = 2;

	for(d = MAX; d > 2; d--)
	{
		t = taille_cycle(1, d);

		if(t > max)
		{
			max = t;
			d_max = d;
		}

		if(t == d - 1)
			break;
	}

	printf("%d\n", d_max);

	return 0;
}
