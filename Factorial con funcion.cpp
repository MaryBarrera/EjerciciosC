#include <stdio.h>

int Factorial(int);

main(){
	int m,F;
	printf("\n Ingrese el numero: ");
	scanf("%d", &m);
	F=Factorial(m);
	printf("\n El resultado es: %d ", F);
}

int Factorial(int m){
	int x, res, factorial;
	
	while (x > 0){ 
		factorial= x * factorial;
		x--;
	}
    
	res=factorial; 
	return res; 
}

