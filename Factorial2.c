#include <stdio.h> 
#include <stdlib.h> 

//factorial recursivo 

int Factorial(int n) 
{ 
     return n <= 1 ? n : n * Factorial(n - 1); 
} 

int main() 
{ 
     int n, i; 
     printf("n: "); 
     scanf("%d", &n); 
     if (n==0)
     printf("1\n");
     else
     for(i = 0; i < n; i++) 
          printf("%d! = %d\n", i, Factorial(i)); 
     system("pause"); 
     return 0; 
}
