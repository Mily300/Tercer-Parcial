#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <string>

using namespace std;

const int MAX_NODOS = 50;
const int INF       = 999999;

class Grafo {
private:
    string nombres[MAX_NODOS];
    int    matriz[MAX_NODOS][MAX_NODOS];
    int    numNodos;

    int buscarNodo(const string& nombre) const {
        for (int i = 0; i < numNodos; i++)
            if (nombres[i] == nombre) return i;
        return -1;
    }

public:

    Grafo() {
        numNodos = 0;
        for (int i = 0; i < MAX_NODOS; i++)
            for (int j = 0; j < MAX_NODOS; j++)
                matriz[i][j] = INF;
    }

    int    getNumNodos()             const { return numNodos; }
    string getNombre(int i)          const { return nombres[i]; }
    int    getPeso(int i, int j)     const { return matriz[i][j]; }

    bool agregarNodo(const string& nombre) {
        if (numNodos >= MAX_NODOS) {
            cout << ">> [Error] Numero maximo de nodos alcanzado." << endl;
            return false;
        }
        if (buscarNodo(nombre) != -1) {
            cout << ">> [Error] El nodo '" << nombre << "' ya existe." << endl;
            return false;
        }
        nombres[numNodos] = nombre;
        matriz[numNodos][numNodos] = 0;
        numNodos++;
        cout << ">> Nodo '" << nombre << "' agregado exitosamente." << endl;
        return true;
    }

    bool agregarArista(const string& origen, const string& destino, int peso) {
        int i = buscarNodo(origen);
        int j = buscarNodo(destino);
        if (i == -1) { cout << ">> [Error] Nodo origen '" << origen << "' no encontrado."   << endl; return false; }
        if (j == -1) { cout << ">> [Error] Nodo destino '" << destino << "' no encontrado." << endl; return false; }
        if (peso <= 0){ cout << ">> [Error] El peso debe ser mayor a 0."                     << endl; return false; }
        matriz[i][j] = peso;
        matriz[j][i] = peso;
        cout << ">> Arista " << origen << " <-> " << destino << " (peso: " << peso << ") agregada." << endl;
        return true;
    }

    void mostrarMatriz() const {
        if (numNodos == 0) { cout << ">> Grafo vacio." << endl; return; }

        cout << "\n--- Matriz de Adyacencia ---" << endl;
        cout << "         ";
        for (int j = 0; j < numNodos; j++)
            cout << nombres[j].substr(0, 7) << "\t";
        cout << endl;

        for (int i = 0; i < numNodos; i++) {
            cout << nombres[i].substr(0, 7) << "\t";
            for (int j = 0; j < numNodos; j++) {
                if (matriz[i][j] == INF) cout << "INF\t";
                else                     cout << matriz[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void mostrarGrafo() const {
        if (numNodos == 0) { cout << ">> Grafo vacio." << endl; return; }

        cout << "\n--- Nodos (" << numNodos << ") ---" << endl;
        for (int i = 0; i < numNodos; i++)
            cout << "  [" << i << "] " << nombres[i] << endl;

        cout << "\n--- Aristas ---" << endl;
        bool hayAristas = false;
        for (int i = 0; i < numNodos; i++) {
            for (int j = i + 1; j < numNodos; j++) {
                if (matriz[i][j] != INF) {
                    cout << "  " << nombres[i] << " <-> " << nombres[j]
                         << "  peso: " << matriz[i][j] << endl;
                    hayAristas = true;
                }
            }
        }
        if (!hayAristas) cout << "  (sin aristas)" << endl;
    }

    void dijkstra(const string& nombreOrigen, const string& nombreDestino) const {
        int origen  = buscarNodo(nombreOrigen);
        int destino = buscarNodo(nombreDestino);

        if (origen  == -1) { cout << ">> [Error] Nodo origen '"  << nombreOrigen  << "' no encontrado." << endl; return; }
        if (destino == -1) { cout << ">> [Error] Nodo destino '" << nombreDestino << "' no encontrado." << endl; return; }

        int  dist[MAX_NODOS];
        int  prev[MAX_NODOS];
        bool visit[MAX_NODOS];

        for (int i = 0; i < numNodos; i++) {
            dist[i]  = INF;
            prev[i]  = -1;
            visit[i] = false;
        }
        dist[origen] = 0;

        for (int iter = 0; iter < numNodos; iter++) {
            int u = -1;
            for (int i = 0; i < numNodos; i++) {
                if (!visit[i] && (u == -1 || dist[i] < dist[u]))
                    u = i;
            }

            if (u == -1 || dist[u] == INF) break; // nodos restantes inaccesibles
            visit[u] = true;

            for (int v = 0; v < numNodos; v++) {
                if (matriz[u][v] != INF && !visit[v]) {
                    int nuevaDist = dist[u] + matriz[u][v];
                    if (nuevaDist < dist[v]) {
                        dist[v] = nuevaDist;
                        prev[v] = u;
                    }
                }
            }
        }

        cout << "\n--- Dijkstra: " << nombreOrigen << " -> " << nombreDestino << " ---" << endl;

        if (dist[destino] == INF) {
            cout << ">> No existe ruta entre '" << nombreOrigen
                 << "' y '" << nombreDestino << "'." << endl;
            return;
        }
        int  pila[MAX_NODOS];
        int  topePila = -1;
        int  actual   = destino;

        while (actual != -1) {
            pila[++topePila] = actual;
            actual = prev[actual];
        }
        cout << "\n  Ruta mas corta:" << endl;
        cout << "  ";
        for (int i = topePila; i >= 0; i--) {
            cout << nombres[pila[i]];
            if (i > 0) cout << " -> ";
        }
        cout << endl;
        cout << "\n  Desglose:" << endl;
        int costoAcum = 0;
        for (int i = topePila; i > 0; i--) {
            int desde  = pila[i];
            int hasta  = pila[i - 1];
            int costo  = matriz[desde][hasta];
            costoAcum += costo;
            cout << "  " << nombres[desde] << " -> " << nombres[hasta]
                 << "  (costo: " << costo << "  acumulado: " << costoAcum << ")" << endl;
        }

        cout << "\n  Distancia total: " << dist[destino] << endl;
    }

    void dijkstraTodos(const string& nombreOrigen) const {
        int origen = buscarNodo(nombreOrigen);
        if (origen == -1) {
            cout << ">> [Error] Nodo origen '" << nombreOrigen << "' no encontrado." << endl;
            return;
        }

        int  dist[MAX_NODOS];
        int  prev[MAX_NODOS];
        bool visit[MAX_NODOS];

        for (int i = 0; i < numNodos; i++) {
            dist[i]  = INF;
            prev[i]  = -1;
            visit[i] = false;
        }
        dist[origen] = 0;

        for (int iter = 0; iter < numNodos; iter++) {
            int u = -1;
            for (int i = 0; i < numNodos; i++)
                if (!visit[i] && (u == -1 || dist[i] < dist[u])) u = i;
            if (u == -1 || dist[u] == INF) break;
            visit[u] = true;
            for (int v = 0; v < numNodos; v++) {
                if (matriz[u][v] != INF && !visit[v]) {
                    int nd = dist[u] + matriz[u][v];
                    if (nd < dist[v]) { dist[v] = nd; prev[v] = u; }
                }
            }
        }

        cout << "\n--- Dijkstra desde '" << nombreOrigen << "' a todos ---" << endl;
        cout << "  Nodo destino\t\tDistancia\tRuta" << endl;
        cout << "  -----------------------------------------------------------" << endl;

        for (int d = 0; d < numNodos; d++) {
            if (d == origen) continue;
            cout << "  " << nombres[d] << "\t\t";
            if (dist[d] == INF) {
                cout << "INF\t\tInaccesible" << endl;
            } else {
                cout << dist[d] << "\t\t";
                int  pila[MAX_NODOS];
                int  tope  = -1;
                int  actual = d;
                while (actual != -1) { pila[++tope] = actual; actual = prev[actual]; }
                for (int i = tope; i >= 0; i--) {
                    cout << nombres[pila[i]];
                    if (i > 0) cout << " -> ";
                }
                cout << endl;
            }
        }
    }
};

#endif
