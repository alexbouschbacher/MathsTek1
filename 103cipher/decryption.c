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

void print_rev_key(int, float *);
void print_decrypt(int *, int);

float *reverse_key2(int *key)
{
	float *new_key = malloc (sizeof(float) * 4);
	int detA = 0;
	float mult;

	detA += key[0] * key[3];
	detA -= key[1] * key[2];
	mult = 1.0 / detA;
	new_key[0] = mult * key[3];
	new_key[1] = -1 * mult * key[1];
	new_key[2] = -1 * mult * key[2];
	new_key[3] = mult * key[0];
	return (new_key);
}

float *reverse_key3(int *key)
{
	float *new_key = malloc (sizeof(float) * 9);
	int detA = 0;
	float mult;

	detA += key[0] * key[4] * key[8] + key[1] * key[5] * key[6];
	detA += key[2] * key[3] * key[7] - (key[2] * key[4] * key[6]);
	detA -= key[0] * key[5] * key[7] + key[1] * key[3] * key[8];
	mult = 1.0 / detA;
	new_key[0] = mult * ((key[4] * key[8]) - (key[5] * key[7]));
	new_key[1] = mult * ((key[2] * key[7]) - (key[1] * key[8]));
	new_key[2] = mult * ((key[1] * key[5]) - (key[2] * key[4]));
	new_key[3] = mult * ((key[5] * key[6]) - (key[3] * key[8]));
	new_key[4] = mult * ((key[0] * key[8]) - (key[2] * key[6]));
	new_key[5] = mult * ((key[2] * key[3]) - (key[0] * key[5]));
	new_key[6] = mult * ((key[3] * key[7]) - (key[4] * key[6]));
	new_key[7] = mult * ((key[1] * key[6]) - (key[0] * key[7]));
	new_key[8] = mult * ((key[0] * key[4]) - (key[1] * key[3]));
	return (new_key);
}

int rev_matrix(float *key, int *message, int coord[3])
{
	float result = 0;
	int c = coord[1];
	int sizek = coord[2];
	int l = coord[0] * sizek;

	for (int a = 0; a < sizek; a++) {
		result += message[l] * key[c];
		l++;
		c += sizek;
	}
	return (roundf(result));
}


void decryption(int *key, int *message, int sizek, int sizem)
{
	float *rev_key;
	int *result = malloc(sizeof(int) * sizem);
	int coord[3];

	if (sqrt(sizek) == 3)
		rev_key = reverse_key3(key);
	else if (sqrt(sizek) == 2)
		rev_key = reverse_key2(key);
	else {
		rev_key = malloc (sizeof (float) * 1);
		rev_key[0] = 1.0 / key[0];
	}
	print_rev_key(sizek, rev_key);
	for (int i = 0; i < sizem; i++) {
		coord[0] = i / sqrt(sizek);
		coord[1] = i - sqrt(sizek) * coord[0];
		coord[2] = sqrt(sizek);
		result[i] = rev_matrix(rev_key, message, coord);
	}
	print_decrypt(result, sizem);
	free (rev_key);
}
