#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

struct personas{
    int edad;
    float altura;
    char nombre[50],sexo[10];
};

struct personas v1[100],aux;

void leer_datos(personas v1[100],int cant);
void mostrar_datos(personas v1[100],int cant);
void ordenar_datos(personas v1[100],int cant);

int main(){
    int cant=0,menu;
    do{
        do{
            cout<<"____________________________________________"<<endl;
            cout<<"             REGISTRO DE PERSONAS "<<endl;;
            cout<<"--------------------------------------------"<<endl;
            cout<<"1) REGISTRAR PERSONAS "<<endl;
            cout<<"2) MOSTRAR DATOS DE LAS PERSONA "<<endl;
            cout<<"3) MOSTRAR REGISTRO ORDENADO POR NOMBRE "<<endl;
            cout<<"4) SALIR "<<endl;
            cout<<"INGRESE UNA OPCION: "<<endl;
            cin>>menu;
            if(menu<1 || menu>4)cout<<"NO ES UNA OPCION VALIDA "<<endl;
        }while(menu<1 || menu>4);

        
        switch(menu){
            case 1:
                cout<<"CANTIDAD DE PERSONAS A REGISTRAR: ";
                cin>>cant;
                leer_datos(v1,cant);
                break;
                
            case 2: mostrar_datos(v1,cant);
                break;
                
            case 3: ordenar_datos(v1,cant);
                break;
                
            case 4: return 0;
        }
    }
    while(menu!=4);
    
    system("pause");
    return 0;
}

void leer_datos(personas v1[100],int cant){
    for(int i=0;i<cant;i++){
        cout<<"INGRESE LOS DATOS DE PERSONA Nro."<<i+1<<endl;;
        
        cout<<"NOMBRE: ";
        cin>>v1[i].nombre;
        
        cout<<"SEXO: ";
        cin>>v1[i].sexo;
        
        cout<<"EDAD: ";
        cin>>v1[i].edad;
        
        cout<<"ALTURA: ";
        cin>>v1[i].altura;
        
        cout<<endl;
    }
}

void mostrar_datos(personas v1[100],int cant){
    if(cant==0){
        cout<<"NO HAY PERSONAS REGISTRADOS "<<endl;;
    }
    else{
        cout<<endl<<endl;
        for(int i=0;i<cant;i++){
            cout<<"DATOS DE LA PERSONA Nro "<<i+1<<" : "<<endl;
            cout<<"NOMBRE: "<<v1[i].nombre<<endl;
            cout<<"SEXO: "<<v1[i].sexo<<endl;
            cout<<"EDAD: "<<v1[i].edad<<endl;
            cout<<"ALTURA: "<<v1[i].altura<<endl;
            cout<<endl;
        }
    }
}

void ordenar_datos(personas v1[100],int cant){
    if(cant==0){
        cout<<"NO HAY PERSONAS REGISTRADOS "<<endl;;
    }
    else{
        int i,j,bandera;
        int temp;
    
        for(i=1;i<cant;i++){
            bandera=0;
            for(j=cant-1; j>=i; j--){
                temp=strcmp(v1[j-1].nombre,v1[j].nombre);
                if(temp>0){
                    aux=v1[j];
                    v1[j]=v1[j-1];
                    v1[j-1]=aux;
                    bandera=1;
                }
            }
            if (bandera==0)
                break;
        }
        cout<<endl<<endl;
        cout<<"LOS DATOS DE LAS PERSONAS ORDENADAS ALFABETICAMENTE SON: "<<endl;
        mostrar_datos(v1,cant);
    }
}
