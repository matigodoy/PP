#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;

int main(){
	int menu;
    do{
    	cout<<endl<<endl;
        cout<<"\tM E N U "<<endl;
        cout<<"1. Burbuja Numeros "<<endl;
        cout<<"2. Burbuja Palabras "<<endl;
        cout<<"3. Seleccion Numeros "<<endl;
		cout<<"4. Seleccion Palabras "<<endl;
		cout<<"5. Insercion Numeros "<<endl;
		cout<<"6. Insercion Palabras "<<endl;
		cout<<"7. Quicksort Numeros "<<endl;
		cout<<"8. Quicksort Palabras "<<endl;
		cout<<"9. Heapsort Numeros "<<endl;
		cout<<"10. Heapsort Palabras "<<endl;
		cout<<"11. Shellsort Numeros "<<endl;
		cout<<"12. Shellsort Palabras "<<endl;
		cout<<"13. Salir "<<endl;
        cout<<"Ingrese opcion: ";
        cin>>menu;
        cout<<endl<<endl;
        switch(menu){
            case 1:
            	system("1)Burbujanumeros.exe");
                break;
            case 2:
				system("2)Burbujapalabras.exe");
				break;
            case 3:
				system("3)Seleccionnumeros.exe");
				break;
			case 4:
				system("4)Seleccionpalabras.exe");
				break;
			case 5:
				system("5)Insercionnumeros.exe");
				break;
			case 6:
				system("6)Insercionpalabras.exe");
				break;
			case 7:
				system("7)Quicksortnumeros.exe");
				break;
			case 8:
				system("8)Quicksortpalabras.exe");
				break;
			case 9:
				system("9)Heapsortnumeros.exe");
				break;
			case 10:
				system("10)Heapsortpalabras.exe");
				break;
			case 11:
				system("11)ShellSortnumeros.exe");
				break;
			case 12:
				system("12)ShellSortpalabras.exe");
				break;
            case 13:
                return 0;
                
            default: cout<<"Ingrese una opcion valida "<<endl;
        }
    }while(menu!=13);
    
    return 0;
}
