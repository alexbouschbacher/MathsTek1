/*
** EPITECH PROJECT, 2017
** architech
** File description:
** my architech
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void translation (float *, float *, float *);
void rotate (float *, float *, float *);
void homotety (float *, float *, float *);
void symetry (float *, float *, float *);

void check_arg(char *tmp, int i)
{
	unsigned int j = 0;

	if (strlen(tmp) == 0) {
		write (2, "Argument is empty\n", 18);
		exit (84);
	}
	for (j = 0; tmp[j] != '.' && tmp[j]; j++) {
		if (j == 0 && tmp[0] == '-')
			j++;
		if (tmp[j] < '0' && tmp[j] > '9') {
			write (2, "Invalid argument\n", 17);
			exit (84);
		}
	}
	if (j == strlen(tmp) - 1 && tmp[i] == '.') {
		write (2, "Invalid argument\n", 17);
		exit (84);
	}
	(tmp[j] == '.') ? j++ : j;
	for (; tmp[j] && tmp[j] >= '0' && tmp[j] <= '9'; j++);
	if (j != strlen(tmp)) {
		write (2, "Invalid argument\n", 17);
		exit (84);
	}
}

void do_op (char op, float *v, float *p, float *matrix)
{
	switch (op) {
		case 't':
			translation (v, p, matrix);
			break;
		case 's':
			symetry (v, p, matrix);
			break;
		case 'h':
			homotety (v, p, matrix);
			break;
		case 'r':
			rotate (v, p, matrix);
	}
}

char find_op (char *op)
{
	switch (op[1]) {
	case 't': return ('t');
	case 's': return ('s');
	case 'h': return ('h');
	case 'r': return ('r');
	default: exit(84);
	}
}

static void do_arg (float *matrix, float *v, float *p, char **av)
{
	char op = '\0';
	int ac = atoi(av[0]);

	for (int i = 3; i < ac; i++) {
		op = find_op(av[i++]);
		v[1] = (op == 'h') ? 1.0 : 0.0;
		if (i == ac)
			exit (84);
		check_arg (av[i], i);
		v[0] = atof (av[i]);
		if (i + 1 >= ac || av[i + 1][1] > 9 || av[i + 1][1] < 0) {
			i = i;
		} else if (op != 'r' && op != 's' && i++ > 0) {
			check_arg (av[i], i);
			v[1] = atof (av[i]);
		} else {
			write (2, "FAILURE!\n", 9);
			exit (84);
		}
		do_op(op, v, p, matrix);
	}
}

int main(int ac, char **av)
{
	float matrix[9] = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
	float p[2] = {0.0, 0.0};
	float v[2] = {0.0, 0.0};

	check_arg (av[1], 1);
	check_arg (av[2], 2);
	p[0] = atof (av[1]);
	p[1] = atof (av[2]);
	sprintf(av[0], "%d", ac);
	do_arg(matrix, v, p, av);
	printf ("%.2f\t%.2f\t%.2f\n", matrix[0], matrix[1], matrix[2]);
	printf ("%.2f\t%.2f\t%.2f\n", matrix[3], matrix[4], matrix[5]);
	printf ("%.2f\t%.2f\t%.2f\n", matrix[6], matrix[7], matrix[8]);
	printf ("(%d,%d) ", atoi(av[1]), atoi(av[2]));
	printf ("=> (%.2f,%.2f)\n", p[0], p[1]);
	return (0);
}
