#include <stdio.h>
#include <conio.h>
#include <string.h>

struct Persona
{
	char nombre [100];
	char apellidos [50];
	int edad;
	float salario;
} P;

int main ()
{
	printf ("Nombre(s): ");
	gets (P.nombre);
	printf ("Apellidos: ");
	gets (P.apellidos);
	printf ("Edad: ");
	scanf ("%d", &P.edad);
	printf ("Salario: ");
	scanf ("%f", &P.salario);
	
	printf ("\n\n Registro Completo \n");
	printf ("\n %s %s", P.nombre, P.apellidos);
	printf ("\n %i anios", P.edad);
	printf ("\n $ %f", P.salario);
	
	getch ();
}
