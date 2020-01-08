/*
** EPITECH PROJECT, 2017
** Project 104intersection
** File description:
** Help, Usage.
*/

#include "main.h"

void help_print(int ch)
{
	write(ch, "Usage ./104intersection OPT xp yp zp xv yv zv P\n", 49);
	write(ch, "OPT: 1: Sphere, 2: Cylinder, 3: Cone\n", 38);
	write(ch, "*p: Coordinates of the point\n", 30);
	write(ch, "*v: Coordinates of the direction vector\n", 41);
	write(ch, "P: Sphere/Cylinder radius or Cone angle and Z axis\n", 52);
}