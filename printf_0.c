#include"main.h"
/**
 * _printf - custom printf function
 * @format: format string
 * @...: optional arguments
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	const char *s;
	size_t size;
	va_list(args);
	int u;

	if (!format)
		return (-1);
	size = 0;
	s = format;
	va_start(args, format);
	while (*s)
	{
		if (*s == '%')
		{
			u = switches(args, *(s + 1), &size);
			if (u == 2)
				s += 2;
			if (u == 1)
				s += 1;
		}
		else
		{
			write(1, s, 1);
			s++;
			size += 1;
		}
	}
	va_end(args);
	return (size);
}
/**
 * switches - helper function for handling conversion specifiers in printf
 * @args: a va_list containing the arguments to be printed
 * @c: the conversion specifier to use
 * @size: a pointer to the size of the output string
 *
 * Return: a string representing the converted value
 */
int switches(va_list args,char c, size_t *size)
{
	char  *str;
	int x;
	switch (c)
	{
		case 's':
			str = va_arg(args, char *);
			if (str)
			{
				write(1, str, strlen(str));
				*size += strlen(str);
				return (2);
			}
			break;
		case 'c':
			x = va_arg(args, int);
			write(1, &x, 1);
			*size += 1;
			return (2);
			break;
		case 'i':
			x = va_arg(args, int);
			str = inttostring(x);
			write(1, str, strlen(str));
			*size += count_chars(x);
			return (2);
			break;
		case '%':
			x = '%';
			write(1, &x, 1);
			*size += 1;
			return (2);
			break;
		default:
			write(1, &c, 1);
			*size += 1;
			return (1);
	}
	return (0);
}
