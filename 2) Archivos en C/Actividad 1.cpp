// Se desea saber si la cantidad de registros que se leen de un archivo, es inferior o no a cien.
// Informar a través de un mensaje. Desarrolle antes un programa para crear y cargar el archivo.

#include<iostream>
#include<stdio.h>
using namespace std;

struct registro{
    int num;
    int cantnum;
}reg;

int cargar_numero();
void mostrar_mayor_menor_100();

int main(){
    int menu;
    do{
        cout<<"MENU DE OPCIONES "<<endl;
        cout<<"1. CARGAR NUMEROS "<<endl;
        cout<<"2. MOSTRAR SI LA CANTIDAD DE NUMEROS INGRESADOS ES INFERIOR O MAYOR A 100 "<<endl;
        cout<<"3. SALIR"<<endl;
        cout<<"Ingrese opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
                cargar_numero();
                break;
            case 2:
                mostrar_mayor_menor_100();
                break;
            case 3:
                return 0;
                
            default:
                cout<<"INGRESE UNA OPCION VALIDA ";
        }
    }while(menu != 3);
}

int cargar_numero(){
    int otro;
    FILE *m;
    m=fopen("Actividad1.dat","wb");
    if(m==NULL){
        cout<<endl<<"No se pudo abrir el archivo "<<endl;
        exit(1);
    }
    else{
        do{
            cout<<"Ingrese el Numero "<<reg.cantnum<<": "<<endl;
            cin>>reg.num;
            reg.cantnum++;
            fwrite(&reg,sizeof(registro),1,m);
            cout<<endl;
            do{
                cout<<"Quiere cargar otro numero? (1. para si - 0. para no): ";
                cin>>otro;
                if(otro>1 || otro<0)cout<<"Se pide 1 o 0 "<<endl;
            }while(otro>1 || otro<0);
            cout<<endl;
        }while(otro!=0);
    }
    fclose(m);
    return reg.cantnum;
}

void mostrar_mayor_menor_100(){
    FILE *m;
    m = fopen("Actividad1.dat","rb");
    if (m== NULL){
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
        fclose(m);
    }
    cout<<endl<<endl;
}
