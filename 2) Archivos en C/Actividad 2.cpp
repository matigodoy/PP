// En un archivo se tienen varios registros, cada uno con tres campos: un código (cod) y dos números distintos (n1 y n2). Para cada registro, se pide imprimir el código, y el mayor de ambos números. Desarrolle antes un programa para crear y cargar el archivo.

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

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
    FILE *m;
    m = fopen("actividad2.dat","wb");
    if (m == NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        do{
            cout<<"Archivo numero "<<i++<<endl;
            cout<<"Ingrese el codigo: ";
            cin>>reg.cod;
            cout<<"Ingrese el primer numero: ";
            cin>>reg.n1;
            cout<<"Ingrese el segundo numero: ";
            cin>>reg.n2;
            fwrite(&reg,sizeof(registro),1,m);
            cout<<endl;
            do{
                cout<<"Quiere cargar otro archivo? (1. para si - 0. para no): ";
                cin>>otro;
                if(otro>1 || otro<0)cout<<"Se pide 1 o 0 "<<endl;
            }while(otro>1 || otro<0);
            cout<<endl;
        }while(otro!=0);
    }
    fclose(m);
    return;
}

void mostrar(){
    FILE *m;
    m = fopen("actividad2.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
            cout<<"Codigo: "<<reg.cod<<endl;
            if(reg.n1>reg.n2)cout<<"El numero mayor es: "<<reg.n1<<endl;
            if(reg.n2>reg.n1)cout<<"El numero mayor es: "<<reg.n2<<endl;
            if(reg.n1==reg.n2)cout<<"Los dos numero son iguales "<<endl;
            fread(&reg, sizeof (registro), 1, m);
            cout<<endl;
        }
        fclose(m);
    }
    cout<<endl<<endl;
    return;
}
