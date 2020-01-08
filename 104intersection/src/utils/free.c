/*
** EPITECH PROJECT, 2017
** Project 104intersection
** File description:
** Help, Usage.
*/

#include "main.h"

void my_free(inputs_t *inputs)
{
	free(inputs->p);
	free(inputs->v);
	free(inputs);
}