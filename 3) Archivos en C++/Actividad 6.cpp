#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct registro{
    int cod;
    long int val;
}reg;

void carga();
void mostrar();
void prom_chicos();
void prom_medianos();
void prom_grandes();
void prom_total();

int main(){
    int menu;
    do{
        cout<<" MENU DE OPCIONES "<<endl;
        cout<<"1. CARGAR LOS AUTOS "<<endl;
        cout<<"2. MOSTRAR TODOS LOS AUTOS CARGADOS "<<endl;
        cout<<"3. MOSTRAR PROMEDIO DE LOS VALORES DE LOS AUTOS CHICOS "<<endl;
        cout<<"4. MOSTRAR PROMEDIO DE LOS VALORES DE LOS AUTOS MEDIANOS "<<endl;
        cout<<"5. MOSTRAR PROMEDIO DE LOS VALORES DE LOS AUTOS GRANDES "<<endl;
        cout<<"6. MOSTRAR PROMEDIO TOTAL DE LOS VALORES DE LOS AUTOS "<<endl;
        cout<<"7. SALIR "<<endl;
        cout<<"Ingrese opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
                carga();
                break;
            case 2:
                mostrar();
            case 3:
                prom_chicos();
                break;
            case 4:
                prom_medianos();
                break;
            case 5:
                prom_grandes();
                break;
            case 6:
                prom_total();
                break;
            case 7:
                return 0;
                
            default: cout<<"Ingrese una opcion valida "<<endl;
        }
    }while(menu!=7);
    
    return 0;
}

void carga(){
    int otro, i=1;
    ofstream archivo;
    archivo.open("actividad6.dat",ios::out);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        do{
            cout<<"Auto numero "<<i++<<endl;
            cout<<"Ingrese el codigo (entre 1 y 20 para chico - entre 1 y 50 para mediano - mayor a 50 para grande): ";
            cin>>reg.cod;
            archivo<<reg.cod<<endl;
            cout<<"Ingrese el valor: $";
            cin>>reg.val;
            archivo<<reg.val<<endl;
            cout<<endl;
            do{
                cout<<"Quiere cargar otro auto? (1. para si - 0. para no): ";
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
    archivo.open("actividad6.dat",ios::in);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
    	int codigo;
   		long int valor;
        while(!archivo.eof()){
        	archivo>>codigo>>valor;
        	if(!archivo.eof()){
        		cout<<"Auto numero "<<i++<<endl;
            	cout<<"Codigo: "<<codigo<<endl;
            	cout<<"Valor: $"<<valor<<endl;
            cout<<endl;
			}
        }
        archivo.close();
    }
    cout<<endl<<endl;
}

void prom_chicos(){
    long int totalchico=0;
    int cantchico=0;
    int i=1;
    ifstream archivo;
    archivo.open("actividad6.dat",ios::in);
    if (!archivo.eof()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
    	int codigo;
    	long int valor;
        while(!archivo.eof()){
            if(codigo<=20 && codigo>=1){
                cantchico++;
                totalchico=totalchico+valor;
            }
        }
        archivo.close();
        cout<<"El valor promedio de los autos de la categoria chicos es: $"<<totalchico/cantchico<<endl;
    }
    cout<<endl<<endl;
}

void prom_medianos(){
    long int totalmediano=0;
    int cantmediano=0;
    ifstream archivo;
    archivo.open("actividad6.dat",ios::in);
    if (!archivo.eof()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
    	int codigo;
    	long int valor;
        while(!archivo.eof()){
            if(codigo<=50 && codigo>=1){
                cantmediano++;
                totalmediano=totalmediano+valor;
            }
        }
        archivo.close();
        cout<<"El valor promedio de los autos de la categoria medianos es: $"<<totalmediano/cantmediano<<endl;
    }
    cout<<endl<<endl;
}

void prom_grandes(){
    long int totalgrande=0;
    int cantgrande=0;
    ifstream archivo;
    archivo.open("actividad6.dat",ios::in);
    if (!archivo.eof()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
    	int codigo;
    	long int valor;
        while(!archivo.eof()){
            if(codigo>50){
                cantgrande++;
                totalgrande=totalgrande+reg.val;
            }
        }
        archivo.close();
        cout<<"El valor promedio de los autos de la categoria grandes es: $"<<totalgrande/cantgrande<<endl;
    }
    cout<<endl<<endl;
}

void prom_total(){
    long int total=0;
    int cant=0;
    ifstream archivo;
    archivo.open("actividad6.dat",ios::in);
    if (!archivo.eof()){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
    	int codigo;
    	long int valor;
        while(!archivo.eof()){
            cant++;
            total=total+valor;
        }
        archivo.close();
        cout<<"El valor promedio total de los autos es: $"<<total/cant<<endl;
    }
    cout<<endl<<endl;
}
