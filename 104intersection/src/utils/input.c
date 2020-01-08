/*
** EPITECH PROJECT, 2017
** Project 104intersection
** File description:
** Input Handling.
*/

#include "main.h"

void input_help(char *arg)
{
	if (arg && arg[1] && arg[0] == '-' && arg[1] == 'h')
		help_print(1);
	else
		help_print(2);
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
	res = my_str_isnum(argv[8]);
	if (!res) {
		help_print(2);
		exit (84);
	}
	if (atoi(argv[5]) == 0 && atoi(argv[6]) == 0 && atoi(argv[7]) == 0) {
		help_print(2);
		exit (84);
	}
}

void input_parse(char *argv[], inputs_t *inputs)
{
	inputs->p = malloc(sizeof(int*) * 3);
	inputs->v = malloc(sizeof(int*) * 3);
	inputs->opt = atoi(argv[1]);
	inputs->p[0] = atoi(argv[2]);
	inputs->p[1] = atoi(argv[3]);
	inputs->p[2] = atoi(argv[4]);
	inputs->v[0] = atoi(argv[5]);
	inputs->v[1] = atoi(argv[6]);
	inputs->v[2] = atoi(argv[7]);
	inputs->par = atoi(argv[8]);
}

void input_validate(int argc, char *argv[], inputs_t *inputs)
{
	if (argc == 1) {
		input_help(argv[1]);
		exit (84);
	} else if (argc == 9) {
		input_verify(argv);
		input_parse(argv, inputs);
	} else {
		help_print(2);
		exit (84);
	}
}
