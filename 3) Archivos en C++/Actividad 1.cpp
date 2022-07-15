#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

struct registro{
    int num;
    int cantnum;
}reg;

void cargar_numero();
void mostrar();
void mostrar_mayor_menor_100();

int main(){
    int menu;
    do{
        cout<<"MENU DE OPCIONES "<<endl;
        cout<<"1. CARGAR NUMEROS "<<endl;
        cout<<"2. MOSTRAR NUMEROS CARGADOS "<<endl;
        cout<<"3. MOSTRAR SI LA CANTIDAD DE NUMEROS INGRESADOS ES INFERIOR O MAYOR A 100 "<<endl;
        cout<<"4. SALIR"<<endl;
        cout<<"Ingrese opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
                cargar_numero();
                break;
            case 2:
                mostrar();
                break;
            case 3:
                mostrar_mayor_menor_100();
                break;
            case 4:
                return 0;
                
            default:
                cout<<"INGRESE UNA OPCION VALIDA ";
        }
    }while(menu != 4);
    return 0;
}

void cargar_numero(){
    int otro;
    ofstream archivo;
    archivo.open("Actividad1.dat",ios::out);
    if(archivo.fail()){
        cout<<endl<<"No se pudo abrir el archivo "<<endl;
        exit(1);
    }
    else{
        do{
            cout<<"Ingrese el Numero "<<reg.cantnum+1<<": ";
            cin>>reg.num;
            reg.cantnum++;
            archivo<<reg.num<<endl;
            cout<<endl;
            do{
                cout<<"Quiere cargar otro numero? (1. para si - 0. para no): ";
                cin>>otro;
                if(otro>1 || otro<0)cout<<"Se pide 1 o 0 "<<endl;
            }while(otro>1 || otro<0);
            cout<<endl;
        }while(otro!=0);
    }
    archivo.close();
}

void mostrar(){
    int i=1;
    ifstream archivo;
    archivo.open("Actividad1.dat",ios::in);
    if(archivo.fail()){
        cout<<endl<<"No se pudo abrir el archivo "<<endl;
        exit(1);
    }
    else{
        int numero;
        while(!archivo.eof()){
            archivo>>numero;
            if(!archivo.eof()){
            cout<<"El numero numero "<<i++<<" es: "<<numero<<endl;
            cout<<endl;
            }
        }
    }
    archivo.close();
    cout<<endl<<endl;
}

void mostrar_mayor_menor_100(){
    ifstream archivo;
    archivo.open("Actividad1.dat",ios::in);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        cout<<"La cantidad de numeros ingresados son: "<<reg.cantnum<<endl;
        cout<<endl;
        if(reg.cantnum>=100)cout<<"Se han ingresado mas de 100 numeros "<<endl;
        if(reg.cantnum<100)cout<<"Se han ingresado menos de 100 numeros "<<endl;
        cout<<endl<<endl;
        archivo.close();
    }
    cout<<endl<<endl;
}
