#include "Auto.h"

void Auto::capturar() {
    cout << "Ingrese precio del auto: ";
    cin >> precio;

    cout << "Ingrese año del auto: ";
    cin >> anio;
}

void Auto::mostrar() {
    cout << "Precio: " << precio
         << "  Año: " << anio << endl;
}