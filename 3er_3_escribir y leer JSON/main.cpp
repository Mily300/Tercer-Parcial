#include <iostream>
#include "Tipos.h"
#include "Adtjson.h"
using namespace std;

int main() {
    AdtJson json;
    DatosBasicos datos;
    ArregloNumeros arreglo;
    Alumno alumnos[10];

    int opcion;
    int nAlumnos;

    do {
        cout << "\n========== MENU JSON ==========\n";
        cout << "1. Escribir JSON datos basicos\n";
        cout << "2. Leer JSON datos basicos\n";
        cout << "3. Escribir JSON con arreglo\n";
        cout << "4. Leer JSON con arreglo\n";
        cout << "5. Escribir JSON con ADT POO\n";
        cout << "6. Leer JSON con ADT POO\n";
        cout << "7. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {

        case 1:
            cout << "\n--- CAPTURA DATOS BASICOS ---\n";
            cout << "Nombre: ";
            cin >> datos.nombre;

            cout << "Edad: ";
            cin >> datos.edad;

            cout << "Promedio: ";
            cin >> datos.promedio;

            json.escribirDatosBasicos(datos);
            break;

        case 2:
            json.leerDatosBasicos();
            break;

        case 3:
            cout << "\nCantidad de numeros: ";
            cin >> arreglo.n;

            for(int i = 0; i < arreglo.n; i++) {
                cout << "Numero " << i + 1 << ": ";
                cin >> arreglo.numeros[i];
            }

            json.escribirArreglo(arreglo);
            break;

        case 4:
            json.leerArreglo();
            break;

        case 5:
            cout << "\nCantidad de alumnos: ";
            cin >> nAlumnos;

            for(int i = 0; i < nAlumnos; i++) {
                cout << "\nAlumno " << i + 1 << endl;
                alumnos[i].capturar();
            }

            json.escribirAlumnos(alumnos, nAlumnos);
            break;

        case 6:
            json.leerAlumnos();
            break;

        case 7:
            cout << "\nSaliendo del programa...\n";
            break;

        default:
            cout << "\nOpcion no valida\n";
        }

    } while(opcion != 7);

    return 0;
}
