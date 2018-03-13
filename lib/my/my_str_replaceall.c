/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** replace all
*/

char *my_str_replaceall(char *str, char from, char to)
{
	int quotemarks = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '"')
			quotemarks += 1;
		if (quotemarks % 2 == 1)
			continue;
		if (str[i] == from)
			str[i] = to;
	}
	return (str);
}
