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

void encryption(int *, int *, int, int);
void decryption(int *, int *, int, int);
void fill_matrix(char *, int *, int, int);
void print_key(int, int *);

int find_mult(int mult, char *str, int todo)
{
	int a = 0;
	int size = 0;

	if (todo ==  0) {
		size = strlen(str);
	} else {
		for (int i = 0; str[i] != '\0'; i++) {
			size = (str[i] == ' ') ? size + 1 : size;
		}
	}
	while (mult * a++ < size);
	return (--a);
}

int find_square_sup(unsigned int nbr)
{
	int a;

	for (a = 0; pow(a, 2) < nbr; a++);
	return (a);
}

void find_error(int ac, char **av)
{
	if (ac != 4) {
		printf("%s, message, key, flag\n", av[0]);
		exit (84);
	}
	if (strlen (av[1]) == 0 || strlen (av[2]) == 0) {
		printf("The message or the key shouldn't be empty\n");
		exit(84);
	}
	if (strlen(av[3]) != 1 || av[3][0] > 49 || av[3][0] < 48) {
		printf("The flag should be only 0 or 1\n");
		exit (84);
	}
	if ((strlen(av[2]) == 5 || strlen(av[2]) == 6) && av[3][0] == '1') {
		printf("Invalid key for decryption\n");
		exit (84);
	}
}

int main(int ac, char **av)
{
	int *key;
	int sizek;
	int *message;
	int sizem;

	find_error(ac, av);
	sizek = find_square_sup(strlen(av[2]));
	key = malloc(sizeof (int) * pow(sizek, 2));
	fill_matrix(av[2], key, pow(sizek, 2), 0);
	sizem = find_mult(sizek, av[1], atoi(av[3]));
	message = malloc(sizeof (int) * (sizem * sizek));
	fill_matrix(av[1], message, (sizem * sizek), atoi(av[3]));
	if (av[3][0] == '0') {
		print_key(pow(sizek,2), key);
		encryption(key, message, pow(sizek, 2), (sizem * sizek));
	}
	else
		decryption(key, message, pow(sizek, 2), (sizem * sizek));
	free(key);
	free(message);
	return (0);
}
