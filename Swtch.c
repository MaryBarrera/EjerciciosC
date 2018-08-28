#include <stdio.h>
#include <conio.h>

void main (void)
 {
    float R,D,T=2500,cant;
    int op;
    
	printf("\t\t Bienvenido al Sistema");
	printf("\n 1.Retiro");
	printf("\n 2.Deposito");
	printf("\n 3.Consultar Saldo");
	printf("\n 4.Salir");
	printf("\n\n Seleccione una opcion [1-4]:");
	scanf("%i", &op);
	
	switch (op)
	{ 
	  case 1: printf("\n Cantidad a Retirar:$");
		  scanf ("%f", &cant);
		  R=T-cant;
		  printf ("\n Su saldo actual es:%f", R);
		  break;

	  case 2: printf("\n Cantidad a Depositar:$");
		 scanf ("%f", &cant);
		  D=T+cant;
	      printf ("\n Su saldo actual es:%f", D);
		  break;

	  case 3: printf("\n Saldo Total:");
          printf("\n Retiros:%f",cant);
          printf("\n Depositos:%f", cant); 
		  T= 1000+(T+cant)+(T-cant);
		  printf("\n Usted cuenta con:%f",T);
		  break;

	  case 4: printf("\n Gracias por utilizar este programa. Adios");
		  break;

	  default: printf("\n Opcion NO valida");
		   break;
	} 

 getch ();
} 
