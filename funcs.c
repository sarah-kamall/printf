#include "main.h"

int print_string(size_t *size, va_list arg)
{
	int num;
	char *str;

	str = va_arg(arg, char *);
	if (str)
	{
		write(1, str, strlen(str));
		*size += strlen(str);
		num =  2;
	}
	return (num);
}
int print_char(size_t *size, va_list arg)
{
	int x;
	int num;

	x = va_arg(arg, int);
	write(1, &x, 1);
	*size += 1;
	num = 2;
	return (num);
}
int print_int(size_t *size, va_list arg)
{
	int x;
	int num;
	char *str;

	x = va_arg(arg, int);
	if (checkifoct(x))
		x = dec2oct(x);
	str = inttostring(x);
	write(1, str, strlen(str));
	*size += count_chars(x);
	num = 2;
	return (num);
}
int print_prec(size_t *size, __attribute__((unused))va_list arg)
{
	int x;
	int num;

	x = '%';
	write(1, &x, 1);
	*size += 1;
	num = 2;
	return (num);
}
int print_dec(size_t *size, va_list arg)
{
	char *binary[];
	int num;

	num = va_args(arg, int);

	if (num <= 0)
	{
		binary[] = "0";
	}
	else
	{
		int i;
		
		i = 0;
		for ( ;num > 0; )
		{
			binaryNum[i++] = num % 2;
			num /= 2;
		}
	}
}
