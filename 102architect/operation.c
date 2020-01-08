/*
** EPITECH PROJECT, 2017
** do_all_translations
** File description:
** all operations
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void calc_symetry_matrix(float *, float *, float);
void del_negO(float *, float *);

static void multmat(float *mat1, float *mat2)
{
	float *mats = malloc (sizeof(float) * 9);
	int ps = 0;

	for (int i = 0; i < 9; i++) {
		mats[i] = mat1[i];
	}
	for (int a = 0; a < 2 ;a++) {
		mat1[ps] = mats[ps] * mat2[0];
		mat1[ps] += mats[ps+1] * mat2[3];
		mat1[ps] += mats[ps+2] * mat2[6];
		ps++;
		mat1[ps] = mats[ps-1] * mat2[1];
		mat1[ps] += mats[ps] * mat2[4];
		mat1[ps] += mats[ps+1] * mat2[7];
		ps++;
		mat1[ps] = mats[ps-2] * mat2[2];
		mat1[ps] += mats[ps-1] * mat2[5];
		mat1[ps] += mats[ps] * mat2[8];
		ps++;
	}
	free(mats);
}

void homotety (float *v, float *p, float *matrix)
{
	matrix[0] = matrix[0] * v[0];
	matrix[1] = matrix[1] * v[0];
	matrix[2] = matrix[2] * v[0];
	matrix[3] = matrix[3] * v[1];
	matrix[4] = matrix[4] * v[1];
	matrix[5] = matrix[5] * v[1];
	p[0] = p[0] * v[0];
	p[1] = p[1] * v[1];
	del_negO(p, matrix);
	printf("Homothety by the ratios %.0f and %.0f\n", v[0], v[1]);
}

void rotate (float *v, float *p, float *matrix)
{
	float angle = v[0];
	float p0 = p[0];
	float DTOR = acosf(-1) / 180;
	float matrot[9] = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};

	if (angle < 0)
		angle = 360.0 - angle;
	angle = angle * DTOR;
	matrot[0] = cosf(angle);
	matrot[1] = -sinf(angle);
	matrot[3] = sinf(angle);
	matrot[4] = cosf(angle);
	multmat(matrix, matrot);
	p[0] = p[0] * cosf(angle) + p[1] * -sinf(angle);
	p[1] = p0 * sinf(angle) + p[1] * cosf(angle);
	del_negO(p, matrix);
	printf("Rotation at the %.0f degree angle\n",v[0]);
}

void translation (float *v, float *p, float *matrix)
{
	p[0] += v[0];
	p[1] += v[1];
	matrix[2] += v[0];
	matrix[5] += v[1];
	del_negO(p, matrix);
	printf("Translation by the vector (%.0f, %.0f)\n",v[0], v[1]);
}

void symetry (float *v, float *p, float *matrix)
{
	float angle = v[0];
	int r;
	float p0 = p[0];
	float ang;
	float DTOR = acosf(-1) / 180;
	float matsym[9] = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};

	if (angle < 0)
		angle = 360.0 - angle;
	r = angle / 180;
	angle = angle - (180 * r);
	ang = angle * DTOR;
	angle = angle * DTOR - (atanf(p[1] / p[0]));
	calc_symetry_matrix(matsym, matrix, ang);
	multmat(matrix, matsym);
	p[0] = p[0] * cosf(angle * 2) + p[1] * -sinf(angle * 2);
	p[1] = p0 * sinf(angle * 2) + p[1] * cosf(angle * 2);
	del_negO(p, matrix);
	printf("Symetry about an axis inclined with an angle of %.0f degree\n",v[0]);
}
