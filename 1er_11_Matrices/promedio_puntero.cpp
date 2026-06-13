// PROMEDIO CON PUNTERO AL ARREGLO
#include <iostream>
#include <fstream>
using namespace std;

class Numeros {
private:
    int arreglo[5];
    int *ptr;

public:

    Numeros() {
        ptr = arreglo;
    }

    void ingresar() {
        int dato;

        cout << "Ingrese 5 numeros:" << endl;

        for(int i = 0; i < 5; i++) {
            cout << "Numero " << i + 1 << ": ";
            cin >> dato;
            *(ptr + i) = dato;
        }
    }

    void calcular() {
        int suma = 0;
        int maximo = *ptr;
        int minimo = *ptr;

        for(int i = 0; i < 5; i++) {
            suma += *(ptr + i);

            if(*(ptr + i) > maximo) {
                maximo = *(ptr + i);
            }

            if(*(ptr + i) < minimo) {
                minimo = *(ptr + i);
            }
        }

        float promedio = suma / 5.0;

        cout << "\nResultados:" << endl;
        cout << "Suma: " << suma << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "Maximo: " << maximo << endl;
        cout << "Minimo: " << minimo << endl;

        generarTXT(suma, promedio, maximo, minimo);
        generarCSV(suma, promedio, maximo, minimo);
        generarJSON(suma, promedio, maximo, minimo);
        generarXML(suma, promedio, maximo, minimo);

        cout << "\nArchivos generados correctamente." << endl;
    }

    void generarTXT(int suma, float promedio, int maximo, int minimo) {
        ofstream archivo("resultado.txt");

        archivo << "RESULTADOS" << endl;
        archivo << "Suma: " << suma << endl;
        archivo << "Promedio: " << promedio << endl;
        archivo << "Maximo: " << maximo << endl;
        archivo << "Minimo: " << minimo << endl;

        archivo.close();
    }

    void generarCSV(int suma, float promedio, int maximo, int minimo) {
        ofstream archivo("resultado.csv");

        archivo << "Suma,Promedio,Maximo,Minimo" << endl;
        archivo << suma << ","
                << promedio << ","
                << maximo << ","
                << minimo << endl;

        archivo.close();
    }

    void generarJSON(int suma, float promedio, int maximo, int minimo) {
        ofstream archivo("resultado.json");

        archivo << "{" << endl;
        archivo << "\"suma\": " << suma << "," << endl;
        archivo << "\"promedio\": " << promedio << "," << endl;
        archivo << "\"maximo\": " << maximo << "," << endl;
        archivo << "\"minimo\": " << minimo << endl;
        archivo << "}" << endl;

        archivo.close();
    }

    void generarXML(int suma, float promedio, int maximo, int minimo) {
        ofstream archivo("resultado.xml");

        archivo << "<?xml version=\"1.0\"?>" << endl;
        archivo << "<resultados>" << endl;
        archivo << "   <suma>" << suma << "</suma>" << endl;
        archivo << "   <promedio>" << promedio << "</promedio>" << endl;
        archivo << "   <maximo>" << maximo << "</maximo>" << endl;
        archivo << "   <minimo>" << minimo << "</minimo>" << endl;
        archivo << "</resultados>" << endl;

        archivo.close();
    }
};

int main() {
    Numeros obj;

    obj.ingresar();
    obj.calcular();

    return 0;
}
