#include <iostream>
using namespace std;
#include <ctime>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void hora();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

struct alumnos{
	char nombre[50];
	char apellido[50];
	long int dni;
	long int legajo;
	int cant;
}alum;
int main() {
	hora();
	}
void hora(){
	char* dS[7] = {"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};
	time_t tSac = time(NULL); // instante actual
	struct tm* tmP = localtime(&tSac);
	int hora,minutos,dia,mes,anio;
	char* nombre_dia[20];
	hora=tmP->tm_hour;minutos=tmP->tm_min;  // HORA
	dia=tmP->tm_mday+1;mes=tmP->tm_mon+1;anio=tmP->tm_year+1900; // FECHA
	nombre_dia[20]=dS[tmP->tm_wday+1];  // DIA DE SEMANA
	
	int seguridad=0, continuar=0;
	system("cls");
	FILE *m;
	FILE *n;
    m = fopen("alumnos.dat","rb");
    n = fopen("temp.dat","wb");
    if (m== NULL || n== NULL){
    	fclose(m);
    	fclose(n);
    	remove("temp.dat");
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay aulas registradas "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        return;
    }
    else{
    		   			SetConsoleTextAttribute(hConsole, 12);
				cout<<endl<<endl<<"\tReservado hasta"<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
				cout << "Hora: " << hora << ":" << minutos << endl;
				cout << "Fecha: " << dia << "-" << mes << "-"<< anio << endl;
				cout << "Dia de semana: " << nombre_dia[20] << endl;
    			seguridad=1;
    	    			do{
	    			cout<<endl<<"\tQuieres reservar? (1. para si - 0. para no): ";
	                cin>>continuar;
	                if(continuar<0 || continuar>1)cout<<"\tSe pide 1 o 0 "<<endl;
	            }while(continuar<0 || continuar>1);
    	
    	
    	/////////////////////////////////////////////////////////////////////
    	fread(&alum, sizeof (alumnos), 1, m);
    	while(feof(m)==0){
    			if(continuar==1){
    				system("cls");
					alum.reservado=1;
		        	alum.reservado_hora=tmP->tm_hour;
					alum.reservado_minutos=tmP->tm_min; 
					alum.reservado_dia=tmP->tm_mday+1;
					alum.reservado_mes=tmP->tm_mon+1;
					alum.reservado_anio=tmP->tm_year+1900; 
					alum.reservado_nombre_dia[20]=nombre_dia[20];
		    		seguridad1=1;
					fwrite(&alum,sizeof(alumnos),1,n);
				}
				if(continuar==0){
					fclose(m);
    				fclose(n);
    				remove("temp.dat");
    				return;
				}
			fread(&alum, sizeof (alumnos), 1, m);
		}
    }
    fclose(m);
    fclose(n);
    if(continuar==1){
	    remove("alumnos.dat");
	    rename("temp.dat","alumnos.dat");
	}
    if(seguridad==0){
    	cout<<endl<<endl<<"\tEl DNI ingresado no corresponde a ningun alumno "<<endl<<endl;
    	escape();
	}
}

