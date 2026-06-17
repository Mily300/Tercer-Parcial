#include <iostream>
#include "CalculadoraNueva.h"
using namespace std;

int main() {
    CalculadoraNueva calc;
    int opcion;

    do {
        cout << "\n===== CALCULADORA CON HERENCIA =====\n";
        cout << "1. Suma\n";
        cout << "2. Resta\n";
        cout << "3. Multiplicacion\n";
        cout << "4. Division\n";
        cout << "5. Potencia\n";
        cout << "6. Raiz del primer numero\n";
        cout << "7. Modulo\n";
        cout << "8. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
        case 1:
            calc.capturar();
            cout << "Resultado: " << calc.sumar() << endl;
            break;

        case 2:
            calc.capturar();
            cout << "Resultado: " << calc.restar() << endl;
            break;

        case 3:
            calc.capturar();
            cout << "Resultado: " << calc.multiplicar() << endl;
            break;

        case 4:
            calc.capturar();
            cout << "Resultado: " << calc.dividir() << endl;
            break;

        case 5:
            calc.capturar();
            cout << "Resultado: " << calc.potencia() << endl;
            break;

        case 6:
            calc.capturar();
            cout << "Resultado: " << calc.raizPrimerNumero() << endl;
            break;

        case 7:
            calc.capturar();
            cout << "Resultado: " << calc.modulo() << endl;
            break;

        case 8:
            cout << "\nSaliendo...\n";
            break;

        default:
            cout << "\nOpcion no valida.\n";
        }

    } while(opcion != 8);

    return 0;
}