/* Creamos MAX_THREAD threads que sacan por pantalla una cadena y su
identificador. Una vez que terminan su ejecución devuelven como resultado su
identificador */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_THREADS 10

pthread_t tabla_thr[MAX_THREADS]; //tabla con los identificadores de los threads

typedef struct{ // tipo de datos y tabla con los parámetros
	int id;
	char *cadena;
} thr_param_t;

thr_param_t param[MAX_THREADS];
//tenemos que crear una tabla para los parámetros porque los pasamos
//por referencia. Así, si solo tuviéramos una variable para
//los parámetros al modificar esta modificaríamos todas las que habíamos
//pasado anteriormente porque los threads no se quedan con el valor
//sino con la direccion

// Esta es la funcion que ejecutan los threads
void * funcion_thr(void *p){
	thr_param_t *datos;
	datos= (thr_param_t *)p;
	printf("%s %d\n", datos->cadena, datos->id);
	pthread_exit(&(datos->id)); //una vez terminamos, devolvemos el valor
}

int main(void){
	int i, *res;
	void * r;
	
	printf("Creando threads...\n");
	for (i=0; i<MAX_THREADS; i++){
		param[i].cadena="Hola, soy el thread";
		param[i].id= i;
		pthread_create(&tabla_thr[i],NULL,funcion_thr,(void*)&param[i]);
	}

	printf("Threads creados. Esperando que terminen...\n");
	for (i=0; i<MAX_THREADS; i++){
		pthread_join(tabla_thr[i],&r);
		res=(int *)r;
		printf("El thread %d devolvio el valor %d\n", i, *res);
	}
	
	printf("Todos los threads finalizados. Adios!\n");
	system("PAUSE");
	return 0;
}

