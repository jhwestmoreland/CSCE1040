#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void swap(int *x, int *y); //prototype

int main()
{
	int a = 1,
	    b = 2;

	printf("Before swap: a=%d b=%d\n", a, b);
	swap(&a,&b);
	printf("After swap: a=%d b=%d\n", a, b);

	return 0;
}

void swap()
{
	return;
}

void swap(int, int); // prototype


void swap(int *x, int *y) // function header
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
	printf("Inside swap: x=%d y=%d\n", *x, *y);

	return;
}

