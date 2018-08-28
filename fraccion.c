#include <stdio.h>

typedef struct _Fraccion{
   int numerador, denominador;
}Fraccion;

int mcm(int, int);
Fraccion inicializar(int, int);
Fraccion suma(Fraccion, Fraccion);
Fraccion resta(Fraccion, Fraccion);
Fraccion multiplicacion(Fraccion, Fraccion);
Fraccion division(Fraccion, Fraccion);
double razon(Fraccion);
int num(Fraccion);
int den(Fraccion);
void escribir(Fraccion);

main(){
   Fraccion x, y, z;
   double r;
   x= inicializar(1, 8);
   y= inicializar(5, 12);
   printf("\nPrimera fraccion: ");
   escribir(x);
   printf("\n\nSegunda fraccion: ");
   escribir(y);
   printf("\n\nSu suma es: ");
   escribir(suma(x, y));
   printf("\n\nSu resta es: ");
   escribir(resta(y, x));
   printf("\n\nSu multiplicacion es: ");
   escribir(multiplicacion(x, y));
   printf("\n\nSu division es: ");
   escribir(division(x, y));
   printf("\n\nSus razones respectivas son: %g y %g", razon(x), razon(y));
}

int mcm(int m, int n){
   int d= 2, res= 1, r1, r2;
   do{
      r1= m % d;
      r2= n % d;
      if(!r1)
         m= m / d;
      if(!r2)
         n= n / d;
      if(!r1 || !r2)
         res= res * d;
      else
         d++;
   }while(m!=1 || n!=1);
   return res;
}

Fraccion inicializar(int n, int d){
   Fraccion r;
   if(!d){
      r.numerador= 1;
      r.denominador= 1;
   }else{
      r.numerador= n;
      r.denominador= d;
   }
   return r;
}

Fraccion suma(Fraccion a, Fraccion b){
   Fraccion c;
   c.denominador= mcm(a.denominador, b.denominador);
   c.numerador= c.denominador/a.denominador*a.numerador + c.denominador/b.denominador*b.numerador;
   return c;
}

Fraccion resta(Fraccion a, Fraccion b){
   Fraccion c;
   c.denominador= mcm(a.denominador, b.denominador);
   c.numerador= c.denominador/a.denominador*a.numerador - c.denominador/b.denominador*b.numerador;
   return c;
}

Fraccion multiplicacion(Fraccion a, Fraccion b){
   Fraccion c;
   c.numerador= a.numerador * b.numerador;
   c.denominador= a.denominador * b.denominador;
   return c;
}

Fraccion division(Fraccion a, Fraccion b){
   Fraccion c;
   c.numerador= a.numerador * b.denominador;
   c.denominador= a.denominador * b.numerador;
   return c;
}

double razon(Fraccion f){
   return (double)(f.numerador)/(double)(f.denominador);
}

int num(Fraccion f){
   return f.numerador;
}

int den(Fraccion f){
   return f.denominador;
}

void escribir(Fraccion f){
   printf("%d/%d", f.numerador, f.denominador);
}
