/*
** EPITECH PROJECT, 2017
** getnbr
** File description:
** my lib :)
*/

int	my_getnbr(char const *str)
{
	int i = 0;
	long nb = 0;
	int sign = 0;

	while (str[i] != '\0') {
		if (str[i] == '-')
			sign++;
		if (str[i] >= 48 && str[i] <= 57) {
			nb += str[i] - 48;
			nb *= 10;
		} else if (nb != 0) {
			break;
		}
		i++;
	}
	if (nb <= -2147483648 || nb >= 2147483647)
		return (0);
	if (sign % 2 != 0)
		nb = -nb;
	return ((int)nb/10);
}
