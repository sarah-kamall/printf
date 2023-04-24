#include "main.h"

int print_unsigned(size_t *size, va_list arg)
{
	int x;
	char *str;

	x = va_arg(arg, unsigned int);
	str = uninttostring(x);
	write(1, str, strlen(str));
	*size += count_chars(x);
	return (0);
}
int print_octal(size_t *size, va_list arg)
{
	int octal;
	int i;
	int decimal;
	char *str;

	octal = 0;
	i = 0;
	decimal = va_arg(arg, unsigned int);
	while (decimal != 0)
	{
		octal += (decimal % 8) * i;
		decimal /= 8;
		i *= 10;
	}
	str = uninttostring(octal);
	write(1, str, strlen(str));
	*size += count_chars(octal);
	return (2);
}
int print_hexupp(size_t *size, va_list arg)
{
	int rem, i;
	char hexnum[50];
	int decnum;

	decnum = va_arg(arg, unsigned int);
	i = 0;
	while (decnum != 0)
	{
		rem = decnum % 16;
		if (rem < 10)
        		rem = rem + 48;
		else
			rem = rem + 55;
		hexnum[i] = rem;
		i++;
		decnum = decnum / 16;
	}
	for(i=i-1; i>=0; i--)
	{
		write(1, &hexnum[i], 1);
		*size +=1;
	}
	return (2);
}
int print_hexlow(size_t *size, va_list arg)
{

	int rem, i;
	char hexnum[50];
	int decnum;

	decnum = va_arg(arg, unsigned int);
	i = 0;
	while (decnum != 0)
	{
		rem = decnum % 16;
		if (rem < 10)
        		rem = rem + 48;
		else
			rem = rem + 87;
		hexnum[i] = rem;
		i++;
		decnum = decnum / 16;
	}
	for(i=i-1; i>=0; i--)
	{
		write(1, &hexnum[i], 1);
		*size +=1;
	}
	return (2);
}
