#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;
struct alumnos{
	char nombre[50], apellido[50];
	long int dni, legajo;
	short int reservado;
	int numero, reservado_hora, reservado_minutos, reservado_dia, reservado_mes, reservado_anio, reservado_numero;
}alum;
struct profesores{
	char nombre[50], apellido[50];
	long int dni;	
	short int reservado;
	int reservado_dni, reservado_hora, reservado_minutos, reservado_dia, reservado_mes, reservado_anio, reservado_numero;
}prof;
struct pers_admin{
	char nombre[50];
	char apellido[50];
	long int dni;
}admin;
struct ingreso{
	char nombre[50];
	char apellido[50];
	long int dni;
}ingr, *puntero_ingr = &ingr;
void iniciar(), iniciar_alum(), iniciar_prof(), iniciar_pers_admin(), registrar(), escape();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main(){
	int menu;
	do{
		system("cls");
		cout<<endl<<endl;
		SetConsoleTextAttribute(hConsole, 9);
		cout<<"\t\t _______      _______.  ______  __    __   _______  __           ___      "<<endl;
		cout<<"\t\t|   ____|    /       | /      ||  |  |  | |   ____||  |         /   \\    "<<endl;
		cout<<"\t\t|  |__      |   (----`|  ,----'|  |  |  | |  |__   |  |        /  ^  \\    "<<endl;
		cout<<"\t\t|   __|      \\   \\    |  |     |  |  |  | |   __|  |  |       /  /_\\  \\   "<<endl;
		cout<<"\t\t|  |____ .----)   |   |  `----.|  `--'  | |  |____ |  `----. /  _____  \\  "<<endl;
		cout<<"\t\t|_______||_______/     \\______| \\______/  |_______||_______|/__/     \\__\\ "<<endl<<endl<<endl;
	    SetConsoleTextAttribute(hConsole, 12);
	    cout<<"\t\t1. INICIAR SESION "<<endl;
	    SetConsoleTextAttribute(hConsole, 7);
	    cout<<"\t\t\t >Iniciar como alumno "<<endl;
	    cout<<"\t\t\t >Iniciar como profesor "<<endl;
	    cout<<"\t\t\t >Iniciar como personal administrativo "<<endl<<endl;
	    SetConsoleTextAttribute(hConsole, 12);
	    cout<<"\t\t2. REGISTRARTE "<<endl;
	    SetConsoleTextAttribute(hConsole, 7);
	    cout<<"\t\t\t >Registrarse como alumno "<<endl;
	    cout<<"\t\t\t >Registrarse como profesor "<<endl;
	    cout<<"\t\t\t >Registrarse como personal administrativo "<<endl<<endl;
	    SetConsoleTextAttribute(hConsole, 12);
	    cout<<"\t\t3. SALIR "<<endl;
	    SetConsoleTextAttribute(hConsole, 7);
	    cout<<endl<<"\t\tIngrese una opcion: ";
	    cin>>menu;
	    cout<<endl<<endl;
	    switch(menu){
	        case 1:
	        	iniciar();
	            break;
	        case 2:
	        	registrar();
				break;
	        case 3:
	            return 0;
	        default:
	        	system("cls");
				cout<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 12);
				cout<<"\tIngrese una opcion valida "<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
				escape();
	    }
	}while(menu!=3);
}
void iniciar(){
	int menu;
    do{
    	system("cls");
    	cout<<endl<<endl;
    	SetConsoleTextAttribute(hConsole, 12);
    	cout<<"\tINICIAR SESION "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Iniciar sesion como alumno "<<endl;
        cout<<"\t2. Iniciar sesion como profesor "<<endl;
        cout<<"\t3. Iniciar sesion como personal administrativo "<<endl<<endl;
        cout<<"\t4. Volver "<<endl<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	iniciar_alum();
                break;
            case 2:
            	iniciar_prof();
                break;
            case 3:
            	iniciar_pers_admin();
                break;
            case 4:
                return;
            default:
            	system("cls");
				SetConsoleTextAttribute(hConsole, 12);
				cout<<endl<<endl<<"\tIngrese una opcion valida "<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
				escape();
        }
    }while(menu!=4);
}
void iniciar_alum(){
	int dnix=0;
	system("cls");
	SetConsoleTextAttribute(hConsole, 12);
	cout<<endl<<endl<<"\tINICIO DE SESION "<<endl<<endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout<<"\tIngrese su DNI: ";
	cin>>dnix;
	FILE *m;
    m = fopen("alumnos.dat","rb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay alumnos registrados "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	int seguridad=0, continuar;
    	fread(&alum, sizeof (alumnos), 1, m);
        while(feof(m)==0){
        	if(alum.dni==dnix){
        		strcpy(puntero_ingr->nombre,alum.nombre);
        		strcpy(puntero_ingr->apellido,alum.apellido);
		    	puntero_ingr->dni=alum.dni;
        		system("cls");
        		SetConsoleTextAttribute(hConsole, 12);
        		cout<<endl<<endl<<"\tIniciara sesion como '"<<alum.nombre<<" "<<alum.apellido<<"' (DNI: "<<alum.dni<<")"<<endl;
        		SetConsoleTextAttribute(hConsole, 7);
	            do{
		            cout<<endl<<"\tDesea continuar? (1. para si - 0. para no): ";
		            cin>>continuar;
		            if(continuar<0 || continuar>1)cout<<"\tSe pide 1 o 0 "<<endl;
		        }while(continuar<0 || continuar>1);
		        seguridad=1;
        	}
        	fread(&alum, sizeof (alumnos), 1, m);
        }
        if(seguridad==0){
        	fclose(m);
		    system("cls");
	        SetConsoleTextAttribute(hConsole, 12);
	        cout<<endl<<endl<<"\tEl numero '"<<dnix<<"' no corresponde a un alumno "<<endl<<endl;
	        SetConsoleTextAttribute(hConsole, 7);
	        dnix=0;
        	escape();
        	return;
		}
		if(continuar==0){
        	fclose(m);
        	dnix=0;
		    system("cls");
		    cout<<endl<<endl;
        	escape();
        	return;
		}
		if(continuar==1){
			FILE *i;
		    i = fopen("ingreso.dat","wb");
		    if (i== NULL){
		    	fclose(i);
		        system("cls");
		        SetConsoleTextAttribute(hConsole, 12);
		        cout<<endl<<endl<<"\tError en el archivo "<<endl<<endl;
		        SetConsoleTextAttribute(hConsole, 7);
		        escape();
		        return;
		    }
		    else{
		    	puntero_ingr->nombre;
		    	puntero_ingr->apellido;
				puntero_ingr->dni;
	    		fwrite(&*puntero_ingr,sizeof(ingreso),1,i);
	    	}
	    	fclose(i);
			system("0-1)Menu_alumnos.exe");
		}
    }
}
void iniciar_prof(){
	int dnix=0;
	system("cls");
	SetConsoleTextAttribute(hConsole, 12);
	cout<<endl<<endl<<"\tINICIO DE SESION "<<endl<<endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout<<"\tIngrese su DNI: ";
	cin>>dnix;
	FILE *m;
    m = fopen("profesores.dat","rb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay profesores registrados "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	int seguridad=0, continuar;
    	fread(&prof, sizeof (profesores), 1, m);
        while(feof(m)==0){
        	if(prof.dni==dnix){
        		strcpy(puntero_ingr->nombre,prof.nombre);
        		strcpy(puntero_ingr->apellido,prof.apellido);
		    	puntero_ingr->dni=prof.dni;
        		system("cls");
        		SetConsoleTextAttribute(hConsole, 12);
        		cout<<endl<<endl<<"\tIniciara sesion como '"<<prof.nombre<<" "<<prof.apellido<<"' (DNI: "<<prof.dni<<")"<<endl;
        		SetConsoleTextAttribute(hConsole, 7);
	            do{
		            cout<<endl<<"\tQuiere continuar? (1. para si - 0. para no): ";
		            cin>>continuar;
		            if(continuar<0 || continuar>1)cout<<"\tSe pide 1 o 0 "<<endl;
		        }while(continuar<0 || continuar>1);
		        seguridad=1;
        	}
        	fread(&prof, sizeof (profesores), 1, m);
        }
        if(seguridad==0){
        	fclose(m);
		    system("cls");
	        SetConsoleTextAttribute(hConsole, 12);
	        cout<<endl<<endl<<"\tEl numero '"<<dnix<<"' no corresponde a un alumno "<<endl<<endl;
	        SetConsoleTextAttribute(hConsole, 7);
	        dnix=0;
        	escape();
        	return;
		}
		if(continuar==0){
        	fclose(m);
        	dnix=0;
		    system("cls");
		    cout<<endl<<endl;
        	escape();
        	return;
		}
		if(continuar==1){
			FILE *i;
		    i = fopen("ingreso.dat","wb");
		    if (i== NULL){
		    	fclose(i);
		        system("cls");
		        SetConsoleTextAttribute(hConsole, 12);
		        cout<<endl<<endl<<"\tError en el archivo "<<endl<<endl;
		        SetConsoleTextAttribute(hConsole, 7);
		        escape();
		        return;
		    }
		    else{
		    	puntero_ingr->nombre;
		    	puntero_ingr->apellido;
				puntero_ingr->dni;
	    		fwrite(&*puntero_ingr,sizeof(ingreso),1,i);
	    	}
	    	fclose(i);
			system("0-2)Menu_profesores.exe");
		}
    }
}
void iniciar_pers_admin(){
	int dnix=0;
	system("cls");
	SetConsoleTextAttribute(hConsole, 12);
	cout<<endl<<endl<<"\tINICIO DE SESION "<<endl<<endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout<<"\tIngrese su DNI: ";
	cin>>dnix;
	FILE *m;
    m = fopen("pers_admin.dat","rb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay personal administrativo registrado "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	int seguridad=0, continuar;
    	fread(&admin, sizeof (pers_admin), 1, m);
        while(feof(m)==0){
        	if(admin.dni==dnix){
        		strcpy(puntero_ingr->nombre,admin.nombre);
        		strcpy(puntero_ingr->apellido,admin.apellido);
		    	puntero_ingr->dni=admin.dni;
        		system("cls");
        		SetConsoleTextAttribute(hConsole, 12);
        		cout<<endl<<endl<<"\tIniciara sesion como '"<<admin.nombre<<" "<<admin.apellido<<"' (DNI: "<<admin.dni<<")"<<endl;
        		SetConsoleTextAttribute(hConsole, 7);
	            do{
		            cout<<endl<<"\tQuiere continuar? (1. para si - 0. para no): ";
		            cin>>continuar;
		            if(continuar<0 || continuar>1)cout<<"\tSe pide 1 o 0 "<<endl;
		        }while(continuar<0 || continuar>1);
		        seguridad=1;
        	}
        	fread(&admin, sizeof (pers_admin), 1, m);
        }
        if(seguridad==0){
        	fclose(m);
		    system("cls");
	        SetConsoleTextAttribute(hConsole, 12);
	        cout<<endl<<endl<<"\tEl numero '"<<dnix<<"' no corresponde a un alumno "<<endl<<endl;
	        SetConsoleTextAttribute(hConsole, 7);
	        dnix=0;
        	escape();
        	return;
		}
		if(continuar==0){
        	fclose(m);
        	dnix=0;
		    system("cls");
		    cout<<endl<<endl;
        	escape();
        	return;
		}
		if(continuar==1){
			FILE *i;
		    i = fopen("ingreso.dat","wb");
		    if (i== NULL){
		    	fclose(i);
		        system("cls");
		        SetConsoleTextAttribute(hConsole, 12);
		        cout<<endl<<endl<<"\tError en el archivo "<<endl<<endl;
		        SetConsoleTextAttribute(hConsole, 7);
		        escape();
		        return;
		    }
		    else{
		    	puntero_ingr->nombre;
		    	puntero_ingr->apellido;
				puntero_ingr->dni;
	    		fwrite(&*puntero_ingr,sizeof(ingreso),1,i);
	    	}
	    	fclose(i);
			system("0-3)Menu_personal_admin.exe");
		}
    }
}
void registrar(){
	int menu;
    do{
    	system("cls");
    	cout<<endl<<endl;
    	SetConsoleTextAttribute(hConsole, 12);
    	cout<<"\tREGISTRARSE "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Registrarse como alumno "<<endl;
        cout<<"\t2. Registrarse como profesor "<<endl;
        cout<<"\t3. Registrarse como personal administrativo "<<endl<<endl;
        cout<<"\t4. Volver "<<endl<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("1)cargar_alumnos.exe");
                break;
            case 2:
				system("2)cargar_profesores.exe");
				break;
            case 3:
            	system("3)cargar_pers_admin.exe");
				break;
            case 4:
                return;
            default:
            	system("cls");
				SetConsoleTextAttribute(hConsole, 12);
				cout<<endl<<endl<<"\tIngrese una opcion valida "<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
				escape();
        }
    }while(menu!=4);
}
void escape(){
	int i=3;
	do{
		Sleep(200);
		cout<<"\tVolviendo al menu en "<<i<<" ..."<<endl;
		Sleep(1000);
		i--;
	}while(i!=0);
}
