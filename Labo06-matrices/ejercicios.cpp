#include<vector>/*
#include "matrix_utilities.h"

using namespace std;

// Ej 38
void mostrarMatriz(vector<vector<int>> matriz){
    //TODO: implementar
    int n = matriz.size();
    for(int i = 0; i < n; i++){
        for(int j=0; j<n; j++){
            cout << matriz[i][j] << "\t .";
        }
        cout << "\n";
    }
}

// Ej 39
void transponer(vector<vector<int>> matriz) {
    //TODO: implementar
}

// Ej 40
vector<int> matrizPorIesimaFila(vector<vector<int>> matriz, int i){
    // TODO: implementar
    return {};
}

vector<vector<int>> matrizPorTranspuesta(vector<vector<int>> matriz){
    //TODO: implementar
    vector<vector<int>> ret;
    return ret;
}

// Ej 41
vector<vector<int>> redimensionar(vector<vector<int>> matriz, int n, int m){
    //TODO: implementar
    vector<vector<int>> ret;
    return ret;
}

// Ej 42
int contarPicos(vector<vector<int>> matrix){
    //TODO: implementar
    return 0;
}


// Ej 43
char* estadoTaTeTi(vector<vector<int>> tablero){
    //TODO: implementar
    return "implementar";
}

// Ejercicios de terreno

void elevar(vector<vector<int>> &terreno, int x){
    //TODO: implementar
}

bool sobresalen(vector<vector<int>> terreno, int n, int& mts){
    //TODO: implementar
    return false;
}
/*
tuple<int,int> resumen(vector<vector<int>> terreno){
    //TODO: implementar
    return make_pair(0,0);
}

int islas(vector<vector<int>> terreno){
    //TODO: implementar
    return 0;
}

// Ej 45
vector<tuple<int, int, int>> aTriplas(vector<vector<int> > m){
    //TODO: implementar
    vector<tuple<int,int,int>> tripla;
    return tripla;
}

// Ej 45
vector<vector<int>> aMatriz(vector<tuple<int, int, int>> m){
    //TODO: implementar
    vector<vector<int>> ret;
    return ret;
}

// Ej 46

//iterativo: algunValle

//recursivo: valleMasProfundo

//recursivo: caminosAValles

//opcional iterativo: valleMasProfundo y caminosAValles

// Ej 47

// temperaturaPromedioPorPunto

// temperaturaPromedioPorMomento
*/
