//este es el header
#include<iostream.h>

void mostrar()
{

} 


//Y ESTE ES EL CODIGO:
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include "Presentacion.h"

char izq[10][2],der[10][15],datos[10][15],cadena[20],noTer[20],Ter[20],pila[20]={"S#"};
int cp,cT=0,cnT=0,pro[20],pr; 

bool BuscarCadena(char aux[20],char letra) /* Funcion de busqueda en los arreglos terminales y no terminales */
{
	for(int i=0;aux[i]!='\0';i++)
	{
		if(aux[i]==letra) 
		return true;
	}
	return false;
} 

void Determinar(char LnT,char aux[15]) /* Funcion para determinar los terminales y los no terminales */
{ 
	if(BuscarCadena(noTer,LnT)==false) noTer[cnT++]=LnT; 
	for(int i=0;aux[i]!='\0';i++)
	{
		if(BuscarCadena(noTer,aux[i])==false)
		noTer[cnT++]=aux[i];
		if(((aux[i]>=97 && aux[i]<=123) || (aux[i]>=48 && aux[i]<=57)) && BuscarCadena(Ter,aux[i])==false)
		Ter[cT++]=aux[i];
	}
	noTer[cnT]='\0';
	Ter[cT]='\0';
} 

char *ordenar(char aux[10],int ri) /* Funcion para ordenar los datos de los arreglos terminales y no terminales */
{
	char temp;
	for(int i=ri;aux[i]!='\0';i++)
	{
		for(int j=i;aux[j]!='\0';j++)
		{
			if(int(aux[i])>int(aux[j]))
			{
				temp=aux[i];
				aux[i]=aux[j];
				aux[j]=temp;
			}
		}
	}
	return aux;
} 

bool buscar(char LnT,char LT,int rf) /* Funcion de busqueda */
{
	for(int i=0;i<rf;i++)
	{
		if(izq[i][0]==LnT && der[i][0]==LT)
		{
		pro[pr++]=i; 
		return true;
		}
	}
	for(int k=0;k<rf;k++)
	{
		if(izq[k][0]==LnT && int(der[k][0])>=65 && int(der[k][0])<=90) 
		{
		pro[pr++]=k;
		return buscar(der[k][0],LT,cp);
		} 
	}
	return false;
}

void verGramatica() /* Funcion para mostrar la gramatica */
{
	system("cls");
	cout<<"--------------------------------------------------------------------------------\t\t\tGramatica LL(1) sin reglas vacias\n--------------------------------------------------------------------------------\n\n"; 
	cout<<" Cantidad de producciones: "<<cp<<"\n\n\n--------------------------------------------------------------------------------\t\t\t\t Producciones\n--------------------------------------------------------------------------------\n"; 
	for(int i=0;i<cp;i++)
	cout<<" "<<(i+1)<<". "<<izq[i]<<" -> "<<der[i]<<endl;
} 

void tabla() /* Funcion para crear la tabla de analisis */
{
	verGramatica();
	cout<<"\n\n\n Funcion analizadora\n ";
	for(int i=0;i<=(cT*8)+14;i++) cout<<"-";
	cout<<"\n Pila\t";
	for(int i=0;i<=cT;i++) cout<<" "<<Ter[i]<<"\t";
	cout<<"\n ";
	for(int i=0;i<=(cT*8)+14;i++) cout<<"-";
	cout<<"\n\n";
	for(int i=0;noTer[i]!='\0';i++)
	{
		cout<<setw(4)<<noTer[i];
		for(int j=0;Ter[j]!='\0';j++)
		{
			if(noTer[i]!=Ter[j])
		{
		pr=0;
		if(buscar(noTer[i],Ter[j],cp)==true)
			cout<<"\t"<<der[pro[0]]<<","<<(pro[0]+1);
		else
		cout<<"\tError";
		}
		else if((noTer[i]!='#' && Ter[j]!='#') && (noTer[i]==Ter[j]))
		cout<<"\tEcima";
		else 
		cout<<"\tAceptar"; 
		}
		cout<<endl<<endl;
	}
	cout<<" ";
	for(int i=0;i<=(cT*8)+14;i++) cout<<"-";
	cout<<"\n\n";
} 

void concatenar(int pos) /* Funcion para concatenar la pila con las derivaciones */
{
	char aux[10];
	strcpy(aux,der[pos]);
	int nc=strlen(aux);
	for(int i=1;pila[i]!='\0';i++)
	aux[nc++]=pila[i];
	aux[nc]='\0';
	strcpy(pila,aux); 
}

void eliCima() /* Funcion para eliminar la cima de la cadena y de la pila */
{
	int i;
	for(i=1;cadena[i]!='\0';i++)
	cadena[i-1]=cadena[i]; 
	cadena[i-1]='\0';
	for(i=1;pila[i]!='\0';i++)
	pila[i-1]=pila[i]; 
	pila[i-1]='\0'; 
}

void rastreo() /* Funcion para realizar el rastreo de una cadena */
{
	int w=0;
	char str[2],cinta[30]="";
	cout<<"\n\n Traza del analisis sintactico de "<<cadena<<endl;
	cout<<" -------------------------------------------------\n Cadena de entrada Pila Cinta de salida\n -------------------------------------------------\n";
	do
	{ 
		cout<<setw(12)<<cadena<<setw(18)<<pila<<"\t\t "<<cinta<<endl; 
		if(cadena[0]!= pila[0])
		{
		pr=0; 
		if(buscar(pila[0],cadena[0],cp)==false) break;
		concatenar(pro[0]);
		itoa((pro[0]+1),str,10);
		cinta[w++]=str[0];
		}
		itoa: 
		
		
		else
		eliCima(); 
	}
	while(cadena[0]!='#' && pila[0]!='#');
	cout<<setw(12)<<cadena<<setw(18)<<pila<<"\t\t "<<cinta<<endl; 
	cout<<" -------------------------------------------------\n\n"; 
	if (cadena[0]!='#' || pila[0]!='#') cout<<"\n Error: La cadena no puede ser generada por esta gramatica.\n\n";
} 

void NuevaGramatica() /* Funcion para ingresar una nueva gramatica */
{
	char aux[10],LnT;
	system("cls"); 
	strcpy(noTer," ");
	strcpy(Ter," ");
	cT=0;
	cnT=0; 
	cout<<"--------------------------------------------------------------------------------\t\t\tGramatica LL(1) sin reglas vacias\n--------------------------------------------------------------------------------\n\n";
	cout<<" Cuantas producciones desea ingresar? ";cin>>cp;
	cout<<"\n\n--------------------------------------------------------------------------------\t\t\t\t Producciones\n--------------------------------------------------------------------------------\n Simbolo inicial: S\n\n Formato: # -> ####\n\n\n"; 
	cin.ignore();
	for(int i=0;i<cp;i++)
	{
		do
		{
			do
			{
			cout<<" "<<(i+1)<<". ";LnT=getche();
			if(int(LnT)>90 || int(LnT)<65) cout<<endl;
			}
			while(int(LnT)>90 || int(LnT)<65);
			izq[i][0]=LnT;izq[i][1]='\0';
			cout<<" -> ";gets(der[i]);
		}
		while(buscar(LnT,der[i][0],i)==true);
		Determinar(LnT,der[i]); 
	} 
	strcpy(Ter,ordenar(Ter,0));
	strcpy(noTer,ordenar(noTer,1)); 
	strcat(Ter,"#");
	strcat(noTer,"#"); 
	verGramatica(); 
} 

void NuevaCadena() /* Funcion para analizar una nueva cadena */
{
	int nc;
	verGramatica();
	tabla(); 
	cin.ignore();
	cout<<"\n\n Cadena: ";gets(cadena); 
	nc=strlen(cadena);
	if(cadena[nc-1]!='#'){cadena[nc]='#';cadena[nc+1]='\0';}
	strcpy(pila,"S#"); 
	verGramatica();
	tabla();
	rastreo(); 
} 

main() /* Funcion principal */
{
	int op;
	mostrar();
	getch();
	system("cls");//"clear" limpia pantalla y crea una nueva con la siguiente funcion o cout
	cout<<"--------------------------------------------------------------------------------\t\t\tGramatica LL(1) sin reglas vacias\n--------------------------------------------------------------------------------";
	do
	{
		cout<<"\n\n\t Menu Principal\n\n";
		cout<<"\n 1. Ingresar Gramatica LL(1)\n";
		cout<<"\n 2. Mostrar Gramatica LL(1)\n"; 
		cout<<"\n 3. Mostrar Funcion analizadora\n"; 
		cout<<"\n 4. Realizar Analisis sintactico\n"; 
		cout<<"\n 5. Salir\n\n\n"; 
		do
		{
			cout<<" Opcion: ";cin>>op;
			if(izq[0][0]=='\0' && op>1 && op<5) op=0;
		}
		while(op<=0 || op>5);
		switch(op)
		{
			case 1: NuevaGramatica();break;
			case 2: cout<<"\n\n";verGramatica();;break;
			case 3: tabla();break;
			case 4: cout<<endl;NuevaCadena();break;
		}
	}
	while(op==1 || op==2 || op==3 || op==4); 
}
