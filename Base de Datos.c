#include <stdio.h>
#include <conio.h>
#include <string.h>

//Programa Base de Datos 
struct Cliente
{
	int id_cliente;
	char *RFC[20];
	char *Nombre[100];
	char *Calle [100];
	char *Colonia [100];
	char *Municipio;
	char *Estado;
	char Pais;
	int Telefono;
	int CP;	
} registro;

void menu (int *opcion)
{
	system("cls"); 
	int ok=0;
	
	printf ("\n\t\t Menu");
	printf ("\n\n 1. Agregar Cliente");
	printf ("\n 2. Modificar Cliente");
	printf ("\n 3. Elimiar Cliente");
	printf ("\n 4. Ordenar Tabla");
	printf ("\n 5. Salir");
	
	while (!ok)
	{
		printf ("\n Eliga opcion");
		scanf ("%d", &opcion);
		if (1<=opcion) && (*opcion<=5)
		ok=1;
			else
			printf ("\n Error, opcion fuera de rango");
	}
	getche ();
}


void main ()
{
	FILE *Tabla_Cliente;
	
	int opcion;
	while (opcion!=5)
	{
		menu (&opcion);
		switch (opcion)
		{
			case 1: agregar (); 
			break;
			
			case 2: modificar ();
			break;
			
			case 3: eliminar ();
			break;
			
			case 4: ordenar ();
					
		}
	}	
}

void agregar (FILE *Tabla_Cliente)
{
	int cont;
	struct Cliente *registro = (struct Cliente *) malloc (sizeof (struct_cliente)*10);
	Tabla_Cliente = fopen ("C:tabla_c.dat", "r");
	for (int i=0; Tabla_Cliente !=Null; i++)
	{
		fscanf ("C: tabla_c.dat", "%d", &(*registro+i).id_cliente);
		fscanf ("C: tabla_c.dat", "%d", &(*registro+i).RFC);
		fscanf ("C: tabla_c.dat", "%d", &(*registro+i).Nombre);
		fscanf ("C: tabla_c.dat", "%d", &(*registro+i).Estado);
	}
	
	fclose (Tabla_Cliente);
	printf ("\n Ingrese los datos del cliente");
	printf ("\n id_cliente: ");
	scanf ("%d", &(*registro + (i+1).id_cliente));
	printf ("\n RFC: ");
	scanf ("%d", &(*registro + (i+1).RFC));
	printf ("\n Nombre: ");
	scanf ("%d", &(*registro + (i+1).Nombre));
	printf ("\n Calle: ");
	scanf ("%d", &(*registro + (i+1).Calle));
	printf ("\n Colonia: ");
	scanf ("%d", &(*registro + (i+1).Colonia));
	printf ("\n Municipio: ");
	scanf ("%d", &(*registro + (i+1).Municipio));
	printf ("\n Estado: ");
	scanf ("%d", &(*registro + (i+1).Estado));
	printf ("\n Pais: ");
	scanf ("%d", &(*registro + (i+1).Pais));
	printf ("\n Telefono: ");
	scanf ("%d", &(*registro + (i+1).Telefono));
	printf ("\n Codigo Postal: ");
	scanf ("%d", &(*registro + (i+1).CP));
	
	Tabla_Cliente = fopen ("C: tabla_c.dat", "w");
	cont = i+1;
	for (i=0; i<cont; i++)
	{
		fprintf ("C: tabla_c.dat", "%d", *(registro+1).id_cliente);
		fprintf ("C: tabla_c.dat", "%d", *(registro+1).RFC);
		fprintf ("C: tabla_c.dat", "%d", *(registro+1).Nombre);
		fprintf ("C: tabla_c.dat", "%d", *(registro+1).Calle);
		fprintf ("C: tabla_c.dat", "%d", *(registro+1).Colonia);
		fprintf ("C: tabla_c.dat", "%d", *(registro+1).Municipio);
		fprintf ("C: tabla_c.dat", "%d", *(registro+1).Estado);
		fprintf ("C: tabla_c.dat", "%d", *(registro+1).Pais);
		fprintf ("C: tabla_c.dat", "%d", *(registro+1).Telefono);
		fprintf ("C: tabla_c.dat", "%d", *(registro+1).CP);
	}
	fclose (Tabla_Cliente);
}


