//2.-Suma de 2 numeros como parametros
#include <iostream>
#include "logger.h"

using namespace std;

class Calculadora {
    public:
        void sumar(int a, int b) {
            int resultado = a + b;
			cout << "La suma de " << a << " + " << b << " es: " << resultado << "\n";
        }
};

int main() {
    Calculadora operacion;

    operacion.sumar(10,5);
    operacion.sumar(25,15);

    Logger log("2-Suma de Dos");
    log.registrar("suma", "sumar(10, 5)",  15);
    log.registrar("suma", "sumar(25, 15)", 40);
    log.guardar();

    return 0;
}
