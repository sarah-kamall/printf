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
	va_list args;
	int u;

	if (!format || !(*format))
		return (-1);
	size = 0;
	s = format;
	va_start(args, format);
	while (*s)
	{
		if (*s == '%')
		{
			if (*(s + 1))
			{
				while (*(s + 1) && *(s + 1) == ' ')
				{
					write(1, (s + 1), 1);
					size += 1;
					s++;
				}
				u = switches(args, *(s + 1), &size);
				s += u;
			}
			else
			{
				return (-1);
			}
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
int switches(va_list args, char c, size_t *size)
{
	int i;

	mod_t mod[] = {
		{'s', print_string},
		{'c', print_char},
		{'i', print_int},
		{'d', print_int},
		{'%', print_prec},
		{'b', print_dec},
		{'\0', NULL}
	};
	i = 0;
	while (i < 6)
	{
		if (mod[i].mod == c)
		{
			return (mod[i].f(size, args));
		}
		i++;
	}
	return (0);
}
