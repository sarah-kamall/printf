#include"main.h"
int switches(va_list args,char c, size_t *size, char **s);
int count_chars(int num) {
    int count = 0;
    while(num != 0) {
        num /= 10;
        count++;
    }
    return count;
}
int _printf(const char *format, ...)
{
	const char *s;
	size_t size;
	va_list(args);

	if (!format)
		return (-1);
	size = 0;
	s = format;
	va_start(args, format);
	while (*s)
	{
		if (*s == '%')
		{
			 switches(args, char c, size_t *size, char **s);
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
int switches(va_list args,char c, size_t *size, char **s)
{
	va_list args_copy;
    	va_copy(args_copy, args);
	char  *str;
	int x;
	switch (c)
	{
		case 's':
			str = va_arg(args, char *);
			if (str)
			{
				write(1, str, sizeof(str));
				size += sizeof(str);
				s += 2;
			}
			break;
		case 'c':
			x = va_arg(args, int);
			write(1, &x, 1);
			size += 1;
			s += 2;
			break;
		case 'i':
			x = va_arg(args, int);
			write(1, &x, sizeof(x));
			size += sizeof(x);
			s += 2;
		default:
			write(1, s, 1);
			size += 1;
			s++;
	}
}


