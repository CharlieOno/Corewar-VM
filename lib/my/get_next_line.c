/*
** EPITECH PROJECT, 2018
** CPE getnextline 2017
** File description:
** get next line function
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*my_calloc(int);
int	my_strlen(char*);
char	*my_strcat(char*, char*);

char *fix_no_char_line(char *str, char *buff, int index)
{
	if (str == NULL && buff[index] == '\n')
		str = my_strcat(NULL, "\0");
	return (str);
}

char *get_next_line(int fd)
{
	static char buff[4096 + 1];
	static char littlestr[2] = "\0";
	char *str = NULL;
	int buffsize = 4096;
	static int i = 0;

	if (fd < 0 && 4096 < 0)
		return (NULL);
	do {
		littlestr[0] = buff[i];
		if (buff[i] == '\0' || littlestr[0] == '\0') {
			i = 0;
			buffsize = read(fd, buff, 4096);
			buff[buffsize] = '\0';
			continue;
		}
		str = my_strcat(str, (littlestr[0] == '\n' ? NULL : littlestr));
		i++;
	} while (buff[i] != '\n' && buffsize > 0);
	return (fix_no_char_line(str, buff, i));
}
