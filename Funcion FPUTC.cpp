#include <stdio.h>

//Programa que escribe un caracteer en el archivo especificado
 
int main ( int argc, char **argv )
{
 	FILE *fp;
 	char caracter;
 		
 	fp = fopen ( "fichero.txt", "a+t" ); //parametro para escritura al final y para file tipo texto
 	
 	printf("\nIntroduce un texto al fichero: ");
 	
 	while((caracter = getchar()) != '\n'){
 		printf("%c", fputc(caracter, fp));
 	}
 	
 	fclose ( fp );
 	return 0;
}
