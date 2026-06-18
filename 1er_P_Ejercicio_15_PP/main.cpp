#include <iostream>
#include <fstream>
#include <string>

#include "GeneradorFractales.h"

using namespace std;

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

        if (opcion == 1 || opcion == 2) {

            // TXT
            ofstream txt("datos.txt");

            txt << "Fractal generado: "
                << ultimoFractal << endl;

            txt.close();

            // CSV
            ofstream csv("datos.csv");

            csv << "Fractal" << endl;
            csv << ultimoFractal << endl;

            csv.close();

            // XML
            ofstream xml("datos.xml");

            xml << "<?xml version=\"1.0\"?>" << endl;
            xml << "<datos>" << endl;
            xml << "<fractal>"
                << ultimoFractal
                << "</fractal>" << endl;
            xml << "</datos>" << endl;

            xml.close();

            // HTML
            ofstream html("datos.html");

            html << "<html>" << endl;
            html << "<body>" << endl;
            html << "<h1>"
                 << ultimoFractal
                 << "</h1>" << endl;
            html << "</body>" << endl;
            html << "</html>" << endl;

            html.close();

            // JSON
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