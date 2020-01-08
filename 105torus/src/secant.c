/*
** EPITECH PROJECT, 2017
** Project 104intersection
** File description:
** Main file.
*/

#include "main.h"

static double func(int *coef, double x)
{
	double f = 0;

	for (int i = 0; i <= 4; i++) {
		f += coef[i] * powf(x, i);
	}
	return (f);
}

void secant(int *num, int prec)
{
	double xn = 0.0;
	double xn1 = 1.0;
	double tmp;
	int i = 0;
	double fx;
	double fx1;

	while (fabs(xn1 - xn) >= powf(10, -prec) && i < 5) {
		i++;
		fx = func(num, xn);
		fx1 = func(num, xn1);
		if (fabs(fx) > 0.0) {
			tmp = xn1;
			xn1 = xn1 - ((xn1 - xn) / (fx1 - fx)) * fx1;
			xn = tmp;
			printf("x = %.*g\n", prec, xn1);
			continue;
		}
		break;
	}
}
