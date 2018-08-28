#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void * imprimir_mensaje( void *puntero );
int main(){
	pthread_t hilo1, hilo2; char *mensaje1 = "Hola"; char *mensaje2 = "Mundo";
	pthread_create(&hilo1,NULL,imprimir_mensaje,(void*)
	mensaje1);
	pthread_create(&hilo2,NULL,imprimir_mensaje,(void*)
	mensaje2); printf("\n\n"); system("PAUSE"); exit(0);
	return 1;
}

void * imprimir_mensaje( void *puntero ){
	char *mensaje;
	mensaje = (char *) puntero; printf("%s ", mensaje);
	return puntero;
}
