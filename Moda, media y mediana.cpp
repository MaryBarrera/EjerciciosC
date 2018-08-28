#include <stdio.h>
#define N 5

main(){
	
	int datos[N], datosNoR[N], frec[N], i, j, k, bandera=1, imayor, suma, temp;
	float media, mediana;
	
	printf("Ingrese los datos: \n");
	for (i=0; i<N; i++)
		scanf("%d", &datos[i]);
	for(i=0; i<N; i++)
		frec[i]=1;
		
	for(i=0, j=0; i<N; i++){
		for (k=0; k<j; k++)
		if (datosNoR[k] == datos[i])
			bandera=0;
		if (bandera!=0){
			datosNoR[j] = datos[i];
			for (k=i+1; k<N; k++)
				if (datos[k] == datosNoR[j])
					frec[j]++;
			j++;		
		}
		bandera=1;
	}
	
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
