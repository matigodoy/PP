#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;

void alta(), baja(), modificacion(), consulta(), escape(), alta_reserva();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main(){
	int menu;
	do{
		system("cls");
		cout<<endl<<endl;
		SetConsoleTextAttribute(hConsole, 415);
		cout<<"\t\t     ___         .______      .___  ___.      ______ "<<endl;
		cout<<"\t\t    /   \\        |   _  \\     |   \\/   |     /      |"<<endl;
		cout<<"\t\t   /  ^  \\       |  |_)  |    |  \\  /  |    |  ,----'"<<endl;
		cout<<"\t\t  /  /_\\  \\      |   _  <     |  |\\/|  |    |  |     "<<endl;
		cout<<"\t\t /  _____  \\     |  |_)  |    |  |  |  |    |  `----."<<endl;
		cout<<"\t\t/__/     \\__\\    |______/     |__|  |__|     \\______|"<<endl<<endl<<endl;
	    SetConsoleTextAttribute(hConsole, 12);
	    cout<<endl<<"\t\t1. ALTA"<<endl;
	    SetConsoleTextAttribute(hConsole, 7);
	    cout<<"\t\t\t >Carga de recursos "<<endl;
	    cout<<"\t\t\t >Carga de reserva "<<endl;
	    SetConsoleTextAttribute(hConsole, 12);
	    cout<<endl<<"\t\t2. BAJA "<<endl;
	    SetConsoleTextAttribute(hConsole, 7);
	    cout<<"\t\t\t >Baja de recursos "<<endl;
	    cout<<"\t\t\t >Baja de reserva "<<endl;
	    SetConsoleTextAttribute(hConsole, 12);
	    cout<<endl<<"\t\t3. MODIFICACION "<<endl;
	    SetConsoleTextAttribute(hConsole, 7);
	    cout<<"\t\t\t >Modificacion de recursos "<<endl;
	    cout<<"\t\t\t >Modificacion de reserva "<<endl;
	    SetConsoleTextAttribute(hConsole, 12);
	    cout<<endl<<"\t\t4. CONSULTA "<<endl;
	    SetConsoleTextAttribute(hConsole, 7);
	    cout<<"\t\t\t >Consulta de recursos "<<endl;
	    SetConsoleTextAttribute(hConsole, 12);
	    cout<<endl<<"\t\t5. SALIR "<<endl;
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
	            system("3)modificar.exe");
	            break;
	        case 4:
	            system("4)consulta.exe");
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
    	cout<<"\tMENU DE ALTA "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Carga de reserva "<<endl;
        cout<<"\t2. Carga de recursos "<<endl<<endl;
        cout<<"\t3. Volver "<<endl<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	alta_reserva();
                break;
            case 2:
            	system("1)alta.exe");
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
    }while(menu!=4);
}
void alta_reserva(){
	int menu;
    do{
    	system("cls");
    	cout<<endl<<endl;
    	SetConsoleTextAttribute(hConsole, 12);
    	cout<<"\tCARGA DE RESERVA "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Reservar aula "<<endl;
        cout<<"\t2. Reservar libro "<<endl<<endl;
        cout<<"\t3. Volver "<<endl<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("1.1)reservar_aulas.exe");
                break;
            case 2:
            	system("1.2)reservar_libros.exe");
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
    }while(menu!=4);
}
void baja(){
	int menu;
    do{
    	system("cls");
    	cout<<endl<<endl;
    	SetConsoleTextAttribute(hConsole, 12);
    	cout<<"\tMENU DE BAJA "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Dar de baja recursos "<<endl;
        cout<<"\t2. Dar de baja reserva "<<endl<<endl;
        cout<<"\t3. Volver "<<endl<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("2)eliminar.exe");
                break;
            case 2:
            	modificacion();
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
    }while(menu!=4);
}
void modificacion(){
	int menu;
    do{
    	system("cls");
    	cout<<endl<<endl;
    	SetConsoleTextAttribute(hConsole, 12);
    	cout<<"\tMENU DE BAJA "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Dar de baja reserva de aula "<<endl;
        cout<<"\t2. Dar de baja reserva de libro "<<endl<<endl;
        cout<<"\t3. Volver "<<endl<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("2.1)eliminar_reserva_aulas.exe");
                break;
            case 2:
            	system("2.2)eliminar_reserva_libros.exe");
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
