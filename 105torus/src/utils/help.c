/*
** EPITECH PROJECT, 2017
** Project 105torus
** File description:
** Help, Usage.
*/

#include "main.h"

void help_print(int wanted)
{
	_IO_FILE *output = wanted == 0 ? stdout : stderr;

	fprintf(output, "Usage ./105torus opt a0 a1 a2 a3 a4 n\n");
	fprintf(output, "OPT: Methods 1:Bisection 2:Newton 3:Secant\n");
	fprintf(output, "N: Precision (Smaller than 10^-n)\n");
}
