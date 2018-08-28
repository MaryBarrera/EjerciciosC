#include <stdio.h>
//#include <iostream.h>

int main (void)
{
	int m1[4][4];
	int m2[4][4];
	int fil1, cd1;
	int fil2, cd2;
	int sum;
	
	/*Llenar tabla*/
	for (fil1=0; fil1<4; fil1++)
	{
		for(cd1=0; cd1<4; cd1++)
		{
			printf("\n De un numero entero: ");
			scanf("%d",&m1[fil1][cd1]);
			printf("/n");
		}
	}
	
	/*Des´legar tabla*/
	for (fil1=0; fil1<4; fil1++)
	{
		for (cd1=0; cd1<4; cd1++)
		{
			printf("%d", m1[fil1][cd1]);
			printf("/n");
		}
	}
	
	/*LLenar tabla 2*/
	for (fil2=0; fil2<4; fil2++)
	{
		for (cd2=0; cd2<4; cd2++)
		{
			printf("/n De un numero entero: ");
			scanf("%d", &m2[fil2][cd2]);
			printf("/n");
		}
	}
	
	/*Desplegar tabla 2*/
	for (fil2=0; fil2<4; fil2++)
	{
		for (cd2=0; cd2<4; cd2++)
		{
			printf("%d", m2[fil2][cd2]);
			printf("/n");
		}
	}
	
	sum=m1[fil1][cd1]+m2[fil2][cd2];
	printf("/n La suma es: %d", &sum);
	printf("/n");
	
	system("pause");
	return 0;
}
