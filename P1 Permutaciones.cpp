#include <stdio.h>

int Permutacion(int, int);
int Factorial(int);

main(){
	int m,n,V;
	printf("\n Ingrese el numero de corredores: "); //Numero de elementos a permutar
	scanf("%d", &m);
	printf("\n Ingrese el numero a permutar: "); //elementos tomados de 'm'
	scanf("%d", &n);
	V=Permutacion(m,n);
	printf("\n El resultado es: %d ", V);
}

int Permutacion(int m, int n){
	int res;
	m=Factorial(m);
	n=Factorial(n);
	res=m/(m-n);
	return res; 
}

int Factorial(int n){
	
}
