#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream.h>

main()
{
	int i,j=0,estado=1,ruta[10],mensaje;
	ruta[0]=estado; // asigna el estado '1' al arreglo ruta en la primera posición
	char palabra[10]; // declara un arreglo de caracteres para recibir la cadena del usuario
	cout<<"AUTOMATA FINITO DETERMINISTA "<<endl;
	cout<<"Introduzca el numero a evaluar: ";
	
	for(i=0;(palabra[i]=getchar())!='\n';i++); //bucle que pide la cadena y la va almacenando
	cout<<endl<<"Evaluacion de la cadena: ";
	do{
		// PROGRAMAR PARA CADA ESTADO
		// ESTADO 1
		if((estado==1 && palabra[j]=='b') || (estado==2 && palabra[j]=='a'))
		{
			estado=1;
			j++;
			ruta[j]=estado;
			mensaje=0;
			i--;
		}
		// ESTADO 2
		if((estado==1 && palabra[j]=='a') || (estado==2 && palabra[j]=='b'))
		{
			estado=2;
			j++;
			ruta[j]=estado;
			mensaje=1;
			i--;
		}
	}
	while(i!=0); // mientras i que es la longitud de la cadena original no llegue a 0
	// EVALUACION DE LA ACEPTACION O RECHAZO DE LA CADENA
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
