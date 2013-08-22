/*******************************
 * Site: Project Euler
 * Link: http://projecteuler.net/problems
 * Problem:
 * In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by only moving to the right and down, is indicated in bold red and is equal to 2427.
 * 
 * 	
 * 131	673	234	103	18
 * 201	96	342	965	150
 * 630	803	746	422	111
 * 537	699	497	121	956
 * 805	732	524	37	331
 * 	
 * 
 * Find the minimal path sum, in matrix.txt (right click and 'Save Link/Target As...'), a 31K text file containing a 80 by 80 matrix, from the top left to the bottom right by only moving right and down.
 * 
 * Solution by: David
 * Answer: 427337
 *
 * Comment : Même principe que les problème 18 et 67.
 * On parcourt la matrice de gauche à droite et de haut en bas.
 * Pour chaque case de la matrice on ajoute la valeur minimale entre celle du dessus et celle de gauche.
 * À la fin, la case en bas à droite contient la somme des valeurs du trajet minimal.
 *******************************/

#include <stdio.h>
#include <stdlib.h>

#define LINE 80
#define COL  80

void matrix_from_file(FILE *f, int M[][COL])
{
	int c;
	int line = 0, col = 0;

	while((c = fgetc(f)) != EOF)
	{
		if(c == '\n')
		{
			line++;
			col = 0;
		}

		if(c == ',')
			col++;

		if(c >= '0' && c <= '9')
		{
			M[line][col]  = M[line][col] * 10 + c - '0';
		}
	}
}


void sum_min_path_matrix(int M[][COL])
{
	int l, c;

	for(c = 1; c < COL; c++)
	{
		M[0][c] += M[0][c - 1];
	}	

	for(l = 1; l < LINE; l++)
	{
		M[l][0] += M[l - 1][0];
	}

	for(l = 1; l < LINE; l++)
	{
		for(c = 1; c < COL; c++)
		{
			if(M[l - 1][c] < M[l][c - 1])
				M[l][c] += M[l - 1][c];
			else
				M[l][c] += M[l][c - 1];
		}
	}
}

int main(void)
{
	int matrix[LINE][COL] = {{0}};
	FILE *f = fopen("problem81.txt", "r");

	if(f == NULL)
	{
		perror("problem81.txt");
		exit(EXIT_FAILURE);
	}

	matrix_from_file(f, matrix);

	sum_min_path_matrix(matrix);

	printf("%d\n", matrix[LINE - 1][COL - 1]);

	return EXIT_SUCCESS;
}
