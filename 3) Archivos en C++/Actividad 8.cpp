#include <fstream>
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
    ofstream archivo;
    archivo.open("actividad8.dat",ios::out);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        do{
            cout<<"Alumno numero "<<i++<<endl;
            cout<<"Ingrese el legajo: ";
            cin>>reg.legajo;
            archivo<<reg.legajo<<endl;
            cout<<"Ingrese la altura (en cm): ";
            cin>>reg.altura;
            archivo<<reg.altura<<endl;
            cout<<"Ingrese el peso: ";
            cin>>reg.peso;
            archivo<<reg.peso<<endl;
            cout<<endl;
            do{
                cout<<"Quiere cargar otro alumno? (1. para si - 0. para no): ";
                cin>>otro;
                if(otro>1 || otro<0)cout<<"Se pide 1 o 0 "<<endl;
            }while(otro>1 || otro<0);
            cout<<endl;
        }while(otro!=0);
    }
    archivo.close();
    return;
}

void mostrar_alumnos(){
	
    int i=1;
    ifstream archivo;
    archivo.open("actividad8.dat",ios::in);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
    int alt=0;
    float pes=0.0;
    long int leg=0;
        cout<<"Los alumnos cargados son: "<<endl<<endl;
        while(!archivo.eof()){
        	archivo>>leg>>alt>>pes;
        	if (!archivo.eof()){
        	cout<<"Alumno numero "<<i++<<endl;
            cout<<"Legajo: "<<leg<<endl;
            cout<<"Altura: "<<alt<<" cm "<<endl;
            cout<<"Peso: "<<pes<<" kg "<<endl;
		}
            cout<<endl;
        }
        archivo.close();
    }
    cout<<endl<<endl;
}


void mostrar_peso(){
	
    float pesomaximo=0, pesominimo=999;
    ifstream archivo;
    archivo.open("actividad8.dat",ios::in);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
    	    int alt=0;
    float pes=0.0;
    long int leg=0;
        while(!archivo.eof()){
        	archivo>>leg>>alt>>pes;
        	if(!archivo.eof()){
        		if(pesomaximo<pes)pesomaximo=pes;
           		if(pesominimo>pes)pesominimo=pes;
			}
        }
        archivo.close();
        cout<<"El peso minimo es: "<<pesomaximo<<" kg"<<endl;
        cout<<"El peso maxima es: "<<pesominimo<<" kg"<<endl;
    }
    cout<<endl<<endl;
}

void mostrar_altura(){
    int alturamaxima=0, alturaminima=999;
    ifstream archivo;
    archivo.open("actividad8.dat",ios::in);
    if (!archivo.eof()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
    int alt=0;
    float pes=0.0;
    long int leg=0;
        while(!archivo.eof()){
        	archivo>>leg>>alt>>pes;
        	if(!archivo.eof()){
                if(alturamaxima<alt)alturamaxima=alt;
            	if(alturaminima>alt)alturaminima=alt;
			}		
        }
        archivo.close();
        cout<<"La altura maxima es: "<<alturamaxima<<" cm"<<endl;
        cout<<"La altura minima es: "<<alturaminima<<" cm"<<endl;
    }
    cout<<endl<<endl;
}

void mostrar_altura_segun_medidas(){
    int menor140=0, entre140_180=0, mayor180=0;
    ifstream archivo;
    archivo.open("actividad8.dat",ios::in);
    int alt=0;
    float pes=0.0;
    long int leg=0;
    if (!archivo.eof()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        while(!archivo.eof()){
        	archivo>>leg>>alt>>pes;
        	if(!archivo.eof()){
           		if(alt<140)menor140++;
            	if(alt>=140 && alt<=180)entre140_180++;
            	if(alt>180)mayor180++;        		
			}
        }
        archivo.close();
        cout<<"La cantidad de alumnos con una altura menor a 140 cm: "<<menor140<<endl;
        cout<<"La cantidad de alumnos con una altura entre 140 cm y 180 cm: "<<entre140_180<<endl;
        cout<<"La cantidad de alumnos con una altura mayor a 180 cm: "<<mayor180<<endl;
    }
    cout<<endl<<endl;
}
