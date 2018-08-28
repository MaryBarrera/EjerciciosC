#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char usuario [100];
char director [100];
char libro [100];
  
main()
{
	char pwscorrecto[9]="12345";
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
	    printf("Ingrese nombre: ");
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
      
	      	/*  prueba*/
	      	{
	      		
		      	struct  usuario
				{
			    	char inscripcion[10];
			        char nombre[30];
			        char apellido[50];
			        char direccion[30];
			        int edad;     
		        } usuario[100];
              
        		{
			      	struct  director
					{
			        	char inscripcion[10];
				        char nombre[30];
				        char apellido[50];
				        char direccion[30];
				        int edad;
				        char plantel[100];
	              	} director[100];
              
    			{
				    struct  libro
					{
				        char inscripcion[10];
				        char titulo[30];
				        char autor[50];
				        char editor[30];
				        int  edicion;
				        char categoria[30];    
				    } libro[100];
              
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
			            printf("8) Cagar una base de datos existente \n");
			            printf("\nElige una opcion: ");
			            scanf("%d",&op);
		            
			            switch (op)
			            {
			              case 1:
				              printf("\n--------------------------\n");
				              if(c>=100)
				              	printf("La base de datos esta completa\n");
				              else
					              printf("Ingresa los datos del Usuario:");
					              printf("clave: %.3d\n",c);
					              printf("fecha de inscripcion[dd/mm/aa]::");
					              scanf("%s",usuario[c].inscripcion);
					              printf("Ingresa el nombre(s):");
					              fflush(stdin);
					              gets (usuario[c].nombre);
					              printf("ingresa apellido(os):");
					              gets (usuario[c].apellido);
					              printf("Direccion:");
					              gets(usuario[c].direccion);
					              printf("edad:");
					              scanf("%d",&usuario[c].edad);
					              c++;
					              system("cls");
			              break;
		              
			              case 2:
			                   printf("\n-------------------------\n");
			                   printf("clave:");
			                   scanf("%d",&clave);
		
			                   while(clave>=100 || clave<0)
				                   printf("-------\n");
				                   printf( "fecha de inscripcion: %s\n", usuario[clave].inscripcion);                   
				                   printf("nombre:%s\n",usuario[clave].nombre);
				                   printf( "Apellido: %s\n", usuario[clave].apellido);
				                   printf( "Direccion: %s\n", usuario[clave].direccion);
				                   printf( "edad: %d a%cos\n", usuario[clave].edad,164);
				                   system("pause");
				                   system("cls");
			                   break;
			              
			              case 3:
				            	printf("\n--------------------------\n");
				              	if(c>=100)
					            	printf("La base de datos esta completa\n");
					            else
					              
					            printf("\nIngresa los datos del Director (a) de plantel:");
					            printf("clave: %.3d\n",c);
					            printf("fecha de inscripcion[dd/mm/aa]:");
					            scanf("%s",director[c].inscripcion);
					            printf("Ingresa el nombre(s):");
					            fflush(stdin);
					            gets (director[c].nombre);
					            printf("ingresa apellido(os):");
					            gets (director[c].apellido);
					            printf("Direccion:");
					            gets(director[c].direccion);
					            printf("edad:");
					            scanf("%d",&director[c].edad);
					            printf("Plantel educativo:");
					            scanf("%s",&director[c].plantel);
					            c++;
					            system("cls");
					            break;
				              
			              case 4:
			                   	printf("\n-------------------------\n");
			                    printf("clave:");
			                    scanf("%d",&clave);
			                   
			                    while(clave>=100 || clave<0) 
				                    printf("-------\n");
				                    printf( "fecha de inscripcion: %s\n", usuario[clave].inscripcion);                   
				                    printf("nombre:%s\n",director[clave].nombre);
				                    printf( "Apellido: %s\n", director[clave].apellido);
				                    printf( "Direccion: %s\n", director[clave].direccion);
				                    printf( "edad: %d a%cos\n", director[clave].edad,164);
				                    printf( "Plantel Educativo: %s\n", director[clave].plantel);
				                    system("pause");
				                    system("cls");
			                    break;
		                   
			               case 5:    
			                    printf("\n--------------------------\n");
				                if(c>=100)
				                	printf("La base de datos esta completa\n");
				              	else
				              
				                printf("\nIngresa los datos del libro:");
				                printf("clave: %.3d\n",c);
				                printf("fecha de inscripcion[dd/mm/aa]:");
				                scanf("%s",libro[c].inscripcion);
				                printf("Ingresa el titulo del libro:");
				                fflush(stdin);
				                gets (libro[c].titulo);
				                printf("ingresa el nombre del autor:");
				                gets (libro[c].autor);
				                printf("nombre de la editorial:");
				                gets(libro[c].editor);
				                printf("año de edicion:");
				                scanf("%d",&libro[c].edicion);
				                printf("categoria:");
				                scanf("%s",&libro[c].categoria);
				                c++;
				                system("cls");
				                break;
			              
			              case 6:
			                    printf("\n-------------------------\n");
			                    printf("clave:");
			                    scanf("%d",&clave);
			                   
			                    while(clave>=100 || clave<0)
				                    printf("-------\n");
				                    printf( "fecha de inscripcion: %s\n", libro[clave].inscripcion);                   
				                    printf("Titulo del libro:%s\n",libro[clave].titulo);
				                    printf( "Nombre del autor: %s\n", libro[clave].autor);
				                    printf( "editorial: %s\n", libro[clave].editor);
				                    printf( "numero de edicion: %d a%cos\n", libro[clave].edicion,164);
				                    printf( "Categoria: %s\n", libro[clave].categoria);
				                    system("pause");
				                    system("cls");
			                    break;
			                   
			            	case 7:
			                    printf("\n\nGracias por su visita\n\n");
			                    printf("\n  Presione para regresar a pagina de inicio \n O Cierre el programa manualmente\n\n");
			                    system("pause");
			                    system("cls");
			                    break;
			                
			                case 8:
			                	printf ("\nLibros existentes ...\n");
			                	FILE *archivo;
								char caracter;
								archivo = fopen("libros.txt","r");
								if (archivo == NULL){
									printf("\nError de apertura del archivo. \n\n");
								}
								else{
									printf("");
									while (feof(archivo) == 0){
										caracter = fgetc(archivo);
										printf("%c",caracter);
									}
								} 
								fclose(archivo);
								system("pause");
			                    system("cls");
			                    break;
			                        
			                default:
			                    printf("\n\nopcion no valida\n");
			                    printf("Intenta de nuevo\n\n");
			                    system("pause");
	                                
	            		}
	            	} while (op!=7);
           		}
          	  }
          	}
    	}
		                                                                                                                                                                  
     /*prueba*/  
	    else 
		{	
		    strcpy(mensaje, "Acceso denegado");
		    puts(mensaje);
		    printf("\n\n¿Quieres volver a comenzar (S/N)?");
		    scanf("%s",volver);
		    while ((volver[0]=='n')||(volver[0]=='N'))
		    {
		    	printf("\n         Por favor\n    Cierre el programa\n    e intente de nuevo\n\n");
		      	system("pause");
		      	break;
		    }
		}
	}
}
