#ifndef ARBOL_H
#define ARBOL_H

#include <vector>
#include <string>
#include <map>

using namespace std;

struct Conexion {
    char origen;   
    char destino;  
    int peso;      
};

class Arbol {
private:
    vector<Conexion> conexiones;
    

    map<char, vector<pair<char, int>>> grafo; 

public:
    void leerXML();
    void mostrarConexiones();
    void dijkstra(char origen, char destino);
};

#endif