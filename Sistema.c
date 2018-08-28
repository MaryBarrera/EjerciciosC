#include <stdio.h>
#include <conio.h>

void main (void)

{  
  char NIP[]="12011";
  char res[5];
  int b, cont=0;
  
  printf("\t---------------CAJERO-----------------");  
  printf("\n\n Digite su NIP:");
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
    float R,D,T=2500,cant;
    int op;
    
	printf("\n\n ---------------MENU DEL CAJERO---------------");
	printf("\n\n\t Retiro.............................(1)");
	printf("\n\t Deposito...........................(2)");
	printf("\n\t Consultar Saldo....................(3)");
	printf("\n\t Salir..............................(4)");
	printf("\n\n Elija la transaccion que desea realizar [1-4]:");
	scanf("%i", &op);
	
	switch (op)
	{ 
	  case 1: printf("\n\n -----------OPCION RETIRO--------------");
          printf("\n\n Ingrese Cantidad a Retirar: $");
          int r,b1000,b500,b200,b100,b50,rb1000,rb500,rb200,rb100,rb50;
          scanf ("%i", &r);
		  b1000=r/1000;
		  rb1000=r%1000;
		  
          b500=rb1000/500;
          rb500=rb1000%500;
                  
          b200=rb500/200;
          rb200=rb500%200;
                  
          b100=rb200/100;
          rb100=rb200%100;
                
          b50=rb100/50;
          rb50=rb100%50;
                               
          // Este cajero cuenta con billetes de $1000, $500, $200, $100, $50                
          printf("\n Billetes de $1000: %i \n", b1000); 
          printf(" Billetes de $500: %i \n", b500);                
          printf(" Billetes de $200: %i \n", b200);                
          printf(" Billetes de $100: %i \n", b100);                
          printf(" Billetes de $50: %i \n", b50);                 
		  break;

	  case 2: printf("\n\n -----------OPCION DEPOSITO--------------");
          printf("\n\n Ingrese Cantidad a Depositar: $");
		  scanf ("%f", &cant);
		  D=T+cant;
	      printf ("\n Su nuevo saldo es: $%f", D);
		  break;

	  case 3: printf("\n\n -------OPCION CONSULTA DE SALDO---------");
          
          if (cant==0)
            {
              printf("\n\n Usted no tiene saldo en su cuenta");
            }
          else
            {
              printf("\n\n Usted cuenta con:%f",T); 
            }  
		  break; 

	  case 4: printf("\n\n ---------------OPCION SALIR---------------");
          printf("\n\n Gracias por usar este cajero. Vuelva pronto");
		  break;

	  default: printf("\n Opcion NO valida");
		   break;
	} //cierra switch
  }  //cierra if
  
 else
   {
       printf ("\n NIP incorrecto. \n Por favor vuelva a intentar \n");
   }        
 getch ();
} 
