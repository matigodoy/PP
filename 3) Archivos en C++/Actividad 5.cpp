#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct registro{
    long int cod;
    float imp;
}reg;

void carga();
void mostrar();
void mostrar_codigo_superior1000();
void mostrar_codigo_inferior1000();

int main(){
    int menu;
    do{
        cout<<"MENU DE OPCIONES "<<endl;
        cout<<"1. CARGAR LOS PRODUCTOS "<<endl;
        cout<<"2. MOSTRAR PRODUCTOS CARGADOS "<<endl;
        cout<<"3. MOSTRAR CANTIDAD DE PRODUCTOS CON UN CODIGO SUPERIOR A 1000 "<<endl;
        cout<<"4. MOSTRAR CANTIDAD DE PRODUCTOS CON UN CODIGO INFERIOR O IGUAL A 1000 "<<endl;
        cout<<"5. SALIR "<<endl;
        cout<<"Ingrese opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
                carga();
                break;
            case 2:
                mostrar();
                break;
            case 3:
                mostrar_codigo_superior1000();
                break;
            case 4:
                mostrar_codigo_inferior1000();
                break;
            case 5:
                return 0;
                
            default: cout<<"Ingrese una opcion valida "<<endl;
        }
    }while(menu!=5);
    
    return 0;
}

void carga(){
    int otro, i=1;
    ofstream archivo;
    archivo.open("actividad5.dat",ios::out);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        do{
            cout<<"Producto numero "<<i++<<endl;
            cout<<"Ingrese el codigo ";
            cin>>reg.cod;
            archivo<<reg.cod<<endl;
            cout<<"Ingrese el importe: $";
            cin>>reg.imp;
            archivo<<reg.imp<<endl;
            cout<<endl;
            do{
                cout<<"Quiere cargar otro producto? (1. para si - 0. para no): ";
                cin>>otro;
                if(otro>1 || otro<0)cout<<"Se pide 1 o 0 "<<endl;
            }while(otro>1 || otro<0);
            cout<<endl;
        }while(otro!=0);
    }
    archivo.close();
    return;
}

void mostrar(){
    ifstream archivo;
    archivo.open("actividad5.dat",ios::in);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        int i=1;
        long int codigo=0;
    	float importe=0;
        while(!archivo.eof()){
        	archivo>>codigo>>importe;
            if(!archivo.eof()){
            	cout<<"Producto numero "<<i++<<endl;
            	cout<<"Codigo: "<<codigo<<endl;
            	cout<<"Importe: $"<<importe<<endl;
            	cout<<endl;
			}
		}
    }
    archivo.close();
    cout<<endl<<endl;
}

void mostrar_codigo_superior1000(){
    int cantmayor=0, importemayor=0;
    ifstream archivo;
    archivo.open("actividad5.dat",ios::in);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
    	long int codigo=0;
    	float importe=0;
        while(!archivo.eof()){
        	archivo>>codigo>>importe;
        	if(!archivo.eof()){
	            if(codigo>1000){
	                cantmayor++;
	                importemayor=importemayor+importe;
	            }
			}
        }
        archivo.close();
        cout<<"La cantidad de productos que tienen un codigo mayor a 1000 son: "<<cantmayor<<endl;
        cout<<"El importe total de los productos que tienen un codigo mayor a 1000 es: $"<<importemayor<<endl;
    }
    cout<<endl<<endl;
}

void mostrar_codigo_inferior1000(){
    int cantmenor=0, importemenor=0;
    ifstream archivo;
    archivo.open("actividad5.dat",ios::in);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
    	long int codigo=0;
    	float importe=0;
		while(!archivo.eof()){
			archivo>>codigo>>importe;
        	if(!archivo.eof()){
	            if(reg.cod<=1000){
	                cantmenor++;
	                importemenor=importemenor+importe;
	            }
			}
        }
        archivo.close();
        cout<<"La cantidad de productos que tienen un codigo menor o igual a 1000 son: "<<cantmenor<<endl;
        cout<<"El importe total de los productos que tienen un codigo menor o igual a 1000 es: $"<<importemenor<<endl;
    }
    cout<<endl<<endl;
}
