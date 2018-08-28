//programa que calcula el factorial de un numero 

#include <stdio.h> 
#include <conio.h>

int main()
{ 
	int n,f=1,i; 
	printf("Numero: "); 
	scanf("%d",&n); 
	i=n; 
         while(i>1) 
         f*=i--; 
	printf("%d!: %d",n,f); 
    getch(); 
  return 0; 
}

