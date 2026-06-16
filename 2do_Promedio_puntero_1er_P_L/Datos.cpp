#include <iostream>
#include <fstream>
#include "datos.h"

using namespace std;

void Datos::llenar() {

    for (int i = 0; i < 5; i++) {

        cout << "Ingresa numero: ";
        cin >> arr[i];
    }
}

void Datos::guardarArchivos(int suma, float promedio, int max, int min) {

    ofstream txt("datos.txt");

    txt << "NUMEROS" << endl;

    for(int i = 0; i < 5; i++){
        txt << arr[i] << endl;
    }

    txt << endl;
    txt << "Suma: " << suma << endl;
    txt << "Promedio: " << promedio << endl;
    txt << "Maximo: " << max << endl;
    txt << "Minimo: " << min << endl;

    txt.close();


    ofstream csv("datos.csv");

    csv << "Numero" << endl;

    for(int i = 0; i < 5; i++){
        csv << arr[i] << endl;
    }

    csv << endl;
    csv << "Suma," << suma << endl;
    csv << "Promedio," << promedio << endl;
    csv << "Maximo," << max << endl;
    csv << "Minimo," << min << endl;

    csv.close();


    ofstream xml("datos.xml");

    xml << "<?xml version=\"1.0\"?>" << endl;
    xml << "<datos>" << endl;

    for(int i = 0; i < 5; i++){
        xml << "  <numero>"
            << arr[i]
            << "</numero>" << endl;
    }

    xml << "  <suma>" << suma << "</suma>" << endl;
    xml << "  <promedio>" << promedio << "</promedio>" << endl;
    xml << "  <maximo>" << max << "</maximo>" << endl;
    xml << "  <minimo>" << min << "</minimo>" << endl;

    xml << "</datos>" << endl;

    xml.close();


    ofstream html("datos.html");

    html << "<html>" << endl;
    html << "<body>" << endl;

    html << "<h1>Resultados</h1>" << endl;

    for(int i = 0; i < 5; i++){
        html << "<p>"
             << arr[i]
             << "</p>" << endl;
    }

    html << "<p>Suma: "
         << suma
         << "</p>" << endl;

    html << "<p>Promedio: "
         << promedio
         << "</p>" << endl;

    html << "<p>Maximo: "
         << max
         << "</p>" << endl;

    html << "<p>Minimo: "
         << min
         << "</p>" << endl;

    html << "</body>" << endl;
    html << "</html>" << endl;

    html.close();


    ofstream json("datos.json");

    json << "{" << endl;

    json << "\"numeros\":[";

    for(int i = 0; i < 5; i++){

        json << arr[i];

        if(i < 4)
            json << ",";
    }

    json << "]," << endl;

    json << "\"suma\":" << suma << "," << endl;
    json << "\"promedio\":" << promedio << "," << endl;
    json << "\"maximo\":" << max << "," << endl;
    json << "\"minimo\":" << min << endl;

    json << "}" << endl;

    json.close();
}

void Datos::calcular() {

    int *p = arr;

    int suma = 0;
    int max = *p;
    int min = *p;

    for (int i = 0; i < 5; i++) {

        suma += *(p + i);

        if (*(p + i) > max)
            max = *(p + i);

        if (*(p + i) < min)
            min = *(p + i);
    }

    float promedio = suma / 5.0;

    cout << "Suma: " << suma << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Maximo: " << max << endl;
    cout << "Minimo: " << min << endl;

    guardarArchivos(suma, promedio, max, min);
}
