#include <iostream>

using namespace std;
void Agregar_Fumador();
void Agregar_NoFumador();
int Pasajes[10];
int ContPasajes=0;

int main(){
	int Dato;
	while(ContPasajes<10){
		cout<<endl; //Dejo unos espacios de prolijidad
		cout<<endl;
		cout<<"Por favor digite 1 para la seccion de fumadores o digite 2 para la seccion de no fumadores: ";
		cin>>Dato;
		if(Dato==1){
			Agregar_Fumador(); 
		}
		else{
			Agregar_NoFumador();
		}
	}
	return 0;
}

void Agregar_Fumador(){
	int i;
	int Dato;
	if(ContPasajes<10){
		for(i=0;i<5;i++){
			if(Pasajes[i]==0){
				Pasajes[i]=1;
				ContPasajes++;
				cout<<"Pasaje n° "<<i+1<<" de la seccion de fumadores."<<endl;
				break;
			}
			else{
				if(i==4 && Pasajes[i]==1){
					cout<<"Se ocuparon todos los pasajes de la seccion fumadores. Desea un pasaje para la seccion no fumadores? 1-Si 0-No : ";
					cin>>Dato;
					if(Dato==1){
						Agregar_NoFumador();
					}
				}
			}
		}
	}
}

void Agregar_NoFumador(){
	int i;
	int Dato;
	if(ContPasajes<10){
		for(i=5;i<10;i++){
			if(Pasajes[i]==0){
				Pasajes[i]=1;
				ContPasajes++;
				cout<<"Pasaje n° "<<i+1<<" de la seccion de no fumadores."<<endl;
				break;
				}
			else{
				if(i==9 && Pasajes[i]==1){
					cout<<"Se ocuparon todos los pasajes de la seccion fumadores. Desea un pasaje para la seccion fumadores? 1-Si 0-No : ";
					cin>>Dato;
					if(Dato==1){
						Agregar_Fumador();
					}
				}
			}
		}
	}
}
