#include"main.h"
int _printf(const char *format, ...)
{
	char *s, *str;
	size_t size;
	char c;
	va_list(args);

	if (!format)
		return (-1);
	size = 0;
	s = format;
	va_start(args, format);
	while (s)
	{
		if (*s == '%')
		{
			switch (*s)
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
					c = va_arg(args, int);
					write(1, &c, 1);
					size += 1;
					s +=2;
			}
		}
		else
		{
			write(1, s, 1);
			s++;
			size += 1;
		}
	}
	return (size);
}



