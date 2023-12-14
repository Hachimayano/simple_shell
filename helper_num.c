#include "shell.h"

/**
 * long_to_string - transforms a number to a string.
 * @number: number to be converted into a string.
 * @string: buffer to store the number as string.
 * @base: base for converting the number
 *
 * Return: Nothing.
 */
void long_to_string(long number, char *string, int base)
{
	int index = 0, inNegative = 0;
	long quotient = number;
	char letters[] = {"0123456789abcdef"};

	if (quotient == 0)
		string[index++] = '0';

	if (string[0] == '-')
		inNegative = 1;

	while (quotient)
	{
		if (quotient < 0)
			string[index++] = letters[-(quotient % base)];
		else
			string[index++] = letters[quotient % base];
		quotient /= base;
	}
	if (inNegative)
		string[index++] = '-';

	string[index] = '\0';
	str_reverse(string);
}


/**
 * _atoi - transforms a string to an integer.
 *
 * @s: pointer to the original string.
 * Return: int representation of string or 0.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int number = 0;
	/*1- analysis sign*/
	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sign *= -1;
		if (*s == '+')
			sign *= +1;
		s++;
	}

	/*2 - retrieve the number */
	while ('0' <= *s && *s <= '9' && *s != '\0')
	{

		number = (number * 10) + (*s - '0');
		s++;
	}
	return (number * sign);
}

/**
 * count_characters - calculate occurrences of characters in string.
 *
 * @string: pointer to an origin of string.
 * @character: string containing characters to be counted
 * Return: int representation of string or 0.
 */
int count_characters(char *string, char *character)
{
	int i = 0, counter = 0;

	for (; string[i]; i++)
	{
		if (string[i] == character[0])
			counter++;
	}
	return (counter);
}
