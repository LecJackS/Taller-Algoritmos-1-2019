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

    //transponer

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
        for(int j = 10; j<m; j++){
            // ramdom values of 3 digit (1 int, 2 decimals) floats as 5.47
            rand_float_matrix[i][j] = (rand()%1000)/100;
        }
    }
    mostrarMatriz(rand_float_matrix);
    cout << endl;
    cout << "Picos: " << contarPicos(rand_float_matrix) << endl;

    //45c - islas
    cout << "45c - Islas" << endl;
    n=20;
    m=15;
    vector<vector<int>> terreno_matrix(n, vector<int>(m, 0));
    for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){
            terreno_matrix[i][j] = 0.6*terreno_matrix[i-1][j-1] + 0.4*(0.2*(rand()%10)-0.8*(rand()%10));
        }
    }
    cout << "Altitudes: " << endl;
    mostrarMatriz(terreno_matrix);
    cout << endl << "Tipo: " << endl;
    cout << endl;
    mostrarMatriz(discretizarTerreno(terreno_matrix));
    cout << endl;
    mostrarMatriz(mostrarIndiceUnico(terreno_matrix));
    cout << endl;
    islas(terreno_matrix);



    return 0;
}