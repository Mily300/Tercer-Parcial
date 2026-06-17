#include <iostream>
#include "CalculadoraNueva.h"

using namespace std;

int main() {

    CalculadoraNueva calc;

    int opcion;
    int a, b;

    do {

        cout << "\n===== CALCULADORA HERENCIA =====\n";
        cout << "1. Suma\n";
        cout << "2. Resta\n";
        cout << "3. Multiplicacion (sumas sucesivas)\n";
        cout << "4. Division (restas sucesivas)\n";
        cout << "5. Potencia (multiplicaciones sucesivas)\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {

        case 1:

            cout << "Numero 1: ";
            cin >> a;

            cout << "Numero 2: ";
            cin >> b;

            cout << "Resultado: "
                 << calc.suma(a,b)
                 << endl;

            break;

        case 2:

            cout << "Numero 1: ";
            cin >> a;

            cout << "Numero 2: ";
            cin >> b;

            cout << "Resultado: "
                 << calc.resta(a,b)
                 << endl;

            break;

        case 3:

            cout << "Numero 1: ";
            cin >> a;

            cout << "Numero 2: ";
            cin >> b;

            cout << "Resultado: "
                 << calc.multiplicacion(a,b)
                 << endl;

            break;

        case 4:

            cout << "Numero 1: ";
            cin >> a;

            cout << "Numero 2: ";
            cin >> b;

            cout << "Resultado: "
                 << calc.division(a,b)
                 << endl;

            break;

        case 5:

            cout << "Base: ";
            cin >> a;

            cout << "Exponente: ";
            cin >> b;

            cout << "Resultado: "
                 << calc.potencia(a,b)
                 << endl;

            break;

        case 6:

            cout << "\nSaliendo...\n";
            break;

        default:

            cout << "\nOpcion invalida\n";
        }

    } while(opcion != 6);

    return 0;
}