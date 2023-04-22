#include"main.h"
int main()
{
	int x;
	x = _printf("STRINGS %s and CHARS %c \n", "HELLO\0", 'l');
	printf("%d", x);
	return (0);
}
