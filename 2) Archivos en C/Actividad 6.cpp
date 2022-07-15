// En un archivo se tienen registros con los datos correspondientes a los precios de autos nuevos en el mercado. Cada registro contiene dos campos: Cod (código del auto) y Val (es el precio del auto). Los códigos de los autos chicos están entre 1 y 20, los de los medianos entre 1 y 50; y los de los grandes son superiores a 50. Se desea saber el precio promedio para cada una de las categorías mencionadas, y el precio promedio general. Desarrolle antes un programa para crear y cargar el archivo​.

#include <stdio.h>
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
    int otro, i=0;
    FILE *m;
    m = fopen("actividad6.dat","wb");
    if (m == NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        do{
            i++;
            cout<<"Auto numero "<<i<<endl;
            cout<<"Ingrese el codigo (entre 1 y 20 para chico - entre 1 y 50 para mediano - mayor a 50 para grande): ";
            cin>>reg.cod;
            cout<<"Ingrese el valor: $";
            cin>>reg.val;
            fwrite(&reg,sizeof(registro),1,m);
            cout<<endl;
            do{
                cout<<"Quiere cargar otro auto? (1. para si - 0. para no): ";
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
    int i=1;
    FILE *m;
    m = fopen("actividad6.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
            cout<<"Auto numero "<<i++<<endl;
            cout<<"Codigo: "<<reg.cod<<endl;
            cout<<"Valor: $"<<reg.val<<endl;
            fread(&reg, sizeof (registro), 1, m);
            cout<<endl;
        }
        fclose(m);
    }
    cout<<endl<<endl;
}

void prom_chicos(){
    long int totalchico=0;
    int cantchico=0;
    FILE *m;
    m = fopen("actividad6.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
            if(reg.cod<=20 && reg.cod>=1){
                cantchico++;
                totalchico=totalchico+reg.val;
            }
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        cout<<"El valor promedio de los autos de la categoria chicos es: $"<<totalchico/cantchico<<endl;
    }
    cout<<endl<<endl;
}

void prom_medianos(){
    long int totalmediano=0;
    int cantmediano=0;
    FILE *m;
    m = fopen("actividad6.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
            if(reg.cod<=50 && reg.cod>=1){
                cantmediano++;
                totalmediano=totalmediano+reg.val;
            }
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        cout<<"El valor promedio de los autos de la categoria medianos es: $"<<totalmediano/cantmediano<<endl;
    }
    cout<<endl<<endl;
}

void prom_grandes(){
    long int totalgrande=0;
    int cantgrande=0;
    FILE *m;
    m = fopen("actividad6.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
            if(reg.cod>50){
                cantgrande++;
                totalgrande=totalgrande+reg.val;
            }
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        cout<<"El valor promedio de los autos de la categoria grandes es: $"<<totalgrande/cantgrande<<endl;
    }
    cout<<endl<<endl;
}

void prom_total(){
    long int total=0;
    int cant=0;
    FILE *m;
    m = fopen("actividad6.dat","rb");
    if (m== NULL){
        cout<<"Error al abrir el archivo ";
        cout<<"Presione una tecla... ";
        exit(1);
    }
    else{
        fread(&reg, sizeof (registro), 1, m);
        while(feof(m)==0){
            cant++;
            total=total+reg.val;
            fread(&reg, sizeof (registro), 1, m);
        }
        fclose(m);
        cout<<"El valor promedio total de los autos es: $"<<total/cant<<endl;
    }
    cout<<endl<<endl;
}
