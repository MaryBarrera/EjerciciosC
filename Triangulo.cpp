#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//Programa que uestra en pantalla un triangulo dado un numero entero n

int main (void)
{
	int x,i,j;
	printf("Ingrese un numero entero: ");
	scanf("%d",&x);
	printf("\n");
	
	if (x%2==0)
	{
		for (i=0; i<x; i++)
		{
			for (j=1; j<x-1; j++)
			{
				printf("%d", j);
				printf("\n\n");	
			}
		}
	}
	else 
	{
		for (i=1; i<=x; i++)
		{
			for (j=1; j<=i; j++)
			{
				printf("%d",j);
				printf("\n\n");
			} 
		}
	}
	system("pause");
}
