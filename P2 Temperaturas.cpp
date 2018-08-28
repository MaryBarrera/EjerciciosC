#include <stdio.h>
#include <stdlib.h>
#define N 5

main(){
	
	FILE *archivo;
	archivo = fopen ( "temps.txt", "r" );        
	//fclose ( archivo);
	
	printf("\nEl dia más caluroso es: \nEl dia mas frio es: ", calor, frio);
	printf("\nLa temperatura promedio de cada mes es: ", temperatura);
	printf("\nLa diferencia entre l dia mas caluroso y frio es: ", calor-frio);
	printf("Ingrese el mes y dia del que quiere conocer su teperatura: ");
	
	int datos[archivo], datosNoR[archivo], frec[archivo], i, j, k, bandera=1, imayor, suma, temp;
	float media, mediana;
	
//Calculo para la moda	
	imayor=0;
	for (i=0; i<j; i++)
		if (frec[i] > frec[imayor])
			imayor=i;
	printf("\n La moda es %d con %d repeticiones", datosNoR[imayor], frec[imayor]);
	
//Calculo para la media	
	suma=0;
	for (i=0; i<N; i++)
		suma=datos[i];
	media=suma/N;
	printf("\n La media es: %f", media);
	
//Calculo para la mediana
	for (i=0; i<N-1; i++){
		imayor=0;
		for (j=imayor; j<N; j++)
			if (datos[j] > datos[imayor])
				imayor=j;
		temp=datos[imayor];
		datos[imayor]=datos[i];
		datos[i]=temp;
	}
	if(N%2==1)
		mediana=datos[N/2];
	else
		mediana=datos[N/2]=(datos[N/2-1] + datos[N/2])/2;
	//mediana = (N%2==1)? datos[N/2]=(datos[N/2-1] + datos[N/2])/2;
	printf("\n La mediana es : %f", mediana);
	
//Calculo para la desviacion estandar

	
}
