#include <stdio.h>

double dFlex(char T, double L);
main ()
{
	{
		char T;
		double L, Dmax;
		
		/*Perdir Datos*/
		printf("Ingrese la longitud de la viga:");
		scanf("%d", &L);
		printf("Ingrese el tipo de viga: ");
		scanf("%c", &T);
		Dmax=dFlex(T,L);
		printf("El resultado es: ");
	}
	
	double dFlex(char T, double L);
	{
		if (T=='t')
		{
			return (L/180);
		} 
		else if (T=='p')
		{
			return (L/240);
		} 
		else 
		{
			printf("Error tipo incorrecto \n ");
			return (-1);
		}
	}
	return (exp);
}
