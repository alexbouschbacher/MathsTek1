/*
** EPITECH PROJECT, 2017
** Project 105torus
** File description:
** Header file
*/

#ifndef MAIN_H_
	#define MAIN_H_
	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <math.h>

	typedef struct inputs {
		int opt;
		int *coef;
		int n;
	} inputs_t;

	void input_validate(int, char**, inputs_t*);
	void help_print(int);
	void my_free(inputs_t*);
	int my_str_isnum(char const*);
	void bisection(int *, int);
	void newton(int *, int);
	void secant(int *, int);
#endif
