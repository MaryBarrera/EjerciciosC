#include <stdio.h>

//variables globales 
int gato[9]={0,0,0,0,0,0,0,0,0};
int turno, jugador;

//Declaracion de Funciones 
void Jugador1();
void Jugador2();
void Imprimir_Gato();
int Ganador();
char tirada();

//Funcion principal ------------------------------------------------------------------
int main(){
	printf("\n ******************* Juego del Gato ***********************\n\n");
 	printf("\n Las casillas estan enumeradas asi: \n 1 |2 |3 \n --+--+-- \n 4 |5 |6 \n --+--+--\n 7 |8 |9 \n");
    printf("\n Debes elejir una casilla tecleando un numero.");
	
	jugador = 1; //Inicia partida el jugador
	turno = 0;
	do {
	    turno++;
	    if (jugador) Jugador1(); 
		else Jugador2();
	    Imprimir_Gato();
	}
	while ( (!Ganador()) && (turno<=8) );
		
	switch (Ganador()) {
	    case 0:
		    printf("\n EMPATE!");
	        break;
	                                     
	    case 1:
	        printf("\n GANA JUGADOR 1!");
	        break;
	                                
	    case -1:
	        printf("\n GANA JUGADOR 2! ");
	        break;
	} 
	getchar();   
}

//funcion jugador 1 -----------------------------------------------------------------
void Jugador1(){
	int Casilla_Jugador1;
    printf("\n\n Es turno del jugador 1, en que casilla quieres tirar? [1-9]:  ");
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


//funcion jugador 2 ---------------------------------------------------------------------
void Jugador2(){
	int Casilla_Jugador2;
    printf("\n\n Es turno del jugador 2, en que casilla quieres tirar? [1-9]:  ");
    scanf("%d", &Casilla_Jugador2);
     
    if ((Casilla_Jugador2>9) || (Casilla_Jugador2<1) || (gato[Casilla_Jugador2-1]!=0)){
        do{
        	printf("\n Esa casilla esta ocupada, intenta en otra: [1-9] ");
            fflush(stdin);                  
            scanf("%d", &Casilla_Jugador2);
        }
        while ((Casilla_Jugador2>9) || (Casilla_Jugador2<1) || (gato[Casilla_Jugador2-1]!=0));
    }
     
    gato[Casilla_Jugador2-1]=-1;
    jugador = 1;
	
} //fin funcion

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
	
	/* if (gato[0]==gato[1] && gato[1]==gato[2]) //compara valores primer fila
		printf("Ganaste!");
	else if (gato[3]==gato[4] && gato[4] ==gato[5]) //Compara valores segunda fila
		printf("Ganaste!");		
	else if (gato[6]==gato[7] && gato[7]==gato[8]) //compara valores tercer fila
		printf("Ganaste!");
	else if (gato[0]==gato[3] && gato[3]==gato[6]) //compara valores primer columna
		printf("Ganaste!");
	else if (gato[1]==gato[4] && gato[4]==gato[7]) //compara valores segunda columna
		printf("Ganaste!");
	else if (gato[2]==gato[5] && gato[5]==gato[8]) //compara valores tercer columna
		printf("Ganaste!");	
	else if (gato[0]==gato[4] && gato[4]==gato[7]) //compara valores en diagonal descendiente
		printf("Ganaste!");
	else if (gato[2]==gato[4] && gato[4]==gato[6]) //compara valores e diagonal ascendente 
		printf("Ganaste!");
	*/
	
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


