#include <stdio.h>
int id=0;
int val[V];

void buscar()
{
  int k;
  for (k=1; k<=V; k++)
    val[k]=0;
  for (k=1; k<=V; k++)
    if (val[k]==0) visitar(k);
}

void visitar(int k) // matriz de adyacencia
{
  int t;
  val[k]=++id;
  for (t=1; t<=V; t++)
    if (a[k][t] && val[t]==0) visitar(t);
}

void visitar(int k) // listas de adyacencia
{
  struct nodo *t;
  val[k]=++id;
  for (t=a[k]; t!=z; t=t->sig)
    if (val[t->v]==0) visitar(t->v);
}
