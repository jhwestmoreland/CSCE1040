/*
	Jared Westmoreland
	2/25/2016
	Lab5
	Details:
	Liar-Liar numbers area a sequence of negative numbers in which each number is two
	times the sum of the previous two negative numbers
*/
#include <iostream>
#include <stdio.h>

void Liar(int n, int Liar_Liar[24]);

int main()
{
	int Liar_Liar[24];
	int n = 0;
	printf("123456789012345678901234567890\n");
	Liar(n, Liar_Liar);
	return 0;
}

void Liar(int n, int Liar_Liar[24])
{
	if(n < 23)	//loops until n becomes greater than 23
	{
		n++;
		if( (n == 1) || (n == 2) )	//if n = 1 or 2 then make Liar_Liar = -1
		{
			Liar_Liar[n]= -1;
		}
		if(n >= 3)	//if n is greater than or equal to 3 use this equation
		{
			//store as n = 2x(the previos Liar_Liar - the previos Liar_Liar + the previos Liar_Liar + Liar_Liar from two loops ago
			Liar_Liar[n] = 2*(Liar_Liar[n-1] - (Liar_Liar[n-1]) + Liar_Liar[n-1] + Liar_Liar [n-2]);
		}
		if(n < 10)//if n is less than 10 add a space in the ( )
		{
			printf("Liar-Liar( %d) =%13d\n", n, Liar_Liar[n]);
		}
		else	//if greater than 10
		{
			printf("Liar-Liar(%d) =%13d\n", n, Liar_Liar[n]);
		}
		Liar(n, Liar_Liar);//Allows this to loop without a for, while, or do-while
	}
}
