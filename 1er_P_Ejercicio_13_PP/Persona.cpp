#include "Persona.h"

void Persona::capturar() {
    cout << "Nombre: ";
    cin >> nombre;

    cout << "Apellido paterno: ";
    cin >> ap;

    cout << "Apellido materno: ";
    cin >> am;

    cout << "Genero: ";
    cin >> genero;

    cout << "Edad: ";
    cin >> edad;
}

void Persona::mostrar() {
    cout << nombre << " "
         << ap << " "
         << am
         << "  Gen: "
         << genero
         << "  Edad: "
         << edad << endl;
}