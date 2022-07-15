/* Ejercicio 14.) Se dispone de  un archivo de un colegio secundario, con los siguientes datos en cada registro: 	
	- Nombre del alumno
	- Promedio del primer trimestre en una materia
	- Promedio del segundo trimestre en esa materia
	- Promedio del tercer trimestre en esa materia 
Sabiendo que si el promedio general (PG) es: 
		PG   >=  7		El alumno se exime
		PG  >= 4 y <  7		El alumno rinde en diciembre
		PG   <   4		El alumno rinde en marzo
Calcule el promedio general de cada alumno, imprimiendo un listado con los nombres y promedios generales de los alumnos que se eximen. 
Informar además por fin de archivo, cuantos alumnos se eximen, cuantos rinden en diciembre y cuantos en marzo. Desarrolle el programa de creación  y carga del archivo.*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct registro{
	char nombre[30], materia[20];
	float prom1er, prom2do, prom3ro, promgral;
}reg;

int main(){
	int menu;
    do{
    	cout<<endl<<endl;
        cout<<"MENU DE OPCIONES "<<endl;
        cout<<"1. CARGAR ALUMNOS "<<endl;
        cout<<"2. MOSTRAR ALUMNOS CARGADOS "<<endl;
        cout<<"3. MOSTRAR ALUMNOS QUE SE EXIMEN "<<endl;
        cout<<"4. SALIR "<<endl;
        cout<<"Ingrese opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad14\\cargar.exe");
                break;
            case 2:
                system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad14\\mostrar.exe");
                break;
            case 3:
                system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad14\\alumnoseximen.exe");
                break;
            case 4:
            	system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad14\\cantalumnosporpromedio.exe");
                return 0;
                
            default: cout<<"Ingrese una opcion valida "<<endl;
        }
    }while(menu!=4);
    
    return 0;
}

