#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

FILE *fp;
struct nodo{
	float dato;
	struct nodo *liga;
};

//leer datos
int lee(){
   int t;       
   printf("Ingrese tiempo:");
   scanf("%d", &t);
   return(t);
}

//crear un nodo
struct nodo *crea_nodo(){
	return ((struct nodo *)malloc(sizeof(struct nodo)));
}

//crea una lista ligada
struct nodo *crea_lista (int t, int i){
	if (i<=t){ //caso recursive
		struct nodo *temp = crea_nodo();
		temp-> dato = 20.0*exp((1.0/10.0)*log(7.0/4.0)*i);
		temp-> liga = crea_lista (t, i+1);
		return(temp);
	}
	else
		return (NULL); //caso base
}

//imprime cabecera
void muestra_cabecera(){
	printf ("\n tiempo(t)  \tpoblacion p(t)\n");
	printf ("\n--------------------------------\n");
	fp = fopen ( "fichero.txt", "w+" );
	fprintf(fp, "\n tiempo(t)  \tpoblacion p(t)\n");
}

// imprimir datos, t y p(t)
void muestra_datos (struct nodo *head, int t, int i){
	if(i<=t){
		printf("    %d             %.2f   \n",i, head -> dato);
		fprintf(fp, "    %d             %.2f   \n",i, head -> dato);
		muestra_datos(head->liga,t,i+1);
	}
}

//función principal
int main(){
	int t;	
	t = lee();
	struct nodo *head = crea_lista(t,0);
	muestra_cabecera();
	muestra_datos(head,t,0);
	return(1);
}
fclose (fp);


