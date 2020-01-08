/*
** EPITECH PROJECT, 2017
** Project 105torus
** File description:
** Help, Usage.
*/

#include "main.h"

void my_free(inputs_t *inputs)
{
	free(inputs->coef);
	free(inputs);
}