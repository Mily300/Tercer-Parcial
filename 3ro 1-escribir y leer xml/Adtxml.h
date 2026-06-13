#ifndef ADTXML_H
#define ADTXML_H
#include <iostream>
#include <fstream>
#include <string>
#include "Tipos.h"

using namespace std;


template <class T>
struct Nodo {
    T        dato;
    Nodo<T>* siguiente;

    Nodo(T val) {
        dato      = val;
        siguiente = NULL;
    }
};

// Interfaz ADT
template <class T>
class IADT {
public:
    virtual void insertar(T elemento) = 0;
    virtual void eliminar()           = 0;
    virtual bool estaVacia()    const = 0;
    virtual void mostrar()      const = 0;
    virtual ~IADT() {}
};

// PILA dinamica
template <class T>
class PilaDinamica : public IADT<T> {
private:
    Nodo<T>* tope;

public:
    PilaDinamica() { tope = NULL; }

    ~PilaDinamica() {
        while (tope != NULL) {
            Nodo<T>* aux = tope;
            tope = tope->siguiente;
            delete aux;
        }
    }

    void insertar(T elemento) override {
        Nodo<T>* nuevoNodo   = new Nodo<T>(elemento);
        nuevoNodo->siguiente = tope;
        tope = nuevoNodo;
        cout << ">> Elemento " << elemento << " apilado exitosamente." << endl;
    }

    void eliminar() override {
        if (estaVacia()) {
            cout << ">> La pila esta vacia, no se puede desapilar." << endl;
        } else {
            Nodo<T>* aux = tope;
            cout << ">> Elemento " << tope->dato << " desapilado exitosamente." << endl;
            tope = tope->siguiente;
            delete aux;
        }
    }

    bool estaVacia() const override { return tope == NULL; }

    void mostrar() const override {
        if (estaVacia()) { cout << "Pila vacia." << endl; return; }
        cout << "Pila (tope -> fondo): ";
        Nodo<T>* aux = tope;
        while (aux != NULL) {
            cout << "[ " << aux->dato << " ] -> ";
            aux = aux->siguiente;
        }
        cout << "NULL" << endl;
    }

    int toArreglo(T arr[], int max) const {
        int n = 0;
        Nodo<T>* aux = tope;
        while (aux != NULL) { n++; aux = aux->siguiente; }
        if (n > max) n = max;
        aux = tope;
        for (int i = n - 1; i >= 0; i--) {
            arr[i] = aux->dato;
            aux = aux->siguiente;
        }
        return n;
    }
};

// COLA dinamica
template <class T>
class ColaDinamica : public IADT<T> {
private:
    Nodo<T>* frente;
    Nodo<T>* final_;

public:
    ColaDinamica() { frente = NULL; final_ = NULL; }

    ~ColaDinamica() {
        while (frente != NULL) {
            Nodo<T>* aux = frente;
            frente = frente->siguiente;
            delete aux;
        }
    }

    void insertar(T elemento) override {
        Nodo<T>* nuevoNodo = new Nodo<T>(elemento);
        if (estaVacia()) {
            frente = nuevoNodo;
            final_ = nuevoNodo;
        } else {
            final_->siguiente = nuevoNodo;
            final_ = nuevoNodo;
        }
        cout << ">> Elemento " << elemento << " encolado exitosamente." << endl;
    }

    void eliminar() override {
        if (estaVacia()) {
            cout << ">> La cola esta vacia, no se puede desencolar." << endl;
        } else {
            Nodo<T>* aux = frente;
            cout << ">> Elemento " << frente->dato << " desencolado exitosamente." << endl;
            frente = frente->siguiente;
            if (frente == NULL) final_ = NULL;
            delete aux;
        }
    }

    bool estaVacia() const override { return frente == NULL; }

    void mostrar() const override {
        if (estaVacia()) { cout << "Cola vacia." << endl; return; }
        cout << "Cola (frente -> final): ";
        Nodo<T>* aux = frente;
        while (aux != NULL) {
            cout << "[ " << aux->dato << " ] -> ";
            aux = aux->siguiente;
        }
        cout << "NULL" << endl;
    }

    int toArreglo(T arr[], int max) const {
        int n = 0;
        Nodo<T>* aux = frente;
        while (aux != NULL && n < max) {
            arr[n] = aux->dato;
            n++;
            aux = aux->siguiente;
        }
        return n;
    }
};

// LISTA dinamica
template <class T>
class ListaDinamica : public IADT<T> {
private:
    Nodo<T>* cabeza;

public:
    ListaDinamica() { cabeza = NULL; }

    ~ListaDinamica() {
        while (cabeza != NULL) {
            Nodo<T>* aux = cabeza;
            cabeza = cabeza->siguiente;
            delete aux;
        }
    }

    void insertar(T elemento) override {
        Nodo<T>* nuevoNodo = new Nodo<T>(elemento);
        if (cabeza == NULL) {
            cabeza = nuevoNodo;
        } else {
            Nodo<T>* aux = cabeza;
            while (aux->siguiente != NULL) aux = aux->siguiente;
            aux->siguiente = nuevoNodo;
        }
        cout << ">> Elemento " << elemento << " insertado en la lista exitosamente." << endl;
    }

    void eliminar() override {
        if (estaVacia()) {
            cout << ">> La lista esta vacia, no hay elementos para eliminar." << endl;
        } else {
            Nodo<T>* aux = cabeza;
            cout << ">> Elemento " << cabeza->dato << " eliminado de la lista exitosamente." << endl;
            cabeza = cabeza->siguiente;
            delete aux;
        }
    }

    bool estaVacia() const override { return cabeza == NULL; }

    void mostrar() const override {
        if (estaVacia()) { cout << "Lista vacia." << endl; return; }
        cout << "Lista: ";
        Nodo<T>* aux = cabeza;
        while (aux != NULL) {
            cout << "[ " << aux->dato << " ] -> ";
            aux = aux->siguiente;
        }
        cout << "NULL" << endl;
    }

    int toArreglo(T arr[], int max) const {
        int n = 0;
        Nodo<T>* aux = cabeza;
        while (aux != NULL && n < max) {
            arr[n] = aux->dato;
            n++;
            aux = aux->siguiente;
        }
        return n;
    }
};

// XML - Funciones auxiliares de escritura
void xmlAbrirTag(ofstream& f, const string& tag, int nivel) {
    f << string(nivel * 2, ' ') << "<" << tag << ">\n";
}

void xmlCerrarTag(ofstream& f, const string& tag, int nivel) {
    f << string(nivel * 2, ' ') << "</" << tag << ">\n";
}

void xmlEscribir(ofstream& f, const string& tag, const string& valor, int nivel) {
    f << string(nivel * 2, ' ') << "<" << tag << ">" << valor << "</" << tag << ">\n";
}

// XML - Escritura con datos del usuario
void escribirDatosBasicos(const string& ruta,
                          int entero, float flotante,
                          char caracter, bool booleano,
                          const string& cadena) {
    ofstream f(ruta.c_str());
    f << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    xmlAbrirTag(f, "datos_basicos", 0);
    xmlEscribir(f, "entero",   to_string(entero),           1);
    xmlEscribir(f, "flotante", to_string(flotante),         1);
    xmlEscribir(f, "caracter", string(1, caracter),         1);
    xmlEscribir(f, "booleano", booleano ? "true" : "false", 1);
    xmlEscribir(f, "cadena",   cadena,                      1);
    xmlCerrarTag(f, "datos_basicos", 0);
    cout << ">> Datos basicos escritos en: " << ruta << endl;
}

void escribirArreglos(const string& ruta,
                      int enteros[],    int ne,
                      float flotantes[], int nf,
                      string cadenas[], int nc) {
    ofstream f(ruta.c_str());
    f << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    xmlAbrirTag(f, "arreglos", 0);

    xmlAbrirTag(f, "arreglo_enteros", 1);
    for (int i = 0; i < ne; i++) xmlEscribir(f, "item", to_string(enteros[i]), 2);
    xmlCerrarTag(f, "arreglo_enteros", 1);

    xmlAbrirTag(f, "arreglo_flotantes", 1);
    for (int i = 0; i < nf; i++) xmlEscribir(f, "item", to_string(flotantes[i]), 2);
    xmlCerrarTag(f, "arreglo_flotantes", 1);

    xmlAbrirTag(f, "arreglo_cadenas", 1);
    for (int i = 0; i < nc; i++) xmlEscribir(f, "item", cadenas[i], 2);
    xmlCerrarTag(f, "arreglo_cadenas", 1);

    xmlCerrarTag(f, "arreglos", 0);
    cout << ">> Arreglos escritos en: " << ruta << endl;
}

void escribirTiposCreados(const string& ruta,
                          PersonaPOO personas[], int np,
                          AutoPOO autos[],       int na) {
    ofstream f(ruta.c_str());
    f << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    xmlAbrirTag(f, "tipos_creados", 0);

    xmlAbrirTag(f, "personas", 1);
    for (int i = 0; i < np; i++) {
        xmlAbrirTag(f, "persona", 2);
        xmlEscribir(f, "nombre",           personas[i].getNombre(),            3);
        xmlEscribir(f, "apellido_paterno", personas[i].getApellidoPaterno(),   3);
        xmlEscribir(f, "apellido_materno", personas[i].getApellidoMaterno(),   3);
        xmlEscribir(f, "genero",           string(1, personas[i].getGenero()), 3);
        xmlEscribir(f, "edad",             to_string(personas[i].getEdad()),   3);
        xmlCerrarTag(f, "persona", 2);
    }
    xmlCerrarTag(f, "personas", 1);

    xmlAbrirTag(f, "autos", 1);
    for (int i = 0; i < na; i++) {
        xmlAbrirTag(f, "auto", 2);
        xmlEscribir(f, "marca",   autos[i].getMarca(),             3);
        xmlEscribir(f, "precio",  to_string(autos[i].getPrecio()), 3);
        xmlEscribir(f, "anio",    to_string(autos[i].getAnio()),   3);
        xmlCerrarTag(f, "auto", 2);
    }
    xmlCerrarTag(f, "autos", 1);

    xmlCerrarTag(f, "tipos_creados", 0);
    cout << ">> Tipos creados escritos en: " << ruta << endl;
}

void escribirADTs(const string& ruta,
                  PilaDinamica<int>&    pila,
                  ColaDinamica<string>& cola,
                  ListaDinamica<float>& lista) {
    const int MAX = 50;
    int    pilaArr[MAX];   int np = pila.toArreglo(pilaArr,  MAX);
    string colaArr[MAX];   int nc = cola.toArreglo(colaArr,  MAX);
    float  listaArr[MAX];  int nl = lista.toArreglo(listaArr, MAX);

    ofstream f(ruta.c_str());
    f << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    xmlAbrirTag(f, "adts", 0);

    xmlAbrirTag(f, "pila_enteros", 1);
    xmlEscribir(f, "tipo", "PilaDinamica<int>", 2);
    xmlAbrirTag(f, "elementos", 2);
    for (int i = 0; i < np; i++) xmlEscribir(f, "item", to_string(pilaArr[i]), 3);
    xmlCerrarTag(f, "elementos", 2);
    xmlCerrarTag(f, "pila_enteros", 1);

    xmlAbrirTag(f, "cola_cadenas", 1);
    xmlEscribir(f, "tipo", "ColaDinamica<string>", 2);
    xmlAbrirTag(f, "elementos", 2);
    for (int i = 0; i < nc; i++) xmlEscribir(f, "item", colaArr[i], 3);
    xmlCerrarTag(f, "elementos", 2);
    xmlCerrarTag(f, "cola_cadenas", 1);

    xmlAbrirTag(f, "lista_flotantes", 1);
    xmlEscribir(f, "tipo", "ListaDinamica<float>", 2);
    xmlAbrirTag(f, "elementos", 2);
    for (int i = 0; i < nl; i++) xmlEscribir(f, "item", to_string(listaArr[i]), 3);
    xmlCerrarTag(f, "elementos", 2);
    xmlCerrarTag(f, "lista_flotantes", 1);

    xmlCerrarTag(f, "adts", 0);
    cout << ">> ADTs escritos en: " << ruta << endl;
}

// XML - Lectura
string xmlLeerArchivo(const string& ruta) {
    ifstream f(ruta.c_str());
    if (!f.is_open()) return "";
    string contenido = "", linea = "";
    while (getline(f, linea)) contenido += linea + "\n";
    return contenido;
}

string xmlLeerElemento(const string& xml, const string& tag) {
    string abre   = "<" + tag + ">";
    string cierra = "</" + tag + ">";
    int ini = xml.find(abre);
    if (ini == (int)string::npos) return "";
    ini += abre.size();
    int fin = xml.find(cierra, ini);
    if (fin == (int)string::npos) return "";
    return xml.substr(ini, fin - ini);
}

int xmlLeerBloques(const string& xml, const string& tag, string bloques[], int maxBloques) {
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

void leerDatosBasicos(const string& ruta) {
    string xml = xmlLeerArchivo(ruta);
    if (xml.empty()) { cout << ">> [Error] No se pudo leer: " << ruta << endl; return; }
    cout << "\n--- Leyendo Datos Basicos ---" << endl;
    cout << "  Entero   : " << xmlLeerElemento(xml, "entero")   << endl;
    cout << "  Flotante : " << xmlLeerElemento(xml, "flotante") << endl;
    cout << "  Caracter : " << xmlLeerElemento(xml, "caracter") << endl;
    cout << "  Booleano : " << xmlLeerElemento(xml, "booleano") << endl;
    cout << "  Cadena   : " << xmlLeerElemento(xml, "cadena")   << endl;
}

void leerArreglos(const string& ruta) {
    string xml = xmlLeerArchivo(ruta);
    if (xml.empty()) { cout << ">> [Error] No se pudo leer: " << ruta << endl; return; }
    cout << "\n--- Leyendo Arreglos ---" << endl;

    string nombSec[] = {"arreglo_enteros", "arreglo_flotantes", "arreglo_cadenas"};
    for (int s = 0; s < 3; s++) {
        string bloque[1];
        if (xmlLeerBloques(xml, nombSec[s], bloque, 1) > 0) {
            string items[50];
            int n = xmlLeerBloques(bloque[0], "item", items, 50);
            cout << "  [" << nombSec[s] << "]: ";
            for (int i = 0; i < n; i++) cout << items[i] << " ";
            cout << endl;
        }
    }
}

void leerTiposCreados(const string& ruta) {
    string xml = xmlLeerArchivo(ruta);
    if (xml.empty()) { cout << ">> [Error] No se pudo leer: " << ruta << endl; return; }
    cout << "\n--- Leyendo Tipos Creados ---" << endl;

    string bPersonas[50];
    int np = xmlLeerBloques(xml, "persona", bPersonas, 50);
    cout << "  Personas (" << np << "):" << endl;
    for (int i = 0; i < np; i++) {
        PersonaPOO p;
        p.setNombre(xmlLeerElemento(bPersonas[i], "nombre"));
        p.setApellidoPaterno(xmlLeerElemento(bPersonas[i], "apellido_paterno"));
        p.setApellidoMaterno(xmlLeerElemento(bPersonas[i], "apellido_materno"));
        string gen = xmlLeerElemento(bPersonas[i], "genero");
        p.setGenero(gen.empty() ? '?' : gen[0]);
        p.setEdad(atoi(xmlLeerElemento(bPersonas[i], "edad").c_str()));
        cout << "  "; p.imprimir(); cout << endl;
    }

    string bAutos[50];
    int na = xmlLeerBloques(xml, "auto", bAutos, 50);
    cout << "  Autos (" << na << "):" << endl;
    for (int i = 0; i < na; i++) {
        AutoPOO a;
        a.setMarca(xmlLeerElemento(bAutos[i], "marca"));
        a.setPrecio(atof(xmlLeerElemento(bAutos[i], "precio").c_str()));
        a.setAnio(atoi(xmlLeerElemento(bAutos[i], "anio").c_str()));
        cout << "  "; a.imprimir(); cout << endl;
    }
}

void leerADTs(const string& ruta) {
    string xml = xmlLeerArchivo(ruta);
    if (xml.empty()) { cout << ">> [Error] No se pudo leer: " << ruta << endl; return; }
    cout << "\n--- Leyendo ADTs ---" << endl;

    string tags[] = {"pila_enteros", "cola_cadenas", "lista_flotantes"};
    for (int t = 0; t < 3; t++) {
        string bloque[1];
        if (xmlLeerBloques(xml, tags[t], bloque, 1) > 0) {
            cout << "  Tipo: " << xmlLeerElemento(bloque[0], "tipo") << endl;
            string bElem[1];
            if (xmlLeerBloques(bloque[0], "elementos", bElem, 1) > 0) {
                string items[50];
                int n = xmlLeerBloques(bElem[0], "item", items, 50);
                cout << "  Elementos: ";
                for (int i = 0; i < n; i++) cout << items[i] << " ";
                cout << endl;
            }
        }
    }
}

#endif
