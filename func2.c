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
int print_ptr(size_t *size, va_list arg)
{
	intptr_t p;
	void *ptr;
	char *s, zx[2];
	long unsigned int i;

	ptr = va_arg(arg, void *);
	if (ptr == NULL)
	{
		s = malloc(strlen("(nil)") + 1);
		if (!s)
			return (1);
		s = "(nil)\0";
		*size += strlen(s);
		write(1, s, strlen(s));
		return (2);
	}
	p = (intptr_t) ptr;
	i = p;
	s = conv_bas(i, 16, 0);
	zx[0] = '0';
	zx[1] = 'x';
	write(1, zx, 2);
	str_to_lower(s);
	write(1, s, strlen(s));
	*size += (strlen(s) + 2);
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
