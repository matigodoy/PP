// Se tiene un archivo con la siguiente información en cada registro: Legajo del alumno, altura y peso. Determinar cuál es el peso máximo y el mínimo, la altura máxima y la mínima, cuantos alumnos tienen altura menor a 140 cm., cuántos entre 140 y 180 cm., y cuantos en más de 180 cm. Desarrolle antes un programa para crear y cargar el archivo.

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct registro{
    int altura;
    float peso;
    long int legajo;
}reg;

void carga();
void mostrar_alumnos();
void mostrar_peso();
void mostrar_altura();
void mostrar_altura_segun_medidas();

int main(){
    int menu;
    do{
        cout<<"MENU DE OPCIONES "<<endl;
        cout<<"1. CARGAR LOS ALUMNOS "<<endl;
        cout<<"2. MOSTRAR ALUMNOS CARGADOS "<<endl;
        cout<<"3. MOSTRAR PESO MAXIMO Y MINIMO "<<endl;
        cout<<"4. MOSTRAR ALTURA MAXIMA Y MINIMA "<<endl;
        cout<<"5. MOSTRAR ALUMNOS SEGUN LA ALTURA "<<endl;
        cout<<"6. SALIR "<<endl;
        cout<<"Ingrese opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
                carga();
                break;
            case 2:
                mostrar_alumnos();
                break;
            case 3:
                mostrar_peso();
                break;
            case 4:
                mostrar_altura();
                break;
            case 5:
                mostrar_altura_segun_medidas();
                break;
            case 6:
                return 0;
                
            default: cout<<"Ingrese una opcion valida "<<endl;
        }
    }while(menu!=6);
    
    return 0;
}

void carga(){
    int otro, i=1;
    FILE *m;
    m = fopen("actividad8.dat","wb");
    if (m == NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        do{
            cout<<"Alumno numero "<<i++<<endl;
            cout<<"Ingrese el legajo: ";
            cin>>reg.legajo;
            cout<<"Ingrese la altura (en cm): ";
            cin>>reg.altura;
            cout<<"Ingrese el peso: ";
            cin>>reg.peso;
            fwrite(&reg,sizeof(registro),1,m);
            cout<<endl;
            do{
                cout<<"Quiere cargar otro alumno? (1. para si - 0. para no): ";
                cin>>otro;
                if(otro>1 || otro<0)cout<<"Se pide 1 o 0 "<<endl;
            }while(otro>1 || otro<0);
            cout<<endl;
        }while(otro!=0);
    }
    fclose(m);
    return;
}

void mostrar_alumnos(){
    int i=1;
    FILE *m;
    m = fopen("actividad8.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        cout<<"Los alumnos cargados son: "<<endl<<endl;
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
            cout<<"Alumno numero "<<i++<<endl;
            cout<<"Legajo: "<<reg.legajo<<endl;
            cout<<"Altura: "<<reg.altura<<" cm "<<endl;
            cout<<"Peso: "<<reg.peso<<" kg "<<endl;
            fread(&reg, sizeof (registro), 1, m);
            cout<<endl;
        }
        fclose(m);
    }
    cout<<endl<<endl;
}


void mostrar_peso(){
    float pesomaximo=0, pesominimo=999;
    FILE *m;
    m = fopen("actividad8.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
            if(pesomaximo<reg.peso)pesomaximo=reg.peso;
            if(pesominimo>reg.peso)pesominimo=reg.peso;
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        cout<<"El peso minimo es: "<<pesomaximo<<" kg"<<endl;
        cout<<"El peso maxima es: "<<pesominimo<<" kg"<<endl;
    }
    cout<<endl<<endl;
}

void mostrar_altura(){
    int alturamaxima=0, alturaminima=999;
    FILE *m;
    m = fopen("actividad8.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
            if(alturamaxima<reg.altura)alturamaxima=reg.altura;
            if(alturaminima>reg.altura)alturaminima=reg.altura;
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        cout<<"La altura maxima es: "<<alturamaxima<<" cm"<<endl;
        cout<<"La altura minima es: "<<alturaminima<<" cm"<<endl;
    }
    cout<<endl<<endl;
}

void mostrar_altura_segun_medidas(){
    int menor140=0, entre140_180=0, mayor180=0;
    FILE *m;
    m = fopen("actividad8.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
            if(reg.altura<140)menor140++;
            if(reg.altura>=140 && reg.altura<=180)entre140_180++;
            if(reg.altura>180)mayor180++;
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        cout<<"La cantidad de alumnos con una altura menor a 140 cm: "<<menor140<<endl;
        cout<<"La cantidad de alumnos con una altura entre 140 cm y 180 cm: "<<entre140_180<<endl;
        cout<<"La cantidad de alumnos con una altura mayor a 180 cm: "<<mayor180<<endl;
    }
    cout<<endl<<endl;
}
