#ifndef MAIN_H
#define MAIN_H


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>
#include<unistd.h>

/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */
typedef struct mod
{
	char mod;
	int (*f)(size_t *size, va_list arg);
} mod_t;


int _printf(const char *format, ...);
int switches(va_list args,char c, size_t *size);
int count_chars(int num);
int checkifoct(int num);
int dec2oct(int num);
char *inttostring(int x);
int print_string(size_t *size, va_list arg);
int print_char(size_t *size, va_list arg);
int print_int(size_t *size, va_list arg);
int print_prec(size_t *size, va_list arg);


#endif
