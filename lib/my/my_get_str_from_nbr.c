/*
** EPITECH PROJECT, 2018
** Libmy
** File description:
** my get str from nbr
*/

#include <stdlib.h>
char *my_calloc(int);
char *my_revstr(char *);

int	my_get_int_len(int nb)
{
	int	len = 1;

	if (nb < 0) {
		len++;
		nb = -nb;
	}
	while (nb > 9) {
		nb /= 10;
		len++;
	}
	return (len);
}

char *my_get_str_from_nbr(int nb)
{
	char *strnbr = my_calloc(my_get_int_len(nb) + 1);
	int index = 0;
	int neg = nb < 0 ? 1 : 0;

	if (strnbr == NULL)
		return (NULL);
	nb *= nb < 0 ? -1 : 1;
	if (nb == 0) {
		strnbr[index] = '0';
		strnbr[index + 1] = '\0';
	}
	for (; nb != 0; index++) {
		strnbr[index] = (nb % 10) + '0';
		nb /= 10;
	}
	strnbr[index] = neg == 1 ? '-' : '\0';
	strnbr[index+1] = '\0';
	strnbr = my_revstr(strnbr);
	return (strnbr);
}
