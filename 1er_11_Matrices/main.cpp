//MATRICES
#include <iostream>
#include <fstream>

using namespace std;
class Matriz {
private:
    int A[3][3];
    int B[3][3];
    int C[3][3];
    int D[3][3];
    int constante;
public:
    void ingresarMatrices() {
        cout << "Ingrese los elementos de la matriz A (3x3):\n";
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cout << "A[" << i << "][" << j << "]: ";
                cin >> A[i][j];
            }
        }
        cout << "\nIngrese los elementos de la matriz B (3x3):\n";
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cout << "B[" << i << "][" << j << "]: ";
                cin >> B[i][j];
            }
        }
    }

    void multiplicarConstante() {
        cout << "\nIngrese la constante: ";
        cin >> constante;
        cout << "\nResultado A * constante:\n";
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                D[i][j] = A[i][j] * constante;
                cout << D[i][j] << " ";
            }
            cout << endl;
        }
    }

    void multiplicarMatrices() {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                C[i][j] = 0;
                for(int k = 0; k < 3; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        cout << "\nResultado A * B:\n";
        for(int i = 0; i < 3; i++) {

            for(int j = 0; j < 3; j++) {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
        generarTXT();
        generarCSV();
        generarJSON();
        generarXML();
        cout << "\nArchivos generados correctamente.\n";
    }
    void generarTXT() {
        ofstream archivo("resultado.txt");
        archivo << "MATRIZ A\n\n";
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                archivo << A[i][j] << " ";
            }
            archivo << endl;
        }
        archivo << "\nMATRIZ B\n\n";

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                archivo << B[i][j] << " ";
            }
            archivo << endl;
        }
        archivo << "\nCONSTANTE\n\n";
        archivo << constante << endl;
        archivo << "\nA * CONSTANTE\n\n";
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                archivo << D[i][j] << " ";
            }
            archivo << endl;
        }
        archivo << "\nA * B\n\n";
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                archivo << C[i][j] << " ";
            }
            archivo << endl;
        }
        archivo.close();
    }
    void generarCSV() {
        ofstream archivo("resultado.csv");
        archivo << "Tipo,Fila1,Fila2,Fila3\n";
        archivo << "Matriz A,\""
                << A[0][0] << " " << A[0][1] << " " << A[0][2]
                << "\",\""
                << A[1][0] << " " << A[1][1] << " " << A[1][2]
                << "\",\""
                << A[2][0] << " " << A[2][1] << " " << A[2][2]
                << "\"\n";

        archivo << "Matriz B,\""
                << B[0][0] << " " << B[0][1] << " " << B[0][2]
                << "\",\""
                << B[1][0] << " " << B[1][1] << " " << B[1][2]
                << "\",\""
                << B[2][0] << " " << B[2][1] << " " << B[2][2]
                << "\"\n";

        archivo << "Constante," << constante << ",,\n";

        archivo << "A*Constante,\""
                << D[0][0] << " " << D[0][1] << " " << D[0][2]
                << "\",\""
                << D[1][0] << " " << D[1][1] << " " << D[1][2]
                << "\",\""
                << D[2][0] << " " << D[2][1] << " " << D[2][2]
                << "\"\n";

        archivo << "A*B,\""
                << C[0][0] << " " << C[0][1] << " " << C[0][2]
                << "\",\""
                << C[1][0] << " " << C[1][1] << " " << C[1][2]
                << "\",\""
                << C[2][0] << " " << C[2][1] << " " << C[2][2]
                << "\"\n";
        archivo.close();
    }
    void generarJSON() {
        ofstream archivo("resultado.json");
        archivo << "{\n";
        archivo << "\"constante\": " << constante << ",\n";
        archivo << "\"matrizA\": [\n";
        archivo << "[" << A[0][0] << "," << A[0][1] << "," << A[0][2] << "],\n";
        archivo << "[" << A[1][0] << "," << A[1][1] << "," << A[1][2] << "],\n";
        archivo << "[" << A[2][0] << "," << A[2][1] << "," << A[2][2] << "]\n";
        archivo << "],\n";

        archivo << "\"matrizB\": [\n";
        archivo << "[" << B[0][0] << "," << B[0][1] << "," << B[0][2] << "],\n";
        archivo << "[" << B[1][0] << "," << B[1][1] << "," << B[1][2] << "],\n";
        archivo << "[" << B[2][0] << "," << B[2][1] << "," << B[2][2] << "]\n";
        archivo << "],\n";

        archivo << "\"A_por_constante\": [\n";
        archivo << "[" << D[0][0] << "," << D[0][1] << "," << D[0][2] << "],\n";
        archivo << "[" << D[1][0] << "," << D[1][1] << "," << D[1][2] << "],\n";
        archivo << "[" << D[2][0] << "," << D[2][1] << "," << D[2][2] << "]\n";
        archivo << "],\n";

        archivo << "\"A_por_B\": [\n";
        archivo << "[" << C[0][0] << "," << C[0][1] << "," << C[0][2] << "],\n";
        archivo << "[" << C[1][0] << "," << C[1][1] << "," << C[1][2] << "],\n";
        archivo << "[" << C[2][0] << "," << C[2][1] << "," << C[2][2] << "]\n";
        archivo << "]\n";
        archivo << "}\n";
        archivo.close();
    }
    void generarXML() {
        ofstream archivo("resultado.xml");
        archivo << "<?xml version=\"1.0\"?>\n";
        archivo << "<matrices>\n";
        archivo << "   <constante>" << constante << "</constante>\n";
        archivo << "   <matrizA>\n";
        for(int i = 0; i < 3; i++) {
            archivo << "      <fila>"
                    << A[i][0] << " "
                    << A[i][1] << " "
                    << A[i][2]
                    << "</fila>\n";
        }
        archivo << "   </matrizA>\n";
        archivo << "   <matrizB>\n";
        for(int i = 0; i < 3; i++) {
            archivo << "      <fila>"
                    << B[i][0] << " "
                    << B[i][1] << " "
                    << B[i][2]
                    << "</fila>\n";
        }
        archivo << "   </matrizB>\n";
        archivo << "   <A_por_constante>\n";
        for(int i = 0; i < 3; i++) {
            archivo << "      <fila>"
                    << D[i][0] << " "
                    << D[i][1] << " "
                    << D[i][2]
                    << "</fila>\n";
        }
        archivo << "   </A_por_constante>\n";
        archivo << "   <A_por_B>\n";
        for(int i = 0; i < 3; i++) {
            archivo << "      <fila>"
                    << C[i][0] << " "
                    << C[i][1] << " "
                    << C[i][2]
                    << "</fila>\n";
        }
        archivo << "   </A_por_B>\n";
        archivo << "</matrices>\n";
        archivo.close();
    }
};
int main() {
    Matriz obj;
    obj.ingresarMatrices();
    obj.multiplicarConstante();
    obj.multiplicarMatrices();

    return 0;
}
