#include <stdio.h>
#include <conio.h>

 main ()
{
	int Q; //Almacena el numero de estados
	int numF; //Almacena el numero de estados finales
	int nSimbolos; //Almacena el numero de simbolos que tiene el automata
	char cadena[100]; //Alamacena una cadena de caracteres
	int edoActual; // Es el estado en que ternima la cadena
	char ntr,si; //ntr almacena un "enter" que ingrese el usuario 
	int i,j,c; //contadores

	printf("\n\n Maribel Barrera Tabares \n 12-011-1344");
	printf("\n\n\t\t AUTOMATA FINITO DETERMINISTICO \n\n");

	printf(" --> Ingrese el numero de estados que tiene su automata: ");
	scanf("%d",&Q);

	printf("\n --> Ingrese el numero de simbolos que tiene su alfabeto: ");
	scanf("%d",&nSimbolos);

    int sigma[nSimbolos]; //Se crea el arreglo de tamaño nSimbolos con el numero de elementos que tiene el alfabeto
    int delta[Q][nSimbolos]; //Se crea el arreglo de tamaño Q por nSimbolos que representa a la función delta
   
    for (i=0;i<=nSimbolos-1;i++) //Ciclo para captura los distintos  simbolos que pueda tener el alfabeto
    {
        printf("\n --> Ingrese el %d simbolo: ",i+1);
        scanf("%c%c",&ntr,&sigma[i]);  //Almacena un caracter del alfabeto 
    }

	printf("\n\n\t Asumimos que el estado inicial es \"q0\"");
	printf("\n\n --> Ingrese el numero de estados finales: ");
	scanf("%d", &numF);
	int eF[numF];
	for (i=0;i<numF;i++) //Cilco que captura  cada uno de los estados finales
    {
        printf("\n\t -> Estado Final %d: q",i+1);
	    scanf("%d",&eF[i]);
    }
    
	printf("\n\n---------------Captura de la funcion \"delta\"-----------------");
	for (i=0;i<=Q-1;i++) //Ciclo que captura las transciones de estado a estado
     {
         for (j=0;j<=nSimbolos-1;j++) 
    	{
        	printf("\n\n--> El estado q%d con \"%c\" va a el estado q", i,sigma[j]);
			scanf("%d",&delta[i][j]);
     	}	
     }
     
	printf("\n\n--------------Automata Cargado Correctamente---------------- \n");
	
	do // Pedir una cadena mientras el usuario no indique otra cosa
	{   
	    edoActual=0;
		printf("\n --> Inserte una cadena: ");
		scanf("%c",&ntr);
		gets(cadena);
		
		for (i=0; cadena [i]!=0; i++) //Ciclo que analiza la posicion de cada uno de los caracteres del alfabeto 
			{
				for (j=0;j<nSimbolos;j++)
		     	{
			         if (cadena[i]==sigma[j] ) //Condición para comparar que cada subcadena en el alfabeto
			         {
			            
			            edoActual=delta[edoActual][j];  //Asignamos a edoActual la posicion del ultimo simbolo 
			            printf("%d",edoActual);
			            break;
			         }
				}
			}	
				
		for (i=0; i<numF; i++){ 
			if(edoActual==eF[i]) //Condición que compara el último estado con la última posicion del último simbolo
			{
		        printf("\n La cadena es ACEPATADA, el analisis termino en un estado final");
		    }
		       
		    if(edoActual!=eF[i]) //Si la posición del último simbolo o es igual a la de un estado final, imprimir rechazado
			{
		    	printf("\n La cadena es RECHAZADA, el analisis termino en un estado no final");	
		    }
		        
			printf("\n\n Desea insertar otra cadena (Si) Presione \"s\": ");
			canf("%c",&si);
        }
	} while (si=='s'); //Mientras el usuario teclee "s" el programa calcula cadenas
	
	getch();
}
