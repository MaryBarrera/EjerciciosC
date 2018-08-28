/* ------------------------------------- */
/* CREADORES: DORIAN BUTRON Y GUSTAVO C */
/* Programa Video Juego Pacman */

#include <stdio.h>
#include <conio.h>
#include <dos.h> 
#include <stdlib.h>
#include <time.h>
#define Tfil 20
#define Tcol 20

void generar_m (char m, int F, int C){
    int i,j;
    for (i=0; j<F; i++)
        for (j=0; j<C; j++)
            m[i][j]='.';
}

int bichos (char m, int F, int C){
    int i=0, j=0, x1=C-1, x2=C-1, y1=0, y2=F-1, k=0;
    char c;
    int r;

    m[i][j]='@';
    m[y1][x1]=2; //monster 1
    m[y2][x2]=1; //monster 2

    while (1){
        imprimir_m (m, F, C, k);
        m[y1][x1]=' '; //monster 1
        m[y2][x2]=' '; //monster 2

        if (Vacio(m, F, C)){
            printf("*** Ganaste!! ***");
            getch();
            exit(0);
        }

        if (kbhit()){ //revisa si una tecla pulsada esta disponible
            m[i][j]='.';
            c=getch();

            if (c==0)
                c=getch();

            switch (c){
                case 75:
                    if (j)
                        j--;
                    break;

                case 77:
                    if (j<C-1)
                        j++;
                    break;

                case 72:
                    if (i)
                        i--;
                    break;

                case 80:
                    if (j<F-1)
                        i++;
                    break;

                case 27:
                    exit(0);
            }

            if (m[i][j]=='.')
                k++;
            m[i][j]='@';
        }

        if ((x1==j && y1==i)||(x2==j && y2==i)){
            m[i][j]='X';
            imprimir_m(m,F,C,k);
            printf("*** Perdiste!! ***");
            getch();
            exit(0);
        }

        if ( rand() ){
            if (x1 < C-1){
                x1++;
            }

            else{
                if (x1)
                    x1--;
            }

            if (rand()){
                if (y1<F-1)
                    y1++;
            }

            else{
                if (y1)
                    y1--;
            }
            m[y1][x1]=2;

            if(rand()){
                if (x2<C-1)
                    x2++;
            }

            else{
                if (x2)
                    x2--;
            }

            if (rand()){
                if (y2<F-1)
                    y2--;
            }

            else{
                if(y2)
                    y2--;
            }
            m[i][j]=1;
        }
    }
}

void imprimir_m(char m, int F, int C, int puntos){ 
    int i,j;
    system ("pause");
    system ("cls");
    system ("6"); //textcolor( YELLOW ); 
	printf ("Preciona <ESC> para salir");
    printf("n");

    for (i=0; j<F; i++){
        system ("7"); //textcolor(WHITE);
        for (j=0; j<C; j++)
            printf("%c", m[i][j]);
            printf("n");
    }

    system ("7"); //textcolor( GREEN );
    printf("n < %i puntos >", puntos*15);
    system ("8"); //texcolor ( RED );
    printf("Creado por Dorian Butron C. ");
    delay (100000);
}

int Vacio(char m, int F, int C){
    int i,j;
    for (i=0; i<F; i++){
        for (j=0; j<C; j++){
            if (m[i][j]=='.')
                return 0;
        }
    }
    return 1;
}

main (){
    char m[Tfil][Tcol]; //m[20][20] 
    rand();
    system ("pause"); 
    system ("cls"); //clrscr();
    generar_m(m,10,20);
    bichos(m,10,20);
    getch();
}


