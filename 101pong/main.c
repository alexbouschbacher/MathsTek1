/*
** EPITECH PROJECT, 2017
** pong
** File description:
** the pong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void find_errors(int, char **);
void pong(float *, float *, unsigned int);

int main(int argc, char **argv)
{
	float pos0[3];
	float pos1[3];
	unsigned int timer;

	find_errors (argc, argv);
	timer = atoi(argv[7]);
	pos0[0] = atof(argv[1]);
	pos0[1] = atof(argv[2]);
	pos0[2] = atof(argv[3]);
	pos1[0] = atof(argv[4]);
	pos1[1] = atof(argv[5]);
	pos1[2] = atof(argv[6]);
	pong (pos0, pos1, timer);
	return (0);
}
