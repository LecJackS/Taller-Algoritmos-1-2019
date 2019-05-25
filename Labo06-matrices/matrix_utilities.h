#ifndef MATRIX_UTILITIES_H
#define MATRIX_UTILITIES_H

#include<vector>
#include<iostream>
using namespace std;
int a(int b);



template <class T>
void mostrarMatriz(vector<vector<T>> matriz){
    int n = matriz.size();
    int m = 0;
    T valor;
    if (n>0){
        m = matriz[0].size();
    }
    for(int i = 0; i < n; i++){
        for(int j=0; j<m; j++){
            valor = matriz[i][j];
            if(valor<0){
                cout << valor << "\t";
            }
            else{
                // add one empty space because sign of negatives
                cout << " " << valor << "\t";
            }
            
        }
        cout << "\n";
    }
}

template <class T>
vector<vector<T>> init_matrix(int n, int m, T defaultValue){
    vector<T> row(m, defaultValue);
    vector<vector<T>> ret(n, row);
    return ret;
}


template<class T>
bool vecContiene(vector<T> v, T elem) {
    for(int i=0; i<v.size(); i++){
        if(v[i]==elem){
            return true;
        }
    }
    return false;
}


/*
vector<vector<int>> rand_int_matrix(int n, int m){
    vector<vector<int>> ret;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            ret[i][j] = rand();
    return ret;
}
*/
void transponer(vector<vector<int>> &matriz);

// Ej 40
vector<int> matrizPorIesimaFila(vector<vector<int>> matriz, int i);

vector<vector<int>> matrizPorTranspuesta(vector<vector<int>> matriz);

// Ej 41
vector<vector<int>> redimensionar(vector<vector<int>> matriz, int n, int m);

// Ej 42
bool esPico(vector<vector<float>> matrix, int i, int j);

int contarPicos(vector<vector<float>> matrix);

/*
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

tuple<int,int> resumen(vector<vector<int>> terreno){
    //TODO: implementar
    return make_pair(0,0);
}*/
bool esTierra(int t);
void verContorno(vector<vector<int>> terreno, int i, int j);

vector<vector<char>> discretizarTerreno(vector<vector<int>> terreno);
vector<vector<int>> mostrarIndiceUnico(vector<vector<int>> terreno);
void mostrarVisitas(vector<vector<char>> mapa, vector<int> visitadas);
void buscarIslas(vector<vector<int>> terreno, vector<vector<int>> areas, vector<vector<int>> &islas);
int islas(vector<vector<int>> terreno);





/*
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


        //std::vector<std::vector<T>> init_matrix(int n, int m, T defaultValue);
//std::vector<std::vector<int>> rand_int_matrix(int n, int m);

#endif MATRIX_UTILITIES_H
