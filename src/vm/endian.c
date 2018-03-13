/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** endian memory convertions
*/

#include "vm_prototype.h"

int	endian_swap(int x)
{
	int	y = 0;

	y += (x & 0x000000ff)<<24;
	y += (x & 0x0000ff00)<<8;
	y += (x & 0x00ff0000)>>8;
	y += (x & 0xff000000)>>24;
	return (y);
}

int	analys_byte_code(char byte, int argc, int indexes)
{
	int	length = 0;
	int	size;

	size = (indexes == S_TRUE) ? 2 : 4;
	length = (argc == 1) ? (byte & 0xc0)>>6 : length;
	length = (argc == 2) ? (byte & 0x30)>>4 : length;
	length = (argc == 3) ? (byte & 0x0c)>>2 : length;
	length = (argc == 4) ? (byte & 0x03)>>0 : length;
	length = (length == 2) ? size : length;
	length = (length == 3) ? 2 : length;
	return (length);
}

int	length_byte_code(char byte, int indexes)
{
	int	length = 0;

	for (int i = 1; i <= MAX_ARGS_NUMBER; i++)
		length += analys_byte_code(byte, i, indexes);
	return (length);
}

int	my_powpow(int value, int pow)
{
	int	result = value;

	if (pow == 0)
		return (1);
	for (int i = 1; i < pow; i++)
		result *= value;
	return (result);
}

int	mem_value(char *mem, int index, int length)
{
	int	power = length - 1;
	int	value = 0;

	for (int i = 0; i < length; i++)
		value += mem[(index + i)] * my_powpow(256, power - i);
	return (value);
}