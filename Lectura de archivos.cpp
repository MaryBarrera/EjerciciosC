#include <stdio.h>
#include <stdlib.h>

//Programa que lee archivo de texto (.txt)

int main(){
	FILE *archivo;
	char caracter;
	
	if (archivo == NULL) //Se compueba que el archivo no este vacio
		printf("\nArchivo vacio");
	
	else{
		archivo = fopen("prueba.txt","r"); //Abre el archivo en modo de lectura (reader)
		printf("\nContenido del archivo: \n\n");
	    while (feof(archivo) == 0){ //Comprueba el fin del archivo
			caracter = fgetc(archivo); //Se lee caractera por caracter del archivo
			printf("%c",caracter); //Muestra en pantalla cada uno de los caracteres
	    }
	}
		    
	fclose(archivo); //Cerrar el archivo
	return 0;
}
