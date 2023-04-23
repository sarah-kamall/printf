#include"main.h"
/**
 * count_chars - count the number of digits in an integer
 * @num: the integer to count digits of
 *
 * Return: the number of digits in the integer
 */
int count_chars(int num)
{
	int count;

	count = 0;
	if (num < 0)
		count ++;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}
/**
 * inttostring - convert an integer to a string
 * @x: the integer to convert
 *
 * Return: a newly allocated string representing the integer
 *         or NULL if memory allocation fails
 */
char *inttostring(int x)
{
	int sign;
	int length;
	int tmp;
	char *str;
	int i;

	length = 0;
	tmp = x;
	sign = x < 0 ? -1 : 1;
	while (tmp != 0)
	{
		length++;
		tmp /= 10;
	}
	if (sign < 0)
	{
		length++;
	}
	str = malloc(length + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	str[length] = '\0';
	i = length - 1;
	while (x != 0)
	{
		str[i] = abs(x % 10) + '0';
		x /= 10;
		i--;
	}
	if (sign < 0)
	{
		str[0] = '-';
	}
	return (str);
}
