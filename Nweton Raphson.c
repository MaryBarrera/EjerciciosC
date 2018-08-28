#include <stdio.h>
#include <conio.h>
#include <math.h>

float funcion(float x0){ //funcion a aplicar el metodo
	float y;
	y=pow(x0,3)-x0-1; //x^3-x-1
	return y;
}

float der_funcion (float x0){ //derivada de la funcion
	float dy;
	dy=3*pow(x0,2)-1; //3x-1
	return dy;
}

float NewtonRaphson (float y, float dy, float x0, float delta, float epsilon, float N_iteracion){
	int k;
	float x1, err, relerr;
	 for (k=1; k<N_iteracion; k++){
        x1 = x0 - (funcion(x0) / der_funcion(x0)); //regla de correspondecia para el metodo
        err = fabs(x1-x0); //error
        relerr = 2*err/(fabs(x1) + delta);
        x0 = x1;
        y = funcion(x0);
        printf("[%6f, %6.5f] %8.5f %8.5f\n", k, x0,x1, err);
        if ((err<delta) || (relerr<delta) || (fabs(y)<epsilon))
			break;
	}
}

main(){
	
	printf("\t APLICACION METODO NEWTON - RAPHSON \n\n");
    printf("---------------------------------------------\n");
    
    float x0=1.0, y, dy;
    float epsilon = 0.0005;	//margen de error
	float delta = 0.0005;	//tolerancia para x0
	float N_iteracion = 10;	//numero maximo de iteraciones
    
    printf(" N°Iteracion	 aprox	 valor_derivada		 c\n");
    y=funcion(x0);
    dy=der_funcion(x0);
    NewtonRaphson (y, dy, x0, delta, epsilon, N_iteracion);
    
   
}

