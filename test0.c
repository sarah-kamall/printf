#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");

     len = _printf("Length:[%d, %i]\n", len, len);
      len2=printf("Length:[%d, %i]\n", len2, len2);
      _printf("Length:[%d, %i]\n", len, len);
      printf("Length:[%d, %i]\n", len2, len2);

   len= _printf("Negative:[%d]\n", -762534);
    len2=printf("Negative:[%d]\n", -762534);

     _printf("Length:[%d, %i]\n", len, len);
     printf("Length:[%d, %i]\n", len2, len2);

    len= _printf("Character:[%c]\n", 'H');
    len2=printf("Character:[%c]\n", 'H');
      _printf("Length:[%d, %i]\n", len, len);
      printf("Length:[%d, %i]\n", len2, len2);

    len=_printf("String:[%s]\n", "I am a string !");
    len2= printf("String:[%s]\n", "I am a string !");	
     _printf("Length:[%d, %i]\n", len, len);
     printf("Length:[%d, %i]\n", len2, len2);

     len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[]\n");
     _printf("%b\n", 98);
    return (0);
}

