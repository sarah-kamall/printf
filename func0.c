#include "main.h"
/**
*print_string -  prints  a  string
*@size: pointer to string size
*@arg: va_list supplied
*Return: number of chars to skip
*/
int print_string(size_t *size, va_list arg)
{
	int num;
	char *str;

	str = va_arg(arg, char *);
	if (str)
	{
		write(1, str, strlen(str));
		*size += strlen(str);
		num =  2;
	}
	return (num);
}

/**
*print_char -  prints  a  char
*@size: pointer to string size
*@arg: va_list supplied
*Return: number of chars to skip
*/
int print_char(size_t *size, va_list arg)
{
	int x;
	int num;

	x = va_arg(arg, int);
	write(1, &x, 1);
	*size += 1;
	num = 2;
	return (num);
}

/**
*print_int -  prints  a  int
*@size: pointer to string size
*@arg: va_list supplied
*Return: number of chars to skip
*/
int print_int(size_t *size, va_list arg)
{
	int x;
	int num;
	char *str;

	x = va_arg(arg, int);
	if (checkifoct(x))
		x = dec2oct(x);
	str = inttostring(x);
	write(1, str, strlen(str));
	*size += count_chars(x);
	num = 2;
	return (num);
}

/**
*print_prec -  prints  a prec
*@size: pointer to string size
*@arg: va_list supplied
*Return: number of chars to skip
*/
int print_prec(size_t *size, __attribute__((unused))va_list arg)
{
	int x;
	int num;

	x = '%';
	write(1, &x, 1);
	*size += 1;
	num = 2;
	return (num);
}
/**
*print_dec -  prints  a dec
*@size: pointer to string size
*@arg: va_list supplied
*Return: number of chars to skip
*/

int print_dec(size_t *size, va_list arg)
{
	int num;
	int binary[32];
	int i;
	int len;

	num = va_arg(arg, unsigned int);

	for (i = 0 ;num > 0; i++)
	{
		binary[i] = num % 2;
		num /= 2;
		len++;
	}
	for (i = len - 1; i >= 0; i--)
	{
		char z;

		z = binary[i] + '0';
		write(1, &z, 1);
		*size += 1;
	}
	
	return (2);
}
