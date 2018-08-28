#include <stdio.h>

main()
{
	long Dato=0;
	long *refDato;
	refDato=&Dato;
	
	printf("\t DIRECCION CON APUNTADOR DE UN DATO");
	printf("\n\n La direccion de una variable dato es: %p", &Dato);
	printf("\n El valor de la variable refDato es: %p", &refDato);
}
