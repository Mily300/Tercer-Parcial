//3.-Calculadora basica suma, resta mult, div
#include <iostream>
#include "logger.h"
using namespace std;

class Calculadora {
public:

    float sumar(float a, float b) {
        return a + b;
    }

    float restar(float a, float b) {
        return a - b;
    }

    float multiplicar(float a, float b) {
        return a * b;
    }

    void dividir(float a, float b) {
        if (b != 0) {
            cout << "Resultado: " << a / b << endl;
        } else {
            cout << "Error: No se puede dividir entre 0" << endl;
        }
    }
};

int main() {
    Calculadora Operaciones; 
    float n1, n2;
    int opcion;
    Logger log("3-Calculadora Basica");
    
	do {
    cout << " CALCULADORA \n";
    cout << "\n1 - Suma";
    cout << "\n2 - Resta";
    cout << "\n3 - Multiplicacion";
    cout << "\n4 - Division";
    cout << "\n5 - Salir\n";
    cout << "\nElige una opcion: ";
    cin >> opcion;

	if (opcion >= 1 && opcion <= 4) {
            cout << "Ingresa primer numero: ";
            cin >> n1;
            cout << "Ingresa segundo numero: ";
            cin >> n2;
        }

    switch(opcion) {
        case 1: {
            float r = Operaciones.sumar(n1, n2);
            cout << "Resultado: " << r << endl;
            log.registrar("suma", to_string(n1) + " + " + to_string(n2), r);
            break;
        }
        case 2: {
            float r = Operaciones.restar(n1, n2);
            cout << "Resultado: " << r << endl;
            log.registrar("resta", to_string(n1) + " - " + to_string(n2), r);
            break;
        }
        case 3: {
            float r = Operaciones.multiplicar(n1, n2);
            cout << "Resultado: " << r << endl;
            log.registrar("multiplicacion", to_string(n1) + " * " + to_string(n2), r);
            break;
        }
        case 4:
            if (n2 != 0) {
                log.registrar("division", to_string(n1) + " / " + to_string(n2), n1 / n2);
            } else {
                log.registrar("division", to_string(n1) + " / " + to_string(n2), "Error: division entre cero");
            }
            Operaciones.dividir(n1, n2);
            break;
		case 5:
                cout << "Saliendo" << endl;
                break;
		    
        default:
            cout << "Opcion invalida" << endl;
    }
    
	} while (opcion != 5);

    log.guardar();

    return 0;
}
