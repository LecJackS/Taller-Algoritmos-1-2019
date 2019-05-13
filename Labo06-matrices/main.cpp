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
    return 0;
}