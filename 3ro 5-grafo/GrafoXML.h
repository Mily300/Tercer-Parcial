#ifndef GRAFXML_H
#define GRAFXML_H

#include <iostream>
#include <fstream>
#include <string>
#include "Grafo.h"

using namespace std;

void gxmlAbrirTag(ofstream& f, const string& tag, int nivel) {
    f << string(nivel * 2, ' ') << "<" << tag << ">\n";
}

void gxmlCerrarTag(ofstream& f, const string& tag, int nivel) {
    f << string(nivel * 2, ' ') << "</" << tag << ">\n";
}

void gxmlEscribir(ofstream& f, const string& tag, const string& valor, int nivel) {
    f << string(nivel * 2, ' ') << "<" << tag << ">" << valor << "</" << tag << ">\n";
}

string gxmlLeerArchivo(const string& ruta) {
    ifstream f(ruta.c_str());
    if (!f.is_open()) return "";
    string contenido = "", linea = "";
    while (getline(f, linea)) contenido += linea + "\n";
    return contenido;
}

string gxmlLeerElemento(const string& xml, const string& tag) {
    string abre   = "<" + tag + ">";
    string cierra = "</" + tag + ">";
    int ini = xml.find(abre);
    if (ini == (int)string::npos) return "";
    ini += abre.size();
    int fin = xml.find(cierra, ini);
    if (fin == (int)string::npos) return "";
    return xml.substr(ini, fin - ini);
}

int gxmlLeerBloques(const string& xml, const string& tag, string bloques[], int maxBloques) {
    string abre   = "<" + tag + ">";
    string cierra = "</" + tag + ">";
    int cnt = 0, pos = 0;
    while (cnt < maxBloques) {
        int ini = xml.find(abre, pos);
        if (ini == (int)string::npos) break;
        ini += abre.size();
        int fin = xml.find(cierra, ini);
        if (fin == (int)string::npos) break;
        bloques[cnt] = xml.substr(ini, fin - ini);
        cnt++;
        pos = fin + cierra.size();
    }
    return cnt;
}

void escribirGrafoXML(const Grafo& g, const string& ruta) {
    ofstream f(ruta.c_str());
    if (!f.is_open()) {
        cout << ">> [Error] No se pudo abrir el archivo: " << ruta << endl;
        return;
    }

    f << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    gxmlAbrirTag(f, "grafo", 0);

    gxmlAbrirTag(f, "nodos", 1);
    for (int i = 0; i < g.getNumNodos(); i++)
        gxmlEscribir(f, "nodo", g.getNombre(i), 2);
    gxmlCerrarTag(f, "nodos", 1);

    gxmlAbrirTag(f, "aristas", 1);
    for (int i = 0; i < g.getNumNodos(); i++) {
        for (int j = i + 1; j < g.getNumNodos(); j++) {
            if (g.getPeso(i, j) != INF) {
                gxmlAbrirTag(f, "arista", 2);
                gxmlEscribir(f, "origen",  g.getNombre(i),            3);
                gxmlEscribir(f, "destino", g.getNombre(j),            3);
                gxmlEscribir(f, "peso",    to_string(g.getPeso(i,j)), 3);
                gxmlCerrarTag(f, "arista", 2);
            }
        }
    }
    gxmlCerrarTag(f, "aristas", 1);

    gxmlCerrarTag(f, "grafo", 0);
    cout << ">> Grafo escrito exitosamente en: " << ruta << endl;
}

bool leerGrafoXML(Grafo& g, const string& ruta) {
    string xml = gxmlLeerArchivo(ruta);
    if (xml.empty()) {
        cout << ">> [Error] No se pudo leer el archivo: " << ruta << endl;
        return false;
    }

    string bNodos[1];
    if (gxmlLeerBloques(xml, "nodos", bNodos, 1) == 0) {
        cout << ">> [Error] No se encontro la seccion <nodos> en el XML." << endl;
        return false;
    }
    string nodosArr[MAX_NODOS];
    int numNodos = gxmlLeerBloques(bNodos[0], "nodo", nodosArr, MAX_NODOS);
    for (int i = 0; i < numNodos; i++)
        g.agregarNodo(nodosArr[i]);

    string bAristas[1];
    if (gxmlLeerBloques(xml, "aristas", bAristas, 1) == 0) {
        cout << ">> [Error] No se encontro la seccion <aristas> en el XML." << endl;
        return false;
    }
    string aristasArr[MAX_NODOS * MAX_NODOS];
    int numAristas = gxmlLeerBloques(bAristas[0], "arista", aristasArr, MAX_NODOS * MAX_NODOS);
    for (int i = 0; i < numAristas; i++) {
        string origen  = gxmlLeerElemento(aristasArr[i], "origen");
        string destino = gxmlLeerElemento(aristasArr[i], "destino");
        int    peso    = atoi(gxmlLeerElemento(aristasArr[i], "peso").c_str());
        g.agregarArista(origen, destino, peso);
    }

    cout << ">> Grafo cargado exitosamente desde: " << ruta << endl;
    cout << "   Nodos: " << numNodos << " | Aristas: " << numAristas << endl;
    return true;
}

void generarXMLEjemplo(const string& ruta) {
    ofstream f(ruta.c_str());
    if (!f.is_open()) {
        cout << ">> [Error] No se pudo crear el archivo: " << ruta << endl;
        return;
    }
    f << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    f << "<grafo>\n";
    f << "  <nodos>\n";
    f << "    <nodo>CiudadA</nodo>\n";
    f << "    <nodo>CiudadB</nodo>\n";
    f << "    <nodo>CiudadC</nodo>\n";
    f << "    <nodo>CiudadD</nodo>\n";
    f << "    <nodo>CiudadE</nodo>\n";
    f << "    <nodo>CiudadF</nodo>\n";
    f << "  </nodos>\n";
    f << "  <aristas>\n";
    f << "    <arista><origen>CiudadA</origen><destino>CiudadB</destino><peso>4</peso></arista>\n";
    f << "    <arista><origen>CiudadA</origen><destino>CiudadC</destino><peso>2</peso></arista>\n";
    f << "    <arista><origen>CiudadB</origen><destino>CiudadC</destino><peso>5</peso></arista>\n";
    f << "    <arista><origen>CiudadB</origen><destino>CiudadD</destino><peso>10</peso></arista>\n";
    f << "    <arista><origen>CiudadC</origen><destino>CiudadE</destino><peso>3</peso></arista>\n";
    f << "    <arista><origen>CiudadD</origen><destino>CiudadF</destino><peso>11</peso></arista>\n";
    f << "    <arista><origen>CiudadE</origen><destino>CiudadD</destino><peso>4</peso></arista>\n";
    f << "    <arista><origen>CiudadE</origen><destino>CiudadF</destino><peso>5</peso></arista>\n";
    f << "  </aristas>\n";
    f << "</grafo>\n";
    cout << ">> XML de ejemplo generado en: " << ruta << endl;
}

#endif
