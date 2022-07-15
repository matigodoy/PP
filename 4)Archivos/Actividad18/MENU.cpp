#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct registro{
	long int Nro;
	char Nom[30];
	short int Tipo, Categ;
	float Monto, MontoActuali;
}reg;

int main(){
	int menu;
    do{
    	cout<<endl<<endl;
        cout<<"COMPANIA FINANCIERA "<<endl;
        cout<<"1. CARGAR OPERACIONES "<<endl;
        cout<<"2. MOSTRAR OPERACIONES CARGADAS CON MONTO ACTUALIZADO "<<endl;
        cout<<"3. MOSTRAR CLIENTE CON MAYOR MONTO ACTUALIZADO EN DEPOSITOS A CORTO PLAZO "<<endl;
        cout<<"4. MOSTRAR PROMEDIO DE LOS MONTOS POR LAS CATEGORIAS DE LOS TIPOS DE CUENTAS A CREDITO "<<endl;
        cout<<"5. MOSTRAR PROMEDIO DE LOS MONTOS POR CADA UNA DE LAS CATEGORIAS "<<endl;
        cout<<"6. SALIR "<<endl;
        cout<<"Ingrese opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad18\\cargar.exe");
                break;
            case 2:
                system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad18\\mostrar.exe");
                break;
            case 3:
            	system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad18\\clientescortoplazo.exe");
            	break;
            case 4:
            	system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad18\\promcuentascredito.exe");
            	break;
            case 5:
            	system("C:\\Users\\fedem\\Desktop\\FACU\\2doSEMESTRE\\PP\\TRABAJOS\\4)Archivos\\Actividad18\\promcategorias.exe");
            	break;
            case 6:
                return 0;
                
            default: cout<<"Ingrese una opcion valida "<<endl;
        }
    }while(menu!=6);
    
    return 0;
}

