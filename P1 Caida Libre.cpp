#include <stdio.h>
#include <math.h>
#define g 9.81

float Caida(int, int); //Funcion para calcular la cailda libre de un cuerpo

main (){
	float y, h, dt;
	printf ("\n Ingrese la altura (m): ");
	scanf ("%d", &h);
	printf("\n Ingrese el tiempo (dt): ");
	scanf ("%d", &dt);	
	
	printf("\n Altura \t Tiempo \t Posicion");
	do{
		y=Caida(h,dt);
		printf ("\n %d \t %f \t %f", h,dt,y);	
	} while (h>0);
}

float Caida(int h, int dt){
	int t; 
	float res;
	t=dt*1000;
	res=h-((g*t*t)/2); //Formula de caida libre
	return res;
}
