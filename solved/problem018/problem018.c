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
 * Find the maximum total from top to bottom of the triangle below:
 * 
 * 75
 * 95 64
 * 17 47 82
 * 18 35 87 10
 * 20 04 82 47 65
 * 19 01 23 75 03 34
 * 88 02 77 73 07 63 67
 * 99 65 04 28 06 16 70 92
 * 41 41 26 56 83 40 80 70 33
 * 41 48 72 33 47 32 37 16 94 29
 * 53 71 44 65 25 43 91 52 97 51 14
 * 70 11 33 28 77 73 17 78 39 68 17 57
 * 91 71 52 38 17 14 91 43 58 50 27 29 48
 * 63 66 04 68 89 53 67 30 73 16 69 87 40 31
 * 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
 * 
 * NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
 * 
 * Solution by: David
 * Answer: 1074
 *
 * Comment : Résolution de façon intelligente.
 * En partant du bas de l'arbre on ajoute à la valeur de chaque noeud la valeur maximale entre ces deux fils et on remonte jusqu'à la racine.
 * A la fin, la racine contient la valeur recherchée.
 *******************************/

#include <stdio.h>
#include <stdlib.h>

#define TRI_HEIGHT 15

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
	FILE *f = fopen("problem18.txt", "r");

	if(f == NULL)
	{
		perror("problem18.txt");
		exit(EXIT_FAILURE);
	}

	int sum[TRI_HEIGHT][TRI_HEIGHT] = {{0}};

	read_triangle_from_file(f, sum);

	fclose(f);

	sum_max_triangle(sum);

	printf("max : %d\n", sum[0][0]);

	return 0;
}
