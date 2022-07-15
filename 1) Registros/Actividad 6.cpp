#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

struct pacientes{
    char nombre[30], direccion[50], telefono[20], fecha[10];
    int alegias, obrasocial;
};

bool leer_obrasocial();
bool leer_alergias();
void leer_datos(pacientes v[50],int cant);
void mostrar_datos_paciente(pacientes v[50],int cant);
void mostrar_ultima_visita(pacientes v[50], int cant);
void mostrar_pacientes_alergia(pacientes v[50], int cant);
void mostrar_obrasocial(pacientes v[50],int cant);

int main(){
    pacientes v[50];
    int menu,cant=0;
    
    do{
        do{
            cout<<"_________________________________________________"<<endl;
            cout<<"                 DATOS DE PACIENTES "<<endl;
            cout<<"-------------------------------------------------"<<endl<<endl;
            cout<<"1) CARGAR DATO DEL PACIENTE "<<endl;
            cout<<"2) VER DATOS DE LOS PACIENTES "<<endl;
            cout<<"3) VER ULTIMA VISITA DE UN PACIENTE "<<endl;
            cout<<"4) NOMBRE Y TELEFONO DE PACIENTES CON ALERGIA "<<endl;
            cout<<"5) PACIENTES CON OBRA SOCIAL "<<endl;
            cout<<"6) Salir "<<endl;
            cout<<"Ingrese alguna opcion: ";
            cin>>menu;
            if(menu<1 || menu>6)cout<<"No es una opcion valida "<<endl;
        }while(menu<1 || menu>6);
        
        if(menu==1){
            do{
                cout<<"Ingrese la cantidad de pacientes a cargar (que sea mayor a 0 y menor a 50) "<<endl;
                cin>>cant;
                if(cant<=0||cant>50)cout<<"Se pedia mayor a 0 y menor a 50 "<<endl;
            }while(cant<=0||cant>50);
            
            leer_datos(v,cant);
        }
        
        if(menu==2){
            mostrar_datos_paciente(v, cant);
        }
        
        if(menu==3){
            mostrar_ultima_visita(v, cant);
        }
        
        if(menu==4){
            mostrar_pacientes_alergia(v,cant);
        }
        
        if(menu==5){
            mostrar_obrasocial(v,cant);
        }
    }
    while ( menu != 6 );
    
    system("pause");
    return 0;
}

bool leer_obrasocial(){
    int cargar;
    do{
        cout<< "El paciente tiene obra social? (0 para no / 1 para si): ";
        cin >> cargar;
        if(cargar < 0 || cargar > 1) cout << "No es un numero valido, solo el 0 y el 1" << endl;
    }while (cargar < 0 || cargar > 1);
    
    if(cargar==1) return true;
    
    return false;
}

bool leer_alergias(){
    int cargar;
    do{
        cout<< "Tiene alergia? (0: no - 1: si): ";
        cin >> cargar;
        if(cargar < 0 || cargar > 1) cout << "Se pedia 0(por no) o 1(por sÌ)... " << endl;
    }
    while (cargar < 0 || cargar > 1);
    
    if(cargar == 1) return true;
    
    return false;
}

void leer_datos(pacientes v[50], int cant){
    for(int i=0;i<cant;i++){
        cout<<"Ingrese el nombre del paciente "<<i+1;
        cin>>v[i].nombre;
        
        fflush(stdin);
        cout<<"Ingrese la direccion del paciente "<<i+1;
        cin>>v[i].direccion;
        
        fflush(stdin);
        cout<<"Ingrese el telefono del paciente "<<i+1;
        cin>>v[i].telefono;
        
        fflush(stdin);
        cout<<"Ingrese la utima fecha de visita del paciente "<<i+1;
        cin>>v[i].fecha;
        
        v[i].obrasocial=leer_obrasocial();
        
        v[i].alegias=leer_alergias();
        
        cout<<endl;
    }
}

void mostrar_datos_paciente(pacientes v[50],int cant){
    if(cant==0)cout<<"No hay pacientes cargados "<<endl;
    else{
        int c;
        do{
            cout<<"Ingrese el numero del paciente a consultar (entre 1 y "<<cant<<"): ";
            cin>>c;
            if(c<1 || c>cant){
                cout<< "Se pedia entre 0 y "<<cant<< endl;
            }
        }
        while (c<1 || c>cant);
    
        cout<<"LOS DATOS DEL PACIENTE ELEJIDO SON: "<<endl;
        cout<<"Nombre: "<<v[c].nombre<<endl;
        cout<<"Direccion: "<<v[c].direccion<<endl;
        cout<<"Telefono: "<<v[c].telefono<<endl;
        cout<<"Ultima visita: "<<v[c].fecha<<endl;
    
        if(v[c].obrasocial==true){
            cout<<"Si tiene obra social "<<endl;
        }
        if(v[c].obrasocial==false){
            cout<<"No tiene obra social "<<endl;
        }
    
        if(v[c].alegias==true){
            cout<<"Si tiene alergias "<<endl;
        }
        if(v[c].alegias==false){
            cout<<"No tiene alergias "<<endl;
        }
    }
}

void mostrar_ultima_visita(pacientes v[50],int cant){
    if(cant==0)cout<<"No hay pacientes cargados "<<endl;
    else{
        char ultvista[30];
        int a=99;
        cout<<"Ingrese el nombre del paciente para ver su ultima visita ";
        cin>>ultvista;
        
        for(int i=0;i<cant;i++){
            if(ultvista==v[i].nombre){
                a=i;
            }
        }
        cout<<"La ultima fecha de visita del paciente dado es: "<<v[a].fecha<<endl;
        if(a==99){
            cout<<"El nombre ingresado no corresponde a un paciente "<<endl;
        }
    }
}

void mostrar_pacientes_alergia(pacientes v[50], int cant){
    if(cant==0)cout<<"No hay pacientes cargados "<<endl;
    else{
        cout<<"Los pacientes con alergia son: "<<endl;
        for(int i=0;i<cant;i++){
            if(v[i].alegias==true){
                cout<<"Nombre: "<<v[i].nombre<<endl;
                cout<<"Telefono: "<<v[i].telefono<<endl;
            }
        }
    }
}

void mostrar_obrasocial(pacientes v[50],int cant){
    if(cant==0)cout<<"No hay pacientes cargados "<<endl;
    else{
        cout<<"Los pacientes con obra social son: "<<endl;
        for(int i=0;i<cant;i++){
            if(v[i].obrasocial==true){
                cout<<"Nombre: "<<v[i].nombre<<endl;
            }
        }
    }
}
