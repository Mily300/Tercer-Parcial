//4.-Calculadora con variantes en las funciones (reciben 2 parametros, 0 parametros o 3 parametros) 
#include <iostream>
#include "logger.h"
using namespace std;

class CalculadoraSobrecarga {
public:
    void sumar() {
        float a = 10, b = 20; 
        cout << "sin parametros (10 + 20): " << a + b << endl;
    }

    float sumar(float a, float b) {
        return a + b;
    }

    float sumar(float a, float b, float c) {
        return a + b + c;
    }
};

int main() {
    CalculadoraSobrecarga Calculadora;
    int opcion;
    Logger log("4-Calculadora Sobrecarga");
    
	do {
    cout << "CALCULADORA SOBRECARGA\n";
    cout << "\n1 - Sumar (sin parametros)";
    cout << "\n2 - Sumar (2 numeros)";
    cout << "\n3 - Sumar (3 numeros)";
    cout << "\n4 - Salir\n" << endl;
    cout << "\nElige una opcion: ";
    cin >> opcion;

    switch(opcion) {
        case 1:
            Calculadora.sumar(); 
            log.registrar("sumar()", "sin parametros (10 + 20)", 30);
            break;
            
        case 2: {
            float n1, n2;
            cout << "Ingresa dos numeros: ";
            cin >> n1 >> n2;
            float r = Calculadora.sumar(n1, n2);
            cout << "Resultado: " << r << endl;
            log.registrar("sumar(a,b)", to_string(n1) + " + " + to_string(n2), r);
            break;
        }

        case 3: {
            float n1, n2, n3;
            cout << "Ingresa tres numeros: ";
            cin >> n1 >> n2 >> n3;
            float r = Calculadora.sumar(n1, n2, n3);
            cout << "Resultado: " << r << endl;
            log.registrar("sumar(a,b,c)", to_string(n1) + " + " + to_string(n2) + " + " + to_string(n3), r);
            break;
        }
        
		case 4:
                cout << "Saliendo" << endl;
                break;
                
        default:
            cout << "Opcion no valida" << endl;
    }
    
	} while (opcion != 4);

    log.guardar();

    return 0;
}
