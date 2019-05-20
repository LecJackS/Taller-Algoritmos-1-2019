#include<iostream>
#include<vector>
#include "matrix_utilities.h"

using namespace std;


int main() {
    cout << "38 - Mostrar" << endl;
    vector<vector<int>> matriz(10, vector<int>(10, 0));

    int n=4;
    int m=4;
    vector<vector<int>> rand_matrix(n, vector<int>(m, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            rand_matrix[i][j] = rand()%10;
        }
    }
    mostrarMatriz(rand_matrix);

    //trasponer

    cout << endl << "39 - Transponer";
    transponer(rand_matrix);
    cout << endl;
    mostrarMatriz(rand_matrix);
    cout << endl;

    //40a. matriz por iesima fila
    cout << endl << "40a - Transponer" << endl;
    vector<int> unVector(rand_matrix.size(), 0);
    unVector = matrizPorIesimaFila(rand_matrix, 0);
    for(int j = 0; j<unVector.size(); j++){
        cout << unVector[j] << " ";
    }
    cout << endl << endl;

    //40b
    cout << endl << "40b - Matriz x Transpuesta" << endl;
    matriz = matrizPorTranspuesta(rand_matrix);
    mostrarMatriz(matriz);

    //41
    cout << endl << "41 - Resizeando" << endl;
    vector<vector<int>> matriz41(2, vector<int>(8, 0));
    matriz41 = redimensionar(rand_matrix, 2, 8);

    mostrarMatriz(rand_matrix);
    cout << endl;
    mostrarMatriz(matriz41);

    //42 Picos
    cout << "42 - Picos" << endl;
    n=4;
    m=4;
    vector<vector<float>> rand_float_matrix(n, vector<float>(m, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            // ramdom values of 3 digit (1 int, 2 decimals) floats as 5.47
            rand_float_matrix[i][j] = (rand()%1000)/100;
        }
    }
    mostrarMatriz(rand_float_matrix);
    cout << endl;
    cout << "Picos: " << contarPicos(rand_float_matrix) << endl;

    //45c - islas
    cout << "45c - Islas" << endl;
    n=10;
    m=10;
    vector<vector<int>> terreno_matrix(n, vector<int>(m, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            terreno_matrix[i][j] = rand()%10 - rand()%10;
        }
    }
    cout << "Terreno: " << endl;
    mostrarMatriz(terreno_matrix);


    return 0;
}