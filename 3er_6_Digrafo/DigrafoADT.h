#ifndef DIGRAFOADT_H
#define DIGRAFOADT_H

#include <iostream>
#include "Digrafo.h"
using namespace std;

class DigrafoADT {
public:

    void crearDigrafo(Digrafo &d) {
        int v;

        cout << "Ingrese cantidad de vertices: ";
        cin >> v;

        if(v > 0 && v <= 10) {
            d.setVertices(v);
            d.limpiarMatriz();

            cout << "\nDigrafo creado correctamente.\n";
        }
        else {
            cout << "\nCantidad invalida.\n";
        }
    }

    void agregarArista(Digrafo &d) {

        if(d.getVertices() == 0) {
            cout << "\nPrimero cree el digrafo.\n";
            return;
        }

        int origen;
        int destino;

        cout << "Vertice origen: ";
        cin >> origen;

        cout << "Vertice destino: ";
        cin >> destino;

        d.agregarArista(origen, destino);
    }

    void mostrarMatriz(Digrafo &d) {

        if(d.getVertices() == 0) {
            cout << "\nPrimero cree el digrafo.\n";
            return;
        }

        cout << "\nMATRIZ DE ADYACENCIA\n\n";

        for(int i = 0; i < d.getVertices(); i++) {

            for(int j = 0; j < d.getVertices(); j++) {

                cout << d.obtenerValor(i,j) << " ";
            }

            cout << endl;
        }
    }

    void mostrarAristas(Digrafo &d) {

        if(d.getVertices() == 0) {
            cout << "\nPrimero cree el digrafo.\n";
            return;
        }

        cout << "\nARISTAS DEL DIGRAFO\n";

        for(int i = 0; i < d.getVertices(); i++) {

            for(int j = 0; j < d.getVertices(); j++) {

                if(d.obtenerValor(i,j) == 1) {

                    cout << i
                         << " -> "
                         << j
                         << endl;
                }
            }
        }
    }
};

#endif
