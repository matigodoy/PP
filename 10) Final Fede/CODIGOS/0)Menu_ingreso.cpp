#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;
void alta(), baja(), modificar(), consultar(), escape();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main(){
	system("00)Menu.exe");
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
	    cout<<"\t\t1. ALTA "<<endl;
	    SetConsoleTextAttribute(hConsole, 7);
	    cout<<"\t\t\t >Agregar recursos "<<endl;
	    cout<<"\t\t\t >Reservar recurso "<<endl<<endl;
	    SetConsoleTextAttribute(hConsole, 12);
	    cout<<"\t\t2. BAJA "<<endl;
	    SetConsoleTextAttribute(hConsole, 7);
	    cout<<"\t\t\t >Eliminar recursos "<<endl<<endl;
	    SetConsoleTextAttribute(hConsole, 12);
	    cout<<"\t\t3. MODIFICAR "<<endl;
	    SetConsoleTextAttribute(hConsole, 7);
	    cout<<"\t\t\t >Modificar recursos "<<endl;
	    cout<<"\t\t\t >Eliminar reserva "<<endl<<endl;
	    SetConsoleTextAttribute(hConsole, 12);
	    cout<<"\t\t4. CONSULTAR "<<endl;
	    SetConsoleTextAttribute(hConsole, 7);
	    cout<<"\t\t\t >Mostrar recursos "<<endl;
	    cout<<"\t\t\t >Buscar recursos "<<endl<<endl;
	    SetConsoleTextAttribute(hConsole, 12);
	    cout<<"\t\t5. SALIR "<<endl;
	    SetConsoleTextAttribute(hConsole, 7);
	    cout<<endl<<"\t\tIngrese una opcion: ";
	    cin>>menu;
	    cout<<endl<<endl;
	    switch(menu){
	        case 1:
	        	alta();
	            break;
	        case 2:
	        	baja();
				break;
			case 3:
	        	modificar();
				break;
			case 4:
	        	consultar();
				break;
	        case 5:
	            return 0;
	        default:
	        	system("cls");
				cout<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 12);
				cout<<"\tIngrese una opcion valida "<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
				escape();
	    }
	}while(menu!=5);
}
void alta(){
	int menu;
    do{
    	system("cls");
    	cout<<endl<<endl;
    	SetConsoleTextAttribute(hConsole, 12);
    	cout<<"\tALTA "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Cargar recursos "<<endl;
        cout<<"\t2. Reservar recurso "<<endl<<endl;
        cout<<"\t3. Volver "<<endl<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("1)Agregar.exe");
                break;
            case 2:
            	system("2)Reservar.exe");
                break;
            case 3:
                return;
            default:
            	system("cls");
				SetConsoleTextAttribute(hConsole, 12);
				cout<<endl<<endl<<"\tIngrese una opcion valida "<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
				escape();
        }
    }while(menu!=3);
}
void baja(){
	int menu;
    do{
    	system("cls");
    	cout<<endl<<endl;
    	SetConsoleTextAttribute(hConsole, 12);
    	cout<<"\tBAJA "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Eliminar recursos "<<endl<<endl;
        cout<<"\t2. Volver "<<endl<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("3)Eliminar.exe");
                break;
            case 2:
                return;
            default:
            	system("cls");
				SetConsoleTextAttribute(hConsole, 12);
				cout<<endl<<endl<<"\tIngrese una opcion valida "<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
				escape();
        }
    }while(menu!=2);
}
void modificar(){
	int menu;
    do{
    	system("cls");
    	cout<<endl<<endl;
    	SetConsoleTextAttribute(hConsole, 12);
    	cout<<"\tMODIFICAR "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Modificar recursos "<<endl;
        cout<<"\t2. Eliminar una reserva "<<endl<<endl;
        cout<<"\t3. Volver "<<endl<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("4)Modificar.exe");
                break;
            case 2:
            	system("5)Eliminar_reserva.exe");
                break;
            case 3:
                return;
            default:
            	system("cls");
				SetConsoleTextAttribute(hConsole, 12);
				cout<<endl<<endl<<"\tIngrese una opcion valida "<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
				escape();
        }
    }while(menu!=3);
}
void consultar(){
	int menu;
    do{
    	system("cls");
    	cout<<endl<<endl;
    	SetConsoleTextAttribute(hConsole, 12);
    	cout<<"\tCONSULTAR "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Mostrar recursos "<<endl;
        cout<<"\t2. Buscar recursos "<<endl<<endl;
        cout<<"\t3. Volver "<<endl<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("6)Mostrar.exe");
                break;
            case 2:
            	system("7)Buscar.exe");
                break;
            case 3:
                return;
            default:
            	system("cls");
				SetConsoleTextAttribute(hConsole, 12);
				cout<<endl<<endl<<"\tIngrese una opcion valida "<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
				escape();
        }
    }while(menu!=3);
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
