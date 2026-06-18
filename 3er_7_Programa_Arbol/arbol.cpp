#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include "arbol.h"

using namespace std;

void Arbol::leerXML() {
    conexiones.clear();
    grafo.clear(); 

    ifstream archivo("arbol.xml");
    if(!archivo) {
        cout << "\n[Error] No se pudo abrir arbol.xml. Verifica que este en la misma carpeta.\n";
        return;
    }

    string linea;
    while(getline(archivo, linea)) {
        size_t p1 = linea.find("origen=\"");
        size_t p2 = linea.find("destino=\"");
        size_t p3 = linea.find("peso=\"");

        if(p1 != string::npos && p2 != string::npos && p3 != string::npos) {
            Conexion c;
            

            c.origen  = linea[p1 + 8];
            c.destino = linea[p2 + 9];
            c.peso    = stoi(linea.substr(p3 + 6, linea.find("\"", p3 + 6) - (p3 + 6)));

            conexiones.push_back(c);
            
            grafo[c.origen].push_back(make_pair(c.destino, c.peso));

            cout << "\nConexion cargada: " << c.origen << " -> " << c.destino << " (Peso: " << c.peso << ")";
        }
    }
    archivo.close();
    cout << "\n\nXML cargado correctamente.\n";
}

void Arbol::mostrarConexiones() {
    if(conexiones.empty()) {
        cout << "\nNo hay conexiones cargadas en memoria.\n";
        return;
    }

    cout << "\n--- CONEXIONES REGISTRADAS EN EL XML ---\n";
    for(size_t i = 0; i < conexiones.size(); i++) {
        cout << conexiones[i].origen << " -> " << conexiones[i].destino << " | Peso: " << conexiones[i].peso << endl;
    }
}

void Arbol::dijkstra(char origen, char destino) {
    const int INF = 99999;
    map<char, int> dist;
    map<char, char> padre;

    for (auto const& x : grafo) {
        dist[x.first] = INF;
        padre[x.first] = '-';
        for (auto const& vecino : x.second) {
            dist[vecino.first] = INF;
            padre[vecino.first] = '-';
        }
    }

    if (dist.find(origen) == dist.end()) {
        cout << "\n[Error] El nodo origen '" << origen << "' no existe en el XML.\n";
        return;
    }
    if (dist.find(destino) == dist.end()) {
        cout << "\n[Error] El nodo destino '" << destino << "' no existe en el XML.\n";
        return;
    }

    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;

    dist[origen] = 0;
    pq.push(make_pair(0, origen));

    while(!pq.empty()) {
        char actual = pq.top().second;
        pq.pop();

        if (actual == destino) break;

        for(size_t i = 0; i < grafo[actual].size(); i++) {
            char vecino = grafo[actual][i].first;
            int peso = grafo[actual][i].second;

            if(dist[actual] + peso < dist[vecino]) {
                dist[vecino] = dist[actual] + peso;
                padre[vecino] = actual;
                pq.push(make_pair(dist[vecino], vecino));
            }
        }
    }
    cout << "\n--- BUSQUEDA DE RUTA: " << origen << " -> " << destino << " ---\n";
    
    if (dist[destino] == INF) {
        cout << "No existe un camino disponible para ir desde '" << origen << "' hasta '" << destino << "'.\n";
    } else {
        cout << "Distancia Total (Costo mínimo): " << dist[destino] << "\n";
        cout << "Ruta Optima: ";
        vector<char> ruta;
        char temp = destino;
        while(temp != '-') {
            ruta.push_back(temp);
            temp = padre[temp];
        }

        for(int j = (int)ruta.size() - 1; j >= 0; j--) {
            cout << ruta[j];
            if(j > 0) cout << " -> ";
        }
        cout << "\n";
    }
}