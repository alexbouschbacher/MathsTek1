/*
** EPITECH PROJECT, 2017
** del_zeros
** File description:
** del all neg 0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void calc_symetry_matrix(float *matsym, float *matrix, float ang)
{
	float angular;

	if (atanf(matrix[3] / matrix[0]) != ang) {
		if (atanf(matrix[3] / matrix[0]) != ang + cos(-1)) {
			angular = (ang  - atanf(matrix[3] / matrix[0])) * 2;
			matsym[0] = matrix[0] * cosf(angular);
			matsym[0] += matrix[3] * -sinf(angular);
			matsym[3] = matrix[0] * sinf(angular);
			matsym[3] += matrix[3] * cosf(angular);
		}
	}
	if (atanf(matrix[4] / matrix[1]) != ang) {
		if (atanf(matrix[4] / matrix[1]) != ang + cos(-1)) {
			angular = (ang  - atanf(matrix[4] / matrix[1])) * 2;
			matsym[1] = matrix[1] * cosf(angular);
			matsym[1] += matrix[4] * -sinf(angular);
			matsym[4] = matrix[1] * sinf(angular);
			matsym[4] += matrix[4] * cosf(angular);
		}
	}
}

void del_negO(float *p, float *matrix)
{
	matrix[0] = (matrix[0] == -0.00) ? 0.00 : matrix[0];
	matrix[1] = (matrix[1] == -0.00) ? 0.00 : matrix[1];
	matrix[3] = (matrix[3] == -0.00) ? 0.00 : matrix[3];
	matrix[4] = (matrix[4] == -0.00) ? 0.00 : matrix[4];
	p[0] = (p[0] == -0.00) ? 0.00 : p[0];
	p[1] = (p[1] == -0.00) ? 0.00 : p[1];
}
