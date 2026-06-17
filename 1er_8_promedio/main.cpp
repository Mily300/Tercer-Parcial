// PROMEDIO, MEDIA, SUMA, MAXIMO Y MINIMO
#include <iostream>
#include <fstream>
using namespace std;

class Numeros {
private:
    int numeros[5];

public:

    void ingresar() {
        for(int i = 0; i < 5; i++) {
            cout << "Ingrese numero " << i + 1 << ": ";
            cin >> numeros[i];
        }
    }

    int suma() {
        int s = 0;

        for(int i = 0; i < 5; i++) {
            s += numeros[i];
        }

        return s;
    }

    float promedio() {
        return suma() / 5.0;
    }

    float media() {
        return promedio();
    }

    int maximo() {
        int max = numeros[0];

        for(int i = 1; i < 5; i++) {
            if(numeros[i] > max) {
                max = numeros[i];
            }
        }

        return max;
    }

    int minimo() {
        int min = numeros[0];

        for(int i = 1; i < 5; i++) {
            if(numeros[i] < min) {
                min = numeros[i];
            }
        }

        return min;
    }

    void generarTXT() {
        ofstream archivo("resultado.txt");

        archivo << "RESULTADOS\n";
        archivo << "Suma: " << suma() << endl;
        archivo << "Promedio: " << promedio() << endl;
        archivo << "Media: " << media() << endl;
        archivo << "Maximo: " << maximo() << endl;
        archivo << "Minimo: " << minimo() << endl;

        archivo.close();
    }

    void generarCSV() {
        ofstream archivo("resultado.csv");

        archivo << "Suma,Promedio,Media,Maximo,Minimo\n";
        archivo << suma() << ","
                << promedio() << ","
                << media() << ","
                << maximo() << ","
                << minimo() << endl;

        archivo.close();
    }

    void generarJSON() {
        ofstream archivo("resultado.json");

        archivo << "{\n";
        archivo << "\"suma\": " << suma() << ",\n";
        archivo << "\"promedio\": " << promedio() << ",\n";
        archivo << "\"media\": " << media() << ",\n";
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
        archivo << "   <media>" << media() << "</media>\n";
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

    void mostrarResultados() {
        cout << "\nRESULTADOS\n";
        cout << "Suma: " << suma() << endl;
        cout << "Promedio: " << promedio() << endl;
        cout << "Media: " << media() << endl;
        cout << "Maximo: " << maximo() << endl;
        cout << "Minimo: " << minimo() << endl;
    }
};

int main() {
    Numeros obj;

    obj.ingresar();
    obj.mostrarResultados();
    obj.generarArchivos();

    cout << "\nArchivos generados correctamente.\n";

    return 0;
}