#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>
#include<unistd.h>
int _printf(const char *format, ...);
int switches(va_list args,char c, size_t *size);
int count_chars(int num);
char *inttostring(int x);
