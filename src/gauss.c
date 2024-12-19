#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{
	int n = mat->r;
	for (int k = 0; k < n - 1; k++)
	{
		// wybor pivota
		int maxRow = k;
		for (int i = k + 1; i < n; i++)
		{
			if (fabs(mat->data[i][k]) > fabs(mat->data[maxRow][k]))
			{
				maxRow = i;
			}
		}

		// zmaian wierszy
		if (maxRow != k)
		{
			for (int j = 0; j < n; j++)
			{
				double temp = mat->data[k][j];
				mat->data[k][j] = mat->data[maxRow][j];
				mat->data[maxRow][j] = temp;
			}
			double temp = b->data[k][0];
			b->data[k][0] = b->data[maxRow][0];
			b->data[maxRow][0] = temp;
		}

		if (mat->data[k][k] == 0.0)
		{
			return 1; // Dzielenie przez 0 - macierz osobliwa
		}

		// Elem gaus
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