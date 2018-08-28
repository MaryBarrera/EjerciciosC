#include <stdio.h>

main(){ //Programa que calcula el menor, mayor y su promedio de una lista de numeros
	
	int arreglo[20], menor, mayor, i, suma;
	float promedio;
	
	printf("Digite los numeros:\n ");
	for (i=0; i<20; i++)
	scanf ("%d", &arreglo[i]); 
	mayor=arreglo[0];
	menor=arreglo[0];
	suma=0;
	
	for (i=0; i<20; i++){
		if(mayor<arreglo[i])
			mayor =arreglo[i];
		if (menor> arreglo[i]) 
			menor=arreglo[i];
		suma=suma + arreglo[i];
	}
	
	promedio=suma/20;
	printf("\n RESULTADOS");
	printf("\n %d es el numero mayor", mayor);
	printf("\n %d es el numero menorr", menor);
	printf("\n %f es el promedio", promedio);	
	
}
