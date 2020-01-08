/*
** EPITECH PROJECT, 2017
** Project 104intersection
** File description:
** Main file.
*/

#include "main.h"

void print_line(int *p, int *v)
{
	char msg[] = "straight line going through the";

	printf("%s (%d,%d,%d) ", msg, p[0], p[1], p[2]);
	printf("point and of direction vector (%d,%d,%d)\n", v[0], v[1], v[2]);
}

int main(int argc, char *argv[])
{
	inputs_t *inputs = malloc(sizeof(inputs_t));

	input_validate(argc, argv, inputs);
	if (inputs->opt == 1) {
		printf("sphere of radius %d\n", inputs->par);
		print_line(inputs->p, inputs->v);
		inter_sphere(inputs->p, inputs->v, inputs->par);
	} else if (inputs->opt == 2) {
		printf("cylinder of radius %d\n", inputs->par);
		print_line(inputs->p, inputs->v);
		inter_cylindre(inputs->p, inputs->v, inputs->par);
	} else {
		printf("cone of %d degree angle\n", inputs->par);
		print_line(inputs->p, inputs->v);
		inter_cone(inputs->p, inputs->v, inputs->par);
	}
	my_free(inputs);
	return (0);
}
