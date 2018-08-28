#include <stdio.h>
struct tcola *cola;

void visitar(int k) // listas de adyacencia
{
  struct nodo *t;
  encolar(&cola,k);
  while (!vacia(cola))
  {
    desencolar(&cola,&k);
    val[k]=++id;
    for (t=a[k]; t!=z; t=t->sig)
    { 
      if (val[t->v]==0)
      {
        encolar(&cola,t->v);
        val[t->v]=-1;
      }
    } 
  }
}
