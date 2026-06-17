#include "MergeSort.h"

int main() {
    MergeSort ms;
    int opcion, n;

    do {
        cout << "\n________ MENU MERGE SORT ________\n";
        cout << "1. Enteros\n";
        cout << "2. Caracteres\n";
        cout << "3. Personas\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {

        case 1: {
            cout << "Cantidad: ";
            cin >> n;

            int *arr = new int[n];

            for(int i = 0; i < n; i++) {
                cout << "Numero " << i + 1 << ": ";
                cin >> arr[i];
            }

            ms.ordenarInt(arr, 0, n - 1);
            ms.mostrarInt(arr, n);

            delete[] arr;
            break;
        }

        case 2: {
            cout << "Cantidad: ";
            cin >> n;

            char *arr = new char[n];

            for(int i = 0; i < n; i++) {
                cout << "Caracter " << i + 1 << ": ";
                cin >> arr[i];
            }

            ms.ordenarChar(arr, 0, n - 1);
            ms.mostrarChar(arr, n);

            delete[] arr;
            break;
        }

        case 3: {
            cout << "Cantidad: ";
            cin >> n;

            Persona *arr = new Persona[n];

            for(int i = 0; i < n; i++) {
                cout << "Edad: ";
                cin >> arr[i].edad;

                cout << "Inicial: ";
                cin >> arr[i].inicial;
            }

            ms.ordenarPersona(arr, 0, n - 1);
            ms.mostrarPersona(arr, n);

            delete[] arr;
            break;
        }

        case 4:
            cout << "\nSaliendo...\n";
            break;

        default:
            cout << "\nOpcion no valida.\n";
        }

    } while(opcion != 4);

    return 0;
}