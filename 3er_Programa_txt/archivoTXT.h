#ifndef ARCHIVOTXT_H
#define ARCHIVOTXT_H

#include <string>

using namespace std;

class ArchivoTXT {
private:
    string nombres[5];

public:
    void capturar();
    void escribirTXT();
    void leerTXT();
};

#endif