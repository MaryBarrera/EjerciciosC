#include <stdio.h>
//Programa de figuras geometricas

int main ()
{
	int num, L1, L2,L3, B,H;
	printf ("\n\t\t PROGRAMA DE FIGURAS GEOMETRICAS");
	printf ("\n --------------------------------------------------------");
	printf("\n Ingrese el numero de lados que tiene su figura [3-10]: ");
	scanf("%d", &num); 
	
	switch (num) //Casos segun el ingreso del numero de lados 
	{
		case 3: 
			printf ("\n Su figura es un TRIANGULO");
			printf ("\n Ingrese el valor del lado 1: ");
			scanf ("%d", &L1);
			printf ("\n Ingrese el valor del lado 2: ");
			scanf ("%d", &L2);
			printf ("\n Ingrese el valor del lado 3: ");
			scanf ("%d", &L3);
			
			if (L1==L2 && L2==L3 && L1==L3 ) //Comparacion cuando los tres lados del trinagulo son iguales
			printf("\n Triangulo EQUILATERO");
			else 
				if (L1!=L2 && L2!=L3 && L1!=L3) //Comparacion cuando los tres lados del triangulo son desiguales
				printf("\n Triangulo ESCALENO");
				else
					printf("\n Tringulo ISOSCELES"); //Opcion cuando dos lados son iguales y uno desigual
		break;
		
		case 4:
			printf("\n Cuadrado o Rectangulo?");
			printf ("\n Ingrese el valor de la base: ");
			scanf("%d", &B);
			printf ("\n Ingrese el valor de la altura: ");
			scanf("%d", &H);
			if (B==H)     	//Comparacion cuando ambos lados son iguales 
				printf ("\n Su figura es un CUADRADO");
			else 
				printf ("\n Su figura es un RECTANGULO");
		break;
		
		case 5:
			printf ("\n Su figura es un PENTAGONO");
		break;
	
		case 6:
			printf ("\n Su figura es un HEXAGONO");
		break;
	
		case 7:
			printf ("\n Su figura es un HEPTAGONO");
		break;
	
		case 8:
			printf ("\n Su figura es un OCTAGONO");
		break;
	
		case 9:
			printf ("\n Su figura es un NONAGONO");
		break;
	
		case 10:
			printf ("\n Su figura es un DECAGONO");
		break;
		
		default:
			printf ("Opcion no valida");
		break;
	}
}
