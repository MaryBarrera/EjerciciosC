#include <stdio.h>

typedef struct _Complejo{
   int real, imaginario;
}Complejo;

Complejo inicializar(int , int );
Complejo sumar(Complejo,Complejo);
Complejo restar(Complejo, Complejo);
Complejo multiplicar(Complejo, Complejo);
Complejo dividir(Complejo, Complejo);
int parteReal(Complejo);
int parteImaginaria(Complejo);
void escribir(Complejo);

main (){
	Complejo a, b, c;
	a=inicializar(2,5);
	b=inicializar(3,2);
	
	printf("\nNumero complejo 1: ");
	escribir(a);
	printf("\nNumero complejo 2: ");
	escribir(b);
	printf("\nLa suma es: ");
	escribir(sumar(a,b));
	printf("\nLa resta es: ");
	escribir(restar(a,b));
	printf("\nLa mutiplicacion es: ");
	escribir(multiplicar(a,b));
	printf("\nLa divicion es: ");
	escribir(dividir(a,b));
	printf("\nLa parte real es: ");
//	escribir(parteReal(c));
	printf("\nLa parte imaginaria es: ");
//	escribir(parteImaginaria(c));	
}

Complejo inicializar(int x, int y){
	Complejo c;
	c.real=x;
	c.imaginario=y;
	return c;
}

Complejo sumar(Complejo a, Complejo b){
	Complejo c;
	c.real=a.real + b.real;
	c.imaginario=a.imaginario + b.imaginario;
}

Complejo restar(Complejo a, Complejo b){
	Complejo c;
	c.real=a.real + b.real;
	c.imaginario=a.imaginario + b.imaginario;
}

Complejo multiplicar (Complejo a, Complejo b){
	Complejo c;
	c.real=(a.real*b.real)-(a.imaginario*b.imaginario);
	c.imaginario=(a.real*b.imaginario)+(a.imaginario*b.real);
}

Complejo dividir(Complejo a, Complejo b){
	Complejo c;
	c.real=((a.real*b.real)+(a.imaginario*b.imaginario))/((b.real^2)+(b.imaginario^2));
	c.imaginario=((a.imaginario*b.real)-(a.imaginario*b.imaginario))/((b.real^2)+(b.imaginario^2));
}

int parteReal(Complejo c){
	return c.real;
}

int parteImaginaria(Complejo c){
	return c.imaginario;
}

void escribir(Complejo c){
	printf("%d + %di", parteReal, parteImaginaria);
}
