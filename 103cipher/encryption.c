/*
** EPITECH PROJECT, 2017
** encrytion.c
** File description:
** encrypted the message
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int mult_matrix(int *key, int *message, int coord[3])
{
	int result = 0;
	int col = coord[1];
	int sizek = coord[2];
	int lign = coord[0] * sizek;

	for (int a = 0; a < sizek; a++) {
		result += message[lign] * key[col];
		lign++;
		col += sizek;
	}
	return (result);
}

void encryption(int *key, int *message, int sizek, int sizem)
{
	int *result = malloc(sizeof(int) * sizem);
	int coord[3];

	for (int i = 0; i < sizem; i++) {
		coord[0] = i / sqrt(sizek);
		coord[1] = i - sqrt(sizek) * coord[0];
		coord[2] = sqrt(sizek);
		result[i] = mult_matrix(key, message, coord);
	}
	printf("Encrypted message :\n");
	for (int i = 0; i < sizem; i++) {
		if (result[i] != 0)
			printf("%d", result[i]);
		if (i + 1 != sizem)
			printf(" ");
	}
	printf("\n");
	free (result);
}
