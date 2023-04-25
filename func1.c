#include "main.h"
/**
 * convert_to_base - Convert unsigned int to given base
 * @arg: va_list to find the desired argument
 * @base: The base to convert the number to
 * @size: to uincrement the size
 *
 * Return: A string representing the converted number
 */
char *convert_to_base(va_list arg, size_t *size, unsigned int base)
{
	unsigned int num;
	static char representation[] = "0123456789ABCDEF";
	static char buffer [50];
	char *ptr;

	num = va_arg(arg, unsigned int);
	if (base < 2 || base > 16)
		return (NULL);

	ptr = &buffer[49];
	*ptr = '\0';
	do
	{
		*(--ptr) = representation[num % base];
		num /= base;
		(*size)++;
	}while (num != 0);

	return (ptr);
}
int print_binary(size_t *size, va_list arg)
{
	char *s;

	s = convert_to_base(arg, size, 2);
	write(1, s, strlen(s));
	return (2);
}
int print_unsigned(size_t *size, va_list arg)
{
	char *s;

	s = convert_to_base(arg, size, 10);
	write(1, s, strlen(s));
	return (2);
}
int print_octal(size_t *size, va_list arg)
{
	char *s;

	s = convert_to_base(arg, size, 8);
	write(1, s, strlen(s));
	return (2);
}
int print_hexupp(size_t *size, va_list arg)
{
	char *s;

	s = convert_to_base(arg, size, 16);
	write(1, s, strlen(s));
	return(2);
}
void str_to_lower(char *str) 
{
	int i;

	int len = strlen(str);
        for (i = 0; i < len; i++) 
	{
        	str[i] = tolower(str[i]);
        }
}

int print_hexlow(size_t *size, va_list arg)
{
	char *s;

	s = convert_to_base(arg, size, 16);
	str_to_lower(s);
	write(1, s, strlen(s));
	return (2);
}

