#include "Burbuja.h"
#include <fstream>

void generarInt(int arr[], int idx[], int n){
    ofstream txt("resultado.txt");
    ofstream csv("resultado.csv");
    ofstream json("resultado.json");
    ofstream xml("resultado.xml");

    txt << "ENTEROS ORDENADOS\n";
    csv << "Enteros\n";
    json << "{\n\"enteros\": [";
    xml << "<?xml version=\"1.0\"?>\n<enteros>\n";

    for(int i=0;i<n;i++){
        txt << arr[idx[i]] << endl;
        csv << arr[idx[i]] << endl;
        json << arr[idx[i]];

        if(i < n-1){
            json << ",";
        }

        xml << "   <numero>" << arr[idx[i]] << "</numero>\n";
    }

    json << "]\n}";
    xml << "</enteros>\n";
}

void generarChar(char arr[], int idx[], int n){
    ofstream txt("resultado.txt");
    ofstream csv("resultado.csv");
    ofstream json("resultado.json");
    ofstream xml("resultado.xml");

    txt << "CARACTERES ORDENADOS\n";
    csv << "Caracteres\n";
    json << "{\n\"caracteres\": [";
    xml << "<?xml version=\"1.0\"?>\n<caracteres>\n";

    for(int i=0;i<n;i++){
        txt << arr[idx[i]] << endl;
        csv << arr[idx[i]] << endl;
        json << "\"" << arr[idx[i]] << "\"";

        if(i < n-1){
            json << ",";
        }

        xml << "   <caracter>" << arr[idx[i]] << "</caracter>\n";
    }

    json << "]\n}";
    xml << "</caracteres>\n";
}

void generarPersona(Persona arr[], int idx[], int n){
    ofstream txt("resultado.txt");
    ofstream csv("resultado.csv");
    ofstream json("resultado.json");
    ofstream xml("resultado.xml");

    txt << "PERSONAS ORDENADAS POR EDAD\n";
    csv << "Edad,Inicial\n";
    json << "{\n\"personas\": [\n";
    xml << "<?xml version=\"1.0\"?>\n<personas>\n";

    for(int i=0;i<n;i++){
        txt << "Edad: " << arr[idx[i]].edad
            << " Inicial: " << arr[idx[i]].inicial << endl;

        csv << arr[idx[i]].edad << ","
            << arr[idx[i]].inicial << endl;

        json << "{";
        json << "\"edad\": " << arr[idx[i]].edad << ",";
        json << "\"inicial\": \"" << arr[idx[i]].inicial << "\"";
        json << "}";

        if(i < n-1){
            json << ",";
        }

        json << "\n";

        xml << "   <persona>\n";
        xml << "      <edad>" << arr[idx[i]].edad << "</edad>\n";
        xml << "      <inicial>" << arr[idx[i]].inicial << "</inicial>\n";
        xml << "   </persona>\n";
    }

    json << "]\n}";
    xml << "</personas>\n";
}

int main(){
    Burbuja b;
    int opcion = 0, n;

    do{
        cout<<"\n______________MENU______________\n";
        cout<<"1. Enteros\n";
        cout<<"2. Caracteres\n";
        cout<<"3. Personas\n";
        cout<<"4. Salir\n";
        cout<<"Opcion: ";
        cin>>opcion;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Entrada invalida\n";
            continue;
        }

        switch(opcion){

        case 1:{
            cout<<"Cantidad: ";
            cin>>n;

            int *arr = new int[n];
            int *idx = new int[n];

            for(int i=0;i<n;i++){
                cout<<"Numero "<<i+1<<": ";
                cin>>arr[i];
                idx[i] = i;
            }

            b.ordenarInt(arr, idx, n);
            b.mostrarInt(arr, idx, n);
            generarInt(arr, idx, n);

            cout<<"\nArchivos generados correctamente.\n";

            delete[] arr;
            delete[] idx;
            break;
        }

        case 2:{
            cout<<"Cantidad: ";
            cin>>n;

            char *arr = new char[n];
            int *idx = new int[n];

            for(int i=0;i<n;i++){
                cout<<"Caracter "<<i+1<<": ";
                cin>>arr[i];
                idx[i] = i;
            }

            b.ordenarChar(arr, idx, n);
            b.mostrarChar(arr, idx, n);
            generarChar(arr, idx, n);

            cout<<"\nArchivos generados correctamente.\n";

            delete[] arr;
            delete[] idx;
            break;
        }

        case 3:{
            cout<<"Cantidad: ";
            cin>>n;

            Persona *arr = new Persona[n];
            int *idx = new int[n];

            for(int i=0;i<n;i++){
                cout<<"Edad: ";
                cin>>arr[i].edad;
                cout<<"Inicial: ";
                cin>>arr[i].inicial;
                idx[i] = i;
            }

            b.ordenarPersona(arr, idx, n);
            b.mostrarPersona(arr, idx, n);
            generarPersona(arr, idx, n);

            cout<<"\nArchivos generados correctamente.\n";

            delete[] arr;
            delete[] idx;
            break;
        }

        case 4:
            cout<<"Saliendo...\n";
            break;

        default:
            cout<<"Opcion invalida\n";
        }

    }while(opcion != 4);

    return 0;
}
