#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class CalculadoraRecursiva {
public:
    int multiplicar(int a, int b) {
        if (b == 0) return 0;
        if (b > 0) return a + multiplicar(a, b - 1);
        return 0;
    }

    int dividir(int a, int b) {
        if (b == 0) {
            cout << "Error, division por cero" << endl;
            return 0;
        }
        if (a < b) return 0;
        return 1 + dividir(a - b, b);
    }

    int potencia(int base, int exp) {
        if (exp == 0) return 1;
        return multiplicar(base, potencia(base, exp - 1));
    }

    int factorial(int n) {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }

    int fibonacci(int n) {
        if (n <= 1) return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
};

int main() {

    CalculadoraRecursiva calc;
    int opcion, a, b;
    int resultado = 0;
    string operacion = "";

    do {

        cout << "\n EJERCICIO 14 RECURSIVIDAD " << endl;
        cout << "1. Multiplicacion" << endl;
        cout << "2. Division" << endl;
        cout << "3. Potencia " << endl;
        cout << "4. Factorial" << endl;
        cout << "5. Fibonacci" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1:

                cout << "Ingresa dos numeros: ";
                cin >> a >> b;

                resultado = calc.multiplicar(a, b);
                operacion = "Multiplicacion";

                cout << "Resultado: " << resultado << endl;
                break;

            case 2:

                cout << "Ingresa dividendo y divisor: ";
                cin >> a >> b;

                resultado = calc.dividir(a, b);
                operacion = "Division";

                cout << "Resultado: " << resultado << endl;
                break;

            case 3:

                cout << "Ingresa base y exponente: ";
                cin >> a >> b;

                resultado = calc.potencia(a, b);
                operacion = "Potencia";

                cout << "Resultado: " << resultado << endl;
                break;

            case 4:

                cout << "Ingresa numero: ";
                cin >> a;

                resultado = calc.factorial(a);
                operacion = "Factorial";

                cout << "Factorial: " << resultado << endl;
                break;

            case 5:

                cout << "Ingresa posicion: ";
                cin >> a;

                resultado = calc.fibonacci(a);
                operacion = "Fibonacci";

                cout << "Fibonacci: " << resultado << endl;
                break;
        }

        if(opcion >= 1 && opcion <= 5){

            ofstream txt("datos.txt");

            txt << "Operacion: " << operacion << endl;
            txt << "Resultado: " << resultado << endl;

            txt.close();


            ofstream csv("datos.csv");

            csv << "Operacion,Resultado" << endl;
            csv << operacion << "," << resultado << endl;

            csv.close();


            ofstream xml("datos.xml");

            xml << "<?xml version=\"1.0\"?>" << endl;
            xml << "<datos>" << endl;
            xml << "<operacion>" << operacion << "</operacion>" << endl;
            xml << "<resultado>" << resultado << "</resultado>" << endl;
            xml << "</datos>" << endl;

            xml.close();


            ofstream html("datos.html");

            html << "<html>" << endl;
            html << "<body>" << endl;
            html << "<h1>" << operacion << "</h1>" << endl;
            html << "<p>Resultado: " << resultado << "</p>" << endl;
            html << "</body>" << endl;
            html << "</html>" << endl;

            html.close();


            ofstream json("datos.json");

            json << "{" << endl;
            json << "\"operacion\":\"" << operacion << "\"," << endl;
            json << "\"resultado\":" << resultado << endl;
            json << "}" << endl;

            json.close();
        }

    } while(opcion != 6);

    return 0;
}
