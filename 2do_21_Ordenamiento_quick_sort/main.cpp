#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include "PersonaPOO.h"
#include "logger.h"

using namespace std;

void ordenarEnteros(Logger& log) {
    int n;
    cout << "\nCuantos enteros desea ingresar? ";
    cin >> n;
    int* datos = new int[n];       
    int** punteros = new int*[n];  
    for(int i = 0; i < n; i++) {
        cout << "Entero " << i + 1 << ": ";
        cin >> datos[i];
        punteros[i] = &datos[i]; 
    }
    quickSortIndirecto(punteros, 0, n - 1);
    cout << "\n[RESULTADO] Enteros ordenados: "; 
    imprimirArreglo(punteros, n);
    ostringstream ss;
    for(int i = 0; i < n; i++) ss << *punteros[i] << (i < n-1 ? " | " : "");
    log.registrar("quicksort_enteros", "Ordenados " + to_string(n) + " enteros", ss.str());
    delete[] punteros; delete[] datos;
}

void ordenarCaracteres(Logger& log) {
    int n;
    cout << "\nCuantos caracteres desea ingresar? ";
    cin >> n;
    char* datos = new char[n];
    char** punteros = new char*[n];
    for(int i = 0; i < n; i++) {
        cout << "Caracter " << i + 1 << ": ";
        cin >> datos[i];
        punteros[i] = &datos[i];
    }
    quickSortIndirecto(punteros, 0, n - 1);
    cout << "\n[RESULTADO] Caracteres ordenados: "; 
    imprimirArreglo(punteros, n);
    ostringstream ss;
    for(int i = 0; i < n; i++) ss << *punteros[i] << (i < n-1 ? " | " : "");
    log.registrar("quicksort_caracteres", "Ordenados " + to_string(n) + " caracteres", ss.str());
    delete[] punteros; delete[] datos;
}

void ordenarPersonasPOO(Logger& log) {
    int n;
    cout << "\nCuantas personas desea ingresar? ";
    cin >> n;
    PersonaPOO* datos = new PersonaPOO[n];
    PersonaPOO** punteros = new PersonaPOO*[n];
    for(int i = 0; i < n; i++) {
        string nom; int ed;
        cout << "Nombre de la persona " << i + 1 << ": ";
        cin >> nom;
        cout << "Edad de " << nom << ": ";
        cin >> ed;
        datos[i] = PersonaPOO(nom, ed); 
        punteros[i] = &datos[i]; 
    }
    quickSortIndirecto(punteros, 0, n - 1);
    cout << "\n[RESULTADO] Personas ordenadas por edad: \n"; 
    ostringstream ss;
    for(int i = 0; i < n; i++) {
        cout << "- " << *punteros[i] << endl;
        ostringstream tmp; tmp << *punteros[i];
        ss << tmp.str() << (i < n-1 ? " | " : "");
    }
    log.registrar("quicksort_personas", "Ordenadas " + to_string(n) + " personas por edad", ss.str());
    delete[] punteros; delete[] datos;
}

int menu() {
    int opcion;
    cout << "\nMenu Quick Sort Indirecto (POO)\n";
    cout << "\n1 - Ingresar y ordenar Enteros";
    cout << "\n2 - Ingresar y ordenar Caracteres";
    cout << "\n3 - Ingresar y ordenar Personas (Tipo Creado)";
    cout << "\n4 - Salir del menu\n";
    cout << "\nTeclee la opcion deseada : ";
    cin >> opcion;
    return opcion;
}

int main() {
    int opcion;
    Logger log("2do_21-Ordenamiento QuickSort POO");
    
    for (int repeticion = 0; repeticion == 0; ) {
        opcion = menu(); 

        switch (opcion) {
            case 1:
                ordenarEnteros(log);
                break;
            case 2:
                ordenarCaracteres(log);
                break;
            case 3:
                ordenarPersonasPOO(log);
                break;
            case 4:
                cout << "\nHasta luego";
                log.registrar("salir", "Sesion terminada", "OK");
                repeticion++; 
                break;
            default:
                cout << "\nOpcion invalida";
        }
        
        cout << endl;
    }

    log.guardar();
    cout << endl;
    return 0;
}
