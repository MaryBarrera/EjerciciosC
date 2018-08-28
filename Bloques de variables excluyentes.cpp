#include<stdio.h>

int x=3, y=2;
int f(int, int);
 
main(){  //Progrma que combina funciones con variebles en bloques excluyentes
	int x=1;
	printf("Ingrese un valor para Y:");
	scanf ("%d", &y);
	if (y+x<10){
		int x, y=3;
		printf("Ingrese un valor para X:");
		scanf("%d", &x);
		if (x<30){
			int z;
			z=f(x++, ++y);
			printf("\n Valor de Z: %d", z);
		}
		x=f(--y, ++x);
		printf("\n Imprime Y: %d", y);	
	}
	y=f(++y, x--);
	printf("\n Valor de X: %d", x);
}

int f(int y, int x){
	printf("\n Par: %d , %d", ++x,y--);
	return x++ + y++;
}
