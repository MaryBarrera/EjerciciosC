#include <stdio.h>

int factorial (int);

main (){
	
	int n;
	printf ("Numero: ");
	scanf ("%d", &n);
	printf ("%d!", factorial);
}

int factorial (int n){
	if (n<=1)
	return 1;
	return (n*factorial(n-1));
}
