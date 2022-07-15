#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <math.h>
#include <stdio.h>

using namespace std;

struct personas
{
	int long dni;
	char nombre[90];
};

struct personas_vector
{
	int long dni_vec;
	char nombre_vec[90];	
};

int main()
{
	FILE*m;
	m = fopen("Variedad.dat","rb");
	personas r;
	personas_vector a[100];
	int contador = 0;
	int aux = 0;
	char auxi[90];
	if (m == NULL)
	{
		cout<<"Error interno con el archivo..."<<endl;
		exit (1);
	}
	else
	{
		int i=0;
		fread(&r, sizeof(personas), 1, m);
		while (feof(m) == 0)
		{
		a[i].dni_vec = r.dni;
		strcpy(a[i].nombre_vec,r.nombre);
		i++;
		contador++;
		fread(&r, sizeof(personas), 1, m);
	}
	for(int i=0;i<contador-1;i++)
	{
		for(int j=i+1;j<contador;j++)
		{
			if(strcmp(a[i].nombre_vec,a[j].nombre_vec))
			{
				strcpy(auxi,a[j].nombre_vec);
				aux = a[j].dni_vec;
				strcpy(a[j].nombre_vec,a[i].nombre_vec);
				a[j].dni_vec = a[i].dni_vec;
				strcpy(a[j].nombre_vec,a[i].nombre_vec);
				a[i].dni_vec = aux;
				strcpy(a[i].nombre_vec, auxi);
			}
		}
	}
	for(int i=0; i<contador; i++)
    {
    	cout<<"DNI: "<<a[i].dni_vec<<endl;
    	cout<<"Nombre y Apellido: "<<a[i].nombre_vec<<endl;
    	cout<<".............................."<<endl;
	}
	system("pause");system("cls");
	fclose(m);
	}
}
