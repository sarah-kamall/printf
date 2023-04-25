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
	int num;
	char *str;

	str = va_arg(arg, char *);
	while (str)
	{
		if (((*str > 0) && (*str < 32)) || (*str >= 127))
		{
			int i;
			static char pf[]  = "\x";
			char *hex;

			i = *str;
			write(1, pf, 2);
			*size += 2;
			hex = conv_bas(i, 16);
			write(1, hex, 2);
			*size += count_chars(i);
		}
		else
		{
		write(1, str, strlen(str));
		*size += strlen(str);
		num =  2;
		}
		str++;
	}
	return (num);
}
char *conv_bas(int num, int base)
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
		(*size)++;
	}while (num != 0);

	return (ptr);
}
}
