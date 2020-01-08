/*
** EPITECH PROJECT, 2017
** print.c
** File description:
** print all matrix
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void print_key(int size, int *matrix)
{
	int s = sqrt(size);
	int pos;

	printf("Key matrix :\n");
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			pos = i * s + j;
			printf("%d", matrix[pos]);
			printf((pos + 1 == (i + 1) * s) ? "\n" : "\t");
		}
	}
}

void print_rev_key(int size, float *matrix)
{
	int s = sqrt(size);
	int pos;

	printf("Key matrix :\n");
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			pos = i * s + j;
			printf("%.3f", matrix[pos]);
			printf((pos + 1 == (i + 1) * s) ? "\n" : "\t");
		}
	}
}

void print_decrypt(int *message, int size)
{
	printf("Decrypted message :\n");
	for (int i = 0; i < size; i++) {
		if (message[i] != 0)
			printf("%c", message[i]);
	}
	printf("\n");
	free(message);
}
