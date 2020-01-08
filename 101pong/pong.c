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

void check_arg(char *tmp, int i)
{
	int j = 0;

	if (strlen(tmp) == 0) {
		printf ("Argument %i is empty\n", i);
		exit (84);
	}
	for (j = 0; tmp[j] != '.' && tmp[j]; j++) {
		if (j == 0 && tmp[0] == '-')
			j++;
		if (tmp[j] < '0' && tmp[j] > '9') {
			printf("Invalid argument1\n");
			exit (84);
		}
	}
	if (j == strlen(tmp) - 1 && tmp[i] == '.') {
		printf ("Invalid argument2\n");
		exit (84);
	}
	(tmp[j] == '.') ? j++ : j;
	for (; tmp[j] && tmp[j] >= '0' && tmp[j] <= '9'; j++);
	if (j != strlen(tmp)) {
		printf ("Invalid argument3: %d, %s\n", j, tmp);
		exit (84);
	}
}

void find_errors(int argc, char **argv)
{
	char *tmp = argv[0];

	if (argc < 8) {
		printf ("Too few arguments\n");
		exit (84);
	} else if (argc > 8) {
		printf ("Too much arguments\n");
		exit (84);
	}
	for (int i = 1; i < argc; i++) {
		tmp = argv[i];
		check_arg(tmp, i);
	}
}

float find_degree(float *speed)
{
	float adj = sqrtf (powf(speed[0], 2) + powf(speed[1], 2));
	float hypo = sqrtf (powf(adj, 2) + powf(speed[2], 2));
	float cosinus = acosf(adj / hypo) * 180 / acosf(-1);

	return (cosinus);
}

void print_par(float *speed, float *post, float angle, unsigned int timer)
{
	printf ("The speed vector coordinates are :\n");
	printf ("(%.2f;%.2f;%.2f)\n", speed[0], speed[1], speed[2]);
	printf ("At time t+%i, ball coordinates will be :\n", timer);
	printf ("(%.2f;%.2f;%.2f)\n", post[0], post[1], post[2]);
	if (angle > 90)
		printf ("The ball won't reach the bat\n");
	else {
		printf ("The incidence angle is :\n");
		printf ("%.2f degrees\n", angle);
	}
}

void pong(float *pos0, float *pos1, unsigned int timer)
{
	float post[3];
	float speed[3];
	float degree;

	speed[0] = pos1[0] - pos0[0];
	speed[1] = pos1[1] - pos0[1];
	speed[2] = pos1[2] - pos0[2];
	post[0] = speed[0] * timer + pos1[0];
	post[1] = speed[1] * timer + pos1[1];
	post[2] = speed[2] * timer + pos1[2];
	if (post[2] * pos1[2] <= 0)
		degree = find_degree(speed);
	else
		degree = 100;
	print_par (speed, post, degree, timer);
}
