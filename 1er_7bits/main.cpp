// 7 BIS - IDENTIFICAR TAMANOS DE TIPOS DE DATOS EN POO
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Auto {
public:
    int precio;
    int anio;
};

class Persona {
public:
    string nombre;
    string ap;
    string am;
    string genero;
    int edad;
};

void mostrarTamanos() {
    cout << "\n===== TAMANOS DE TIPOS DE DATOS =====\n";

    cout << "\nTIPOS BASICOS\n";
    cout << "char: " << sizeof(char) << " bytes" << endl;
    cout << "int: " << sizeof(int) << " bytes" << endl;
    cout << "float: " << sizeof(float) << " bytes" << endl;
    cout << "double: " << sizeof(double) << " bytes" << endl;
    cout << "bool: " << sizeof(bool) << " bytes" << endl;

    cout << "\nTIPOS CREADOS EN POO\n";
    cout << "Auto: " << sizeof(Auto) << " bytes" << endl;
    cout << "Persona: " << sizeof(Persona) << " bytes" << endl;
}

void generarTXT() {
    ofstream archivo("resultado.txt");

    archivo << "TAMANOS DE TIPOS DE DATOS\n\n";

    archivo << "TIPOS BASICOS\n";
    archivo << "char: " << sizeof(char) << " bytes\n";
    archivo << "int: " << sizeof(int) << " bytes\n";
    archivo << "float: " << sizeof(float) << " bytes\n";
    archivo << "double: " << sizeof(double) << " bytes\n";
    archivo << "bool: " << sizeof(bool) << " bytes\n";

    archivo << "\nTIPOS CREADOS EN POO\n";
    archivo << "Auto: " << sizeof(Auto) << " bytes\n";
    archivo << "Persona: " << sizeof(Persona) << " bytes\n";

    archivo.close();
}

void generarCSV() {
    ofstream archivo("resultado.csv");

    archivo << "Tipo,Nombre,TamanoBytes\n";

    archivo << "Basico,char," << sizeof(char) << endl;
    archivo << "Basico,int," << sizeof(int) << endl;
    archivo << "Basico,float," << sizeof(float) << endl;
    archivo << "Basico,double," << sizeof(double) << endl;
    archivo << "Basico,bool," << sizeof(bool) << endl;

    archivo << "POO,Auto," << sizeof(Auto) << endl;
    archivo << "POO,Persona," << sizeof(Persona) << endl;

    archivo.close();
}

void generarJSON() {
    ofstream archivo("resultado.json");

    archivo << "{\n";

    archivo << "   \"tipos_basicos\": {\n";
    archivo << "      \"char\": " << sizeof(char) << ",\n";
    archivo << "      \"int\": " << sizeof(int) << ",\n";
    archivo << "      \"float\": " << sizeof(float) << ",\n";
    archivo << "      \"double\": " << sizeof(double) << ",\n";
    archivo << "      \"bool\": " << sizeof(bool) << "\n";
    archivo << "   },\n";

    archivo << "   \"tipos_poo\": {\n";
    archivo << "      \"Auto\": " << sizeof(Auto) << ",\n";
    archivo << "      \"Persona\": " << sizeof(Persona) << "\n";
    archivo << "   }\n";

    archivo << "}\n";

    archivo.close();
}

void generarXML() {
    ofstream archivo("resultado.xml");

    archivo << "<?xml version=\"1.0\"?>\n";
    archivo << "<tamanos>\n";

    archivo << "   <tipos_basicos>\n";
    archivo << "      <char>" << sizeof(char) << "</char>\n";
    archivo << "      <int>" << sizeof(int) << "</int>\n";
    archivo << "      <float>" << sizeof(float) << "</float>\n";
    archivo << "      <double>" << sizeof(double) << "</double>\n";
    archivo << "      <bool>" << sizeof(bool) << "</bool>\n";
    archivo << "   </tipos_basicos>\n";

    archivo << "   <tipos_poo>\n";
    archivo << "      <Auto>" << sizeof(Auto) << "</Auto>\n";
    archivo << "      <Persona>" << sizeof(Persona) << "</Persona>\n";
    archivo << "   </tipos_poo>\n";

    archivo << "</tamanos>\n";

    archivo.close();
}

int main() {
    mostrarTamanos();

    generarTXT();
    generarCSV();
    generarJSON();
    generarXML();

    cout << "\nArchivos generados correctamente.\n";

    return 0;
}