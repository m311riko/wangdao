#include <stdio.h>
#include <iostream>

int a=0;
const int b=10;

int main()
{
	int c=20;
	const int d=30;

	printf("&a=%x\n",&a);
	printf("&b=%x\n",&b);
	printf("&c=%x\n",&c);
	printf("&d=%x\n",&d);

	return 0;
}
