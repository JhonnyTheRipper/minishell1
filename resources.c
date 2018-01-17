/*
**EPITECH PROJECT, 2017
**File description:
** @Last Modified by:   Neo
** @Last Modified time: 2018-01-17 10:13:04
*/

int get_size(char **ev)
{
	int i = 0;
	while (ev[i])
		i++;
	return i;
}