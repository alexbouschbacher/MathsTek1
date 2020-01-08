/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** Returns 1 if string is 123 only, else 0
*/

int my_str_isnum(char const *str)
{
	char x;
	int i = 0;

	while (str[i]) {
		x = str[i];
		if (x >= 48 && x <= 57)
			i += 1;
		else
			return (0);
	}
	return (1);
}