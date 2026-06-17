//1.-Hola mundo 
#include <iostream>
#include "logger.h"

using namespace std;

class HolaMundo {
    public:
        void holaMundo() {
            cout << "Hola Mundo";
        }
};

int main() {
    
	HolaMundo obj;
    obj.holaMundo();

    Logger log("1-Hola Mundo");
    log.registrar("salida", "holaMundo()", "Hola Mundo");
    log.guardar();

    return 0;
}