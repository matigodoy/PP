#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct cliente {
    long int dni;
    int ant, cta, cod;
    float saldo;
};

int main ()
{
    FILE *m;
    //clrscr();
    cout<<"Programa de carga para el archivo de clientes";
    m = fopen ("clientes.dat" , "ab");
    if (m == NULL) {
        cout << "Error en la apertura del archivo";
        cout << "Presione una tecla... ";
        exit (1);
    }
    else
    {
        cliente r;
        cout<<"\nIngrese el dni (con cero termina): ";
        cin >> r.dni;
        while (r.dni != 0)
        {
            cout << "Número de cuenta:    ";
            cin >> r.cta;
            cout << "Código de confianza: ";
            cin >> r.cod;
            cout << "Antiguedad:          ";
            cin >> r.ant;
            cout << "Saldo en la cuenta:  ";
            cin >> r.saldo;
            fwrite (&r, sizeof (cliente), 1, m);
            system("cls");
            cout<<"Ingrese otro dni (con cero termina): ";
            cin >> r.dni;
        }
    }
    cout << "\n\n\nPresione una tecla para terminar...";
    system("pause");
    return 0;
}

