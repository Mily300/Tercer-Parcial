#include "QuickSort.h"
#include <fstream>

void generarInt(int arr[], int n){
    ofstream txt("resultado.txt");
    ofstream csv("resultado.csv");
    ofstream json("resultado.json");
    ofstream xml("resultado.xml");

    txt << "ENTEROS ORDENADOS\n";
    csv << "Enteros\n";
    json << "{\n\"enteros\": [";
    xml << "<?xml version=\"1.0\"?>\n<enteros>\n";

    for(int i=0;i<n;i++){
        txt << arr[i] << endl;
        csv << arr[i] << endl;
        json << arr[i];

        if(i < n-1){
            json << ",";
        }

        xml << "   <numero>" << arr[i] << "</numero>\n";
    }

    json << "]\n}";
    xml << "</enteros>\n";
}

void generarChar(char arr[], int n){
    ofstream txt("resultado.txt");
    ofstream csv("resultado.csv");
    ofstream json("resultado.json");
    ofstream xml("resultado.xml");

    txt << "CARACTERES ORDENADOS\n";
    csv << "Caracteres\n";
    json << "{\n\"caracteres\": [";
    xml << "<?xml version=\"1.0\"?>\n<caracteres>\n";

    for(int i=0;i<n;i++){
        txt << arr[i] << endl;
        csv << arr[i] << endl;
        json << "\"" << arr[i] << "\"";

        if(i < n-1){
            json << ",";
        }

        xml << "   <caracter>" << arr[i] << "</caracter>\n";
    }

    json << "]\n}";
    xml << "</caracteres>\n";
}

void generarPersona(Persona arr[], int n){
    ofstream txt("resultado.txt");
    ofstream csv("resultado.csv");
    ofstream json("resultado.json");
    ofstream xml("resultado.xml");

    txt << "PERSONAS ORDENADAS POR EDAD\n";
    csv << "Edad,Inicial\n";
    json << "{\n\"personas\": [\n";
    xml << "<?xml version=\"1.0\"?>\n<personas>\n";

    for(int i=0;i<n;i++){
        txt << "Edad: " << arr[i].edad << " Inicial: " << arr[i].inicial << endl;
        csv << arr[i].edad << "," << arr[i].inicial << endl;

        json << "{";
        json << "\"edad\": " << arr[i].edad << ",";
        json << "\"inicial\": \"" << arr[i].inicial << "\"";
        json << "}";

        if(i < n-1){
            json << ",";
        }

        json << "\n";

        xml << "   <persona>\n";
        xml << "      <edad>" << arr[i].edad << "</edad>\n";
        xml << "      <inicial>" << arr[i].inicial << "</inicial>\n";
        xml << "   </persona>\n";
    }

    json << "]\n}";
    xml << "</personas>\n";
}

int main(){
    QuickSort qs;
    int opcion, n;

    do{
        cout<<"\n_______MENU_______\n";
        cout<<"1. Enteros\n";
        cout<<"2. Caracteres\n";
        cout<<"3. Personas\n";
        cout<<"4. Salir\n";
        cout<<"Opcion: ";
        cin>>opcion;

        switch(opcion){

        case 1:{
            cout<<"Cantidad: ";
            cin>>n;

            int *arr = new int[n];

            for(int i=0;i<n;i++){
                cin>>arr[i];
            }

            qs.ordenarInt(arr,0,n-1);
            qs.mostrarInt(arr,n);

            generarInt(arr,n);

            cout<<"\nArchivos generados correctamente.\n";

            delete[] arr;
            break;
        }

        case 2:{
            cout<<"Cantidad: ";
            cin>>n;

            char *arr = new char[n];

            for(int i=0;i<n;i++){
                cin>>arr[i];
            }

            qs.ordenarChar(arr,0,n-1);
            qs.mostrarChar(arr,n);

            generarChar(arr,n);

            cout<<"\nArchivos generados correctamente.\n";

            delete[] arr;
            break;
        }

        case 3:{
            cout<<"Cantidad: ";
            cin>>n;

            Persona *arr = new Persona[n];

            for(int i=0;i<n;i++){
                cin>>arr[i].edad;
                cin>>arr[i].inicial;
            }

            qs.ordenarPersona(arr,0,n-1);
            qs.mostrarPersona(arr,n);

            generarPersona(arr,n);

            cout<<"\nArchivos generados correctamente.\n";

            delete[] arr;
            break;
        }

        case 4:
            cout<<"\nSaliendo...\n";
            break;

        default:
            cout<<"\nOpcion no valida.\n";
        }

    }while(opcion!=4);

    return 0;
}
