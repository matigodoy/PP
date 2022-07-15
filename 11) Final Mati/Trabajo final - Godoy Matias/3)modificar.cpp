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
struct aulas{
	int numero, sillas, mesas;
	short int proyector, reservado;
	char reservado_nombre[50], reservado_apellido[50];
}aul;
struct biblioteca{
	char titulo[50], reservado_nombre[50], reservado_apellido[50];
	long int codigo;
	short int reservado;
	int DNI;
}biblio;
void escape();
void modificar_alumnnos(), modificar_profesores(), modificar_pers_admin(), modificar_aulas(), modificar_libros();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main(){
	int menu;
    do{
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tMODIFICAR RECURSOS"<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Modificar alumnos"<<endl;
        cout<<"\t2. Modificar profesores"<<endl;
        cout<<"\t3. Modificar libros"<<endl;
        cout<<"\t4. Modificar aulas "<<endl<<endl;
        cout<<"\t5. Volver "<<endl<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	modificar_alumnnos();
                break;
            case 2:
				modificar_profesores();
				break;
            case 3:
				modificar_libros();
				break;
			case 4:
				modificar_aulas();
				break;
            case 5:
                return 0;
            default:
            	system("cls");
				SetConsoleTextAttribute(hConsole, 12);
				cout<<endl<<endl<<"\tIngrese una opcion valida "<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
				escape();
        }
    }while(menu!=6);
}
void modificar_alumnnos(){
	system("cls");
	SetConsoleTextAttribute(hConsole, 12);
	cout<<endl<<endl<<"\tMODIFICAR ALUMNOS "<<endl<<endl;
	SetConsoleTextAttribute(hConsole, 7);
	int seguridad=0, continuar=0;
	long int dnix=0;
	cout<<"\tIngrese el DNI del alumno que deseas modificar: ";
	cin>>dnix;
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
        cout<<endl<<endl<<"\tNo hay alumnos registrados "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	fread(&alum, sizeof (alumnos), 1, m);
    	while(feof(m)==0){
    		if(dnix==alum.dni){
    			SetConsoleTextAttribute(hConsole, 12);
				cout<<endl<<endl<<"\tLos datos del alumno encontrado son: "<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
	            cout<<"\tNombre: "<<alum.nombre<<endl;
	            cout<<"\tApellido: "<<alum.apellido<<endl;
	            cout<<"\tDNI: "<<alum.dni<<endl;
	            cout<<"\tLegajo: "<<alum.legajo<<endl;
    			seguridad=1;
    			do{
	    			cout<<endl<<"\tQuiere modificar este alumno? (1. para si - 0. para no): ";
	                cin>>continuar;
	                if(continuar<0 || continuar>1)cout<<"\tSe pide 1 o 0 "<<endl;
	            }while(continuar<0 || continuar>1);
				if(continuar==1){
    				system("cls");
    				SetConsoleTextAttribute(hConsole, 12);
					cout<<endl<<endl<<"\tModificando alumno "<<endl<<endl;
					SetConsoleTextAttribute(hConsole, 7);
    				cout<<"\tIngrese el NOMBRE: ";
		        	fflush(stdin);
		        	cin.getline(alum.nombre,50,'\n');
		            cout<<"\tIngrese el APELLIDO: ";
		        	fflush(stdin);
		        	cin.getline(alum.apellido,50,'\n');
		        	cout<<"\tIngrese el LEGAJO: ";
		        	cin>>alum.legajo;
					cout<<endl;
					fwrite(&alum,sizeof(alumnos),1,n);
				}
				if(continuar==0){
					fclose(m);
    				fclose(n);
    				remove("temp.dat");
    				return;
				}
			}
			if(dnix!=alum.dni){
	    		fwrite(&alum,sizeof(alumnos),1,n);
			}
			fread(&alum, sizeof (alumnos), 1, m);
		}
    }
    fclose(m);
    fclose(n);
    if(continuar==1){
	    remove("alumnos.dat");
	    rename("temp.dat","alumnos.dat");
		system("cls");
		SetConsoleTextAttribute(hConsole, 12);
		cout<<endl<<endl<<"\tDATOS MODIFICADOS CORRECTAMENTE."<<endl<<endl;
		SetConsoleTextAttribute(hConsole, 7);
		escape();
	}
    if(seguridad==0){
    	system("cls");
		SetConsoleTextAttribute(hConsole, 12);
		cout<<endl<<endl<<"\tEl DNI ingresado no corresponde a ningun alumno ."<<endl<<endl;
		SetConsoleTextAttribute(hConsole, 7);
		escape();
	}
}
void modificar_profesores(){
	system("cls");
	SetConsoleTextAttribute(hConsole, 12);
	cout<<endl<<endl<<"\tMODIFICAR PROFESORES "<<endl<<endl;
	SetConsoleTextAttribute(hConsole, 7);
	int seguridad=0, continuar=0;
	long int dnix=0;
	cout<<"\tIngrese el DNI del profesor que deseas modificar: ";
	cin>>dnix;
	system("cls");
	FILE *m;
	FILE *n;
    m = fopen("profesores.dat","rb");
    n = fopen("temp.dat","wb");
    if (m== NULL || n== NULL){
    	fclose(m);
    	fclose(n);
    	remove("temp.dat");
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay profesores registrados "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	fread(&prof, sizeof (profesores), 1, m);
    	while(feof(m)==0){
    		if(dnix==prof.dni){
    			SetConsoleTextAttribute(hConsole, 12);
				cout<<endl<<endl<<"\tLos datos del profesor encontrado son: "<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
	            cout<<"\tNombre: "<<prof.nombre<<endl;
	            cout<<"\tApellido: "<<prof.apellido<<endl;
	            cout<<"\tDNI: "<<prof.dni<<endl;
    			seguridad=1;
    			do{
	    			cout<<endl<<"\tQuiere modificar este profesor? (1. para si - 0. para no): ";
	                cin>>continuar;
	                if(continuar<0 || continuar>1)cout<<"\tSe pide 1 o 0 "<<endl;
	            }while(continuar<0 || continuar>1);
    			if(continuar==1){
    				system("cls");
    				SetConsoleTextAttribute(hConsole, 12);
					cout<<endl<<endl<<"\tModificando profesor "<<endl<<endl;
					SetConsoleTextAttribute(hConsole, 7);
    				cout<<"\tIngrese el NOMBRE: ";
		        	fflush(stdin);
		        	cin.getline(prof.nombre,50,'\n');
		            cout<<"\tIngrese el APELLIDO: ";
		        	fflush(stdin);
		        	cin.getline(prof.apellido,50,'\n');
					cout<<endl;
					fwrite(&prof,sizeof(profesores),1,n);
				}
				if(continuar==0){
					fclose(m);
    				fclose(n);
    				remove("temp.dat");
    				return;
				}
			}
			if(dnix!=prof.dni){
	    		fwrite(&prof,sizeof(profesores),1,n);
			}
			fread(&prof, sizeof (profesores), 1, m);
		}
    }
    fclose(m);
    fclose(n);
    if(continuar==1){
	    remove("profesores.dat");
	    rename("temp.dat","profesores.dat");
		system("cls");
		SetConsoleTextAttribute(hConsole, 12);
		cout<<endl<<endl<<"\tDATOS MODIFICADOS CORRECTAMENTE."<<endl<<endl;
		SetConsoleTextAttribute(hConsole, 7);
		escape();
	}
    if(seguridad==0){
    	system("cls");
		SetConsoleTextAttribute(hConsole, 12);
		cout<<endl<<endl<<"\tEl DNI ingresado no corresponde a ningun profesor ."<<endl<<endl;
		SetConsoleTextAttribute(hConsole, 7);
		escape();
	}
}
void modificar_pers_admin(){
	system("cls");
	SetConsoleTextAttribute(hConsole, 12);
	cout<<endl<<endl<<"\tMODIFICAR PERSONAL ADMINISTRATIVO "<<endl<<endl;
	SetConsoleTextAttribute(hConsole, 7);
	int seguridad=0, continuar=0;
	long int dnix=0;
	cout<<"\tIngrese el DNI de la persona que deseas modificar: ";
	cin>>dnix;
	system("cls");
	FILE *m;
	FILE *n;
    m = fopen("pers_admin.dat","rb");
    n = fopen("temp.dat","wb");
    if (m== NULL || n== NULL){
    	fclose(m);
    	fclose(n);
    	remove("temp.dat");
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay personal administrativo registrado "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	fread(&admin, sizeof (pers_admin), 1, m);
    	while(feof(m)==0){
    		if(dnix==admin.dni){
    			SetConsoleTextAttribute(hConsole, 12);
				cout<<endl<<endl<<"\tLos datos de la persona encontrado son: "<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
	            cout<<"\tNombre: "<<admin.nombre<<endl;
	            cout<<"\tApellido: "<<admin.apellido<<endl;
	            cout<<"\tDNI: "<<admin.dni<<endl;
    			seguridad=1;
    			do{
	    			cout<<endl<<"\tQuiere modificar esta persona? (1. para si - 0. para no): ";
	                cin>>continuar;
	                if(continuar<0 || continuar>1)cout<<"\tSe pide 1 o 0 "<<endl;
	            }while(continuar<0 || continuar>1);
    			if(continuar==1){
    				system("cls");
    				SetConsoleTextAttribute(hConsole, 12);
					cout<<endl<<endl<<"\tModificando persona del personal administrativo "<<endl<<endl;
					SetConsoleTextAttribute(hConsole, 7);
    				cout<<"\tIngrese el NOMBRE: ";
		        	fflush(stdin);
		        	cin.getline(admin.nombre,50,'\n');
		            cout<<"\tIngrese el APELLIDO: ";
		        	fflush(stdin);
		        	cin.getline(admin.apellido,50,'\n');
					cout<<endl;
					fwrite(&admin,sizeof(pers_admin),1,n);
				}
				if(continuar==0){
					fclose(m);
    				fclose(n);
    				remove("temp.dat");
    				return;
				}
			}
			if(dnix!=admin.dni){
	    		fwrite(&admin,sizeof(pers_admin),1,n);
			}
			fread(&admin, sizeof (pers_admin), 1, m);
		}
    }
    fclose(m);
    fclose(n);
    if(continuar==1){
	    remove("pers_admin.dat");
	    rename("temp.dat","pers_admin.dat");
	    SetConsoleTextAttribute(hConsole, 12);
		cout<<endl<<endl<<"\tDATOS ELIMINADOS CORRECTAMENTE."<<endl<<endl;
		SetConsoleTextAttribute(hConsole, 7);
		escape();
	}
    if(seguridad==0){
    	SetConsoleTextAttribute(hConsole, 12);
    	cout<<endl<<endl<<"\tEl DNI ingresado no corresponde a ningun adminesor "<<endl;
    	SetConsoleTextAttribute(hConsole, 7);
    	escape();
	}
}
void modificar_libros(){
	system("cls");
	SetConsoleTextAttribute(hConsole, 12);
	cout<<endl<<endl<<"\tMODIFICAR LIBROS "<<endl<<endl;
	SetConsoleTextAttribute(hConsole, 7);
	int seguridad=0, continuar=0;
	long int numx=0;
	cout<<"\tIngrese el codigo del libro que deseas modificar: ";
	cin>>numx;
	system("cls");
	FILE *m;
	FILE *n;
    m = fopen("libros.dat","rb");
    n = fopen("temp.dat","wb");
    if (m== NULL || n== NULL){
    	fclose(m);
    	fclose(n);
    	remove("temp.dat");
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay libros registrados "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	fread(&biblio, sizeof (biblioteca), 1, m);
    	while(feof(m)==0){
    		if(numx==biblio.codigo){
    			SetConsoleTextAttribute(hConsole, 12);
				cout<<endl<<endl<<"\tLos datos del libro encontrado son: "<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
	            cout<<"\tTitulo: "<<biblio.titulo<<endl;
	            cout<<"\tCodigo: "<<biblio.codigo<<endl;
    			seguridad=1;
    			do{
	    			cout<<endl<<"\tQuiere modificar este libro? (1. para si - 0. para no): ";
	                cin>>continuar;
	                if(continuar<0 || continuar>1)cout<<"\tSe pide 1 o 0 "<<endl;
	            }while(continuar<0 || continuar>1);
    			if(continuar==1){
    				system("cls");
    				SetConsoleTextAttribute(hConsole, 12);
					cout<<endl<<endl<<"\tModificando libro "<<endl<<endl;
					SetConsoleTextAttribute(hConsole, 7);
		            cout<<"\tIngrese el titulo: ";
		        	fflush(stdin);
		        	cin.getline(biblio.titulo,50,'\n');
		        	biblio.codigo;
					cout<<endl;
					fwrite(&biblio,sizeof(biblioteca),1,n);
				}
				if(continuar==0){
					fclose(m);
    				fclose(n);
    				remove("temp.dat");
    				return;
				}
			}
			if(numx!=biblio.codigo){
	    		fwrite(&biblio,sizeof(biblioteca),1,n);
			}
			fread(&biblio,sizeof(biblioteca),1,m);
		}
    }
    fclose(m);
    fclose(n);
    if(continuar==1){
	    remove("libros.dat");
	    rename("temp.dat","libros.dat");
		system("cls");
		SetConsoleTextAttribute(hConsole, 12);
		cout<<endl<<endl<<"\tDATOS MODIFICADOS CORRECTAMENTE."<<endl<<endl;
		SetConsoleTextAttribute(hConsole, 7);
		escape();
	}
    if(seguridad==0){
    	SetConsoleTextAttribute(hConsole, 12);
    	cout<<endl<<endl<<"\tEl codigo ingresado no corresponde a ningun libro "<<endl<<endl;
    	SetConsoleTextAttribute(hConsole, 7);
    	escape();
	}
}
void modificar_aulas(){
	system("cls");
	SetConsoleTextAttribute(hConsole, 12);
	cout<<endl<<endl<<"\tMODIFICAR AULAS "<<endl<<endl;
	SetConsoleTextAttribute(hConsole, 7);
	int seguridad=0, continuar=0, numx=0;
	cout<<"\tIngrese el numero del aula que deseas modificar: ";
	cin>>numx;
	system("cls");
	FILE *m;
	FILE *n;
    m = fopen("aulas.dat","rb");
    n = fopen("temp.dat","wb");
    if (m== NULL || n== NULL){
    	fclose(m);
    	fclose(n);
    	remove("temp.dat");
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay aulas registradas "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	fread(&aul, sizeof (aulas), 1, m);
    	while(feof(m)==0){
    		if(numx==aul.numero){
    			SetConsoleTextAttribute(hConsole, 12);
				cout<<endl<<endl<<"\tLos datos del aula encontrado son: "<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
				cout<<"\tAula numero: "<<aul.numero<<endl;
	            if(aul.proyector==1)cout<<"\tTiene un televisor "<<endl;
	            if(aul.proyector==2)cout<<"\tTiene un proyector "<<endl;
	            if(aul.proyector==3)cout<<"\tNo tiene televisor / proyector "<<endl;
	            cout<<"\tCantidad de sillas: "<<aul.sillas<<endl;
	            cout<<"\tCantidad de mesas: "<<aul.mesas<<endl;
    			seguridad=1;
    			do{
	    			cout<<endl<<"\tQuiere modificar esta aula? (1. para si - 0. para no): ";
	                cin>>continuar;
	                if(continuar<0 || continuar>1)cout<<"\tSe pide 1 o 0 "<<endl;
	            }while(continuar<0 || continuar>1);
    			if(continuar==1){
    				system("cls");
    				SetConsoleTextAttribute(hConsole, 12);
					cout<<endl<<endl<<"\tModificando aula "<<aul.numero<<endl<<endl;
					SetConsoleTextAttribute(hConsole, 7);
					aul.numero;
		            cout<<"\tIngrese si tiene (1. televisor - 2. proyector - 3. no tiene) : ";
		        	cin>>aul.proyector;
		        	cout<<"\tIngrese la cantidad de sillas: ";
		        	cin>>aul.sillas;
		        	cout<<"\tIngrese la cantidad de mesas: ";
		        	cin>>aul.mesas;
					cout<<endl;
					fwrite(&aul,sizeof(aulas),1,n);
				}
				if(continuar==0){
					fclose(m);
    				fclose(n);
    				remove("temp.dat");
    				return;
				}
			}
			if(numx!=aul.numero){
	    		fwrite(&aul,sizeof(aulas),1,n);
			}
			fread(&aul,sizeof(aulas),1,m);
		}
    }
    fclose(m);
    fclose(n);
    if(continuar==1){
	    remove("aulas.dat");
	    rename("temp.dat","aulas.dat");
		system("cls");
		SetConsoleTextAttribute(hConsole, 12);
		cout<<endl<<endl<<"\tDATOS MODIFICADOS CORRECTAMENTE."<<endl<<endl;
		SetConsoleTextAttribute(hConsole, 7);
		escape();
	}
    if(seguridad==0){
    	SetConsoleTextAttribute(hConsole, 12);
    	cout<<endl<<endl<<"\tEl numero ingresado no corresponde a ninguna aula "<<endl<<endl;
    	SetConsoleTextAttribute(hConsole, 7);
    	escape();
	}
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
