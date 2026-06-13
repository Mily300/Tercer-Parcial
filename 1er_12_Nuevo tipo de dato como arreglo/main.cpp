// PRACTICA 12 - NUEVO TIPO DE DATO COMO ARREGLO
#include <iostream>
#include <fstream>
using namespace std;
class Auto {
public:
    int precio;
    int anio;
    void capturar() {
        cout << "\nIngrese precio del auto: ";
        cin >> precio;
        cout << "Ingrese año del auto: ";
        cin >> anio;
    }
    void mostrar() {
        cout << "Precio: " << precio << "  ";
        cout << "Año: " << anio << endl;
    }
};
class Persona {
public:
    string nombre;
    string ap;
    string am;
    string genero;
    int edad;
    void capturar() {
        cout << "\nNombre: ";
        cin >> nombre;
        cout << "Apellido paterno: ";
        cin >> ap;
        cout << "Apellido materno: ";
        cin >> am;
        cout << "Genero: ";
        cin >> genero;
        cout << "Edad: ";
        cin >> edad;
    }

    void mostrar() {
        cout << nombre << " " << ap << " " << am;
        cout << "  Genero: " << genero;
        cout << "  Edad: " << edad << endl;
    }
};

void generarTXT(Auto autos[], int contAutos,
                Persona personas[], int contPersonas) {
    ofstream archivo("resultado.txt");
    archivo << "LISTA DE AUTOS\n\n";
    for(int i = 0; i < contAutos; i++) {
        archivo << "Auto " << i + 1 << endl;
        archivo << "Precio: " << autos[i].precio << endl;
        archivo << "Año: " << autos[i].anio << endl;
        archivo << endl;
    }
    archivo << "\nLISTA DE PERSONAS\n\n";
    for(int i = 0; i < contPersonas; i++) {
        archivo << "Persona " << i + 1 << endl;
        archivo << "Nombre: "
                << personas[i].nombre << " "
                << personas[i].ap << " "
                << personas[i].am << endl;
        archivo << "Genero: "
                << personas[i].genero << endl;
        archivo << "Edad: "
                << personas[i].edad << endl;
        archivo << endl;
    }
    archivo.close();
}

void generarCSV(Auto autos[], int contAutos,
                Persona personas[], int contPersonas) {
    ofstream archivo("resultado.csv");
    archivo << "AUTOS\n";
    archivo << "Precio,Anio\n";
    for(int i = 0; i < contAutos; i++) {
        archivo << autos[i].precio << ","
                << autos[i].anio << endl;
    }
    archivo << "\nPERSONAS\n";
    archivo << "Nombre,ApellidoPaterno,ApellidoMaterno,Genero,Edad\n";
    for(int i = 0; i < contPersonas; i++) {
        archivo << personas[i].nombre << ","
                << personas[i].ap << ","
                << personas[i].am << ","
                << personas[i].genero << ","
                << personas[i].edad << endl;
    }
    archivo.close();
}

void generarJSON(Auto autos[], int contAutos,
                 Persona personas[], int contPersonas) {
    ofstream archivo("resultado.json");
    archivo << "{\n";
    archivo << "\"autos\": [\n";
    for(int i = 0; i < contAutos; i++) {
        archivo << "{";
        archivo << "\"precio\": " << autos[i].precio << ",";
        archivo << "\"anio\": " << autos[i].anio;
        archivo << "}";
        if(i < contAutos - 1)
            archivo << ",";
        archivo << "\n";
    }
    archivo << "],\n";
    archivo << "\"personas\": [\n";
    for(int i = 0; i < contPersonas; i++) {
        archivo << "{";
        archivo << "\"nombre\": \"" << personas[i].nombre << "\",";
        archivo << "\"apellidoPaterno\": \"" << personas[i].ap << "\",";
        archivo << "\"apellidoMaterno\": \"" << personas[i].am << "\",";
        archivo << "\"genero\": \"" << personas[i].genero << "\",";
        archivo << "\"edad\": " << personas[i].edad;
        archivo << "}";
        if(i < contPersonas - 1)
            archivo << ",";
        archivo << "\n";
    }
    archivo << "]\n";
    archivo << "}\n";
    archivo.close();
}
void generarXML(Auto autos[], int contAutos,
                Persona personas[], int contPersonas) {
    ofstream archivo("resultado.xml");
    archivo << "<?xml version=\"1.0\"?>\n";
    archivo << "<datos>\n";
    archivo << "   <autos>\n";
    for(int i = 0; i < contAutos; i++) {
        archivo << "      <auto>\n";
        archivo << "         <precio>"
                << autos[i].precio
                << "</precio>\n";
        archivo << "         <anio>"
                << autos[i].anio
                << "</anio>\n";
        archivo << "      </auto>\n";
    }
    archivo << "   </autos>\n";
    archivo << "   <personas>\n";
    for(int i = 0; i < contPersonas; i++) {
        archivo << "      <persona>\n";
        archivo << "         <nombre>"
                << personas[i].nombre
                << "</nombre>\n";
        archivo << "         <apellidoPaterno>"
                << personas[i].ap
                << "</apellidoPaterno>\n";
        archivo << "         <apellidoMaterno>"
                << personas[i].am
                << "</apellidoMaterno>\n";
        archivo << "         <genero>"
                << personas[i].genero
                << "</genero>\n";
        archivo << "         <edad>"
                << personas[i].edad
                << "</edad>\n";
        archivo << "      </persona>\n";
    }
    archivo << "   </personas>\n";
    archivo << "</datos>\n";
    archivo.close();
}

int main() {
    Auto autos[10];
    Persona personas[10];
    int contAutos = 0;
    int contPersonas = 0;
    int opcion;
    do {
        cout << "\n===== MENU LISTA DE PERSONAS Y AUTOS =====\n";
        cout << "1. Registrar Auto\n";
        cout << "2. Registrar Persona\n";
        cout << "3. Mostrar Autos\n";
        cout << "4. Mostrar Personas\n";
        cout << "5. Salir\n";
        cout << "Seleccione opcion: ";
        cin >> opcion;
        switch(opcion) {
        case 1:
            if(contAutos < 10) {
                autos[contAutos].capturar();
                contAutos++;
            }
            else {
                cout << "Lista de autos llena\n";
            }
            break;
        case 2:
            if(contPersonas < 10) {
                personas[contPersonas].capturar();
                contPersonas++;
            }
            else {
                cout << "Lista de personas llena\n";
            }
            break;
        case 3:
            cout << "\n--- LISTA DE AUTOS ---\n";
            for(int i = 0; i < contAutos; i++) {
                autos[i].mostrar();
            }
            break;
        case 4:
            cout << "\n--- LISTA DE PERSONAS ---\n";
            for(int i = 0; i < contPersonas; i++) {
                personas[i].mostrar();
            }
            break;
        case 5:
            generarTXT(autos, contAutos, personas, contPersonas);
            generarCSV(autos, contAutos, personas, contPersonas);
            generarJSON(autos, contAutos, personas, contPersonas);
            generarXML(autos, contAutos, personas, contPersonas);
            cout << "\nArchivos generados correctamente.\n";
            cout << "\nSaliendo del programa...\n";
            break;
        default:
            cout << "Opcion no valida\n";
        }
    } while(opcion != 5);

    return 0;
}
