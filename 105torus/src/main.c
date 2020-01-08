/*
** EPITECH PROJECT, 2017
** Project 105torus
** File description:
** Main file.
*/

#include "main.h"

int main(int argc, char *argv[])
{
	inputs_t *inputs = malloc(sizeof(inputs_t));

	input_validate(argc, argv, inputs);
	switch (inputs->opt) {
		case 1: bisection(inputs->coef, inputs->n); break;
		case 2: newton(inputs->coef, inputs->n); break;
		case 3: secant(inputs->coef, inputs->n); break;
		default: break;
	}
	my_free(inputs);
	return (0);
}
