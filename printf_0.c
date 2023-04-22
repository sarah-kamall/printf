#include"main.h"
int switches(va_list args,char c, size_t *size);
int count_chars(int num) {
    int count = 0;
    while(num != 0) {
        num /= 10;
        count++;
    }
    return count;
}
char *inttostring(int x) {
    int sign = x < 0 ? -1 : 1;
    int length = 0;
    int tmp = x;
    char *str;
    int i;

    while (tmp != 0) {
        length++;
        tmp /= 10;
    }
    if (sign < 0) {
        length++;
    }
    str = malloc(length + 1);
    if (str == NULL) {
        return NULL;
    }
    str[length] = '\0';
    i = length - 1;
    while (x != 0) {
        str[i] = abs(x % 10) + '0';
        x /= 10;
        i--;
    }
    if (sign < 0) {
        str[0] = '-';
    }
    return str;
}
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
		default:
			write(1, &c, 1);
			*size += 1;
			return (1);
	}
	return (0);
}
