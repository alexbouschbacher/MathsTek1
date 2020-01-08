/*
** EPITECH PROJECT, 2017
** cipher.c
** File description:
** the source of the cipher
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void fill_matrix(char *str, int *matrix, int size, int flag)
{
	int i;
	int snbr;

	if (flag == 0) {
		for (i = 0; str[i] != '\0'; i++) {
			matrix[i] = str[i];
		}
		while (i < size) {
			matrix[i++] = 0;
		}
	} else {
		for (i = 0; *str != '\0'; i++) {
			matrix[i] = atoi(str);
			snbr = log10(matrix[i]) + 1;
			str += snbr;
			str += (*str == ' ') ? 1 : 0;
		}
		while (i < size) {
			matrix[i++] = 0;
		}
	}
}
