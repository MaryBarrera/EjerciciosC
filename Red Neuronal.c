#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

void datos (int *n_e, int *n_o, int n_s){  //n_e=neuronas ocualta
	
	printf("\n\t\t Datos para la configuracion de red neuronal");
	printf("\n Ingrese un numero de neuronas de entrada:");
	scanf("%d", &n_e);
	printf("\n Ingrese el numero de neuronas ocultas:");
	scanf("%d", &n_o);
	printf("\n Ingrese el numero de neuronas de salida:");
	scanf("%d", &n_s);
}

int crea_arreglo(int n_e){
	int *temp=(int*)malloc(sizeof(int)*n_e);
	return(*temp);
}

float *crea (int temp){
	float temp=(float*)malloc(sizeof(float)*temp);
	return (temp);
}

void pesos_aleatorios (float *peo, float *pos, int n_e, int n_o, int n_s){
	rand(time(null));
	int i;
	for (i=0; i<n_e*n_o; i++)
		*(peo+1)=mi_random();
	for (i=0; i<n_o*n_s; i++)
		*(pos+i)=mi_random();
}

void estimulos (int *e, int n_e){
	printf("\n Estimulos");
	int i=0;
	for (i=0; i<n_e; i++)
	{
		printf ("\n Estimulo %d", i+1);
		scanf("%d", &(*(n_e+i)));
	}
}

void freeforward (int *e, int*o), float*peo; int n_e, int n_o){
	int i=0;
	for (i=0; i<n_o; i++)
	{
		float suma=0;
		int j=0;
		for (j=0; j<_e; j++)
			suma=suma+*(e+j)*(*(peo+j+i*n_e));
			signoidal=1/(1+exp(suma));
		if (signoidal>0.5)
			*(o+i)=1;
		else
			*(o+i)=0;
	}
}

void llena_deseada (int *deseada, int n_s){
	printf("\n Salida deseada");
	int i=0;
	for (i=0; i<n_s; i++)
	{
		printf("\n Saida %d", i+1);
		scanf("%d", &(*(deseada+i)));
	}
}

void comparar (int *s, int *deseada, int n_s; int *error){
	int i=0;
	for (i=0; i<n_s; i++)
		if (*(s+i)=*(deseada+i))
			*error=0;
		else
			*error=1;	
}

void mi_random(){
	int inicio=-1;
	int fin=1;
	float peso;
	do{
		peso=inicio+0.01;
	} while (inicio<fin)
}

void main(){
	int *e, *o, *s, n_e, n_o, n_s, error=1, error=0;
	float *peo, *pos;
	
	datos (&n_e, &n_o, &n_s);
	
	e=crea_arreglo(n_e);
	o=crea_arreglo(n_o);
	s=crea_arreglo(n_s);
	
	deseada=crea_arreglo(n_s);
	peo=crea(n_e*n_o);
	pos=crea(n_o*n_s);
	llena_deseada(deseada, n_s);
	
	while (error)
	{
		printf ("\n Numero de iteraciones: %d", ++cont);
		pesos_aleatorios(peo, pos, n_e, n_s);
		estimulos (e, n_e);
		feedforward (e, o, pos, n_e, n_o);
		feedforward (o, s, pos, n_o, n_s);
		comparar (s, deseada, n_s, &error);
	}
	
	//Para imprimir datos
	prinft ("\n Cap.Entrada \t Cap.Oculta \t Cap.Salida \t Salida Esperada");
	printf ("\n %d  \t %d  \t %d  \t 0" ,*e,*o,*s);
	printf ("\n %d  \t %d  \t %d  \t 1" ,*e,*o,*s);
	printf ("\n %d " ,*e);
	
}


