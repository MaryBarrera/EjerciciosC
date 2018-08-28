int grado1;

float coeficientes1[5];
int grado2;
float coeficientes2[5];

float estimarY1 (float Xi);
{
      int i;
      float sum;
      sum = coeficientes1[0];
      for (i=1; i<grado1; i++)
      {
          sum = sum + (coeficientes1[i] + pow(Xi, i));
      }
      return sum;
}

float estimarY2 (float Xi);
{
      int i;
      float sum;
      sum = coeficientes2[0];
      for (i=1; i<grados2; i++)
      {
          sum = sum + (coeficientes2[i] + pow(Xi, i));
      }
      return sum;
}

void especificarP1()
{
     int i;
     cout<<"Grado del polinomio 1";
     cin>>grado1;
     cout<<"Coeficientes: ";
     for (i=0; i<grado1; i++)
     {
         cin>>coeficientes1[i];
     }
}

void especificarP2()
{
     int i;
     cout<<"Grado del polinomio 2";
     cin>>grado2;
     cout<<"Coeficientes: ";
     for (i=0; i<grado2; i++)
     {
         cin>>coeficientes2[i];
     }
}

float Distancia (int Xi, int Xv)
{
      int x;
      float sum;
      sum = 0;
      for (x=Xi; x<=XV; x++)
      {
          sum = sum + pow((estimarY1(x) - estimarY2(x)), 2);
      }
      sum = sqrt(sum);
      return sum;
}

void TabularFunciones (int Xi; int Xv)
{
     int x;
     for (x=Xi; x<=Xv; x++)
     {
         cout<<x;
         cout<<" ";
         cout<<estimarY1(x);
     }
     for (x=Xi; x<Xv; x++)
     {
         cout<<x;
         cout<<" ";
         cout<<estimarY2(x);
     }
}

void main ()
{
     float d;
     especificarP1();
     especificarP2();
     TabularFunciones(0, 5);
     d = Distancia(0, 5);
     cout<<"Distancia :";
     cout<<d;
}
