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
	while (*str)
	{
		if (((*str > 0) && (*str < 32)) || (*str >= 127))
		{
			int i;

			i = *str;
			write(1, "/x", strlen("/x"));
			*size += 2;
			write(1, &i, 1);

			continue;
		}
		write(1, str, strlen(str));
		*size += strlen(str);
		num =  2;
	}
	return (num);
}
