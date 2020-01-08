/*
** EPITECH PROJECT, 2017
** Project 104intersection
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
		int *p;
		int *v;
		int par;
	} inputs_t;

	void input_validate(int, char**, inputs_t*);
	void help_print(int);
	void my_free(inputs_t*);
	int my_str_isnum(char const*);
	void one_answer(int*, int*, float);
	void two_answer(int*, int*, int[4]);
	void two_inter_cone(int*, int*, float[4]);
	void inter_cone(int*, int*, int);
	void inter_cylindre(int*, int*, int);
	void inter_sphere(int*, int*, int);
#endif
