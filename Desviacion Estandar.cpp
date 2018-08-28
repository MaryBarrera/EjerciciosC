#include <stdio.h>
#include <math.h>
#define L 10

main()
{
	float p, x[L],z;
	int i;
	
	printf("\t Calcula de la Desviacion Estandar de una muestra de datos \n\n");
	printf("Ingrese 10 muestras \n");
	for (i=0, p=0; i<L; i++)
	{
		printf("Ingrese datos: ");
		scanf("%f", &x[i]);
		p=p+x[i];
	}
	
	p=p/L;
	for (i=0; i<L; i++)
	{
		z=pow((x[i]-p),2)+z;
		z=z/L;
	}
	printf("\n La desviacion estandar es: %f",z);	
}


