#include <stdio.h>
#include <math.h>

float CalcularCapital(float, float, float);

main(){
	int n;
	float CF, CI, r;
	printf ("\n Ingrese el capital inicial en su cuenta: ");
	scanf ("%f", &CI);
	printf("\n Ingrese el periodo de inversion (meses): ");
	scanf("%d", &n);
	printf ("\n Ingrese la tasa de interes: ");
	scanf ("%f",&r);
	CF=CalcularCapital(CI,n,r);
	printf("\n Capital Final: %f", CF);
}

float CalcularCapital(float CI, float n, float r){
	float res; 
	r=r/100;
	res=CI*pow((1+r),n);
	return res;
}
