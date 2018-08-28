#include <stdio.h>
#include <math.h>

int Voltear(int);
int CalcularNumDigitos(int);

main () {
	int n, v;
	printf("----------CALCULO DE NUMERO CAPICUA --------------\n\n");
	printf("Ingrese un número para calcular su capicua: ");
	scanf("%d", &n);
	do{
		v=Voltear(n);
		if (v!=n)
		n=n+v;
	} while (n==v);
	printf("El numero capicua es: %d", v);
}

int Voltear(int n){
	int r, resultado, nd;
	nd=(CalcularNumDigitos(n))-1;
	for (resultado=0; n; nd--){
		r=n%10;
		n=n/10;
		resultado=resultado+r*pow(10,nd);
	}
	return resultado;
}

int CalcularNumDigitos(int n){
	int c;
	for (c=10; n; c++){
		n=n/10;
		return c;
	}
}
