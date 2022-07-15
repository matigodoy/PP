#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct registro{
    long int cod;
    float imp;
}reg;

void carga();
void mostrar();
void mostrar_cant();

int main(){
    int menu;
    do{
        cout<<"MENU DE OPCIONES "<<endl;
        cout<<"1. CARGAR REGISTROS "<<endl;
        cout<<"2. MOSTRAR REGISTROS CARGADOS "<<endl;
        cout<<"3. MOSTRAR CANTIDAD DE REGISTROS CON CODIGO IGUAL O DIFETENTE A 200 Y CANTIDAD DE REGISTROS EN TOTAL "<<endl;
        cout<<"4. SALIR "<<endl;
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
                mostrar_cant();
            case 4:
                return 0;
                
            default: cout<<"Ingrese una opcion valida "<<endl;
        }
    }while(menu!=4);
    
    return 0;
}

void carga(){
    int otro, i=1;
    ofstream archivo;
    archivo.open("actividad4.dat",ios::out);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        do{
            cout<<"Registro numero "<<i++<<endl;
            cout<<"Ingrese el codigo: ";
            cin>>reg.cod;
            archivo<<reg.cod<<endl;
            cout<<"Ingrese el importe: $";
            cin>>reg.imp;
            archivo<<reg.imp<<endl;
            cout<<endl;
            do{
                cout<<"Quiere cargar otro codigo? (1. para si - 0. para no): ";
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
    int i=1;
    ifstream archivo;
    archivo.open("actividad4.dat",ios::in);
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
            	cout<<"Registro numero "<<i++<<endl;
           		cout<<"Codigo: "<<codigo<<endl;
           		cout<<"Importe: $"<<importe<<endl;
            	cout<<endl;
			}
        }
        archivo.close();
    }
    cout<<endl<<endl;
}

void mostrar_cant(){
    int canta200=0, cantb200=0, cant=0;
    ifstream archivo;
    archivo.open("actividad4.dat",ios::in);
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
            	if(codigo==200)canta200++;
            	if(codigo!=200)cantb200++;
			}
        }
        archivo.close();
        cant=canta200+cantb200;
        cout<<"La cantidad de registros con un codigo igual a 200: "<<canta200<<endl;
        cout<<"La cantidad de registros con un codigo diferente a 200: "<<cantb200<<endl;
        cout<<"La cantidad de registros totales: "<<cant<<endl;
    }
    cout<<endl<<endl;
}

