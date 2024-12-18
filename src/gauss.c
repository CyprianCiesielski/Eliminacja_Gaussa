#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{
	int n = mat->r;
	for (int k = 0; k < n - 1; k++)
	{
		if (mat->data[k][k] == 0.0)
		{
			return 1; // Dzielenie przez 0 - macierz osobliwa
		}
		for (int i = k + 1; i < n; i++)
		{
			double factor = mat->data[i][k] / mat->data[k][k];
			for (int j = k; j < n; j++)
			{
				mat->data[i][j] -= factor * mat->data[k][j];
			}
			b->data[i][0] -= factor * b->data[k][0];
		}
	}
	return 0;
}
