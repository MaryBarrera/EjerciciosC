#include <stdio.h>
#include <math.h>
#include <conio.h>
#define epsilon 0.001

main ()
{
	double n,x;
	double aprox, r;
	
	//Pedir datos
	printf("\t\t\t Calculo de raiz \n");
	printf("\n\t Ingrese un numero a calcular su raiz: ");
	scanf("%f", &n);
	printf("\n\n");
	printf("\t Ingrese un valor que supone se aproxima a la solucion: ");
	scanf("%f", &x);
	
	//Revizar condicion
	do
	{
		r=((n/x)+x/2);
		aprox=r-x;
	} while (aprox <=epsilon);
	printf("\n\t La raiz es: %f \n", x);
}
