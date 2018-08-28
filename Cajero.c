#include <stdio.h>
void main(void)

/* Tienda  */

{
                int cant, b1000,b500,b200,b100,b50,b20, m10, rb1000,rb500,rb200,rb100,rb50,rb20, rm10;
                  printf("Dame la cantidad: ");
                  scanf("%i", &cant);
                  b1000=cant/1000;
                  rb1000=cant%1000;
                  
                  b500=rb1000/500;
                  rb500=rb1000%500;
                  
                  b200=rb500/200;
                  rb200=rb500%200;
                  
                  b100=rb200/100;
                  rb100=rb200%100;
                  
                  b50=rb100/50;
                  rb50=rb100%50;
                  
                  b20=rb50/20;
                  rb20=rb50%20;
                  
                  m10=rb20/10;
                  rm10=rb20%10;
                  
                              
                  printf("\nBilletes de 1000 Pesos: %i \n", b1000);                
                  printf("Billetes de 500 Pesos: %i \n", b500);                
                  printf("Billetes de 200 Pesos: %i \n", b200);                
                  printf("Billetes de 100 Pesos: %i \n", b100);                
                  printf("Billetes de 50 Pesos: %i \n", b50);                
                  printf("Billetes de 20 Pesos: %i \n", b20);
                  printf("Monedas de 10 Pesos: %i \n", m10);
                  system("pause");
}
