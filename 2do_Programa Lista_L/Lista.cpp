#include <iostream>
#include <fstream>
#include "lista.h"

using namespace std;

Lista::Lista() {
    n = 0;
}

void Lista::guardarArchivos() {

    ofstream txt("datos.txt");

    txt << "LISTA" << endl;

    if(n == 0){
        txt << "Lista vacia";
    } else {
        for(int i = 0; i < n; i++){
            txt << datos[i] << endl;
        }
    }

    txt.close();


    ofstream csv("datos.csv");

    csv << "Valor" << endl;

    for(int i = 0; i < n; i++){
        csv << datos[i] << endl;
    }

    csv.close();


    ofstream xml("datos.xml");

    xml << "<?xml version=\"1.0\"?>" << endl;
    xml << "<lista>" << endl;

    for(int i = 0; i < n; i++){
        xml << "  <dato>"
            << datos[i]
            << "</dato>" << endl;
    }

    xml << "</lista>" << endl;

    xml.close();


    ofstream html("datos.html");

    html << "<html>" << endl;
    html << "<body>" << endl;
    html << "<h1>Lista</h1>" << endl;

    for(int i = 0; i < n; i++){
        html << "<p>"
             << datos[i]
             << "</p>" << endl;
    }

    html << "</body>" << endl;
    html << "</html>" << endl;

    html.close();


    ofstream json("datos.json");

    json << "{" << endl;
    json << "\"lista\":[";

    for(int i = 0; i < n; i++){

        json << datos[i];

        if(i < n - 1)
            json << ",";
    }

    json << "]" << endl;
    json << "}" << endl;

    json.close();
}

void Lista::agregar(int valor) {

    if (n < 5) {

        datos[n] = valor;
        n++;

        guardarArchivos();

    } else {

        cout << "Lista llena\n";
    }
}

void Lista::mostrar() {

    if (n == 0) {

        cout << "Lista vacia\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << datos[i] << endl;
    }
}
