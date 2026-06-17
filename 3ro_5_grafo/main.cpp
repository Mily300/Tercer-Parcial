// Practica 3er Deptal - No. 5
// Grafos: Dijkstra + lectura/escritura XML


#include <iostream>
#include <cstdlib>
#include "GrafoXML.h"

using namespace std;

const string RUTA_XML = "grafo.xml";

void capturarGrafo(Grafo& g) {
    int numNodos;
    cout << "\n--- Captura de Grafo ---" << endl;
    cout << "  Cuantos nodos deseas agregar? "; cin >> numNodos;
    for (int i = 0; i < numNodos; i++) {
        string nombre;
        cout << "  Nombre del nodo [" << i + 1 << "]: "; cin >> nombre;
        g.agregarNodo(nombre);
    }

    int numAristas;
    cout << "\n  Cuantas aristas deseas agregar? "; cin >> numAristas;
    for (int i = 0; i < numAristas; i++) {
        string origen, destino;
        int peso;
        cout << "\n  Arista [" << i + 1 << "]:" << endl;
        cout << "    Nodo origen : "; cin >> origen;
        cout << "    Nodo destino: "; cin >> destino;
        cout << "    Peso        : "; cin >> peso;
        g.agregarArista(origen, destino, peso);
    }
}

void menuDijkstra(const Grafo& g) {
    int opcion;
    system("cls");
    cout << "\nMenu Dijkstra\n";
    cout << "\n1 - Ruta mas corta entre dos nodos";
    cout << "\n2 - Rutas mas cortas desde un nodo a todos";
    cout << "\n3 - Regresar\n";
    cout << "\nTeclee la opcion deseada: ";
    cin >> opcion;

    if (opcion == 1) {
        string origen, destino;
        g.mostrarGrafo();
        cout << "\n  Nodo origen : "; cin >> origen;
        cout << "  Nodo destino: "; cin >> destino;
        g.dijkstra(origen, destino);

    } else if (opcion == 2) {
        string origen;
        g.mostrarGrafo();
        cout << "\n  Nodo origen: "; cin >> origen;
        g.dijkstraTodos(origen);
    }
}

int menuGrafo() {
    int opcion;
    system("cls");
    cout << "\nMenu Grafo\n";
    cout << "\n1 - Cargar grafo desde XML";
    cout << "\n2 - Capturar grafo manualmente";
    cout << "\n3 - Guardar grafo actual en XML";
    cout << "\n4 - Mostrar grafo (nodos y aristas)";
    cout << "\n5 - Mostrar matriz de adyacencia";
    cout << "\n6 - Ejecutar Dijkstra";
    cout << "\n7 - Generar XML de ejemplo";
    cout << "\n8 - Salir del programa\n";
    cout << "\nTeclee la opcion deseada: ";
    int op; cin >> op;
    return op;
}

int main() {
    Grafo  g;
    int    opcion;

    for (int repeticion = 0; repeticion == 0; ) {
        opcion = menuGrafo();

        switch (opcion) {

            case 1:
                g = Grafo();
                leerGrafoXML(g, RUTA_XML);
                break;

            case 2:
                g = Grafo();
                capturarGrafo(g);
                break;

            case 3:
                escribirGrafoXML(g, RUTA_XML);
                break;

            case 4:
                g.mostrarGrafo();
                break;

            case 5:
                g.mostrarMatriz();
                break;

            case 6:
                if (g.getNumNodos() == 0) {
                    cout << "\n>> No hay grafo cargado. Carga o captura uno primero." << endl;
                } else {
                    menuDijkstra(g);
                }
                break;

            case 7:
                generarXMLEjemplo(RUTA_XML);
                cout << ">> Ahora puedes cargarlo con la opcion 1." << endl;
                break;

            case 8:
                cout << "\nHasta luego";
                repeticion++;
                break;

            default:
                cout << "\nOpcion invalida";
                break;
        }

        cout << endl;
        if (opcion != 8) system("pause");
    }

    cout << endl;
    system("pause");
    return 0;
}
