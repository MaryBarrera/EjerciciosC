/*Josephus.c, un programa que dados un numero de personas y una velocidad encuentra el orden en que mueren 
  las personas y al unico sobreviviente */ 

#include <stdio.h> 
#include <math.h> 
#include <string.h> 
//#include <iostream.h> 

int main() 
{ 
  int k;//variable para la velocidad a la que mueren las personas// 
  int n;//el numero de personas// 
  int gente[100];//arrreglo para la cantidad maxima de personas que tolera el programa// 
  int die=0, cont=0;//contadores// 
  int wisin;//el sobreviviente// 

       printf("Introduzca el numero de personas=>"); 
       scanf("%d",&n); 
       printf("\nIntroduce el intervalo en que mataras=> "); 
       scanf("%d",&k); 

          for(int c=0; c<n; c++){ 
      
            gente[c] = (c+1); 
                                } 

       printf("\n\n Los Romanos murieron en el orden siguiente=> :( \n"); 

       while(die != (n-1)) { 
        
                 for(int c1=0; c1<n; c1++) { 
        
                  if(gente[c1]!= 0)  { 
                     cont += 1; 
                      if(cont ==k ){ 
                              cont = 0; 
                              printf("%d\t",gente[c1]); 
                              gente[c1] = 0; 
                              die += 1;              
                                   } 
                                     }              
                                            } 
                            } 
        for(int c2=0; c2<n; c2++) { 
                if(gente[c2] != 0) { 
                wisin = gente[c2]; 
                                   } 
                                  } 

        printf("\n\n El sobreviviente es el numero=> :) %d\n\n", wisin); 

        //system("pause"); 
            return 0; 

} 

