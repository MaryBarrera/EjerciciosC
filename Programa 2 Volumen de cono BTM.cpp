#include <stdio.h>
#include <conio.h>
#define pi 3.1415 //Se define la variable "pi" con el valor 3.1415

int main()
{
	//Programa que calcula el volumen de un cono
	float r,h,v; //Declaracion de variables tipo flotante
	char si; //Variable tipo caracter para almacenar la respuesta del usuario
	printf("\n\t\t Programa que calcula el volumen de un cono");
	printf("\n ------------------------------------------------------------------");
	
	do 
	{	
		printf("\n\n Ingrese el radio del cono: ");
		scanf("%f", &r);
		printf("\n Ingrese la altura del cono: ");
		scanf("%f", &h);
		
		v=(pi*r*r*h)/3; //Calculo para el volumen de un cono
		
		printf("\n El volumen del cono es: %f", v);
		
		printf("\n\n Desea calcular un nuevo volumen (s/n): ");
		scanf("%s", &si);
		
	} while (si=='s'); //Bucle while para calcular un nuevo volumen 
	
	getch();
}
