/*
** EPITECH PROJECT, 2017
** Print_result
** File description:
** Print result of operation
*/

#include <stdio.h>
#include <math.h>

void two_inter_cone(int *origin, int *vector, float calc[4])
{
	float s1 = (-calc[1] + sqrtf(calc[3])) / (2.0 * calc[0]);
	float s2 = (-calc[1] - sqrtf(calc[3])) / (2.0 * calc[0]);
	float x1 = vector[0] * s1 + origin[0];
	float y1 = vector[1] * s1 + origin[1];
	float z1 = vector[2] * s1 + origin[2];
	float x2 = vector[0] * s2 + origin[0];
	float y2 = vector[1] * s2 + origin[1];
	float z2 = vector[2] * s2 + origin[2];

	printf("2 intersection points :\n");
	printf("(%.3f, %.3f, %.3f)\n", x1, y1, z1);
	printf("(%.3f, %.3f, %.3f)\n", x2, y2, z2);
}

void two_answer(int *origin, int *vector, int calc[4])
{
	float s1 = (-calc[1] + sqrtf(calc[3])) / (2.0 * calc[0]);
	float s2 = (-calc[1] - sqrtf(calc[3])) / (2.0 * calc[0]);
	float x1 = vector[0] * s1 + origin[0];
	float y1 = vector[1] * s1 + origin[1];
	float z1 = vector[2] * s1 + origin[2];
	float x2 = vector[0] * s2 + origin[0];
	float y2 = vector[1] * s2 + origin[1];
	float z2 = vector[2] * s2 + origin[2];

	printf("2 intersection points :\n");
	printf("(%.3f, %.3f, %.3f)\n", x1, y1, z1);
	printf("(%.3f, %.3f, %.3f)\n", x2, y2, z2);
}

void one_answer(int *origin, int *vector, float s)
{
	float x = vector[0] * s + origin[0];
	float y = vector[1] * s + origin[1];
	float z = vector[2] * s + origin[2];

	printf("1 intersection point :\n");
	printf("(%.3f, %.3f, %.3f)\n", x, y, z);
}
