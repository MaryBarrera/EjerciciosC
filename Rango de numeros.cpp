#include <stdio.h>

int rango (int x, int y){
	int i;
	
	if (x%2==0){
		printf ("\nNumeros pares");
		do{
			i=x;
			printf ("\n%d", x);
			x=x+2;
		}while (i<y);
	}
	else{
		printf ("\nNumeros impares");
		do{
			i=x;
			printf ("\n%d", x);
			x=x+2;	
		}while(i<y);
	} 
	return 0;
}

main(){
	int x, y;
	printf("x= ");
	scanf ("%d", &x);
	printf("y= ");
	scanf ("%d", &y);
	rango (x,y);
}
