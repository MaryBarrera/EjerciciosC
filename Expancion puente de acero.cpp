#include <stdio.h>
#define a 11.7

main ()
{
	double L,To,Tf,i;
	double expancion,temp;
	
	printf("Ingrese la longitud del puente en metros: ");
	scanf("%f",&L);
	printf("Ingrese la temperatura inicial en grandos celcius: ");
	scanf("%f",&To);
	printf("Ingrese la temperatura final en grados celcius: ");
	scanf("%f",&Tf);
	printf("Ingrese el incremento de la temperatura: ");
	scanf("%f",&i);
	
	for (expancion=0; temp<=Tf; temp+=i)
	{
		printf("Longitud Pte:%f || Temperatura Actual:%f || Expancion Actual:%f \n", L,temp, expancion);
		expancion=a*L*(temp-To);
		L=L+expancion;
	}
}
