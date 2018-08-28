//Programa Sistema de Nomina

#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Tipos
struct Persona
{
	int Numero;
	char Nombre[31];
	int Depto;
	int Puesto;
	float Sueldo;
};

//Variables
FILE *Empleados;
struct Persona RegEmpleado;
int I, Num, NumRegs, Opcion, Opcion2;
char Desea, Seguro;

int main ()
{
	void Crear();
	void Expancion();
	void Altas();
	void Bajas();
	void Cambios();
	void Consultas();
	void Catalogo();
	void Nomina();
	void CatalogoCortes();
	void NominaCortes();
	
	do
	{
		printf("\t\t SISTEMA DE NOMINA \n");
		printf("\n 1. Crear archivo empleados");
		printf("\n 2. Expancion archivo empleados");
		printf("\n 3. Altas de empleados");
		printf("\n 4. Bajas de empleados");
		printf("\n 5. Cambios de empleados");
		printf("\n 6. Consultas archivo empleados");
		printf("\n 7. Catalogo de empleados");
		printf("\n 8. Nomina quincenal");
		printf("\n 9. Catalogo de empleados cortes");
		printf("\n 10. Nomina quincenal con cortes");
		printf("\n 11. Fin");
		printf("\n Teclee opcion: ");
		scanf ("%d", &Opcion);
		
		switch (Opcion)
		{
			case 1:
				Crear();
				break; 
			case 2: 
				Expancion();
				break;
			case 3:
				Altas();
				break;
			case 4:
				Bajas();
				break;
			case 5:
				Cambios();
				break;
			case 6:
				Consultas();
				break;
			case 7:
				Catalogo();
				break;
			case 8:
				Nomina();
				break;
			case 9:
				CatalogoCortes();
			case 10:
				NominaCortes();
		}
	
	}	while (Opcion!=1);
		 
}	 //Fin Funcion Principal

void Crear()
{
	Empleados = fopen("C:\\PROGSLC\\EMDIR2.DAT", "w+b");
	printf ("\n Cuantos registros (empleados) tendra el archivo?: ");
	scanf ("%d", &NumRegs);
	RegEmpleado.Numero=0;
	strcpy (RegEmpleado.Nombre, "");
	RegEmpleado.Depto = 0;
	RegEmpleado.Puesto = 0;
	RegEmpleado.Sueldo = 0;
	
	for (I=1; I<=NumRegs; I++){
		fwrite(&RegEmpleado, sizeof (RegEmpleado), 1, Empleados);
	}
	
	fclose (Empleados);
} //Fin funcion Crear

void Expancion()
{
	Empleados = fopen("C:\\PROGSLC\\EMDIR2.DAT", "a+b");
	printf ("\n Cuantos registros (empleados) desea agregarle al archivo?: ");
	scanf ("%d", &NumRegs);
	RegEmpleado.Numero = 0;
	strcpy(RegEmpleado.Nombre, "");
	RegEmpleado.Depto = 0;
	RegEmpleado.Puesto = 0;
	RegEmpleado.Sueldo = 0;
	
	for (I=1; I<NumRegs; I++)
	{
		fwrite(&RegEmpleado, sizeof (RegEmpleado), 1, Empleados);
	}
	fclose (Empleados);
}

void Altas()
{
	Empleados = fopen("C:\\PROGSLC\\EMDIR2.DAT", "r+b");
	do
	{
		printf ("\n\t Sistema de Nomina");
		printf ("\n Altas archivo de empleado");
		printf ("\n Numero");
		scanf ("%d", &RegEmpleado.Numero);
		printf ("\n Nombre: ");
		fflush (stdin);
		gets(RegEmpleado.Nombre);
		printf ("\n Departamento: ");
		scanf ("%d", &RegEmpleado.Depto);
		printf ("\n Puesto: ");
		scanf ("%d", &RegEmpleado.Puesto);
		printf ("\n Sueldo: ");
		scanf ("%d", & RegEmpleado.Sueldo);
		fflush (stdin);
		fseek (Empleados, sizeof (RegEmpleado)*(RegEmpleado.Numero-1), 0);
		fwrite (&RegEmpleado, sizeof (RegEmpleado),1, Empleados);
		printf ("Otra alta (S/N)?: ");
		Desea=getchar();
		Desea=toupper(Desea);
		fflush(stdin);
				
	} while (Desea=='S');
	fclose (Empleados);
}

void Bajas()
{
	Empleados = fopen ("C:\\PROGSL\\EMDIR2.DAT", "r+b");
	do
	{
		printf ("\n\t Sistema de Nomina");
		printf ("\n Bajas archivo de empleado");
		printf ("\n Numero: ");
		scanf ("%d", &Num);
		fflush(stdin);
		fseek (Empleados, sizeof (RegEmpleado) * (Num-1), 0);
		fread (&RegEmpleado, sizeof (RegEmpleado), 1, Empleados);
		printf ("\n Nombre: %s \n", RegEmpleado.Nombre);
		printf ("\n Departamento: %d \n", RegEmpleado.Depto);
		printf ("\n Sueldo: %10.2f \n", RegEmpleado.Sueldo);
		printf ("\n Son los datos, esta seguro (S/N)?: ");
		Seguro=toupper(Seguro);
		Seguro=toupper(Seguro);
		fflush(stdin);
		
		if (Seguro=='S')
		{
			RegEmpleado.Numero=0;
			strcpy(RegEmpleado.Nombre, "");
			RegEmpleado.Depto=0;
			RegEmpleado.Puesto=0;
			RegEmpleado.Sueldo=0;
			fseek (Empleados, sizeof (RegEmpleado)*(Num-1), 0);
			fwrite (&RegEmpleado, sizeof (RegEmpleado), 1, Empleados);
		}	
		
		printf ("Otra baja (S/N)?: ");
		Desea=getchar();
		Desea=toupper(Desea);
		fflush (stdin);
		
	}	while (Desea == 'S');
		fclose (Empleados);
}

void Cambios()
{
	Empleados = fopen("C:\\PROGSLC\\EMDIR2.DAT", "r+b");
	do 
	{
		printf ("\n\t Sistema de Nomina");
		printf ("\n Cambios de archivos de empleados");
		printf ("\n Numero: ");
		scanf ("%d", &Num);
		fflush (stdin);
		fseek (Empleados, sizeof (RegEmpleado)*(Num-1), 0);
		fread (&RegEmpleado, sizeof (RegEmpleado), 1, Empleados);
		printf ("\n 1. Nombre: %s \n", RegEmpleado.Nombre);
		printf ("\n 2. Departamento: %d \n", RegEmpleado.Puesto);
		printf ("\n 3. Puesto: %d \n", RegEmpleado.Puesto);
		printf ("\n 4. Sueldo: %10.2f \n", RegEmpleado.Sueldo);
		printf ("\n Dato a cambiar (1,2,3,4, 0=Fin): ");
		scanf ("%d", &Opcion);
		
		while (Opcion >0 && Opcion <5) {
		
			switch (Opcion)	{
				
				case 1:
					printf ("\n 1. Nombre: ");
					fflush (stdin);
					gets (RegEmpleado.Nombre);
					break;
				case 2:
					printf ("\n 2. Departamento: ");
					scanf ("%d", &RegEmpleado.Depto);
					break;
				case 3:
					printf ("\n 3. Puesto: ");
					scanf ("%d", &RegEmpleado.Puesto);
					break;
				case 4:
					printf ("\n 4. Sueldo: ");
					scanf ("%f", &RegEmpleado.Sueldo);
					break;
			}
			
			printf ("\n Dato a cambiar (1,2,3,4, 0=Fin): ");
			scanf ("%d", &Opcion);
		}
	
		fseek (Empleados, sizeof (RegEmpleado)*(Num-1), 0);
		fwrite (&RegEmpleado, sizeof (RegEmpleado),1,Empleados);
		printf ("\n Otro cambio (S/N)?: ");
		fflush (stdin);
		Desea=getchar();
		Desea=toupper (Desea);
		fflush (stdin);
		
	} while (Desea == 'S');
	fclose (Empleados);
}

void Consultas ()
{
	Empleados = fopen ("C:\\PROGSLC\\EMDIR2.DAT", "r+b");
	
	do{
		printf ("\n\t Sistema de Nomina");
		printf ("\n Consultas archivo de empleado");
		printf ("\n Numero: ");
		scanf ("%d", & Num);
		fflush (stdin);
		fseek (Empleados, sizeof (RegEmpleado) * (Num-1), 0);
		fread (&RegEmpleado, sizeof (RegEmpleado), 1, Empleados);
		
		printf ("\n Nombre: %s \n", RegEmpleado.Nombre);
		printf ("\n Departamento: %s \n", RegEmpleado.Depto);
		printf ("\n Puesto: %d \n", RegEmpleado.Puesto);
		printf ("\n Sueldo: %10.2f \n", RegEmpleado.Sueldo);
		printf ("\n Otra Consulta (S/N)?: ");
		Desea = getchar();
		Desea = toupper (Desea);
		fflush (stdin);
		
	} while (Desea == 'S');
	fclose (Empleados);
}

void Catalogo()
{
	int TotEmp;
	float TotSueldos;
	
	Empleados = fopen ("C:\\PROGSLC\\EMDIR2.DAT", "r+b");
	TotEmp = 0;
	TotSueldos = 0;
	
	printf ("\n Catalogo de empleados");
	printf ("\n Numero		Nombre		Depto		Puesto		Sueldo");
	printf ("\n ----------------------------------------------------------");
	fread (&RegEmpleado, sizeof (RegEmpleado), 1, Empleados);
	
	while (feof (Empleados) == 0)
	{
		printf ("\n %4d		%-30s		%2d			%2d			%9.2f", RegEmpleado.Numero, RegEmpleado.Nombre, RegEmpleado.Depto, RegEmpleado.Puesto, RegEmpleado.Sueldo);
		TotEmp = TotEmp +1;
		TotSueldos = TotSueldos + RegEmpleado.Sueldo;
		fread (&RegEmpleado, sizeof (RegEmpleado), 1, Empleados);
		printf ("\n --------------------------------------------------------");
		printf ("\n Total	%3d", TotEmp);
		printf ("\n Empleados			");
		printf ("\n %10.2f \n", TotSueldos);
		fclose (Empleados);
		printf ("\n Presione <Intro> para continuar ...");
		fflush (stdin);
		getchar ();
	}
}

void Nomina(){
	
	int TotEmp;
	float Bruto, Impuesto, Neto, TotBruto, TotNeto, TotImpuesto, SalMin;
	
	Empleados = fopen ("C:\\PROGSLC\\EMDIR2.DAT", "r+b");
	TotEmp = 0;
	TotBruto = 0;
	TotNeto = 0;
	TotImpuesto = 0;
	printf ("\n Teclee salario minimo: ");
	scanf ("%f", &SalMin);
	printf ("\n N o m i n a  Q u i n c e n a l");
	printf ("\n Numero		Nombre		Bruto		Impuesto		Neto");
	printf ("\n ----------------------------------------------------------");
	fread (&RegEmpleado, sizeof (RegEmpleado), 1, Empleados);
	
	while (feof (Empleados)==0) {
		Bruto = RegEmpleado.Sueldo/2;
		if (Bruto>SalMin)
			Impuesto = (Bruto - SalMin)* 0.05;
		else
			Impuesto = 0;
		Neto = Bruto - Impuesto;
		printf ("\n %4d		%-30s		%10.2f	%10.2f	%10.2f", RegEmpleado.Numero, RegEmpleado.Nombre, Bruto, Impuesto, Neto);
		TotEmp = TotEmp +1;
		TotBruto = TotBruto + Bruto;
		TotImpuesto = TotImpuesto + Impuesto;
		TotNeto = TotNeto + Neto;
		fread (&RegEmpleado, sizeof (RegEmpleado), 1, Empleados);
	}
	
	printf ("\n -----------------------------------------------------");
	printf ("\n Total  %3d Empleados	", TotEmp);
	printf ("\n %10.2f  %10.2f  %10.2f ", TotBruto, TotImpuesto, TotNeto);
	fclose (Empleados);
	printf ("\n Presione <Intro> para continuar ... \n");
	fflush (stdin);
	getchar ();
}

void CatalogoCortes (){
	int TotEmp, TotEmpDep, DeptoProceso;
	float TotSueldos, TotSueldosDep;
	
	Empleados = fopen ("C:\\PROGSLC\\EMDIR2.DAT", "r+b");
	TotEmp =0;
	TotSueldos = 0;
	printf ("\n Catalogo de Empleados");	
	printf ("\n Numero		Nombre		Depto		Puesto		Sueldo");
	printf ("\n ---------------------------------------------------------");
	fread (&RegEmpleado, sizeof (RegEmpleado), 1, Empleados);
	
	while (feof (Empleados) ==0) {
		TotEmpDep = 0;
		TotSueldosDep = 0;
		DeptoProceso = RegEmpleado.Depto;
		
		while ( feof (Empleados)==0 && DeptoProceso == RegEmpleado.Depto){
			printf ("\n %4d		%-30s	", RegEmpleado.Numero, RegEmpleado.Nombre);
			printf ("\n %2d		%2d		%9.2f", RegEmpleado.Depto, RegEmpleado.Puesto, RegEmpleado.Sueldo);
			TotEmpDep = TotEmpDep +1;
			TotSueldosDep = TotSueldosDep + RegEmpleado.Sueldo;
			fread (&RegEmpleado, sizeof(RegEmpleado), 1, Empleados);
		}
		
		printf ("\n Total Depto. %3d", TotEmpDep);
		printf ("\n Empleados  %10.2f", TotSueldosDep);
		TotEmp = TotEmp + TotEmpDep;
		TotSueldos = TotSueldos + TotSueldosDep;
	}
	 printf ("\n ----------------------------------------------------------");
	 printf ("\n Total	%3d", TotEmp);
	 printf ("\n Empleados  %10.2f \n", TotSueldos);
	 fclose (Empleados);
	 printf ("\n Presione <Intro> para continuar ...\n");
	 fflush (stdin);
	 getchar ();
}

void NominaCortes (){
	int TotEmp, TotEmpDep, DeptoProceso;
	float Bruto, Impuesto, Neto, TotBruto, TotNeto, TotImpuesto, TotBrutoDep, TotNetoDep, TotImpuestoDep, SalMin;
	
	Empleados = fopen ("C:\\PROGSLC\\EMDIR2.DAT", "r+b");
	TotEmp = 0;
	TotBruto = 0;
	TotNeto = 0;
	TotImpuesto = 0;
	printf ("\n Teclee salario minimo: ");
	scanf ("%f", &SalMin);
	printf ("\n N o m i n a  Q u i n c e n a l");
	printf ("\n Numero		Nombre		Bruto		Impuesto		Neto");
	printf ("---------------------------------------------------------------");
	fread (&RegEmpleado, sizeof(RegEmpleado), 1, Empleados);
	
	while (feof (Empleados) == 0){
		TotEmpDep = 0;
		TotBrutoDep = 0;
		TotNetoDep = 0;
		TotImpuesto = 0;
		DeptoProceso = RegEmpleado.Depto;
		
		while (feof (Empleados)==0 && DeptoProceso==RegEmpleado.Depto) {
			Bruto = RegEmpleado.Sueldo/2;
		}
		
	}
}


