#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define continuar
#define k 0.4158
		
void tiempo (int *t)
	{
		clrscr();
		printf("Tiempo de Simulacion");
		scanf("%d", t);
	}
		
void registro (float **datos, int t)
	{
		*datos=(float*)malloc(sizeof (float)*t);
		for (int i=0; i<t; i++)
		*(*datos+i)=15.0*exp((1/5)*ln(8)*t);
	}
		
void mostrar (float *datos, int t)
	{
		clrscr();
		printf("\t Tiempo \t\t Poblacion");
		printf("------------------------------------");
		for (int i=0; i<t; i++)
			printf("%d \t\t %f"), i,*(datos+i));
			continuar;
	}
	
	if (P<1500) {
		printf("%d \t %d", i,50+Ce^(k*t));
	}
	else {
		printf(".");
	}
	
void main ()
	{
		int t;
		float *datos;
		tiempo (&t);
		registro (&datos,t);
	}
	
printf("Teclee <enter> para continuar \n");
getch();
		
