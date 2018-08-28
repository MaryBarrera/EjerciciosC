#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream.h>

main()
{
	int i,j=0,estado=1,ruta[10],mensaje;
	ruta[0]=estado; // asigna el estado ¡¥1¡¦ al arreglo ruta en la primera posicion
	char palabra[10]; // declara un arreglo de caracteres para recibir la cadena del usuario
	cout<<"AUTOMATA FINITO DETERMINISTA QUE EVALUA SOLO NUMEROS DECIMALES"<<endl;
	cout<<"Introduzca el numero a evaluar: ";

	for(i=0;(palabra[i]=getchar())!='\n';i++); //bucle que pide el numero y lo va almacenando
	cout<<endl<<"Evaluacion del numero: ";
	do
	{
		// PROGRAMAR PARA CADA ESTADO
		// ESTADO 2
		if((estado==1||estado==2) && (palabra[j]>='0' && palabra[j]<='9'))
		{
			estado=2;
			j++;
			ruta[j]=estado;
			mensaje=0;
			i--;
		}
		// ESTADO 3
		if(estado==2 && palabra[j]=='.')
		{
			estado=3;
			j++;
			ruta[j]=estado;
			mensaje=0;
			i--;
		}
		// ESTADO 4 (ACEPTACION)
		if((estado==3||estado==4) && (palabra[j]>='0' && palabra[j]<='9'))
			{
				estado=4;
				j++;
				ruta[j]=estado;
				mensaje=1;
				i--;
			}
	}
	while(i!=0);
	if(mensaje==1)
	{
		cout<<"CADENA ACEPTADA"<<endl<<endl;
		cout<<"RUTA:"<<endl;
		for(i=0;i<=j; i++)
		cout<<"estado "<<ruta[i]<<"\t";
	}
	else
	{
		cout<<"CADENA RECHAZADA"<<endl<<endl;
		cout<<"RUTA:"<<endl;
		for(i=0;i<=j; i++)
		cout<<"estado "<<ruta[i]<<"\t";
	}
	getch();
}
