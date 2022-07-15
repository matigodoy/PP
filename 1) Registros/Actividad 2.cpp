#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

struct horaUsual{
    int hora, minutos;
    bool periodo;
};

int leer_horaUsual();
int leer_minutosUsual();
bool leer_periodo();
string mostrarHoraUsual(int hora, int minuto , bool periodo);
//string mostrarHoraUsual2(struct horaUsual horausual);
int leer_horaMilitar();
int convertirUsual_Militar(int horausual, int minutos, bool periodo);
//struct horaUsual convertirMilitar_Usual(int horamilitar);
string convertirMilitar_Usual2( int horamilitar, string hsNueva, string minNueva, bool perNuevo );

int main()
{
    int opcion;
    int horaMilitar;
    struct horaUsual hu, hnueva;
    string hora;
    string minN , horaN;
    bool perN;
    
    do{
        cout<<"         CONVERTIR HORA MILITAR "<<endl;
        cout<<"1. Cargar hora formato USUAL"<<endl;
        cout<<"2. Cargar hora formato MILITAR"<<endl;
        cout<<"3. Convertir hora usual a militar"<<endl;
        cout<<"4. Convertir hora militar a usual"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Ingrese un numero de opcion: "<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
                hu.hora= leer_horaUsual();
                hu.minutos= leer_minutosUsual();
                hu.periodo= leer_periodo();
                cout<<"La hora es usual: "<<mostrarHoraUsual(hu.hora, hu.minutos,hu.periodo);
                break;
                
            case 2:
                horaMilitar = leer_horaMilitar();
                cout<<"La hora militar: "<<horaMilitar;
                break;
                
            case 3:
                horaMilitar = convertirUsual_Militar(hu.hora, hu.minutos,hu.periodo);
                cout<<"La hora convertida es: "<<horaMilitar;
                break;
                
            case 4:
                hora =convertirMilitar_Usual2(horaMilitar,horaN,minN,perN);
                cout<<"La hora usual es: "<<hora;
                break;
        }
    }
    while ( opcion != 7 );
    
    system("pause");
    return 0;
}

int leer_horaUsual(){
    int c;
    do{
        cout<< "Cantidad de horas a (mayor a 0 y menor o igual 12): ";
        cin >> c;
        if(c<=0 || c>12)cout<<"Se pedia mayor a cero "<<endl;
    }
    while(c<=0 || c>12);
    
    return c;
}

int leer_minutosUsual(){
    int c;
    do{
        cout<<"Cantidad de minutos (mayor a 0 y menor o igual 59): ";
        cin>>c;
        if(c<=0 || c>59)cout<<"Se pedia mayor a cero "<<endl;
    }
    while(c<=0 || c>59);
    
    return c;
}

bool leer_periodo(){
    int c;
    do{
        cout<<"Ingrese periodo ( 0 - AM o 1 - PM): ";
        cin>>c;
        if(c<0 || c>1)cout << "Se pedia mayor a cero... " << endl;
    }
    while (c<0 || c>1);
    
    if(c==0){
        return true;
    }
    if(c==1){
        return false;
    }
}

string mostrarHoraUsual(int hora, int minuto , bool periodo){
    
    string per="";
    if(periodo == true) per = "AM";
    else per="PM";
    
    std::string h = static_cast<std::ostringstream*>(&(std::ostringstream() << hora))->str();
    std::string m = static_cast<std::ostringstream*>(&(std::ostringstream() << minuto))->str();
    
    return h+":"+m+" "+per;
}

int leer_horaMilitar(){
    int c;
    do{
        cout<< "Cantidad de horas a (mayor a 0 y menor o igual 2359): ";
        cin>>c;
        
        if(c <= 0 || c >2359) cout << "Se pedia mayor a cero o igual a 2359 " << endl;
    }
    while (c <= 0 || c >2359);
    
    return c;
}

int convertirUsual_Militar(int horausual, int minutos, bool periodo ){
    int hmilitar=0;
    
    if(periodo == true){
        hmilitar= horausual*100 +minutos;
    }
    else if(periodo==false){
        hmilitar= (horausual+12)*100+minutos;
    }
    
    return hmilitar;
}

struct horaUsual convertirMilitar_Usual(int horamilitar){
    struct horaUsual nuevaHora;
    if (horamilitar<1159){
        nuevaHora.periodo= true;
    }
    else{
        nuevaHora.periodo=false;
        horamilitar=horamilitar-1200;
    }
    nuevaHora.hora= horamilitar/100;
    nuevaHora.minutos = 00;
    
    return nuevaHora;
}

string convertirMilitar_Usual2( int horamilitar, string hsNueva, string minNueva, bool perNuevo ){
    string per="";
    if (horamilitar<1159){
        perNuevo= true;
    }
    else{
        perNuevo=false;
        horamilitar=horamilitar-1200;
    }
    
    std::string hm = static_cast<std::ostringstream*>(&(std::ostringstream() << horamilitar))->str();
    if(hm.size()>3){
        hsNueva = hm.substr(0,2);
        minNueva = hm.substr(2,4);
    }else{
        hsNueva = hm.substr(0,1);
        minNueva = hm.substr(1,3);
    }
    if(perNuevo == true) per="AM";
    else per="PM";
    
    return hsNueva+":"+minNueva+" "+per;
}
