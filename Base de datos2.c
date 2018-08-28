#include <stdio.h>
#include <conio.h>
#include <string.h>

//Programa Base de Datos 
struct Cliente
{
	int id_cliente;
	char RFC[20];
	char Nombre[100];
	char Calle [100];
	char Colonia [100];
	char Municipio;
	char Estado;
	char Pais;
	int Telefono;
	int CP;	
} registro;

int main ()
{
	int opcion;
	printf ("\n\t\t Menu");
	printf ("\n\n 1. Agregar Cliente");
	printf ("\n 2. Modificar Cliente");
	printf ("\n 3. Elimiar Cliente");
	printf ("\n 4. Ordenar Tabla");
	printf ("\n 5. Salir");
	printf ("\n Eliga opcion");
	scanf ("%d", &opcion);
	
	switch (opcion)
	{
		case 1: 
			printf ("\n id_registro: ");
			gest (registro.id_cliente);
			printf ("\n RFC: ");
			gets (registro.RFC);
			printf ("\n Nombre: ");
			gets (registro.Nombre);
			printf ("\n Calle: ");
			gets (registro.Calle);
			printf ("\n Colonia: ");
			gets (registro.Colonia);
			printf ("\n Municipio: ");
			gets (registro.Municipio);
			printf ("\n Estado: ");
			gets (registro.Estado);
			printf ("\n Pais: ");
			gets (registro.Pais);
			printf ("\n Telefono: ");
			scanf ("%d", &registro.Telefono);
			printf ("\n Codigo Postal: ");
			scanf ("%d", &registro.CP); 
		break;
		
		case 2: 
			modificar ();
		break;
			
		case 3: 
			eliminar ();
		break;
			
		case 4: 
			ordenar ();
		break;
		
		case 5: 
			salir();
		break;
		
		default : printf ("Error, opcion fuera de rango"); 
	} 
	
	getch ();
}
