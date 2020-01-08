/*
** EPITECH PROJECT, 2017
** Project 104intersection
** File description:
** Main file.
*/

#include "main.h"

static float func(int *num, float x)
{
	float f = 0;

	for (int i = 0; i < 5; i++) {
		f += num[i] * powf(x, i);
	}
	return (f);
}

static void result(float fx[], float x[], int prec)
{
	if (!(fabsf(fx[1]) > 0.0))
		printf("x = %f\n", fx[1]);
	else if (fx[1] * fx[0] < 0.0) {
		x[2] = x[1];
		x[1] = (x[0] + x[1]) / 2.0;
	} else {
		x[0] = x[1];
		x[1] = (x[1] + x[2]) / 2.0;
	}
	if (fabsf(x[2] - x[0]) <= 2 * powf(10, -prec)) {
		printf("x = %.*f\n", prec, x[1]);
		exit (0);
	}
}

void bisection(int *num, int prec)
{
	float x[3] = {0.0, 0.5, 1.0};
	float fx[3] = {0.0, 1.0, 0.0};

	while (1) {
		printf("x = %.*g\n", prec, x[1]);
		fx[0] = func(num, x[0]);
		fx[1] = func(num, x[1]);
		fx[2] = func(num, x[2]);
		result (fx, x, prec);
	}
}
