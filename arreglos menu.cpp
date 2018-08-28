#include <stdio.h>
#include <conio.h>
#include <string.h>

int menu (int x){
	printf("\n\n-----------------------------------------------------------");
	printf("\n\t Arreglos \n");
	printf("\n 1. Inicializar con cero o null");
	printf("\n 2. Ingresar un caracter ");
	printf("\n 3. Ingresar una cadena ");
	printf("\n 4. Consultar la cantidad de elementos almacenados");
	printf("\n 5. Verificar Lleno ");
	printf("\n 6. Verificar Vacio ");
	printf("\n 7. Consultar su contenido ");
	printf("\n 8. Consultar el elemento i-esimo ");
	printf("\n 9. Cambiar el elemento i-esimo ");
	printf("\n 10. Extraer el elemento i-esimo ");
	printf("\n 11. Ordenarlo");
	printf("\n 12. Buscar un elemento ");
	printf("\n 13. Ubicar y contar coincidencias ");
	printf("\n 14. Extraer un elemento y sus repeticiones ");
	printf("\n 15. Salir");
	printf("\n\n Seleccione opcion [1-15]: ");
	scanf("%d", &x);
	return x;
}


//opcion 1
void inicializa(char *a, int n){
	int i;
	for (i=0; i<n; i++)
		a[i]=' ';
	printf("\n Arreglo Inicializado");
}

//opcion 2
void agregar (char *a, int n, char x){	
	a[0] = x;
	printf("\n Caracter %c agregado. ", x); //printf("%c", nom[0]);
}

//opcion 3
void IngresarCadena (char *a, int n){
	int i;
    char ntr, dato;
    printf(" Ingrese cadena: \n");
    for(i=0; i<n; i++){  //ingresa dato por dato
        printf(" %i:",i);
        scanf("%c%c", &ntr, &dato);
        a[i] = dato;
    }
  
}

//opcion 4
void cantElementos(char *a, int n){
	int str;
	str = strlen(a);
	printf(" Longitud del arreglo: %i",strlen(a));
}

//opcion 5
void VerificarLleno(char *a, int n){
	if (strlen(a) == n)
		printf(" Arreglo Lleno");
	else
		printf(" Aun no esta lleno");
}

//opcion 6
void VerificarVacio(char *a, int n){
	if (strlen(a) == 0)
		printf(" Arreglo Vacio");
	else 
		printf(" Arreglo no vacio");
}


//opcion 7
void Contenido(char *a, int n){
	int i;
	//IngresarCadena(nom, 10);
	printf (" Cadena Ingresada: ");
    for(i=0; i<n; i++){  //imprime datos del arreglo
        printf("%c",a[i]);
	}
	
}

//opcion 8
void consultarElement(char *a, int n, int x){
	printf(" Elemento %d = %c", x, a[x] );
}

//opcion 9
void CambiarElement(char *a, int n, int x){
	
}

//opcion 10
void ExtraerElement(char *a, int n, int x){
	
}

//opcion 11
void ordenar (){
	printf("Opcion no disponible");
}

//opcion 12
void buscar (){
	printf("Opcion no disponible");
}

//opcion 13
char UbicarContar(char *a, int n){
    //a[10];
    //puts("Ingrese el arreglo \n");
    //fflush(stdin);
    //gets (a);
    //printf("\n %s \n ",a);
}

//opcion 14
void extraerRepeticiones(){
	
}

//opcion 15
void salir(){
	char res;
	int op;
	do{
		printf("\n Desea salir [s/n]: ");
		scanf("%s", &res);
		if (res == 'n')
			menu(op);
	} while (res != 's');
}


int main (){
	int op; 
	int n=10;
	char nom[n];
	
	switch (menu(op)){
		case 1:
			inicializa(nom, n);
			salir();
		break;
		
		case 2:
			agregar(nom, 10, 'h');
			salir();
		break;
		
		case 3:
			IngresarCadena(nom, 10);
			salir();
		break;
		
		case 4:
			cantElementos(nom, 10);
			salir();
		break;
		
		case 5:
			VerificarLleno(nom, 10);
			salir();
		break;
		
		case 6:
			VerificarVacio(nom, 10);
			salir();
		break;
		
		case 7:
			Contenido(nom, 10);
			salir();
		break;
		
		case 8:
			consultarElement(nom, 10, 5);
			salir();
		break;
		
		case 9:
			CambiarElement(nom, 10, 3);
			salir(); 
		break;
		
		case 10:
			ExtraerElement(nom, 10, 2);
			salir(); 
		break;
		
		case 11:
			ordenar();
		break;
		
		case 12:
			buscar();
			salir();
		break;
		
		case 13:
			UbicarContar(nom, 10);
			salir();
		break;
		
		case 14:
			extraerRepeticiones();
			salir();
		break;
		
		case 15:
			salir();
		break;
		
		default:
			printf("\nOpcion invalida");
		break;
	}	
}



