#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct usuario
{
	char inscripcion[10];
    char nombre[30];
    char apellido[50];
    char direccion[30];
    int edad;        
} usuario;
              
struct director
{
	char inscripcion[10];
    char nombre[30];
    char apellido[50];
    char direccion[30];
    int edad;
    char plantel[100];  
} director;
              
struct libro
{
	char inscripcion[10];
    char titulo[30];
    char autor[50];
    char editor[30];
    int  edicion;
    char categoria[30];
} libro;

  
int main()
{
    char pwscorrecto[9]="12";
    char pwsingresado[9];
    char nombre[10];
    char mensaje[50]="Bienvenido: ";
    char volver[1];
    volver[0]='s';
    int c=0,op,clave;
      
    printf("\n\n  Bienvenido a la Biblioteca Municipal\n");
    printf("\n  -------------Base de datos----------\n"); 
    printf("\n               Programa para \n     El administrador de la biblioteca\n\n");
    printf("Ingrese su nombre: ");
    scanf("%s",&nombre);
    printf("\nIngrese password: ");
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
	else {
		getchar();
		return 0;
	}
	  
	do
	{        
        printf("\n-----------------------------\n");
        printf("\nUsuario de biblioteca\n");
        printf("\n-----------------------------\n");
        printf("1) Registrar un usuario(a)\n");
        printf("2) Buscar por numero de credencial\n");
        printf("3) Registrar un Director(a) de plantel\n");
        printf("4) Buscar por numero de credencial\n");
        printf("5) Registrar un libro a la Base de datos\n");
        printf("6) Buscar por numero de folio\n");
        printf("7) Regresar a pagina principal \n");
        printf("\nElige una opcion:");
        scanf("%d",&op);
         
        switch (op)
        {
           case 1: 
           		printf ("\nRegistrar usuario");
		 		printf ("\nInscripcion: ");
               	scanf ("%s", &usuario.inscripcion);
               	printf ("\nNombre: ");
               	gets (usuario.nombre);
               	printf ("\nApellido: ");
               	gets (usuario.apellido);
               	printf ("\nDireccion: ");
               	gets (usuario.direccion);
               	printf ("\nEdad: ");
               	scanf ("%d", &usuario.edad);  
	 			system("pause");
				system("cls");             
           	  break;
             
             case 2: 
		 		printf ("\nBuscar numero: ");
              break;
                  
             case 3:
		 		printf ("\nInscripcion: ");
               	gets (libro.inscripcion);
               	printf ("\nNombre: ");
               	gets (director.nombre);
               	printf ("\nApellido: ");
               	gets (director.apellido);
               	printf ("\nDireccion: ");
               	gets (director.direccion);
               	printf ("\nEdad: ");
               	scanf ("%d", &director.edad);  
               	printf ("\nPlantel: ");
               	gets (director.plantel);
				system("pause");
				system("cls");
               break;
                  
             case 4: 
			 	printf ("\nBuscar numero de credencial: ");
            	break;
                  
             case 5:
			 	printf ("\nInscripcion: ");
                gets (libro.inscripcion);
                printf ("\nTitulo: ");
                gets (libro.titulo);
                printf ("\nAutor: ");
                gets (libro.autor);
                printf ("\nEditor: ");
                gets (libro.editor);
                printf ("\nEdicion: ");
                scanf ("%d", &libro.edicion);  
                printf ("\nCategoria: ");
                gets (libro.categoria);
				system("pause");
				system("cls");
                break;
                  
             case 6:
			 	printf ("\nBuscar numero de folio: ");
                break;
                  
             case 7:
			 	printf ("Presiones 's' para continuar ..."); 
			 	if (volver[0]=='s')
			 		printf ("\nAdios");
                break;
                  
             default: 
			 	printf ("\nOpcion invalida");                
          } 
          system("pause");   
		   
      } while ((volver[0]=='s')||(volver[0]=='S'));
	           
}
