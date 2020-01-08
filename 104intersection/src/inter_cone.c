/*
** EPITECH PROJECT, 2017
** Intersection_cone
** File description:
** Check intersection with cone
*/

#include "main.h"

void inter_cone(int *orig, int *vec, int ang)
{
	float calc[4];
	float angle = ang / 180.0 * acosf(-1);
	float ta = powf(tanf(angle), 2);

	calc[0] = powf(vec[0], 2) + powf(vec[1], 2) - powf(vec[2], 2) * ta;
	calc[1] = 2.0 * vec[0] * orig[0];
	calc[1] += 2.0 * vec[1] * orig[1];
	calc[1] -= 2.0 * vec[2] * orig[2] * ta;
	calc[2] = powf(orig[0], 2) + powf(orig[1], 2) - powf(orig[2], 2) * ta;
	if (calc[0] != 0) {
		calc[3] = powf(calc[1], 2) - (4 * calc[0] * calc[2]);
		if (calc[3] == 0) {
			one_answer(orig, vec, -calc[1] / (2.0 * calc[0]));
		} else if (calc[3] > 0)
			two_inter_cone(orig, vec, calc);
		else
			printf("No intersection point.");
	} else if (calc[1] == 0 && calc[2] == 0)
		printf ("There is an infinite number of intersection points.\n");
	else
		one_answer(orig, vec, -calc[2] / calc[1]);
}
