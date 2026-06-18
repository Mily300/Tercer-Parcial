#ifndef DIGRAFO_H
#define DIGRAFO_H

#include <iostream>
using namespace std;

class Digrafo {
private:
    int matriz[10][10];
    int vertices;

public:
    Digrafo() {
        vertices = 0;

        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                matriz[i][j] = 0;
            }
        }
    }

    void setVertices(int v) {
        vertices = v;
    }

    int getVertices() {
        return vertices;
    }

    void limpiarMatriz() {
        for(int i = 0; i < vertices; i++) {
            for(int j = 0; j < vertices; j++) {
                matriz[i][j] = 0;
            }
        }
    }

    void agregarArista(int origen, int destino) {
        if(origen >= 0 && origen < vertices &&
           destino >= 0 && destino < vertices) {

            matriz[origen][destino] = 1;
            cout << "\nArista agregada correctamente.\n";
        }
        else {
            cout << "\nVertices invalidos.\n";
        }
    }

    int obtenerValor(int i, int j) {
        return matriz[i][j];
    }
};

#endif
