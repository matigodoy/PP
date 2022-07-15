#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;
struct profesores{
	char nombre[50], apellido[50];
	long int dni;	
	short int reservado;
	int reservado_dni, reservado_hora, reservado_minutos, reservado_dia, reservado_mes, reservado_anio, reservado_numero;
}prof;
struct aulas{
	int numero, sillas, mesas;
	short int proyector, reservado;
	char reservado_nombre[50], reservado_apellido[50];
}aul;
struct ingreso{
	char nombre[50];
	char apellido[50];
	long int dni;
}ingr, *puntero_ingr = &ingr;
void buscar_aula(), reservar_aula(), ingresar(), confirmar(), escape();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int num_aula,dnix,hora,minutos,dia,mes,anio,confirm=0;;
char nombrex[50],apellidox[50];
int main(){
	int menu;
    do{
    	ingresar();
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tRESERVAR AULAS "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\t1. Ver aulas cargadas "<<endl;
        cout<<"\t2. Buscar aula para reservar "<<endl;
        cout<<"\t3. Reservar aula especifica "<<endl<<endl;
        cout<<"\t4. Volver "<<endl<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("7)mostrar_aulas.exe");
				break;
			case 2:
				confirm=0;
				confirmar();
				if(confirm==0){
					buscar_aula();
				}
				break;
			case 3:
				confirm=0;
				confirmar();
				if(confirm==0){
					reservar_aula();
				}
				break;
            case 4:
                return 0;
            default:
            	system("cls");
				SetConsoleTextAttribute(hConsole, 12);
				cout<<endl<<endl<<"\tIngrese una opcion valida "<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 7);
				escape();
        }
    }while(menu!=4);
}
void buscar_aula(){
	int cant_alumnos;
    system("cls");
	SetConsoleTextAttribute(hConsole, 12);
    cout<<endl<<endl<<"\tRESERVAR AULAS "<<endl<<endl;
    SetConsoleTextAttribute(hConsole, 7);
	cout<<"\tIngrese la cantidad de alumnos que va a tener en la clase: ";
	cin>>cant_alumnos;
	FILE *m;
    m = fopen("aulas.dat","rb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tNo hay aulas registradas "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	short int seguridad=0;
    	system("cls");
    	SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tMOSTRAR AULAS DISPONIBLES "<<endl<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        fread(&aul, sizeof (aulas), 1, m);
        while(feof(m)==0){
        	if(aul.sillas>=cant_alumnos && aul.reservado==0){
        		seguridad=1;
	            cout<<"\tAula: "<<aul.numero<<endl;
	            if(aul.proyector==1)cout<<"\tTiene un televisor "<<endl;
	            if(aul.proyector==2)cout<<"\tTiene un proyector "<<endl;
	            if(aul.proyector==3)cout<<"\tNo tiene televisor / proyector "<<endl;
	            cout<<"\tCantidad de sillas: "<<aul.sillas<<endl;
	            cout<<"\tCantidad de mesas: "<<aul.mesas<<endl;
	            cout<<endl;
	        }
	        fread(&aul, sizeof (aulas), 1, m);
        }
        fclose(m);
        if(seguridad==0){
        	system("cls");
	        SetConsoleTextAttribute(hConsole, 12);
	        cout<<endl<<endl<<"\tNo hay aula disponible con esa cantidad de sillas "<<endl<<endl;
	        SetConsoleTextAttribute(hConsole, 7);
	        escape();
	        return;
	    }
        if(seguridad==1){
        	int num_aula;
		    cout<<endl<<"\tIngrese el numero del aula que quiere reservar: ";
		    cin>>num_aula;
		    m = fopen("aulas.dat","rb");
		    if (m== NULL){
		    	fclose(m);
		        system("cls");
		        SetConsoleTextAttribute(hConsole, 12);
		        cout<<endl<<endl<<"\tError en el archivo "<<endl<<endl;
		        SetConsoleTextAttribute(hConsole, 7);
		        escape();
	        	return;
		    }
		    else{
		    	short int seguridad1=0;
		    	fread(&aul, sizeof (aulas), 1, m);
			    while(feof(m)==0){
			    	if(aul.numero==num_aula && aul.sillas>=cant_alumnos && aul.reservado==0){
			    		seguridad1=1;
					}
					fread(&aul, sizeof (aulas), 1, m);
			    }
			    fclose(m);
			    if(seguridad1==0){
			    	system("cls");
			        SetConsoleTextAttribute(hConsole, 12);
			        cout<<endl<<endl<<"\tEl numero '"<<num_aula<<"' no corresponde a un aula disponible "<<endl<<endl;
			        SetConsoleTextAttribute(hConsole, 7);
			        escape();
			        return;
				}
				if(seguridad1==1){
					int continuar;
					time_t tSac = time(NULL); // instante actual
					struct tm* tmP = localtime(&tSac);
					hora=tmP->tm_hour;minutos=tmP->tm_min;  // HORA
					dia=tmP->tm_mday+1;mes=tmP->tm_mon+1;anio=tmP->tm_year+1900; // FECHA
					system("cls");
					SetConsoleTextAttribute(hConsole, 12);
					cout<<endl<<endl<<"\tSe reservara el aula '"<<num_aula<<"'"<<endl<<endl;
					SetConsoleTextAttribute(hConsole, 7);
					cout <<"\tHasta el "<< dia << "-" << mes<< " a las " << hora << ":" << minutos <<". "<< endl;
					cout<<"\tA nombre de "<<nombrex<<" "<<apellidox<<" (DNI: "<<dnix<<")"<<endl;
					do{
						cout<<endl<<"\tQuieres reservar? (1. para si - 0. para no): ";
				        cin>>continuar;
				    	if(continuar<0 || continuar>1)cout<<"\tSe pide 1 o 0 "<<endl;
				    }while(continuar<0 || continuar>1);
				    if(continuar==0){
				    	system("cls");
				        SetConsoleTextAttribute(hConsole, 12);
				        cout<<endl<<endl<<"\tCancelando reserva "<<endl<<endl;
				        SetConsoleTextAttribute(hConsole, 7);
				        escape();
				        return;
				    }
				    if(continuar==1){
				        m = fopen("aulas.dat","rb");
				        FILE *n;
				        n = fopen("temp.dat","wb");
				    	if (m== NULL || n== NULL){
					    	fclose(m);
					    	fclose(n);
					    	remove("temp.dat");
					        system("cls");
					        SetConsoleTextAttribute(hConsole, 12);
					        cout<<endl<<endl<<"\tError en el archivo "<<endl<<endl;
					        SetConsoleTextAttribute(hConsole, 7);
					        escape();
				        	return;
					    }
					    else{
					    	int seguridad2=0;
					    	fread(&aul, sizeof (aulas), 1, m);
					        while(feof(m)==0){
					        	if(aul.numero==num_aula && aul.sillas>=cant_alumnos && aul.reservado==0){
					        		aul.reservado=1;
					        		strcpy(aul.reservado_nombre,nombrex);
					        		strcpy(aul.reservado_apellido,apellidox);
					        		fwrite(&aul,sizeof(aulas),1,n);
					        		seguridad2=1;
					        	}
					        	if(aul.numero!=num_aula){
					        		fwrite(&aul,sizeof(aulas),1,n);
					        	}
					        	fread(&aul, sizeof (aulas), 1, m);
					        }
					        fclose(m);
							fclose(n);
					        if(seguridad2==0){
							    remove("temp.dat");
							    system("cls");
							    cout<<endl<<endl;
					        	escape();
					        	return;
							}
							if(seguridad2==1){
							    remove("aulas.dat");
							    rename("temp.dat","aulas.dat");
							    m = fopen("profesores.dat","rb");
							    n = fopen("temp1.dat","wb");
							    if (m== NULL || n== NULL){
							    	fclose(m);
							    	fclose(n);
							    	remove("temp1.dat");
							        system("cls");
							        SetConsoleTextAttribute(hConsole, 12);
							        cout<<endl<<endl<<"\tError en el archivo "<<endl<<endl;
							        SetConsoleTextAttribute(hConsole, 7);
							        return;
							    }
								else{
							    	fread(&prof, sizeof (profesores), 1, m);
							    	while(feof(m)==0){
										if(dnix==prof.dni){
											prof.reservado_numero=num_aula;
											prof.reservado=1;
								        	prof.reservado_hora=hora;
											prof.reservado_minutos=minutos;
											prof.reservado_dia=dia;
											prof.reservado_mes=mes;
											prof.reservado_anio=anio;
											fwrite(&prof,sizeof(profesores),1,n);
										}
										if(dnix!=prof.dni){
											fwrite(&prof,sizeof(profesores),1,n);
										}
										fread(&prof, sizeof (profesores), 1, m);
									}
									fclose(m);
								    fclose(n);
									remove("profesores.dat");
									rename("temp1.dat","profesores.dat");
								}
								system("cls");
						        SetConsoleTextAttribute(hConsole, 12);
						        cout<<endl<<endl<<"\tSe ha reservado el aula '"<<num_aula<<"' con exito "<<endl<<endl;
						        SetConsoleTextAttribute(hConsole, 7);
							    escape();
							}
					    }
					}
				}
		    }
		}
	}
}
void reservar_aula(){
	system("cls");
    SetConsoleTextAttribute(hConsole, 12);
    cout<<endl<<endl<<"\tRESERVAR AULAS "<<endl<<endl;
    SetConsoleTextAttribute(hConsole, 7);
	int num_aula;
    cout<<"\tIngrese el numero del aula que quiere reservar: ";
    cin>>num_aula;
    FILE *m;
    m = fopen("aulas.dat","rb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tError en el archivo "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
    	return;
    }
    else{
    	short int seguridad1=0,seguri1=0;
    	fread(&aul, sizeof (aulas), 1, m);
	    while(feof(m)==0){
	    	if(aul.numero==num_aula){
	    		seguri1=1;
	    		if(aul.reservado==0){
	    			seguridad1=1;
	    		}
			}
			fread(&aul, sizeof (aulas), 1, m);
	    }
	    fclose(m);
	    if(seguri1==0){
	    	system("cls");
	        SetConsoleTextAttribute(hConsole, 12);
	        cout<<endl<<endl<<"\tEl numero '"<<num_aula<<"' no corresponde a un aula "<<endl<<endl;
	        SetConsoleTextAttribute(hConsole, 7);
	        escape();
	        return;
		}
	    if(seguridad1==0){
	    	system("cls");
	        SetConsoleTextAttribute(hConsole, 12);
	        cout<<endl<<endl<<"\tEl aula '"<<num_aula<<"' ya se encuentra reservada "<<endl<<endl;
	        SetConsoleTextAttribute(hConsole, 7);
	        escape();
	        return;
		}
		if(seguridad1==1){
			int continuar;
			time_t tSac = time(NULL); // instante actual
			struct tm* tmP = localtime(&tSac);
			hora=tmP->tm_hour;minutos=tmP->tm_min;  // HORA
			dia=tmP->tm_mday+1;mes=tmP->tm_mon+1;anio=tmP->tm_year+1900; // FECHA
			system("cls");
			SetConsoleTextAttribute(hConsole, 12);
			cout<<endl<<endl<<"\tSe reservara el aula '"<<num_aula<<"'"<<endl<<endl;
			SetConsoleTextAttribute(hConsole, 7);
			cout <<"\tHasta el "<< dia << "-" << mes<< " a las " << hora << ":" << minutos <<". "<< endl;
			cout<<"\tA nombre de "<<nombrex<<" "<<apellidox<<" (DNI: "<<dnix<<")"<<endl;
			do{
				cout<<endl<<"\tQuieres reservar? (1. para si - 0. para no): ";
		        cin>>continuar;
		    	if(continuar<0 || continuar>1)cout<<"\tSe pide 1 o 0 "<<endl;
		    }while(continuar<0 || continuar>1);
		    if(continuar==0){
		    	system("cls");
		        SetConsoleTextAttribute(hConsole, 12);
		        cout<<endl<<endl<<"\tCancelando reserva "<<endl<<endl;
		        SetConsoleTextAttribute(hConsole, 7);
		        escape();
		        return;
		    }
		    if(continuar==1){
				FILE *n;
		        m = fopen("aulas.dat","rb");
		        n = fopen("temp.dat","wb");
		    	if (m== NULL || n== NULL){
			    	fclose(m);
			    	fclose(n);
			    	remove("temp.dat");
			        system("cls");
			        SetConsoleTextAttribute(hConsole, 12);
			        cout<<endl<<endl<<"\tError en el archivo "<<endl<<endl;
			        SetConsoleTextAttribute(hConsole, 7);
			        escape();
		        	return;
			    }
			    else{
			    	int seguridad2=0;
			    	fread(&aul, sizeof (aulas), 1, m);
			        while(feof(m)==0){
			        	if(aul.numero==num_aula && aul.reservado==0){
			        		aul.reservado=1;
			        		strcpy(aul.reservado_nombre,nombrex);
			        		strcpy(aul.reservado_apellido,apellidox);
			        		fwrite(&aul,sizeof(aulas),1,n);
			        		seguridad2=1;
			        	}
			        	if(aul.numero!=num_aula){
			        		fwrite(&aul,sizeof(aulas),1,n);
			        	}
			        	fread(&aul, sizeof (aulas), 1, m);
			        }
			        if(seguridad2==0){
			        	fclose(m);
					    fclose(n);
					    remove("temp.dat");
					    system("cls");
					    cout<<endl<<endl;
			        	escape();
			        	return;
					}
					if(seguridad2==1){
						fclose(m);
					    fclose(n);
					    remove("aulas.da+t");
					    rename("temp.dat","aulas.dat");
					    m = fopen("profesores.dat","rb");
					    n = fopen("temp2.dat","wb");
					    if (m== NULL || n== NULL){
					    	fclose(m);
					    	fclose(n);
					    	remove("temp2.dat");
					        system("cls");
					        SetConsoleTextAttribute(hConsole, 12);
					        cout<<endl<<endl<<"\tError en el archivo "<<endl<<endl;
					        SetConsoleTextAttribute(hConsole, 7);
					        return;
					    }
						else{
					    	fread(&prof, sizeof (profesores), 1, m);
					    	while(feof(m)==0){
								if(dnix==prof.dni){
									prof.reservado_numero=num_aula;
									prof.reservado=1;
						        	prof.reservado_hora=hora;
									prof.reservado_minutos=minutos;
									prof.reservado_dia=dia;
									prof.reservado_mes=mes;
									prof.reservado_anio=anio;
									fwrite(&prof,sizeof(profesores),1,n);
								}
								if(dnix!=prof.dni){
									fwrite(&prof,sizeof(profesores),1,n);
								}
								fread(&prof, sizeof (profesores), 1, m);
							}
							fclose(m);
						    fclose(n);
							remove("profesores.dat");
							rename("temp2.dat","profesores.dat");
						}
						system("cls");
				        SetConsoleTextAttribute(hConsole, 12);
				        cout<<endl<<endl<<"\tSe ha reservado el aula '"<<num_aula<<"' con exito "<<endl<<endl;
				        SetConsoleTextAttribute(hConsole, 7);
					    escape();
					}
			    }
			}
		}
    }
}
void confirmar(){
	FILE *m;
	FILE *o;
    m = fopen("profesores.dat","rb");
	o = fopen("aulas.dat","rb");
    if (m== NULL || o==NULL){
    	fclose(m);
    	fclose(o);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        cout<<endl<<endl<<"\tError en el archivo "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        escape();
        return;
    }
    else{
    	confirm=0;
        fread(&prof, sizeof (profesores), 1, m);
        while(feof(m)==0){
        	if(dnix==prof.dni){
		        fread(&aul, sizeof (aulas), 1, o);
		        while(feof(o)==0){
		        	if(aul.numero==prof.reservado_numero){
		        		confirm=1;
		        		system("cls");
		        		SetConsoleTextAttribute(hConsole, 12);
				        cout<<endl<<endl<<"\tTiene reservada el aula "<<prof.reservado_numero<<". Para continuar, elimine la reserva "<<endl;
				        SetConsoleTextAttribute(hConsole, 7);
				        Sleep(1000);
					}
					fread(&aul, sizeof (aulas), 1, o);
				}
			}
        	fread(&prof, sizeof (profesores), 1, m);
        }
        fclose(m);
    	fclose(o);
    	if(confirm==1){
    		cout<<endl;
    		escape();
    		return;
		}
    }
}
void ingresar(){
	int i=1;
    FILE *m;
    m = fopen("ingreso.dat","rb");
    if (m== NULL){
    	fclose(m);
        system("cls");
        cout<<endl<<endl<<"\tDebes iniciar sesion antes. "<<endl<<endl;
        return;
    }
    else{
        fread(&*puntero_ingr, sizeof (ingreso), 1, m);
        while(feof(m)==0){
        	strcpy(apellidox,puntero_ingr->apellido);
			strcpy(nombrex,puntero_ingr->nombre);
            dnix=puntero_ingr->dni;
            fread(&*puntero_ingr, sizeof (ingreso), 1, m);
            cout<<endl;
        }
        fclose(m);
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
