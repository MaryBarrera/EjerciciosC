#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char usuario [100];
char director [100];
char libro [100];
  
main()
{
      char pwscorrecto[9]="Taco";
      char pwsingresado[9];
      char nombre[10];
      char mensaje[50]="bienvenido: ";
      char volver[1];
      volver[0]='s';
      while ((volver[0]=='s')||(volver[0]=='S'))
      {
      printf("\n\n  Bienvenido a la Biblioteca Municipal\n");
      printf("\n  -------------Base de datos----------\n"); 
      printf("\n               Programa para \n     El administrador de la biblioteca\n\n");
      printf("Ingrese su nombre: ");
      scanf("%s",&nombre);
      printf("\ningrese password: ");
      scanf("%s",&pwsingresado);
      if (!strcmp(pwscorrecto, pwsingresado))
      {
      printf("password correcto \n\n\n");
      strcat(mensaje,nombre);
      puts(mensaje);
      printf("\n\n");
      system("pause");
      system("cls");
      }
      volver[0]='n';
      }
      /*  prueba*/
  
      struct  usuario{
              char inscripcion[10];
              char nombre[30];
              char apellido[50];
              char direccion[30];
              int edad;
              
              }
              usuario[100];
              
      struct  director{
              char inscripcion[10];
              char nombre[30];
              char apellido[50];
              char direccion[30];
              int edad;
              char plantel[100];
              
              }
              director[100];
              
      struct  libro{
              char inscripcion[10];
              char titulo[30];
              char autor[50];
              char editor[30];
              int  edicion;
              char categoria[30];
              
              
              }
              libro[100];
              struct usuario datospersona;
              struct director datosdirector;
              int c=0,op,clave;
              do
              {
              printf("\n-----------------------\n");
              printf("\nUsuario de biblioteca\n");
              printf("\n-----------------------\n");
              printf("1) Registrar un usuario(a)\n");
              printf("2) Buscar por numero de credencial\n");
              printf("3) Registrar un Director (a) de plantel\n");
              printf("4) Buscar por numero de credencial\n");
              printf("5) Registrar un libro a la Base de datos\n");
              printf("6) Buscar por numero de folio\n");
              printf("7) Regresar a pagina principal \n");
              printf("elige una opcion:");
              scanf("%d",&op);
              switch(op)
              {
              case 1: printf("Registrar un usuario");
                      printf("\n-----------------------------------\n");
                      printf("Ingrese numero de inscripcion:");
                      scanf( "%s", &datospersona.inscripcion);
                      printf("Ingrese nombre:");
                      scanf( "%s", &datospersona.nombre);
                      printf("Ingrese apellido:");
                      scanf( "%s", &datospersona.apellido);
                      printf("Ingrese dirección:");
                      scanf( "%s", &datospersona.direccion);
                      printf("Ingrese edad:");
                      scanf( "%s", &datospersona.edad);
                      printf("\n----------------------------------------------\t");
                      printf("\nDatos guardados correctamente\t");
                      printf("\n\n");
                      system("pause");
                      system("cls");
                      break;
               case 3:printf("Registrar un Director (a) de plantel\n");
                      printf("\n-----------------------------------\n");
                      printf("Ingrese numero de inscripcion:");
                      scanf( "%s", &datosdirector.inscripcion);
                      printf("Ingrese nombre:");
                      scanf( "%s", &datosdirector.nombre);
                      printf("Ingrese apellido:");
                      scanf( "%s", &datosdirector.apellido);
                      printf("Ingrese dirección:");
                      scanf( "%s", &datosdirector.direccion);
                      printf("Ingrese edad:");
                      scanf( "%s", &datosdirector.edad);
                      printf("Ingrese plantel al que pertenece:");
                      scanf( "%s", &datosdirector.plantel);
                      printf("\n----------------------------------------------\t");
                      printf("\nDatos guardados correctamente\t");
                      printf("\n\n");
                      system("pause");
                      system("cls");
                      break;
                case 7: system("pause");
                       break;
              default: printf("Opcion incorrecta");
                      break;
               }
        } while(c=1);    
}
                      
