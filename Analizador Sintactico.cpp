#include <stdio.h>
#include <stdlib.h>

char token;
int expresion ();
int termino ();
int factor ();

void match (char carEsperado)
{
	if (token == carEsperado)
		token=getchar ();
	else 
		error("Caracter no esperado");
}

void error (char *msg)
{
	printf ("stderr, msg");
	exit (1);
}

main ()
{
	int resultado;
	token = getchar ();
	resultado = expresion ();
	if (token=='\n')
		printf ("El resultado de la expresion es: %d", resultado);
	else
		error ("Fin de expresion no esperado");
}

int expresion ()
{
	int tmp;
	tmp=termino ();
	while (token == '+' || token == '-')
		switch (token)
		{
			case '+':
				match ('+');
				tmp = tmp + termino ();
				break;
			case '-':
				match ('-');
				tmp = tmp - termino ();
		}
	return tmp;
}

int termino ()
{
	int tmp;
	tmp = factor ();
	while (token == '*'|| token =='/')
		switch (token)
		{
			case '*':
				tmp = tmp * factor ();
				break;
			case '/':
				match ('/');
				tmp = tmp / factor ();				
		}
	return tmp;
}

int factor ()
{
	int tmp;
	if (token == '(') 
	{
		match ('(');
		tmp= expresion ();
		match (')');
	}
	
	else if (sdigit(token))
	{
		ungetc (token, stdin);
		scanf ("%d", &tmp);
		token = getchar ();		
	} 
	return tmp;	
}

	


