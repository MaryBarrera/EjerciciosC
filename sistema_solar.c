// programa comprenda el sistema Solar
#include <stdio.h>

int main ()
{
	int planeta;
	char si='s';
	

while(si=='s')

{ 
	printf("----------------------SISTEMA SOLAR-----------------------\n");
	printf("\t1.- Mercurio \n\t2.- Venus \n\t3.- Tierra \n\t4.- Marte \n\t5.- Jupiter \n\t6.- Saturno \n\t7.- Urano \n\t8.- Neptuno \n");
	printf("\n\nElige el numero de un planeta para saber mas informacion: ");
	scanf("%i", &planeta);
	printf("\n-----------------------------------------------------------------\n");
	
	switch (planeta) 
	{
		case 1: 
			printf("1.- Mercurio\n");
			printf("\t Distancia al Sol: 57.910.000 KM.\n");
			printf("\t Tamanio: 4.880 KM.\n");
			printf("\t Lunas: 0\n");
			printf("\t Tiempo en completar una vuelta al sol: 58,6 DIAS\n");

			printf("\n\n");
		break;
			
		case 2: 
			printf("2.- Venus \n");
			printf("\t Distancia al Sol: 108.200.000 KM.\n");
			printf("\t Tamanio: 12.104 KM.\n");
			printf("\t Lunas: 0\n");
			printf("\t Tiempo en completar una vuelta al sol: -243 DIAS\n");
			
			printf("\n\n");
		break;
		
		case 3: 
			printf("3.- Tierra \n");
			printf("\t Distancia al Sol: 146.600.000 KM.\n");
			printf("\t Tamanio: 12.756 KM.\n");
			printf("\t Lunas: 1\n");
			printf("\t Tiempo en completar una vuelta al sol: 23,93 HORAS\n");
			
			printf("\n\n");
		break;
						
		case 4: 
			printf("4.- Marte \n");
			printf("\t Distancia al Sol: 227.940.000 KM.\n");
			printf("\t Tamanio: 6.794 KM.\n");
			printf("\t Lunas: 2\n");
			printf("\t Tiempo en completar una vuelta al sol: 24,62 HORAS\n");
			
			printf("\n\n");
		break;
					
		case 5: 
			printf("5.- Jupiter \n");
			printf("\t Distancia al Sol: 778.330.000 KM.\n");
			printf("\t Tamanio: 142.984 KM.\n");
			printf("\t Lunas: 16\n");
			printf("\t Tiempo en completar una vuelta al sol: 9,84 HORAS\n");
			
			printf("\n\n");
		break;
		
		case 6: 
			printf("6.- Saturno \n");
			printf("\t Distancia al Sol: 1.429.400.000 KM.\n");
			printf("\t Tamanio: 108.728 KM.\n");
			printf("\t Lunas: 18\n");
			printf("\t Tiempo en completar una vuelta al sol: 10,23 HORAS\n");
			
			printf("\n\n");
		break;
			
		case 7:
			printf("7.- Urano \n");
			printf("\t Distancia al Sol: 2.870.990.000 KM.\n");
			printf("\t Tamanio: 51.118 KM.\n");
			printf("\t Lunas: 15\n");
			printf("\t Tiempo en completar una vuelta al sol: 17,9 HORAS\n");
			
			printf("\n\n");
		break;
			
		case 8:
			printf("8.- Neptuno \n");
			printf("\t Distancia al Sol: 4.504.300.000  KM.\n");
			printf("\t Tamanio: 49.532 KM.\n");
			printf("\t Lunas: 8\n");
			printf("\t Tiempo en completar una vuelta al sol: 16,11 HORAS\n");
			
			printf("\n\n");
		break;
	
		default:
			printf("ERROR  \n\n no existe el numero de este planeta \n\n");
		break;	
			
	}

system("pause"); 
printf("\n\nPara ver la informacion de otro planeta presione \"s\" si no presione \"n\" y luego enter:"); 
scanf("%s",&si);

system("cls"); 
}

	return 0;
}

