#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

struct registro{
    int num;
    int cantnum;
    double distances [2][2];
}reg;

void cargar_numero();
void mostrar();
void mostrar_mayor_menor_100();

int main(){
    int menu;
    do{
        cout<<"MENU DE OPCIONES "<<endl;
        cout<<"1. CARGAR MATRIZ "<<endl;
        cout<<"2. MOSTRAR MATRIZ "<<endl;
        cout<<"3. SALIR"<<endl;
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
                return 0;
                
            default:
                cout<<"INGRESE UNA OPCION VALIDA ";
        }
    }while(menu != 3);
    return 0;
}

void cargar_numero(){
    int otro;
    int x, y;
    ofstream archivo;
    archivo.open("matriz.txt",ios::out);
    if(archivo.fail()){
        cout<<endl<<"No se pudo abrir el archivo "<<endl;
        exit(1);
    }
    else{
        do{
        
            for (y = 0; y < 2; y++) {
		       for (x = 0; x < 2; x++) {
		       		cout<<"Ingrese el valor de ["<<x<<"]["<< y<<"]:";
		         	cin >> reg.distances[x][y];
		         	//archivo<<reg.distances[x][y]<<endl;
		       }
		     }
            archivo<<reg.distances[x][y]<<endl;
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
    archivo.open("matriz.txt",ios::in);
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
    archivo.open("matriz.txt",ios::in);
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
