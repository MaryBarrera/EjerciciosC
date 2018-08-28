/* ------------------------------------------------------------------------*/
/* TEORIA DE AUTOMATAS FINITOS                                             */                                          
/* PROGRAMA SIMULADOR DE UNA MAQUINA DE TURING.                            */
/* ------------------------------------------------------------------------*/

#define CODIFICA
/*#define DATOS*/
#define LIMPIAR
#define PORTADA
#define MESSAGE
#define CURSOR
#define MAX 100

#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "blt.h"

#ifdef MESSAGE
void message(char texto[81],int atributo);
#endif MESSAGE
#ifdef PORTADA
void portada(void);
#endif PORTADA
void CAPTURA(void);
int BUSCA(char simbolo,char A[MAX]);
int BUSCA_TRANS(char trans[5],char A[MAX][5]);
void SORTEA(char A[MAX]);
void SORTEA_TRANS(char X[MAX][5],int top);
void OPRIMA(char texto[81],int atributo);
void CONSTRUCCION(int transiciones);
void RECORRIDO(void);

char ALFABETO[MAX];
char ESTADOS[MAX];
char INICIO,PARADA;
char TRANSICION[MAX][5],otra;

void main(void)
{
#ifdef DATOS
  RECORRIDO();
  exit(0);
#endif DATOS
#ifdef PORTADA
  portada();
#endif PORTADA
  CAPTURA();
  do
  {
    RECORRIDO();
    do
    {
      OPRIMA(" ¨ Desea evaluar otra cadena con la misma m quina ? [S/N]                       ",27);
    }while(otra!='N' && otra!='S');
  }while(otra=='S');
#ifdef LIMPIAR
  textattr(7); window(1,1,80,25); clrscr();
#endif LIMPIAR
  return;
}

#ifdef PORTADA
void portada(void)
{
  no_cursor();
  textattr(7);clrscr();
  fondo(BLUE);
  fondo1(CYAN);
  textattr(78);
  ventana(20,2,60,6,RED);
  centerv(2,"TEORIA DE AUTOMATAS FINITOS");
  centerv(3,"Dra. Ada Margarita Alvarez S.");

   ventana(15,8,65,19,BLUE);textattr(27);
   centerv(1," MAQUINAS DE TURING ");
   centerv(3,"Equipo # 5");
   centerv(5,"Ma. Gpe. Mendoza Garc¡a ");
   centerv(6,"Javier Casta¤eda Ambriz ");
   centerv(7,"Jaime David Johnston B. ");
   centerv(8,"Sergio Garza Carranza   ");
   centerv(9,"Miguel Angel Guerrero C.");
   centerv(10,"Bruno L¢pez Takeyas     ");

   ventana(13,21,67,24,GREEN);
   textattr(32);
   centerv(2,"<<< Oprima cualquier tecla para continuar >>>");
   getch();
   si_cursor();
   window(1,1,80,25);
   return;
}
#endif PORTADA

void CAPTURA(void)
{
int columna=10,renglon=1,flag,i;
char simbolo;
char transicion[5];
  textattr(BLUE);
  clrscr();
  fondo1(CYAN);
  textattr(30);
  ventana(2,2,78,23,BLUE); textattr(31);
  centerv(1," PROGRAMA SIMULADOR DE UNA MAQUINA DE TURING ");
  window(4,3,76,21);

  for(flag=0;flag<=MAX;flag++)  { ALFABETO[flag]='\0'; ESTADOS[flag]='\0'; }
  i=0;
  do
  {
    do
    {
      textattr(27);
      message("  Anote los s¡mbolos del alfabeto ä                           < ENTER > = Salir ",30);
      gotoxy(columna,renglon);
      cprintf(" %c( %3d ) = ",228,i);
      simbolo=tolower(getch());
      if(simbolo==32)
	OPRIMA(" No introduzca el blanco !!!      <<< Oprima cualquier tecla para continuar >>> ",206);
    }while(simbolo==32);

    flag=BUSCA(simbolo,ALFABETO);
    if(flag<0)
    {
	ALFABETO[i]=simbolo;
	gotoxy(columna+12,renglon); cprintf("%c",ALFABETO[i]);
	renglon++; columna=10;
	i++;
    }
    else
	OPRIMA("  S¡mbolo repetido !!!            <<< Oprima cualquier tecla para continuar >>> ",206);
    if(i%19==0)
    {
      clrscr(); columna=10; renglon=1;
    }
  }while(ALFABETO[i-1]!='\r');
  ALFABETO[i-1]=32;
  ALFABETO[i]='L';
  ALFABETO[i+1]='R';
  ALFABETO[i+2]='\0';
  SORTEA(ALFABETO);

/* CAPTURAR LOS ESTADOS DE LA MAQUINA */
  renglon=2;
  window(1,1,80,25);
  textattr(GREEN);
  clrscr();
  fondo1(GREEN);
  ventana(2,2,78,23,BLUE); textattr(31);
  centerv(1," PROGRAMA SIMULADOR DE UNA MAQUINA DE TURING ");
  ventana(20,10,60,15,GREEN);
  textattr(32);
  centerv(1," ESTADOS INICIAL Y DE PARADA ");
  do
    {
      message(" Estado inicial de la m quina                                                   ",32);
      textattr(33);
      gotoxy(15,3);
      cprintf("Inicial = ",i);
      simbolo=toupper(getch());
      if((simbolo<65 || simbolo>90) && simbolo!='\r')
	OPRIMA(" Estado inv lido !!!              <<< Oprima cualquier tecla para continuar >>> ",206);
      flag=BUSCA(simbolo,ESTADOS);
      if(flag<0)
      {
	gotoxy(25,3); cprintf("%c",simbolo);
	INICIO=simbolo;
      }
      else OPRIMA("  Estado repetido !!!             <<< Oprima cualquier tecla para continuar >>> ",206);
    }while(simbolo<65 || simbolo>90 || flag!=-1);

  do
    {
      message(" Estado de parada de la m quina                                                 ",32);
      textattr(33);
      gotoxy(15,4);
      cprintf("Parada  = ");
      simbolo=toupper(getch());
      if((simbolo<65 || simbolo>90) && simbolo!='\r')
	OPRIMA(" Estado inv lido !!!              <<< Oprima cualquier tecla para continuar >>> ",206);
      if(simbolo==INICIO)
      {
	OPRIMA(" El estado de inicio NO puede ser de parada                                     ",206);
	flag=1;
      }
      else
      {
	flag=BUSCA(simbolo,ESTADOS);
	if(flag<0)
	{
	  gotoxy(25,4); cprintf("%c",simbolo);
	  PARADA=simbolo;
	}
	else OPRIMA("  Estado repetido !!!             <<< Oprima cualquier tecla para continuar >>> ",206);
      }
    }while(simbolo<65 || simbolo>90 || flag!=-1);

    window(1,1,80,24);
    window(4,3,76,21);
    textattr(17);
    clrscr();
    si_cursor();
  i=0; columna=10; renglon=1;
  do
  {
    do
    {
      message(" Estados de la m quina.  No incluya el inicio y parada !!!    < ENTER > = Salir ",32);
      textattr(27);
      gotoxy(columna,renglon);
      cprintf("S ( %3d ) = ",i);
      simbolo=toupper(getch());
      if((simbolo<65 || simbolo>90) && simbolo!='\r')
	OPRIMA(" Estado inv lido !!!              <<< Oprima cualquier tecla para continuar >>> ",206);
    }while((simbolo<65 || simbolo>90) && simbolo!='\r');

    flag=BUSCA(simbolo,ESTADOS);
    if(simbolo==INICIO || simbolo==PARADA) flag=1;
    if(flag<0)
    {
	ESTADOS[i]=simbolo;
	gotoxy(columna+12,renglon); cprintf("%c",ESTADOS[i]);
	renglon++; columna=10;
	i++;
    }
    else OPRIMA("  Estado repetido !!!             <<< Oprima cualquier tecla para continuar >>> ",206);
    if(i%19==0)
    {
      clrscr(); columna=10; renglon=1;
    }
  }while(ESTADOS[i-1]!='\r');
  ESTADOS[i-1]='\0';

  ESTADOS[strlen(ESTADOS)]=32;       ESTADOS[strlen(ESTADOS)+1]='\0';
  ESTADOS[strlen(ESTADOS)]=32;       ESTADOS[strlen(ESTADOS)+1]='\0';
  SORTEA(ESTADOS);
  ESTADOS[0]=INICIO;
  ESTADOS[1]=PARADA;

/* CAPTURAR LAS TRANSICIONES */
  columna=10;   renglon=1;
  window(1,1,80,25);
  textattr(RED);
  clrscr();
  fondo1(6);
  ventana(2,2,78,23,BLUE); textattr(31);
  centerv(1," TRANSICIONES DE LA MAQUINA DE TURING ");
  window(4,3,76,21); gotoxy(1,1);
  i=0;
  while(1)
  {
      do
      {
	flag=-1;
	message("  Estado origen                                               < ENTER > = Salir ",111);
	columna=10; textattr(27);
	gotoxy(columna,renglon);     cprintf("ë( , ) = ( , )");
	columna+=2;
	gotoxy(columna,renglon);   simbolo=toupper(getch());
	if(simbolo==PARADA)
	  OPRIMA("  El estado de parada NO puede originar una transici¢n !!!                      ",206);
	else
	{
	  flag=BUSCA(simbolo,ESTADOS);
	  if(flag<0 && simbolo!='\r')
	    OPRIMA("  Estado inv lido !!!             <<< Oprima cualquier tecla para continuar >>> ",206);
	}
      }while(flag<0 && simbolo!='\r');
/* *************************************************************************/
/* Aqui validar que el estado capturado NO sea el estado de parada */
/* *************************************************************************/

      if(simbolo=='\r') break;
      transicion[0]=simbolo;
      gotoxy(columna,renglon); cprintf("%c",simbolo);

      columna+=2;
      do
      {
	message("  S¡mbolo actual en la cinta de entrada                    < ESPACIO > = Blanco ",111);
	gotoxy(columna,renglon);   simbolo=tolower(getch());
	flag=BUSCA(simbolo,ALFABETO);
	if(flag<0)
	  OPRIMA("  S¡mbolo inv lido !!!            <<< Oprima cualquier tecla para continuar >>> ",206);
      }while(simbolo=='\r' || flag<0);
      transicion[1]=simbolo;
      if(simbolo==32) simbolo=127;
      gotoxy(columna,renglon); cprintf("%c",simbolo);

      columna+=6;
      do
      {
	message("  Estado destino                                                                ",111);
	gotoxy(columna,renglon);   simbolo=toupper(getch());
	flag=BUSCA(simbolo,ESTADOS);
	if(flag<0)
	  OPRIMA("  Estado inv lido !!!             <<< Oprima cualquier tecla para continuar >>> ",206);
      }while(simbolo=='\r' || flag<0);
      transicion[2]=simbolo;
      gotoxy(columna,renglon); cprintf("%c",simbolo);

      columna+=2;
      do
      {
	message("  S¡mbolo a escribir en la cinta u operaci¢n  <F1>=L   <F2>=R  <ESPACIO>=Blanco ",111);
	gotoxy(columna,renglon);   simbolo=tolower(getch());
	if(simbolo==0)
	{
	  simbolo=getch();
	  if(simbolo==F1) simbolo='L';
	  if(simbolo==F2) simbolo='R';
	}
	flag=BUSCA(simbolo,ALFABETO);
	if(flag<0)
	  OPRIMA("  S¡mbolo inv lido !!!            <<< Oprima cualquier tecla para continuar >>> ",206);
      }while(simbolo=='\r' || flag<0);
      transicion[3]=simbolo; transicion[4]='\0';
      if(simbolo==32) simbolo=127;
      gotoxy(columna,renglon); cprintf("%c",simbolo);
      if(transicion[0]==transicion[2] && transicion[1]==transicion[3])
	  OPRIMA("  Transici¢n redundante !!!       <<< Oprima cualquier tecla para continuar >>> ",206);
      else
      {
	flag=BUSCA_TRANS(transicion,TRANSICION);
	if(flag<0)
	{
	  simbolo=transicion[0]; TRANSICION[i][0]=simbolo;
	  simbolo=transicion[1]; TRANSICION[i][1]=simbolo;
	  simbolo=transicion[2]; TRANSICION[i][2]=simbolo;
	  simbolo=transicion[3]; TRANSICION[i][3]=simbolo;
	  simbolo='\0';          TRANSICION[i][4]=simbolo;
	  i++; renglon++;
	  if(i%19==0)
	  {
	    clrscr(); columna=10; renglon=1;
	  }
	}
	else
	 if(flag==(MAX+1))
	 {
	   OPRIMA("  No se permite el NO determinismo  << Oprima cualquier tecla para continuar >> ",206);
	 }
	 else
	 {
	  OPRIMA("  Transici¢n repetida !!!         <<< Oprima cualquier tecla para continuar >>> ",206);
	 }
      }
   }

  SORTEA_TRANS(TRANSICION,i);
  renglon++; columna=3;
  gotoxy(columna,renglon);
#ifdef CODIFICA
  CONSTRUCCION(i);
#endif CODIFICA
  return;
}

int BUSCA(char simbolo,char A[MAX])
{
int k,flag=-1;
  for(k=0;k<=strlen(A);k++)
  {
    if(simbolo==A[k]) flag=k;
    if(flag!=-1) break;
  }
  return flag;
}

#ifdef MESSAGE
void message(char texto[81],int atributo)
{
  gettextinfo(&info);
  window(1,1,80,25);
  textattr(atributo);
  gotoxy(1,24); cputs(texto);
  window(info.winleft,info.wintop,info.winright,info.winbottom);
  textattr(info.attribute);
  gotoxy(info.curx,info.cury);
  return;
}
#endif MESSAGE

void SORTEA(char A[MAX])
{
int i,j;
char car;
  for(i=0;i<strlen(A)-1;i++)
    for(j=i+1;j<strlen(A);j++)
      if(A[i]>A[j])
      {
	car=A[i];
	A[i]=A[j];
	A[j]=car;
      }
  return;
}

int BUSCA_TRANS(char trans[5],char A[MAX][5])
{
int k,flag=-1;
  for(k=0;k<=MAX;k++)
  {
    if(strcmp(A[k],trans)==0)  flag=k;
    if(strcmp(A[k],"")==0 || flag!=-1)     break;
    if(trans[0]==A[k][0] && trans[1]==A[k][1]) flag=MAX+1;
  }
  return flag;
}

void SORTEA_TRANS(char X[MAX][5],int top)
{
int i,j,flag=0;
char cade[5];
char INI[MAX][5];
int top_i=0;

  for(i=0;i<top;i++)
  {
    if(X[i][0]==INICIO)
    {
      strcpy(INI[top_i],X[i]);         top_i++;
      strcpy(X[i],"    ");
    }
  }

  for(i=0;i<top_i-1;i++)
    for(j=i+1;j<top_i;j++)
      if(strcmp(INI[i],INI[j])>0)
      {
	strcpy(cade,INI[i]);
	strcpy(INI[i],INI[j]);
	strcpy(INI[j],cade);
      }

  for(i=0;i<top-1;i++)
   for(j=i+1;j<top;j++)
   {
     if(strcmp(X[i],X[j])>0)
     {
	strcpy(cade,X[i]);
	strcpy(X[i],X[j]);
	strcpy(X[j],cade);
     }
   }

   for(i=0;i<top_i;i++)
     strcpy(X[i],INI[i]);
  return;
}

void OPRIMA(char texto[81],int atributo)
{
  no_cursor();
  message(texto,atributo);
  otra=toupper(getch());
  si_cursor();
  return;
}

void CONSTRUCCION(int transiciones)
{
int i,j,k,flag,columna=2,renglon=2;
char texto[81];
  window(1,1,80,25);
  textattr(5);
  clrscr();
  fondo1(5);
  textattr(30);
  ventana(2,2,78,23,BLUE);
  textattr(30);
  centerv(1," CONSTRUCCION DE LA MAQUINA DE TURING ");
  window(4,3,76,21); gotoxy(columna,renglon);
  OPRIMA(" Indicador de inicio                                      < ENTER > = Continuar ",28);
  textattr(28);
  gotoxy(columna,renglon);
  textov("1");
  for(i=0;i<transiciones;i++)
  {
    for(j=0;j<strlen(TRANSICION[i]);j++)
    {
       texto[0]='\0';
       strcpy(texto," Analizando ë (");
       flag=strlen(texto);
       texto[flag]=TRANSICION[i][0];
       texto[flag+1]='\0';
       strcat(texto,",");
       flag=strlen(texto);
       if(TRANSICION[i][1]==32) TRANSICION[i][1]=127;
       texto[flag]=TRANSICION[i][1];
       texto[flag+1]='\0';
       strcat(texto,") = (");
       flag=strlen(texto);
       texto[flag]=TRANSICION[i][2];
       texto[flag+1]='\0';
       strcat(texto,",");
       flag=strlen(texto);
       if(TRANSICION[i][3]==32) TRANSICION[i][3]=127;
       texto[flag]=TRANSICION[i][3];
       texto[flag+1]='\0';
       strcat(texto,")");
       if(j%2==0) strcat(texto," con el estado ");
       else
       {
	 if(TRANSICION[i][j]=='R' || TRANSICION[i][j]=='L')
	 strcat(texto," con la operaci¢n ");
	 else strcat(texto," con el s¡mbolo ");
       }
       flag=strlen(texto);
       texto[flag]=TRANSICION[i][j];    texto[flag+1]='\0';
       strcat(texto,"        ");
       if(j%2==0) OPRIMA(texto,26); else OPRIMA(texto,25);

       if(j%2==0) flag=BUSCA(TRANSICION[i][j],ESTADOS)+1;
       else flag=BUSCA(TRANSICION[i][j],ALFABETO);
       if(j%2==0) textattr(26); else textattr(25);
       for(k=0;k<flag;k++)
       {
	 textov("0");
       }
       if(j==3)
       {
	 textattr(28);
	 OPRIMA("Indicador de cambio de transici¢n                ",28);
       }
       else
       {
	 textattr(27);
	 OPRIMA("Separador                                        ",27);
       }
       textov("1");
    }
  }
  OPRIMA("Indicador de fin de la codificaci¢n.",28);
  textattr(28);
  textov("1");
  OPRIMA("<<< OPRIMA ENTER PARA CONTINUAR >>>                                             ",206);
  return;
}

void RECORRIDO(void)
{
char cadena[70];
char edo_actual;
int b,i,k,s,flag,columna,col_ant,fin_cadena=0;
  window(1,1,80,25);
  textattr(28);
  clrscr();
  fondo1(12);
  gotoxy(1,24);
  cputs(" Anote la cadena a evaluar                                < ENTER > = Salir     ");
  textattr(30);
  ventana(2,2,78,23,BLUE);
  textattr(30);
  centerv(1," EVALUACION DE UNA CADENA CON ESTA MAQUINA DE TURING ");
  window(4,3,76,21);

  i=0;
  gotoxy(2,2);
  textattr(27);
  do
  {
    do
    {
      cadena[i]=tolower(getch());
    }while(cadena[i]=='\r' && i==0);
    if(cadena[i]=='\r')
    {
      cadena[i]='\0';
      break;
    }
    cadena[i+1]='\0';
    if(cadena[i]==32) cadena[i]=127;
    if(cadena[i]!=32) cprintf("%c",cadena[i]); else cprintf("%c",127);
    if(i==70)
    {
       beep(700,20);
       OPRIMA(" Cadena demasiado larga !!!                               < ENTER > = Continuar ",156);
       MESSAGE(" Anote la cadena a evaluar                                < ENTER > = Salir     ",28);
       clrscr();
       i=0;
       gotoxy(2,2);
       textattr(27);
    }
    else i++;
  }while(i>=70 || cadena[i-1]!='\r');
  for(i=strlen(cadena)-1;i>0;i--)
    if(cadena[i]==127)
      cadena[i]='\0';
    else break;
  textattr(28);
  clrscr();

#ifdef DATOS
  INICIO='I';
  PARADA='Z';
  strcpy(ALFABETO," LRxyz");
  strcpy(ESTADOS,"IZMNQRT");
  strcpy(TRANSICION[0],"I TR");
  strcpy(TRANSICION[1],"IxTR");
  strcpy(TRANSICION[2],"IyTR");
  strcpy(TRANSICION[3],"M MR");
  strcpy(TRANSICION[4],"MxNx");
  strcpy(TRANSICION[5],"MyMR");
  strcpy(TRANSICION[6],"N Z ");
  strcpy(TRANSICION[7],"NxZx");
  strcpy(TRANSICION[8],"NyZy");
  strcpy(TRANSICION[9],"Q QR");
  strcpy(TRANSICION[10],"QxQR");
  strcpy(TRANSICION[11],"QyRy");
  strcpy(TRANSICION[12],"R Z ");
  strcpy(TRANSICION[13],"RxZx");
  strcpy(TRANSICION[14],"RyZy");
  strcpy(TRANSICION[15],"T Z ");
  strcpy(TRANSICION[16],"TxMR");
  strcpy(TRANSICION[17],"TyQR");
  strcpy(TRANSICION[18],"TyQR");
#endif DATOS

  edo_actual=INICIO;
  i=0;
  columna=2;

  textattr(29); gotoxy(2,2); cprintf("Cadena original : ");
  gotoxy(2,3);
  for(s=0;s<=strlen(cadena);s++)
    if(cadena[s]==32) cprintf("%c",127); else cprintf("%c",cadena[s]);
  do
  {
     textattr(26);
     gotoxy(columna,4); cprintf("%c",157);
     textattr(28);
     gotoxy(2,5);
     for(s=0;s<=strlen(cadena);s++)
       if(cadena[s]==32) cprintf("%c",127); else cprintf("%c",cadena[s]);
     textattr(25); gotoxy(2,7);  cprintf("Estado  actual : ");
     textattr(30);               cprintf("%c",edo_actual);
     textattr(25); gotoxy(2,9);  cprintf("S¡mbolo actual : ");
     textattr(30);
     if(cadena[i]!='\0' && cadena[i]!=32) cprintf("%c",cadena[i]);
      else if(cadena[i]!='\0') cprintf("%c",127);
     textattr(25); gotoxy(2,11);  cprintf("Transici¢n     : ");

     if(cadena[i]!='\0' && cadena[i]==127) { flag=BUSCA(32,ALFABETO);}
     else if(cadena[i]!='\0' && cadena[i]!=127) { flag=BUSCA(cadena[i],ALFABETO);}
     else { flag=0; cadena[i]=127;}
     if(flag<0) break;
     for(k=0,flag=-1;k<=MAX;k++)
     {
       if(TRANSICION[k][0]!=edo_actual) continue;
       if(TRANSICION[k][1]==cadena[i])
       {
	 flag=1;
	 textattr(30);
	 cprintf("ë(%c,",TRANSICION[k][0]);
	 if(TRANSICION[k][1]==32) cprintf("%c) = (",127); else cprintf("%c) = (",TRANSICION[k][1]);
	 cprintf("%c,",TRANSICION[k][2]);
	 if(TRANSICION[k][3]==32) cprintf("%c)",127); else cprintf("%c)",TRANSICION[k][3]);
	 edo_actual=TRANSICION[k][2];
	 col_ant=columna;
	 if(TRANSICION[k][3]=='L')
	    { columna--; i--; }
	 if(TRANSICION[k][3]=='R')
	    { columna++; i++; }
	 if(TRANSICION[k][3]!='R' && TRANSICION[k][3]!='L')
	 {
	   cadena[i]=TRANSICION[k][3];
	 }
	 OPRIMA(" <<< Oprima cualquier tecla para continuar >>>                                  ",27);
	 gotoxy(col_ant,4); cprintf(" ");
	 if(i>=strlen(cadena)-1) fin_cadena=1;
	 break;
       }
     }
     if(flag==-1) break;
     if(i==strlen(cadena) && edo_actual!=PARADA)
     {
/* @@@@     cadena[i]=32;*/
      for(b=0;b<=MAX;b++)
	if(TRANSICION[b][0]==edo_actual && TRANSICION[b][1]==127 && TRANSICION[b][2]!=edo_actual)
	{
	   cadena[i]=127;      cadena[i+1]='\0';
	   break;
	}
     }
  }while(i>=0 && i<strlen(cadena) && edo_actual!=PARADA);

  textattr(26); gotoxy(columna,4); cprintf("%c",157);
  textattr(28);
  gotoxy(2,5);
  for(s=0;s<=strlen(cadena);s++)
    if(cadena[s]==32) cprintf("%c",127); else cprintf("%c",cadena[s]);
  textattr(25); gotoxy(2,7);  cprintf("Estado  actual : ");
  textattr(30);               cprintf("%c",edo_actual);
  textattr(25); gotoxy(2,9);  cprintf("S¡mbolo actual : ");
  textattr(30);               cprintf("%c",cadena[i]);
  textattr(25); gotoxy(2,11);  cprintf("Transici¢n     : ");

  if(edo_actual!=PARADA || (i<strlen(cadena)-1 && fin_cadena!=1))
  {
   cprintf("                                  ");
   OPRIMA(" Cadena NO aceptada !!!                                   < ENTER > = Continuar ",206);
  }
  else
  {
   OPRIMA(" Cadena aceptada !!!                                      < ENTER > = Continuar ",206);
  }
  return;
}
