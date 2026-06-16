#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class GeneradorFractales {
public:
    char tableroSierpinski[32][64];

    void inicializarTablero() {
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 64; j++) {
                tableroSierpinski[i][j] = ' ';
            }
        }
    }

    void generarCantor(int n, string linea) {
        if (n == 0) {
            cout << linea << endl;
            return;
        }

        cout << linea << endl;

        string nuevaLinea = "";
        int segmentLen = linea.length() / 3;

        if (segmentLen < 1) return;

        for (int i = 0; i < (int)linea.length(); i++) {
            if (i >= segmentLen && i < 2 * segmentLen)
                nuevaLinea += " ";
            else
                nuevaLinea += linea[i];
        }

        generarCantor(n - 1, nuevaLinea);
    }

    void generarSierpinski(int x, int y, int n) {
        if (n == 1) {
            tableroSierpinski[x][y] = '*';
            return;
        }

        generarSierpinski(x, y, n / 2);
        generarSierpinski(x + n / 2, y - n / 2, n / 2);
        generarSierpinski(x + n / 2, y + n / 2, n / 2);
    }

    void imprimirSierpinski() {
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 64; j++) {
                cout << tableroSierpinski[i][j];
            }
            cout << endl;
        }
    }
};

int main() {

    GeneradorFractales generador;
    int opcion, niveles;
    string inicialCantor = "---------------------------";
    string ultimoFractal = "";

    do {

        cout << "\n EJERCICIO 15-FRACTALES RECURSIVOS" << endl;
        cout << "1. Polvo de Cantor" << endl;
        cout << "2. Triangulo de Sierpinski" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione opcion: ";
        cin >> opcion;

        if (opcion == 1) {

            cout << "Introduce el numero de niveles: ";
            cin >> niveles;

            cout << "\nGenerando Polvo de Cantor\n";

            generador.generarCantor(niveles, inicialCantor);

            ultimoFractal = "Polvo de Cantor";

        }
        else if (opcion == 2) {

            cout << "\nGenerando Triangulo de Sierpinski...\n";

            generador.inicializarTablero();
            generador.generarSierpinski(0, 31, 32);
            generador.imprimirSierpinski();

            ultimoFractal = "Triangulo de Sierpinski";
        }

        if(opcion == 1 || opcion == 2){

            ofstream txt("datos.txt");

            txt << "Fractal generado: "
                << ultimoFractal << endl;

            txt.close();


            ofstream csv("datos.csv");

            csv << "Fractal" << endl;
            csv << ultimoFractal << endl;

            csv.close();


            ofstream xml("datos.xml");

            xml << "<?xml version=\"1.0\"?>" << endl;
            xml << "<datos>" << endl;
            xml << "<fractal>"
                << ultimoFractal
                << "</fractal>" << endl;
            xml << "</datos>" << endl;

            xml.close();


            ofstream html("datos.html");

            html << "<html>" << endl;
            html << "<body>" << endl;
            html << "<h1>"
                 << ultimoFractal
                 << "</h1>" << endl;
            html << "</body>" << endl;
            html << "</html>" << endl;

            html.close();


            ofstream json("datos.json");

            json << "{" << endl;
            json << "\"fractal\":\""
                 << ultimoFractal
                 << "\"" << endl;
            json << "}" << endl;

            json.close();
        }

    } while (opcion != 3);

    return 0;
}
