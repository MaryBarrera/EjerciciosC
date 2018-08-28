#include <stdio.h>
#include <stdlib.h>

//Programa que abre un archivo de texto con la funcion fgetc (lee n caracter a la vez)

int main(){
	FILE *archivo;
	char caracter;
	
	archivo = fopen("libros.txt","r");
	
	if (archivo == NULL){
		printf("\nError de apertura del archivo. \n\n");
    }
        
	else{
		printf("\nEl contenido del archivo de prueba es \n\n");
	    while (feof(archivo) == 0){
			caracter = fgetc(archivo);
			printf("%c",caracter);
	    }
    }
    
	fclose(archivo);
	return 0;
}
