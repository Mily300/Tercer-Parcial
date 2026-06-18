#include "GeneradorFractales.h"

void GeneradorFractales::inicializarTablero() {

    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 64; j++) {
            tableroSierpinski[i][j] = ' ';
        }
    }
}

void GeneradorFractales::generarCantor(int n, string linea) {

    if (n == 0) {
        cout << linea << endl;
        return;
    }

    cout << linea << endl;

    string nuevaLinea = "";

    int segmentLen = linea.length() / 3;

    if (segmentLen < 1)
        return;

    for (int i = 0; i < (int)linea.length(); i++) {

        if (i >= segmentLen && i < 2 * segmentLen)
            nuevaLinea += " ";
        else
            nuevaLinea += linea[i];
    }

    generarCantor(n - 1, nuevaLinea);
}

void GeneradorFractales::generarSierpinski(int x, int y, int n) {

    if (n == 1) {
        tableroSierpinski[x][y] = '*';
        return;
    }

    generarSierpinski(x, y, n / 2);
    generarSierpinski(x + n / 2, y - n / 2, n / 2);
    generarSierpinski(x + n / 2, y + n / 2, n / 2);
}

void GeneradorFractales::imprimirSierpinski() {

    for (int i = 0; i < 32; i++) {

        for (int j = 0; j < 64; j++) {
            cout << tableroSierpinski[i][j];
        }

        cout << endl;
    }
}