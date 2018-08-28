#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>

float *crear_vector (int *cont)  //Funcion para crear un vector de 3 componentes
{
	float *temp=() malloc(sizeof(float)*3);
	printf("\n Define vector: %d", *cont);
	for (int i=0; i<3; i++)
	{
		printf("\n Componente %d", i+1);
		scanf("%f", &(*(temp+1)));
	}
	*cont+1;
	return(temp);
}

float leer_escalar() //Funcion para capturar un escalar
{
	float temp;
	printf("\n Ingrese numero:");
	scanf("%f", &temp);
	return(temp);
}

float *suma(float*v, float*w) //Funcion que suma dos vectores
{
	float *temp=(float*) malloc(sizeof(*float)*3);
	for (int i=0; i<3; i++)
	*(temp+i)=*(v+i)+*(w+i);
	return(temp);
}

float prod_punto (float*v, float*w) //Funcion que calcula el producto punto entre dos vectores
{
	float temp=0;
	for (int i=0; i<3; i++)
	temp=temp+(*(v+i))+(*(w+i));
	return(temp);
}

float prod_escalar (escalar, float *v) //Funcion que calcula el producto escalar entre dos vectores
{
	float temp;
	temp=escalar*(*v);
	return(temp);
	
	int i;
    double escalar=0;
    for (i=0; i<3; i++)
        escalar += a[i]*b[i];
    return(escalar);
}

float prod_cruz (float*v, float*w) //Funcion que calcula el producto cruz entre dos vectores
{
	float temp;
	temp=*v(*w);
	return(temp);
}

void ver(float *v) //Despliega el resultado al realizar una opereacion
{
	
	printf("\n Nuevo Vector \n");
	for (int i=0; i<3; i++)
	printf("%f", *(v+i));
}

void main ()
{
	float *v, *w, *c, escalar; //Vectores 
	int cont=1; //Se inicializa el contador para vectores
	v=crear_vector (&cont); //Se crea el primer vector y sus componentes
	w=crear_vector (&cont); //Se crea el segundo vector y sus componentes
	escalar=leer_escalar (); //Almacena un numero llamado escalar
	
	printf("\n La suma entre dos vectores es:");
	c=suma(v,w); //Realiza la suma de los dos vectores
	ver(c);
	
	printf("El producto punto entre v y w es:%f",prod_punto(v,w));
	
	printf("El producto escalar del numero y su vector es:");
	c=prod_escalar(escalar,v);
	ver(c);
	
	printf("\n La magnitud de v es:%f", sqrt(prod_punto(v,v)));
	printf("\n La magnitud de w es:%f", sqrt(prod_punto(ver,w)));
	
	printf("\n El producto cruz entre dos vectores es:");
	c=prod_cruz(v,w);
	ver(c);
	getch();
}
