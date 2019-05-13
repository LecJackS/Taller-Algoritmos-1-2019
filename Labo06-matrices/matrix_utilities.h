//#ifndef UNTITLED_MATRIX_UTILITIES_H
//#define UNTITLED_MATRIX_UTILITIES_H

#include<vector>
#include<iostream>
using namespace std;
int a(int b);


template <class T>
void mostrarMatriz(vector<vector<T>> matriz){
    int n = matriz.size();
    int m = 0;
    if (n>0){
        m = matriz[0].size();
    }
    for(int i = 0; i < n; i++){
        for(int j=0; j<m; j++){
            cout << matriz[i][j] << "\t";
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

vector<vector<int>> rand_int_matrix(int n, int m){
    vector<vector<int>> ret;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            ret[i][j] = rand();
    return ret;
}

void transponer(vector<vector<int>> &matriz) {
    int aux;
    int n = matriz.size();
    int m = 0;
    if (n>0){
         m = matriz[0].size();
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            aux = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = matriz[i][j];
        }
    }
}

// Ej 40
vector<int> matrizPorIesimaFila(vector<vector<int>> matriz, int i){
    int n = matriz.size();
    int m = 0;
    if (n>0){
        m = matriz[0].size();
    }
    vector<int> res(n, 0);
    //res = matriz[i];
    if(i>=0 && i < n){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<m; k++){
                // en cada casillero de res, acumulo los productos uno a uno
                // de todos los elementos de los vectores en la operacion
                // 1 2 3
                // 4 5 6 <- i
                // 7 8 9
                // res = [4*1 + 5*2 + 6*3,
                //        4*4 + 5*5 + 6*6,
                //        4*7 + 5*8 + 6*9]
                res[j] += matriz[i][k] * matriz[j][k];
            }
        }
    }
    else{
        cout << "ERROR: indice " << i << " fuera de rango para matriz";
    }
    return res;
}

vector<vector<int>> matrizPorTranspuesta(vector<vector<int>> matriz){
    //TODO: implementar
    int n = matriz.size();
    int m = 0;
    if (n>0){
        m = matriz[0].size();
    }
    vector<vector<int>> ret(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        ret[i] = matrizPorIesimaFila(matriz, i);
    }
    return ret;
}

// Ej 41
vector<vector<int>> redimensionar(vector<vector<int>> matriz, int n, int m){
    vector<vector<int>> ret(n, vector<int>(m, 0));
    vector<int> tira;
    int cont;
    int p = matriz.size();
    int q = 0;
    if(p > 0){
        q = matriz[0].size();
    }
    if(p*q == n*m){
        //creo matriz vacia con nueva dimension
        for(int i = 0; i < p; i++) {
            //guardo todos los elementos de matriz[i][j], en
            // una tira de #(p*q) elementos
            for(int j = 0; j<q; j++){
                tira.push_back(matriz[i][j]);
            }
        }
        // recorro la nueva matriz A LA INVERSA insertando los elementos de la tira
        cont = tira.size()-1; // = p*q = n*m
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >=0; j--) {
                ret[i][j] = tira[cont];
                cont--;
            }
        }
    }
    else{
        cout << "No es posible redimensionar la matriz de "<<p<<"x"<<q<< " a "<<n<<"x"<<m<< endl;
    }

    return ret;
}
/*
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


        //std::vector<std::vector<T>> init_matrix(int n, int m, T defaultValue);
//std::vector<std::vector<int>> rand_int_matrix(int n, int m);

//#endif //UNTITLED_MATRIX_UTILITIES_H
