#ifndef DATOS_H
#define DATOS_H

class Datos {
private:
    int arr[5];

public:
    void llenar();
    void calcular();
    void guardarArchivos(int suma, float promedio, int max, int min);
};

#endif
