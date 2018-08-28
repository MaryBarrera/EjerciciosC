#include <stdio.h>

main (){
	int L1,L2,L3, a1, a2, a3, B, H; //variables globales
	printf ("\n\t\t TRIANGULOS");
	printf ("\n ------------------------------------");

	//valor de los lados de un triangulo
	printf ("\n Ingrese los valores de los lados");
    printf ("\n L1: ");
	scanf ("%d", &L1);
	printf (" L2: ");
	scanf ("%d", &L2);
	printf (" L3: ");
	scanf ("%d", &L3);

	//valor de los angulos del triangulo
    printf ("\n Ingrese los valores de los angulos");
	printf ("\n a1: ");
	scanf ("%d", &a1);
	printf (" a2: ");
	scanf ("%d", &a2);
	printf (" a3: ");
	scanf ("%d", &a3);

	//datos del triangulo
	printf ("\n Ingrese las dimensiones del triangulo ");
	printf ("\n base: ");
	scanf("%d", &B);
	printf (" altura: ");
	scanf("%d", &H);

	printf ("\n ----------------------------------------\n");
	printf ("\n Perimetro: %d", Perimetro(L1,L2,L3));
	printf ("\n Area: %d", Area(B,H));
	printf ("\n Suma de angulos: %d ", Angulos(a1, a2, a3));
    printf ("\n Tipo de triangulo: ", Tipo(L1, L2, L3));
}

int Perimetro(int L1, int L2, int L3){
    int perimetro;
    perimetro=L1+L2+L3;
    return perimetro;
}

int Area(int B, int H){
    int area;
    area=(B*H)/2;
    return area;
}

int Angulos(int a1, int a2, int a3){
    int suma;
    suma=a1+a2+a3;
    if (suma<180 || suma>180)
        	printf("Valores invalidos!");
    else
    	return suma;
}

int Tipo(int L1, int L2, int L3){
    if (L1==L2 && L2==L3 && L1==L3 ){ //Comparacion cuando los tres lados del trinagulo son iguales
		printf("\nEquilatero");
	}else
		if (L1!=L2 && L2!=L3 && L1!=L3){ //Comparacion cuando los tres lados del triangulo son desiguales
			printf("\nEscaleno");
		}else
			printf("\nIsoceles"); //Opcion cuando dos lados son iguales y uno desigual
}
