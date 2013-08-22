/*******************************
 * Site: Project Euler
 * Link: http://projecteuler.net/problems
 * Problem:
 * By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
 * 
 * 3
 * 7 4
 * 2 4 6
 * 8 5 9 3
 * 
 * That is, 3 + 7 + 4 + 9 = 23.
 * 
 * Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.
 * 
 * NOTE: This is a much more difficult version of Problem 18. It is not possible to try every route to solve this problem, as there are 299 altogether! If you could check one trillion (1012) routes every second it would take over twenty billion years to check them all. There is an efficient algorithm to solve it. ;o)
 * 
 * Solution by: David
 * Answer: 7273
 *
 * Comment : Résolution de façon intelligente.
 * En partant du bas de l'arbre on ajoute à la valeur de chaque noeud la valeur maximale entre ces deux fils et on remonte jusqu'à la racine.
 * A la fin, la racine contient la valeur recherchée.
 *******************************/

#include <stdio.h>
#include <stdlib.h>

#define TRI_HEIGHT 100

void read_triangle_from_file(FILE *f, int T[][TRI_HEIGHT])
{
	int c;
	int line = 0, l_pos = 0;

	while((c = fgetc(f)) != EOF)
	{
		if(c == '\n')
		{
			line++;
			l_pos = 0;
		}

		if(c <= '9' && c >= '0')
		{
			T[line][l_pos] = (c - '0') * 10;
			c = fgetc(f);
			T[line][l_pos++] += c - '0';
		}
	}
}

void sum_max_triangle(int T[][TRI_HEIGHT])
{
	int line, l_pos;

	for(line = TRI_HEIGHT - 2; line >= 0; line--)
	{
		for(l_pos = line; l_pos >= 0; l_pos--)
		{
			if(T[line + 1][l_pos]  >= T[line + 1][l_pos + 1])
				T[line][l_pos] += T[line + 1][l_pos];
			else
				T[line][l_pos] += T[line + 1][l_pos + 1];
		}
	}
}

int main(void)
{
	FILE *f = fopen("problem67.txt", "r");

	if(f == NULL)
	{
		perror("problem67.txt");
		exit(EXIT_FAILURE);
	}

	int sum[TRI_HEIGHT][TRI_HEIGHT] = {{0}};

	read_triangle_from_file(f, sum);

	fclose(f);

	sum_max_triangle(sum);

	printf("max : %d\n", sum[0][0]);

	return 0;
}
