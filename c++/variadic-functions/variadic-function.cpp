
#include<iostream>
#include<stdarg.h>

void print_list(int num, ...)
{
	va_list args;

	va_start(args, num);

	for(int i = 0; i < num; i++) 
	{
		int value = va_arg(args, int);
		printf("%d: %d\n", i, value);
	}

	va_end(args);
}

int main()
{
	print_list(3, 45, 32, 9);
}
