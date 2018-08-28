#include <stdio.h>
void main(void)
{
    double vector1[3], vector2[3], vectorR[3]; //Arreglos para los vectores 1 y 2 y un tercero para el vector resultado
    int i,opc;
    void suma(double *, double *, double *);
    void resta(double *, double *, double *);
    double prod_escalar(double *, double *);
    void prod_cruz(double *, double *, double *);
    
    printf("\n 1.- Suma de vectores");  //Menu de opciones para elegir una operacion
    printf("\n 2.- Resta de vectores");
    printf("\n 3.- Multiplica escalarmente");
    printf("\n 4.- Multiplica vectorialmente");
    printf("\n Seleccione una opcion [1-4]:");
    scanf("%d", &opc);
    
    printf("\n Ingrese primer vector:"); //Captura de las componentes del primer vector
    for (i=0; i<3; i++)
	{
        printf("\n Componente:[%d]=", i+1);
        scanf("%lf", &vector1[i]);
        printf("\n");
    }
    
    printf("\n Ingrese segundo vector:"); //Captura de las componetes del segundo vector
    for(i=0; i<3; i++) 
	{
        printf("\n Componente[%d]=", i+1);
        scanf("%lf", &vector2[i]);
        printf("\n");
    }
    
	switch (opc) //Selecciona la opcion correspondiente
	{
        case 1:
            suma(vector1, vector2, vectorR);
            printf("\n La suma entre dos vectores:");
            printf("{ ");
            for (i=0; i<3; i++)
                printf("%lf ",vectorR[i]);
            printf("}\n");
            break;
        case 2:
            resta(vector1, vector2, vectorR);
            printf("\n La resta entre dos vectores es:");
            printf("{ ");
            for (i=0; i<3; i++)
                printf("%lf ",vectorR[i]);
            printf("}\n");
            break;
        case 3:
            printf("\n  El producto escalar entre dos vectores es: %lf\n",
             prod_escalar(vector1, vector2));
            break;
        case 4:
            prod_cruz(vector1, vector2, vectorR);
            printf("\n  El producto vectorial entre dos vectores es:\n");
            printf("{ ");
            for(i=0; i<3; i++)
                printf("%lf ", vectorR[i]);
            printf("}\n");
            break;
    }
}

void suma(double *a, double *b, double *c) //Funcion que calcula la resta
{
    int i;
    for (i=0; i<3; i++)
        c[i] = a[i]+b[i];
}

void resta(double *a, double *b, double *c) //Funcion que calcula la resta
{
    int i;
    for (i=0; i<3; i++)
        c[i] = a[i]-b[i];
}

double prod_escalar(double *a, double *b) //Funcion que calcula el producto escalar
{
    int i;
    double escalar=0;
    for (i=0; i<3; i++)
        escalar += a[i]*b[i];
    return(escalar);
}

void prod_cruz(double *a, double *b, double *c) //Fucion que calcula el producto cruz
{
    int i;
    c[0] = a[1]*b[2]-a[2]*b[1];
    c[1] = -a[0]*b[2]+a[2]*b[0];
    c[2] = a[0]*b[1]-a[1]*b[0];
}

