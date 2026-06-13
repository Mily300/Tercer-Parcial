//3er Deptal Practica 1 - Escribir y Leer XML

#include <iostream>
#include <cstdlib>
#include "AdtXML.h"

using namespace std;

const string RUTA_BASICOS  = "datos_basicos.xml";
const string RUTA_ARREGLOS = "arreglos.xml";
const string RUTA_TIPOS    = "tipos_creados.xml";
const string RUTA_ADTS     = "adts.xml";
const int    MAX           = 50;


void capturarDatosBasicos() {
    int    entero;
    float  flotante;
    char   caracter;
    int    boolAux;
    string cadena;

    cout << "\n--- Captura de Datos Basicos ---" << endl;
    cout << "  Ingresa un entero               : "; cin >> entero;
    cout << "  Ingresa un flotante             : "; cin >> flotante;
    cout << "  Ingresa un caracter             : "; cin >> caracter;
    cout << "  Ingresa un booleano (1=true/0=false): "; cin >> boolAux;
    cout << "  Ingresa una cadena              : "; cin >> cadena;

    escribirDatosBasicos(RUTA_BASICOS, entero, flotante, caracter, boolAux != 0, cadena);
}

void capturarArreglos() {
    int    enteros[MAX];
    float  flotantes[MAX];
    string cadenas[MAX];
    int ne, nf, nc;

    cout << "\n--- Captura de Arreglos ---" << endl;

    cout << "\n  Cuantos enteros deseas ingresar? "; cin >> ne;
    for (int i = 0; i < ne; i++) {
        cout << "  Entero [" << i + 1 << "]: "; cin >> enteros[i];
    }

    cout << "\n  Cuantos flotantes deseas ingresar? "; cin >> nf;
    for (int i = 0; i < nf; i++) {
        cout << "  Flotante [" << i + 1 << "]: "; cin >> flotantes[i];
    }

    cout << "\n  Cuantas cadenas deseas ingresar? "; cin >> nc;
    for (int i = 0; i < nc; i++) {
        cout << "  Cadena [" << i + 1 << "]: "; cin >> cadenas[i];
    }

    escribirArreglos(RUTA_ARREGLOS, enteros, ne, flotantes, nf, cadenas, nc);
}

void capturarPersona(PersonaPOO& p) {
    string nom, ap, am;
    char   gen;
    int    ed;
    cout << "    Nombre          : "; cin >> nom;
    cout << "    Apellido paterno: "; cin >> ap;
    cout << "    Apellido materno: "; cin >> am;
    cout << "    Genero (M/F)    : "; cin >> gen;
    cout << "    Edad            : "; cin >> ed;
    p = PersonaPOO(nom, ap, am, gen, ed);
}

void capturarAuto(AutoPOO& a) {
    string mar;
    float  pre;
    int    ani;
    cout << "    Marca  : "; cin >> mar;
    cout << "    Precio : "; cin >> pre;
    cout << "    Anio   : "; cin >> ani;
    a = AutoPOO(mar, pre, ani);
}

void capturarTiposCreados() {
    PersonaPOO personas[MAX];
    AutoPOO    autos[MAX];
    int np, na;

    cout << "\n--- Captura de Tipos Creados ---" << endl;

    cout << "\n  Cuantas personas deseas ingresar? "; cin >> np;
    for (int i = 0; i < np; i++) {
        cout << "\n  Persona " << i + 1 << ":" << endl;
        capturarPersona(personas[i]);
    }

    cout << "\n  Cuantos autos deseas ingresar? "; cin >> na;
    for (int i = 0; i < na; i++) {
        cout << "\n  Auto " << i + 1 << ":" << endl;
        capturarAuto(autos[i]);
    }

    escribirTiposCreados(RUTA_TIPOS, personas, np, autos, na);
}

void capturarADTs() {
    PilaDinamica<int>    pila;
    ColaDinamica<string> cola;
    ListaDinamica<float> lista;
    int n;

    cout << "\n--- Captura de ADTs ---" << endl;

    cout << "\n  [Pila de enteros]" << endl;
    cout << "  Cuantos elementos deseas apilar? "; cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cout << "  Elemento [" << i + 1 << "]: "; cin >> val;
        pila.insertar(val);
    }

    cout << "\n  [Cola de cadenas]" << endl;
    cout << "  Cuantos elementos deseas encolar? "; cin >> n;
    for (int i = 0; i < n; i++) {
        string val;
        cout << "  Elemento [" << i + 1 << "]: "; cin >> val;
        cola.insertar(val);
    }

    cout << "\n  [Lista de flotantes]" << endl;
    cout << "  Cuantos elementos deseas insertar? "; cin >> n;
    for (int i = 0; i < n; i++) {
        float val;
        cout << "  Elemento [" << i + 1 << "]: "; cin >> val;
        lista.insertar(val);
    }

    escribirADTs(RUTA_ADTS, pila, cola, lista);
}

void capturarTodo() {
    capturarDatosBasicos();
    capturarArreglos();
    capturarTiposCreados();
    capturarADTs();
}


int menuEscritura() {
    int opcion;
    system("cls");
    cout << "\nMenu Escritura de XML\n";
    cout << "\n1 - Ingresar y escribir datos basicos";
    cout << "\n2 - Ingresar y escribir arreglos";
    cout << "\n3 - Ingresar y escribir tipos creados (Persona y Auto)";
    cout << "\n4 - Ingresar y escribir ADTs (Pila, Cola, Lista)";
    cout << "\n5 - Ingresar y escribir todos los archivos";
    cout << "\n6 - Regresar al menu principal\n";
    cout << "\nTeclee la opcion deseada: ";
    cin >> opcion;
    return opcion;
}


int menuLectura() {
    int opcion;
    system("cls");
    cout << "\nMenu Lectura de XML\n";
    cout << "\n1 - Leer datos basicos";
    cout << "\n2 - Leer arreglos";
    cout << "\n3 - Leer tipos creados (Persona y Auto)";
    cout << "\n4 - Leer ADTs (Pila, Cola, Lista)";
    cout << "\n5 - Leer todos los archivos";
    cout << "\n6 - Regresar al menu principal\n";
    cout << "\nTeclee la opcion deseada: ";
    cin >> opcion;
    return opcion;
}


int menuPrincipal() {
    int opcion;
    system("cls");
    cout << "\nMenu Archivos XML - 3er Deptal Practica 1\n";
    cout << "\n1 - Escritura de archivos XML";
    cout << "\n2 - Lectura de archivos XML";
    cout << "\n3 - Salir del programa\n";
    cout << "\nTeclee la opcion deseada: ";
    cin >> opcion;
    return opcion;
}


int main() {
    int opcion;

    for (int repeticion = 0; repeticion == 0; ) {
        opcion = menuPrincipal();

        switch (opcion) {
            case 1: {
                int opEscritura;
                for (int rep = 0; rep == 0; ) {
                    opEscritura = menuEscritura();
                    switch (opEscritura) {
                        case 1: capturarDatosBasicos(); break;
                        case 2: capturarArreglos();     break;
                        case 3: capturarTiposCreados(); break;
                        case 4: capturarADTs();         break;
                        case 5: capturarTodo();         break;
                        case 6: rep++; break;
                        default: cout << "\nOpcion invalida"; break;
                    }
                    cout << endl;
                    if (opEscritura != 6) system("pause");
                }
                break;
            }
            case 2: {
                int opLectura;
                for (int rep = 0; rep == 0; ) {
                    opLectura = menuLectura();
                    switch (opLectura) {
                        case 1: leerDatosBasicos(RUTA_BASICOS);  break;
                        case 2: leerArreglos(RUTA_ARREGLOS);     break;
                        case 3: leerTiposCreados(RUTA_TIPOS);    break;
                        case 4: leerADTs(RUTA_ADTS);             break;
                        case 5:
                            leerDatosBasicos(RUTA_BASICOS);
                            leerArreglos(RUTA_ARREGLOS);
                            leerTiposCreados(RUTA_TIPOS);
                            leerADTs(RUTA_ADTS);
                            break;
                        case 6: rep++; break;
                        default: cout << "\nOpcion invalida"; break;
                    }
                    cout << endl;
                    if (opLectura != 6) system("pause");
                }
                break;
            }
            case 3:
                cout << "\nHasta luego";
                repeticion++;
                break;
            default:
                cout << "\nOpcion invalida";
                break;
        }

        cout << endl;
        if (opcion != 3) system("pause");
    }

    cout << endl;
    system("pause");
    return 0;
}
