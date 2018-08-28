#include <stdio.h>
#include <conio.h>

void main (void)
{
  char NIP[]="12011";
  char res[5];
  int b, cont=0;
  
  printf("\t\t BIENVENIDO AL SISTEMA");   
  printf("\n Por favor digite su NIP:");
  res[0]='0';
  for (b=1; res[b-2]!=13; b++)
  {
      res[b-1]=getch();
      printf("*");
  }
      for (b=0; b<5; b++)
      {
          if (res[b]==NIP[b])  
          
          cont++;
      }
    
  if (cont==5)
  {
     printf ("\n Bienvenido"); //aqui va el codigo swcht
  }
  
  else
   {
       printf ("\n NIP incorrecto. \n Por favor vuelva a intentar");
   }

 getch ();
} 
