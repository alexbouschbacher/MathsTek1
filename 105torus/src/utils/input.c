/*
** EPITECH PROJECT, 2017
** Project 105torus
** File description:
** Input Handling.
*/

#include "main.h"

void input_help(char *arg)
{
	if (arg && arg[1] && arg[0] == '-' && arg[1] == 'h') {
		help_print(0);
		exit (0);
	} else
		help_print(1);
	exit (84);
}

void input_verify(char *argv[])
{
	int res = 0;

	res = my_str_isnum(argv[1]);
	res = my_str_isnum(argv[2]);
	res = my_str_isnum(argv[3]);
	res = my_str_isnum(argv[4]);
	res = my_str_isnum(argv[5]);
	res = my_str_isnum(argv[6]);
	res = my_str_isnum(argv[7]);
	if (!res) {
		help_print(1);
		exit (84);
	}
}

void input_parse(char *argv[], inputs_t *inputs)
{
	inputs->opt = atoi(argv[1]);
	inputs->coef = malloc(sizeof(int*) * 5);
	inputs->coef[0] = atoi(argv[2]);
	inputs->coef[1] = atoi(argv[3]);
	inputs->coef[2] = atoi(argv[4]);
	inputs->coef[3] = atoi(argv[5]);
	inputs->coef[4] = atoi(argv[6]);
	inputs->n = atoi(argv[7]);
}

void input_validate(int argc, char *argv[], inputs_t *inputs)
{
	if (argc == 1) {
		input_help(argv[1]);
	} else if (argc == 8) {
		input_verify(argv);
		input_parse(argv, inputs);
	} else {
		help_print(1);
		exit (84);
	}
}
