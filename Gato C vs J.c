#include <stdio.h> //libreria estandar de entrda y salida de datos

struct grafo{
	struct nodo *liga; 
};


//variables globales 
int gato[9]={0,0,0,0,0,0,0,0,0}; //arreglo de nueve casillas del gato
int turno, jugador;

//Declaracion de Funciones 
void Jugador1();
void Turno_Computadora();
void Imprimir_Gato();
int Ganador();
char tirada();
int movDisponibles(int *gato);
int posVacias(int *g );

//Funcion principal ------------------------------------------------------------------
int main(){
	printf("\n ******************* Juego del Gato ***********************\n\n");
 	printf("\n Las casillas estan enumeradas asi: \n 1 |2 |3 \n --+--+-- \n 4 |5 |6 \n --+--+--\n 7 |8 |9 \n");
    printf("\n Debes elejir una casilla tecleando un numero.");
    printf("\n Una vez que tires tu, tirara la computadora.");
	
	jugador = 1; //Inicia partida el jugador
	turno = 0;
	do {
	    turno++;
	    if (jugador) Jugador1(); 
		else Turno_Computadora();
	    Imprimir_Gato();
	}
	while ( (!Ganador()) && (turno<=8) );
		
	switch (Ganador()) {
	    case 0:
		    printf("\n Empate");
	        break;
	                                     
	    case 1:
	        printf("\n Gana el Jugador! ");
	        break;
	                                
	    case -1:
	        printf("\n Gana Computadora");
	        break;
	} 
	getchar();   
}

//funcion jugador 1 -----------------------------------------------------------------
void Jugador1(){
	int Casilla_Jugador1;
    printf("\n\n Turno del jugador 1, en que casilla quieres tirar? [1-9]:  ");
    scanf("%d", &Casilla_Jugador1);
     
    if ((Casilla_Jugador1>9) || (Casilla_Jugador1<1) || (gato[Casilla_Jugador1-1]!=0)){
        do{
        	printf("\n Esa casilla esta ocupada, intenta en otra: [1-9] ");
            fflush(stdin);                  
            scanf("%d", &Casilla_Jugador1);
        }
        while ((Casilla_Jugador1>9) || (Casilla_Jugador1<1) || (gato[Casilla_Jugador1-1]!=0));
    }
     
    gato[Casilla_Jugador1-1]=1;
    jugador = 0;
	
} //fin funcion


//funcion computadora ---------------------------------------------------------------------
void Turno_Computadora(){ /* coloca el valor de la computadora a tirar, en una posicion aleatoria*/
    int Casilla_Comp;
    time_t t;
    printf("\n Turno de la compuatdora, tiro en la casilla: ");
    do {
        srand(time(&t));
        Casilla_Comp = rand()%9;
    } while (gato[Casilla_Comp]!=0);
    
	printf("%d", Casilla_Comp + 1); 
    gato[Casilla_Comp]=-1;
    jugador = 1;
}

//guarda la tirada de un jugador -------------------------------------------------------------------------------
char tirada(int i){
    switch (i){
        case (-1):
            return 'X';
            break;
                 
        case (1):
            return 'O';
            break;
                 
        default:
            return ' ';
    }
}


//muestra el tablero del gato ----------------------------------------------------------------------------------
void Imprimir_Gato(){ /*esta funcion acomoda los valores en el dibujo del tablero*/
    printf("\n %c |%c |%c \n --+--+-- ", tirada(gato[0]), tirada(gato[1]), tirada(gato[2]));
    printf("\n %c |%c |%c \n --+--+-- ", tirada(gato[3]), tirada(gato[4]), tirada(gato[5])); 
    printf("\n %c |%c |%c \n --+--+-- ", tirada(gato[6]), tirada(gato[7]), tirada(gato[8]));
}

//heuristica para saber quien gana -----------------------------------------------------------------------------
int Ganador(){
	//compara las posibles forma de ganar
	if ((gato[0] + gato[1] + gato[2] == 3) || (gato[3] + gato[4] + gato[5] == 3) ||
		(gato[6] + gato[7] + gato[8] == 3) || (gato[6] + gato[3] + gato[0] == 3) || 
		(gato[7] + gato[4] + gato[1] == 3) || (gato[8] + gato[5] + gato[2] == 3) || 
		(gato[6] + gato[4] + gato[2] == 3) || (gato[8] + gato[4] + gato[0] == 3)) 
		return 1;
    else if ((gato[0] + gato[1] + gato[2] == -3) || (gato[3] + gato[4] + gato[5] == -3) || 
		(gato[6] + gato[7] + gato[8] == -3) || (gato[6] + gato[3] + gato[0] == -3)||
		(gato[7] + gato[4] + gato[1] == -3) || (gato[8] + gato[5] + gato[2] == -3)|| 
		(gato[6] + gato[4] + gato[2] == -3) || (gato[8] + gato[4] + gato[0] == -3))
		return -1;
    else 
		return 0;
}

//devuelve los movimientos disponibles para tirar la computadora
int movDisponibles(int *g){
    int i, mov = 0;       
    for (i = 0; i < 9; i ++)
    	if ( g[i] == 0 )
            mov++;     
    return mov;
}

//Devuelve los indices del tablero de las pocisiones vacías.
//int posVacias( int *g ){
    /* //Creamos el vector con los índices.
   	int indices[] = movDisponibles(g);
    int i, indice = 0;        
    //Recorremos y guardamos los indices
    for (i = 0; i < 9; i ++ ){
        if ( g[i] == 0 ){
            indices[indice] = i;
            indice++;
        }
    }
    return indices;
} 


//Método que calcula el MÁXIMO de los nodos hijos de MIN
int Max( NodoG raiz ){
    int Max = -111;
    //Máximo para la computadora, buscamos el valor donde gane
    for (int i = 0; i < raiz.nodos.length; i++){
    	//Preguntamos por un nodo con un valor alto MAX
        if (raiz.nodos[i].ganador > Max){
            //Lo asignamos y pasamos el mejor movimiento a la raíz.
            Max = raiz.nodos[i].ganador;
            raiz.mejorMovimiento = raiz.nodos[i].indice;
            //Terminamos de buscar.
            if (Max == 1)
				break;
        }
    }
        
    //Borramos los nodos
	raiz.nodos = null;       
    return Max;
}
    
//Método que calcula el MÍNIMO de los nodos hijos de MAX.
int Min( NodoG raiz ){
    int Min = 111;
    //Mínimo para el jugador
    for (int i = 0; i < raiz.nodos.length; i++)
        if (raiz.nodos[i].ganador < Min ){
        	Min = raiz.nodos[i].ganador;
            raiz.mejorMovimiento = raiz.nodos[i].indice;
            if (Min == -1) break;
        }
        
    //Borramos los nodos.
    raiz.nodos = null;    
    return Min;
}  
*/

