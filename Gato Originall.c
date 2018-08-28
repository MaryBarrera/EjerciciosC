#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int GATO[9]={0,0,0,0,0,0,0,0,0}, turno, jugador;
char VolverMenu=' ';

char tirada(int i); /*Necesaria en print_gato, retorna 'X', 'O' o ' '*/
int Ganador(); /*Deduce si hay un ganador, regresa -1, 0 o 1*/
void Imprimir_Gato(); /*Imprime el tablero de Gato*/
void turno_jugador();
void turno_computadora();


int main(){
	do{
	    int h, menu;
	    printf("\n Menu Juego GATO");
	    printf("\n 1) Jugar");
	    printf("\n 2) Leer instrucciones");
	    printf("\n 3) Salir");
	    printf("\n Seleccione una opcion [1-3]: ");
	    scanf("%d", &menu);
    
	    switch(menu){
	        case 1:              
	            jugador = 1; //Inicia partida el jugador
	            turno = 0;
	            do {
	                turno++;
	                if (jugador) turno_jugador(); 
					else turno_computadora();
	            	Imprimir_Gato();
	            }
	            while ( (!Ganador()) && (turno<=8) );
	                         
				switch (Ganador()) {
	                case 0:
	                    printf("\n Empatamos");
	                    break;
	                                     
	                case 1:
	                    printf("\n Tu ganas");
	                    break;
	                                
	                case -1:
	                    printf("\n Yo te gano");
	                    break;
	            }                                                                 
	        	break;
         
        case 2:
            printf("\n Juego del GATO! ");
            printf("\n Las casillas estan enumeradas asi: \n 1 |2 |3 \n --+--+-- \n 4 |5 |6 \n --+--+--\n 7 |8 |9 \n");
            printf("\n Debes elejir una casilla tecleando un numero.");
            printf("\n Una vez que tires tu, tirará la maquina.");
			printf("\n Gana quien haga una linea de tres caracteres iguales \n ya sean horizontales, verticales o diagonales"); 
            getchar();
            break;
         
           
        case 3:
        	printf("\n\t Fue divertido jugar contigo. Adios!");
            getchar();
            exit(1);
            break;    
        } 
        
        printf("\n ¿Desea volver al menu? (s/n):  ");
        scanf("%s", &VolverMenu);
        if (VolverMenu >= 97) VolverMenu-=32;
        if ((VolverMenu!='s') && (VolverMenu!='n'))
        for (h=0; h<=8; h++) 
			GATO[h]=0;         
	} while (VolverMenu=='S');             
	getchar();
}

void Imprimir_Gato(){ /*esta funcion acomoda los valores en el dibujo del tablero*/
    printf("\n %c |%c |%c \n --+--+-- ", tirada(GATO[0]), tirada(GATO[1]), tirada(GATO[2]));
    printf("\n %c |%c |%c \n --+--+-- ", tirada(GATO[3]), tirada(GATO[4]), tirada(GATO[5])); 
    printf("\n %c |%c |%c \n --+--+-- ", tirada(GATO[6]), tirada(GATO[7]), tirada(GATO[8]));
}

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

int Ganador(){ /*esta funcion compara el arreglo con los patrones de posible Ganador*/

    if ((GATO[0] + GATO[1] + GATO[2] == 3) || (GATO[3] + GATO[4] + GATO[5] == 3) ||
		(GATO[6] + GATO[7] + GATO[8] == 3) || (GATO[6] + GATO[3] + GATO[0] == 3) || 
		(GATO[7] + GATO[4] + GATO[1] == 3) || (GATO[8] + GATO[5] + GATO[2] == 3) || 
		(GATO[6] + GATO[4] + GATO[2] == 3) || (GATO[8] + GATO[4] + GATO[0] == 3)) 
		return 1;
    else if ((GATO[0] + GATO[1] + GATO[2] == -3) || (GATO[3] + GATO[4] + GATO[5] == -3) || 
		(GATO[6] + GATO[7] + GATO[8] == -3) || (GATO[6] + GATO[3] + GATO[0] == -3)||
		(GATO[7] + GATO[4] + GATO[1] == -3) || (GATO[8] + GATO[5] + GATO[2] == -3)|| 
		(GATO[6] + GATO[4] + GATO[2] == -3) || (GATO[8] + GATO[4] + GATO[0] == -3))
		return -1;
    else 
		return 0;
}

void turno_jugador(){ /*coloca el caracter en la casilla seleccionada y verifica que no este ocupada*/
    int Casilla_Jugador;
    printf("\n Es tu turno, en que casilla quieres tirar? [1-9]:  ");
    scanf("%d", &Casilla_Jugador);
     
    if ((Casilla_Jugador>9) || (Casilla_Jugador<1) || (GATO[Casilla_Jugador-1]!=0)){
        do{
        	printf("\n Esa casilla esta ocupada, intenta en otra: [1-9] ");
            fflush(stdin);                  
            scanf("%d", &Casilla_Jugador);
        }
        while ((Casilla_Jugador>9) || (Casilla_Jugador<1) || (GATO[Casilla_Jugador-1]!=0));
    }
     
    GATO[Casilla_Jugador-1]=1;
    jugador = 0;
}

void turno_computadora(){ /* coloca el valor de la computadora a tirar, en una posicion aleatoria*/
    int Casilla_Comp;
    time_t t;
    printf("\n Me toca, tiro en la casilla: ");
    do {
        srand(time(&t));
        Casilla_Comp = rand()%9;
    } while (GATO[Casilla_Comp]!=0);
    
	printf("%d", Casilla_Comp + 1); 
    GATO[Casilla_Comp]=-1;
    jugador = 1;
}
