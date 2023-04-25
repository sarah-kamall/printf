#include "main.h"

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
int print_mod_string(size_t *size, va_list arg)
{
	char *str, *hexptr;
	static char pf[]  = "\\x";
	int i;

	str = va_arg(arg, char *);
	while (*str)
	{
		if (((*str > 0) && (*str < 32)) || (*str >= 127))
		{
			i = *str;
			write(1, pf, 2);
			*size += 2;
			hexptr = conv_bas(i, 16, 2);
			write(1, hexptr, 2);
			*size += count_chars(i);
		}
		else
		{
		write(1, str, 1);
		*size += 1;
		}
		str++;
	}
	return (2);
}
char *conv_bas(int num, int base, int precision)
{
	static char representation[] = "0123456789ABCDEF";
	static char buffer [50];
	char *ptr;

	if (base < 2 || base > 16)
		return (NULL);

	ptr = &buffer[49];
	*ptr = '\0';
	do
	{
		*(--ptr) = representation[num % base];
		num /= base;
		precision--;
	}while (num != 0);
	while (precision > 0)
	{
		*(--ptr) = '0';
		precision--;
	}
	return (ptr);
}
