#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct registro{
    long int cod;
    int n1, n2;
}reg;

void carga();
void mostrar();

int main(){
    int menu;
    do{
        cout<<"MENU DE OPCIONES "<<endl;
        cout<<"1. CARGAR DATOS "<<endl;
        cout<<"2. MOSTRAR DATOS "<<endl;
        cout<<"3. SALIR "<<endl;
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
            case 3: return 0;
                
            default: cout<<"Ingrese una opcion valida "<<endl;
        }
    }while(menu!=3);
    
    return 0;
}

void carga(){
    int otro=0, i=1;
    ofstream archivo;
    archivo.open("actividad2.dat",ios::out);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        do{
            cout<<"Archivo numero "<<i++<<endl;
            cout<<"Ingrese el codigo: ";
            cin>>reg.cod;
            archivo<<reg.cod<<endl;
            cout<<"Ingrese el primer numero: ";
            cin>>reg.n1;
            archivo<<reg.n1<<endl;
            cout<<"Ingrese el segundo numero: ";
            cin>>reg.n2;
            archivo<<reg.n2<<endl;
            cout<<endl;
            do{
                cout<<"Quiere cargar otro archivo? (1. para si - 0. para no): ";
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
    string texto;
    archivo.open("actividad2.dat",ios::in);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        long int codigo;
        int num1, num2;
        while(!archivo.eof()){
            archivo>>codigo>>num1>>num2;
            if(!archivo.eof()){
                cout<<"Codigo: "<<codigo<<endl;
                if(num1>num2)cout<<"El numero mayor es: "<<num1<<endl;
                if(num2>num1)cout<<"El numero mayor es: "<<num2<<endl;
                if(num1==num2)cout<<"Los dos numero son iguales "<<endl;
                cout<<endl;
            }
        }
        archivo.close();
    }
    cout<<endl<<endl;
    return;
}
