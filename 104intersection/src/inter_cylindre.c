/*
** EPITECH PROJECT, 2017
** Intersection_cylinder
** File description:
** Check intersection with cylinder
*/

#include "main.h"

void inter_cylindre(int *origin, int *vector, int radius)
{
	int calc[4];

	calc[0] = pow(vector[0], 2) + pow(vector[1], 2);
	calc[1] = 2 * vector[0] * origin[0];
	calc[1] += 2 * vector[1] * origin[1];
	calc[2] = pow(origin[0], 2) + pow(origin[1], 2);
	calc[2] -= pow(radius, 2);
	if (calc[0] != 0) {
		calc[3] = pow(calc[1], 2) - (4 * calc[0] * calc[2]);
		if (calc[3] == 0)
			one_answer(origin, vector, -calc[1] / (2.0 * calc[0]));
		else if (calc[3] > 0)
			two_answer(origin, vector, calc);
		else
			printf("No intersection point.");
	} else if (calc[1] == 0 && calc[2] == 0)
		printf ("There is an infinite number of intersection points.\n");
	else
		one_answer(origin, vector, -calc[2] / calc[1]);
}
