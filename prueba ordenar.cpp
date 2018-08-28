#include<stdio.h>
#include<conio.h>

main(){
   int arreglo[10],ciclo1,pasadas,i,almacena;
   for(ciclo1=0;ciclo1<10;ciclo1++){
      printf("\n\tintroduzca el elemento %d para el arreglo:",ciclo1);
      scanf("%d",&arreglo[ciclo1]);
   }
 
   printf("\n\n\t\tel arreglo introducido es el siguiente:\n\n\t\t");
   for(i=0;i<10;i++){
      printf("[%d]",arreglo[i]);
   }
   for(pasadas=1;pasadas<10;pasadas++){
      for(i=0;i<9;i++){
         if(arreglo[i]>arreglo[i+1]){
            almacena=arreglo[i];
            arreglo[i]=arreglo[i+1];
            arreglo[i+1]=almacena;
         }
      }
   }
   printf("\n\n\n\n\t\tel arreglo ordenado es el siguiente:\n\n\t\t");
   for(i=0;i<10;i++){
      printf("[%d]",arreglo[i]);
   }
   getch();
  printf("********************* GRACIAS POR UTILIZAR ESTE PROGRAMA ***********************");
   printf("********************************************************************************");
   getch();
}
