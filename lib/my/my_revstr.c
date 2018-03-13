/*
** EPITECH PROJECT, 2017
** task03
** File description:
** rev str
*/

int	my_strlen(char*);

char	*my_revstr(char *str)
{
	int	len = my_strlen(str);
	int	i2 = 0;
	char	res;

	for (int i = len - 1; i >= len / 2; i--) {
		res = str[i];
		str[i] = str[i2];
		str[i2] = res;
		i2++;
	}
	return (str);
}
