#include <stdio.h>

int main () {
	int n,i,j,k,x,y;
	printf("\t\t Ordenamiento por Monticulo");
	printf("\n HeapSort");
	
	printf("\n Ingrese el numero de elementos que tiene su vector:");
	scanf ("%d", &n);

	for (k=n; k>=2; k--)
	{
		y=x[k];
		x[k]=x[1];
		i=1;
		j=2;
		if ((x[i]>x[2])&&(k-1>=3))
		{
			j=3;
			while (j<=k-1)
			{
				if (x[j]<=y)
				{
					x[i]=y;
					x[i]=x[j];
					i=j;
					j=2*i;
						if (x[j-1]>x[j])
						j++;
				}
			}
		}	
	}

}


