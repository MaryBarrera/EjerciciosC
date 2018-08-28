/* Programa que calcula el sueldo de un empleado*/

#include <stdio.h>

int main ()
{
	char NombreEmp[31];
	int HorasTrab;
	float CuotaHora, Sueldo;
	
	printf ("CALCULA EL SUELDO DE UN EMPLEADO \n\n");
	printf (" -------------------------------------");
	
	printf ("\n TECLEE EL NOMBRE: ");
	gets (NombreEmp);
	
	printf("\n TECLEE HORAS DE TRABAJO: ");
	
	scanf ("%d", &HorasTrab);
	
	printf ("\n TECLEE CUOTA POR HORA: ");
	scanf ("%f", &CuotaHora);
	
	Sueldo = CuotaHora * HorasTrab;
	printf ("\n -----------------------------");
	
	printf ("\n EL EMPLEADO: %s \n", NombreEmp);
	printf ("GANO: $ %8.2f \n\n", Sueldo);
	printf ("\n ----------------------------------");
	
	return 0;
	
}
