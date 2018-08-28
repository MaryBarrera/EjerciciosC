#include <stdio.h>

main()
{
	long Dato=0;
	long *refDato;
	refDato=&Dato;
	
	printf("\n La direccion de la varible dato es: %p", Dato);
	printf("\n La direccion de refDato es: %p", refDato);
	
	Dato=10;
	printf("\n El contenido de Dato es: %d", Dato);
	printf("\n El contenido aputado por refDato: %d", *refDato);
	
	*refDato=5;
	prinft("\n El contenido de Dato es: %d", Dato);
	printf("\n El contenido de refDato es: %d", refDato);
}
