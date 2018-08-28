#include <stdio.h>
#define n 5

main(){ //programa que ordena de forma ascendente un arreglo de numeros
	int datos[n], i, vueltas, imenor, temp;
	
	printf("Introduzca los numeros a ordenar: \n");
	for (i=0; i<n; i++)
		scanf ("%d", &datos[0]);
		
	for (vueltas=0; vueltas<n-1; vueltas++){
		imenor=vueltas;
		for (i=imenor+1; i<n; i++)
			if (datos[imenor] > datos[i])
				imenor=i;
		temp=datos[imenor];
		datos[imenor] = datos[vueltas];
		datos[vueltas] = temp;		
	}
	
	printf("\n Arreglo ordenado:");
	for (i=0; i<n; i++)
		printf("\n %d", datos[i]);
}
