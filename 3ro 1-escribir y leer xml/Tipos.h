#ifndef TIPOS_H
#define TIPOS_H
#include <iostream>
#include <string>

using namespace std;


class PersonaPOO {
private:
    string nombre;
    string apellidoPaterno;
    string apellidoMaterno;
    char   genero;
    int    edad;

public:
    PersonaPOO() : nombre(""), apellidoPaterno(""), apellidoMaterno(""), genero('?'), edad(0) {}

    PersonaPOO(string nom, string ap, string am, char gen, int ed) {
        nombre          = nom;
        apellidoPaterno = ap;
        apellidoMaterno = am;
        genero          = gen;
        edad            = ed;
    }

    string getNombre()          const { return nombre; }
    string getApellidoPaterno() const { return apellidoPaterno; }
    string getApellidoMaterno() const { return apellidoMaterno; }
    char   getGenero()          const { return genero; }
    int    getEdad()            const { return edad; }

    void setNombre(string nom)         { nombre = nom; }
    void setApellidoPaterno(string ap) { apellidoPaterno = ap; }
    void setApellidoMaterno(string am) { apellidoMaterno = am; }
    void setGenero(char gen)           { genero = gen; }
    void setEdad(int ed)               { edad = ed; }

    void imprimir() const {
        cout << nombre << " " << apellidoPaterno << " " << apellidoMaterno
             << " | Genero: " << genero << " | Edad: " << edad;
    }
};


class AutoPOO {
private:
    string marca;
    float  precio;
    int    anio;

public:
    AutoPOO() : marca(""), precio(0.0f), anio(0) {}

    AutoPOO(string mar, float pre, int ani) {
        marca  = mar;
        precio = pre;
        anio   = ani;
    }

    string getMarca()  const { return marca; }
    float  getPrecio() const { return precio; }
    int    getAnio()   const { return anio; }

    void setMarca(string mar)  { marca = mar; }
    void setPrecio(float pre)  { precio = pre; }
    void setAnio(int ani)      { anio = ani; }

    void imprimir() const {
        cout << "Marca: " << marca << " | Precio: $" << precio << " | Anio: " << anio;
    }
};

#endif
