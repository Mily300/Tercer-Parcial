// PROMEDIO CON ARREGLO
#include <iostream>
#include <fstream>
using namespace std;

class Numeros {
private:
    int arreglo[5];

public:

    void ingresar() {
        for(int i = 0; i < 5; i++) {
            cout << "Ingresa el numero " << i + 1 << ": ";
            cin >> arreglo[i];
        }
    }

    int suma() {
        int s = 0;

        for(int i = 0; i < 5; i++) {
            s += arreglo[i];
        }

        return s;
    }

    float promedio() {
        return suma() / 5.0;
    }

    int maximo() {
        int max = arreglo[0];

        for(int i = 1; i < 5; i++) {
            if(arreglo[i] > max) {
                max = arreglo[i];
            }
        }

        return max;
    }

    int minimo() {
        int min = arreglo[0];

        for(int i = 1; i < 5; i++) {
            if(arreglo[i] < min) {
                min = arreglo[i];
            }
        }

        return min;
    }

    void generarTXT() {
        ofstream archivo("resultado.txt");

        archivo << "RESULTADOS\n";
        archivo << "Suma: " << suma() << endl;
        archivo << "Promedio: " << promedio() << endl;
        archivo << "Maximo: " << maximo() << endl;
        archivo << "Minimo: " << minimo() << endl;

        archivo.close();
    }

    void generarCSV() {
        ofstream archivo("resultado.csv");

        archivo << "Suma,Promedio,Maximo,Minimo\n";
        archivo << suma() << ","
                << promedio() << ","
                << maximo() << ","
                << minimo() << endl;

        archivo.close();
    }

    void generarJSON() {
        ofstream archivo("resultado.json");

        archivo << "{\n";
        archivo << "\"suma\": " << suma() << ",\n";
        archivo << "\"promedio\": " << promedio() << ",\n";
        archivo << "\"maximo\": " << maximo() << ",\n";
        archivo << "\"minimo\": " << minimo() << "\n";
        archivo << "}\n";

        archivo.close();
    }

    void generarXML() {
        ofstream archivo("resultado.xml");

        archivo << "<?xml version=\"1.0\"?>\n";
        archivo << "<resultados>\n";
        archivo << "   <suma>" << suma() << "</suma>\n";
        archivo << "   <promedio>" << promedio() << "</promedio>\n";
        archivo << "   <maximo>" << maximo() << "</maximo>\n";
        archivo << "   <minimo>" << minimo() << "</minimo>\n";
        archivo << "</resultados>\n";

        archivo.close();
    }

    void generarArchivos() {
        generarTXT();
        generarCSV();
        generarJSON();
        generarXML();
    }
};

int main() {

    Numeros obj;

    obj.ingresar();

    cout << "\nSuma: " << obj.suma() << endl;
    cout << "Promedio: " << obj.promedio() << endl;
    cout << "Maximo: " << obj.maximo() << endl;
    cout << "Minimo: " << obj.minimo() << endl;

    obj.generarArchivos();

    cout << "\nArchivos generados correctamente." << endl;

    return 0;
}
