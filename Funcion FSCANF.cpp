#include <stdio.h>

//Programa que funciona como un scanf en cuatro parametros
 
int main ( int argc, char **argv )
{
 	FILE *fp;
 	char buffer[100];
 	
 	fp = fopen ( "fichero.txt", "r" );
 	
 	fscanf(fp, "%s" ,buffer);
 	printf("%s",buffer);
 	
 	fclose ( fp );
 	return 0;
}
