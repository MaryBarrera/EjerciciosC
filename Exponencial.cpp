#include <stdio.h>
#include <math.h>

void main(void)
{
    int terminos;
    double x, valor_estimado, valor_exacto;
    double serie(double ,int );
    printf("%s%s", 
        "Este programa calcula \"e\" elevado a \"x\" por desarrollo",
        "en serie\n con el numero de terminos que quieras\n");
    printf("Teclea x:");
    scanf("%lf",&x);
    printf("\nTeclea el numero de terminos:");
    scanf("%d", &terminos);
    printf("%s%lfcon %d %s%16.6lf\n", 
        "El resultado de e elevado a ", x, "terminos es ",
        terminos, serie(x, terminos));
    printf("Error cometido: %16.6lf\n", serie(x, terminos) - exp(x));
}

double serie(double z, int numero)
{
    double miserie = 1, frac;
    int i;
    frac = z;
    miserie += rac;
    i = 2;
    if (numero == 1) {
        miserie = 1;
        return miserie;
    }
    while (i <= numero) {
        frac = frac*z/i++;
        miserie += frac;
    }
    return miserie;
}
