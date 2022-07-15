#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

struct camiones{
    int numcamion, destino, carga;
    float importe;
};

void leer_envios(camiones v[100],int cant);
void mostrar_envios(camiones v[100],int cant);
void importe_total(camiones v[100],int cant);
void porcentaje_tipo_carga(camiones v[100],int cant);
void cant_envios_camiones(camiones v[100],int cant);
void importe_destino5(camiones v[100],int cant);

int main(){
    camiones v[100];
    int menu,cant=0;
    
    do{
        do{
            cout<<endl<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"                       ENVIOS "<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"1) Ingresar datos de los envios"<<endl;
            cout<<"2) Mostrar envios cargados "<<endl;
            cout<<"3) Ver importe total obtenido por los envios "<<endl;
            cout<<"4) Ver porcentaje de cada tipo de carga "<<endl;
            cout<<"5) Ver cantidad de envios por camion "<<endl;
            cout<<"6) Ver importe de envios al destino 5 "<<endl;
            cout<<"7) Salir "<<endl;
            cout<<"Ingrese una opcion : ";
            cin>>menu;
            if(menu<1 || menu>7)cout<<"No es una opcion valida "<<endl;
        }while(menu<1 || menu>7);
        
        if(menu==1){
            cout<<"Ingrese la cantidad de envios a cargar ";
            cin>>cant;
            cout<<endl<<endl;
            leer_envios(v,cant);
        }
        
        if(menu==2){
            mostrar_envios(v,cant);
        }
        
        if(menu==3){
            importe_total(v,cant);
        }
        
        if(menu==4){
            porcentaje_tipo_carga(v,cant);
        }
        
        if(menu==5){
            cant_envios_camiones(v,cant);
        }
        
        if(menu==6){
            importe_destino5(v,cant);
        }
    }
    while (menu!=7);
    
    system("pause");
    return 0;
}

void leer_envios(camiones v[100],int cant){
    for(int i=0;i<cant;i++){
        cout<<"Ingrese los datos del envio "<<i+1<<endl<<endl;;
        
        do{
            cout<<"Numero de camion (mayor a 0 y menor o igual a 20): ";
            cin>>(v[i].numcamion);
            if(v[i].numcamion<=0 || v[i].numcamion>20)cout<<"La cantidad debe ser mayor a cero y menor o igual a 20 "<<endl;
        }while(v[i].numcamion<=0 || v[i].numcamion>20);
        
        do{
            cout<<"Codigo del destino (codigo del 0 al 19): ";
            cin>>(v[i].destino);
            if(v[i].destino<0 || v[i].destino>19)cout<<"La cantidad debe ser mayor o igual a cero y menor o igual a 19 "<<endl;
        }while(v[i].destino<0 || v[i].destino>19);
        
            cout<<"Importe por el envio: $";
            cin>>v[i].importe;
        
        do{
            cout<<"Tipo de carga (1. para ‘a’ - 2. para ‘b’ - 3. para ‘c’) ";
            cin>>v[i].carga;
            if(v[i].carga<=0 || v[i].carga>3)cout<<"Solo se permite el ingreso de 1 - 2 - 3 "<<endl;
        }while(v[i].carga<=0 || v[i].carga>3);
        
        cout<<endl;
    }
}

void mostrar_envios(camiones v[100],int cant){
    if(cant==0)cout<<"No se han ingresado envios "<<endl;
    else{
        cout<<endl<<"Los envios ingresados son: "<<endl;
        for(int i=0;i<cant;i++){
            cout<<"ENVIO Nro "<<i+1<<endl;
            cout<<"Numero de camion: "<<v[i].numcamion<<endl;
            
            cout<<"Codigo del destino: "<<v[i].destino<<endl;
            
            cout<<"Importe por el envio: $"<<v[i].importe<<endl;
            
            if(v[i].carga==1)cout<<"Tipo de carga a"<<endl;
            if(v[i].carga==2)cout<<"Tipo de carga b"<<endl;
            if(v[i].carga==3)cout<<"Tipo de carga c"<<endl;
            
            cout<<endl;
        }
    }
}

void importe_total(camiones v[100],int cant){
    if(cant==0)cout<<"No se han ingresado envios "<<endl;
    else{
        float importetotal=0;
        for(int i=0;i<cant;i++){
            importetotal=importetotal + v[i].importe;
        }
    
        cout<<"El importe total obtenido por todos los envios es: $"<<importetotal<<endl;
    }
}

void porcentaje_tipo_carga(camiones v[100],int cant){
    if(cant==0)cout<<"No se han ingresado envios "<<endl;
    else{
        int totala=0,totalb=0,totalc=0,total=0;
        for(int i=0;i<cant;i++){
            if(v[i].carga==1){
                totala++;
                total++;
            }
            if(v[i].carga==2){
                totalb++;
                total++;
            }
            if(v[i].carga==3){
                totalc++;
                total++;
            }
        }
    
        cout<<"Porcentaje de envios en tipo de carga 'a': %"<<(totala*100)/total<<endl;
        cout<<"Porcentaje de envios en tipo de carga 'b': %"<<(totalb*100)/total<<endl;
        cout<<"Porcentaje de envios en tipo de carga 'c': %"<<(totalc*100)/total<<endl;
    }
}

void cant_envios_camiones(camiones v[100],int cant){
    if(cant==0)cout<<"No se han ingresado envios "<<endl;
    else{
        int cam[20],j=00;
        for(int i=0;i<20;i++){
            cam[i]=0;
        }
        for(int i=1;i<cant+1;i++){
            j=(v[i].numcamion);
            cam[j]=cam[j]+1;
        }
    
        for(int i=0;i<20;i++){
            cout<<"La cantidad de envios que hizo el camion numero "<<i+1<<" fue: "<<cam[i]<<endl;
        }
        return;
    }
}

void importe_destino5(camiones v[100],int cant){
    if(cant==0)cout<<"No se han ingresado envios "<<endl;
    else{
        float importedestino5=0;
        for(int i=0;i<cant;i++){
            if(v[i].destino==5){
                importedestino5=importedestino5+v[i].importe;
            }
        }
        cout<<"El importe total obtenido de envios en el destino numero 5 fue: $"<<importedestino5<<endl;
    }
}
