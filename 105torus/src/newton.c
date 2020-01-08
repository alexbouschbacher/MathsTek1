/*
** EPITECH PROJECT, 2017
** Project 104intersection
** File description:
** Main file.
*/

#include "main.h"

static double func(int *coef, double x, int deg)
{
	double f = 0;

	for (int i = 0; i <= deg; i++) {
		f += coef[i] * powf(x, i);
	}
	return (f);
}

/*0.5
0.522727272727	0.522727264734
0.522740003514	0.522727264746
0.522740003526
*/

void newton(int *num, int prec)
{
	double x = 0.5;
	int i = 0;
	double x1 = 0.0;
	double fx;
	double fx1;
	int coefder[] = {num[1], num[2] * 2, num[3] * 3, num[4] * 4};

	while (fabs(x - x1) >= powf(10, -prec) && i < 4) {
		i++;
		printf("x = %.*g\n", prec, x);
		fx = func(num, x, 4);
		fx1 = func(coefder, x, 3);
		if (fabs(fx) > 0.0) {
			x1 = x;
			x = x - (fx / fx1);
			continue;
		}
		break;
	}
}
