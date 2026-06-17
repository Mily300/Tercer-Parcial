#include <iostream>
#include "AutoPersona.h"

using namespace std;

int main() {
    Auto autos[10];
    Persona personas[10];

    int contAutos = 0;
    int contPersonas = 0;
    int opcion;

    do {
        cout << "\n===== MENU NUEVO TIPO DE DATO =====\n";
        cout << "1. Registrar Auto\n";
        cout << "2. Registrar Persona\n";
        cout << "3. Mostrar Autos\n";
        cout << "4. Mostrar Personas\n";
        cout << "5. Generar archivos\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {

        case 1:
            if(contAutos < 10) {
                autos[contAutos].capturar();
                contAutos++;
            }
            else {
                cout << "\nLista de autos llena.\n";
            }
            break;

        case 2:
            if(contPersonas < 10) {
                personas[contPersonas].capturar();
                contPersonas++;
            }
            else {
                cout << "\nLista de personas llena.\n";
            }
            break;

        case 3:
            cout << "\n--- LISTA DE AUTOS ---\n";
            for(int i = 0; i < contAutos; i++) {
                autos[i].mostrar();
            }
            break;

        case 4:
            cout << "\n--- LISTA DE PERSONAS ---\n";
            for(int i = 0; i < contPersonas; i++) {
                personas[i].mostrar();
            }
            break;

        case 5:
            generarTXT(autos, contAutos, personas, contPersonas);
            generarCSV(autos, contAutos, personas, contPersonas);
            generarJSON(autos, contAutos, personas, contPersonas);
            generarXML(autos, contAutos, personas, contPersonas);

            cout << "\nArchivos generados correctamente.\n";
            break;

        case 6:
            cout << "\nSaliendo del programa...\n";
            break;

        default:
            cout << "\nOpcion no valida.\n";
        }

    } while(opcion != 6);

    return 0;
}