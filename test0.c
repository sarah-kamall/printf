#include"main.h"
int main(void)
{
	char a;
	char *b;

	a = 'H';
	b = "hello";

	a = _printf("%c, %s\n, % \0", a, b);
	return (0);
}
