#include <iostream>
#include <fstream>

#include "Auto.h"
#include "Persona.h"

using namespace std;

int main() {

    Auto autos[10];
    Persona personas[10];

    Auto* ptrA = autos;
    Persona* ptrP = personas;

    int contA = 0;
    int contP = 0;
    int opcion;

    do {

        cout << "\nEJERCICIO 13" << endl;
        cout << "1. Registrar Auto" << endl;
        cout << "2. Registrar Persona" << endl;
        cout << "3. Mostrar Autos" << endl;
        cout << "4. Mostrar Personas" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione opcion: ";
        cin >> opcion;

        if (opcion == 1 && contA < 10) {

            (ptrA + contA)->capturar();
            contA++;

        } else if (opcion == 2 && contP < 10) {

            (ptrP + contP)->capturar();
            contP++;

        } else if (opcion == 3) {

            for (int i = 0; i < contA; i++) {
                (ptrA + i)->mostrar();
            }

        } else if (opcion == 4) {

            for (int i = 0; i < contP; i++) {
                (ptrP + i)->mostrar();
            }
        }

        // TXT
        ofstream txt("datos.txt");

        txt << "AUTOS" << endl;

        for (int i = 0; i < contA; i++) {
            txt << "Precio: "
                << autos[i].precio
                << "  Anio: "
                << autos[i].anio
                << endl;
        }

        txt << endl << "PERSONAS" << endl;

        for (int i = 0; i < contP; i++) {
            txt << personas[i].nombre << " "
                << personas[i].ap << " "
                << personas[i].am << " "
                << personas[i].genero << " "
                << personas[i].edad << endl;
        }

        txt.close();

        // CSV
        ofstream csv("datos.csv");

        csv << "Tipo,Dato1,Dato2,Dato3,Dato4,Dato5" << endl;

        for (int i = 0; i < contA; i++) {
            csv << "Auto,"
                << autos[i].precio << ","
                << autos[i].anio << ",,," << endl;
        }

        for (int i = 0; i < contP; i++) {
            csv << "Persona,"
                << personas[i].nombre << ","
                << personas[i].ap << ","
                << personas[i].am << ","
                << personas[i].genero << ","
                << personas[i].edad << endl;
        }

        csv.close();

        // XML
        ofstream xml("datos.xml");

        xml << "<?xml version=\"1.0\"?>" << endl;
        xml << "<datos>" << endl;

        xml << "<autos>" << endl;

        for (int i = 0; i < contA; i++) {
            xml << "<auto>" << endl;
            xml << "<precio>" << autos[i].precio << "</precio>" << endl;
            xml << "<anio>" << autos[i].anio << "</anio>" << endl;
            xml << "</auto>" << endl;
        }

        xml << "</autos>" << endl;

        xml << "<personas>" << endl;

        for (int i = 0; i < contP; i++) {
            xml << "<persona>" << endl;
            xml << "<nombre>" << personas[i].nombre << "</nombre>" << endl;
            xml << "<apellidoP>" << personas[i].ap << "</apellidoP>" << endl;
            xml << "<apellidoM>" << personas[i].am << "</apellidoM>" << endl;
            xml << "<genero>" << personas[i].genero << "</genero>" << endl;
            xml << "<edad>" << personas[i].edad << "</edad>" << endl;
            xml << "</persona>" << endl;
        }

        xml << "</personas>" << endl;
        xml << "</datos>" << endl;

        xml.close();

        // HTML
        ofstream html("datos.html");

        html << "<html>" << endl;
        html << "<body>" << endl;

        html << "<h1>Autos</h1>" << endl;

        for (int i = 0; i < contA; i++) {
            html << "<p>Precio: "
                 << autos[i].precio
                 << " Año: "
                 << autos[i].anio
                 << "</p>" << endl;
        }

        html << "<h1>Personas</h1>" << endl;

        for (int i = 0; i < contP; i++) {
            html << "<p>"
                 << personas[i].nombre << " "
                 << personas[i].ap << " "
                 << personas[i].am << " "
                 << personas[i].genero << " "
                 << personas[i].edad
                 << "</p>" << endl;
        }

        html << "</body>" << endl;
        html << "</html>" << endl;

        html.close();

        // JSON
        ofstream json("datos.json");

        json << "{" << endl;

        json << "\"autos\":[" << endl;

        for (int i = 0; i < contA; i++) {

            json << "{";
            json << "\"precio\":" << autos[i].precio << ",";
            json << "\"anio\":" << autos[i].anio;
            json << "}";

            if (i < contA - 1)
                json << ",";

            json << endl;
        }

        json << "]," << endl;

        json << "\"personas\":[" << endl;

        for (int i = 0; i < contP; i++) {

            json << "{";
            json << "\"nombre\":\"" << personas[i].nombre << "\",";
            json << "\"apellidoP\":\"" << personas[i].ap << "\",";
            json << "\"apellidoM\":\"" << personas[i].am << "\",";
            json << "\"genero\":\"" << personas[i].genero << "\",";
            json << "\"edad\":" << personas[i].edad;
            json << "}";

            if (i < contP - 1)
                json << ",";

            json << endl;
        }

        json << "]" << endl;
        json << "}" << endl;

        json.close();

    } while (opcion != 5);

    return 0;
}