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
    int valor;
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

// Ej 42
bool esPico(vector<vector<float>> matrix, int i, int j){
    bool res = true;
    int n = matrix.size();
    int m = 0;
    if(n > 0){
        m = matrix[0].size();
    }
    // limites del cuadrado alrededor de i,j
    int limitMinX = max(0, i-1);
    int limitMaxX = min(n, i+2);
    int limitMinY = max(0, j-1);
    int limitMaxY = min(n, j+2);
    for(int x = limitMinX; x < limitMaxX; x++) {
        for(int y = limitMinY; y < limitMaxY; y++){
            if(matrix[x][y] >= matrix[i][j] && !(x==i && y==j)){
                //no es pico
                res = false;
            }
        }
    }
    //if(res == true){
    //    cout << "Pico encontrado i,j: [" << i << "," << j << "]" << endl;
    //}
    return res;
}

int contarPicos(vector<vector<float>> matrix){
    // Dada una matriz, cuenta los picos
    // Es pico si todas las celdas de alredor tienen un valor menor
    int n = matrix.size();
    int m = 0;
    if(n > 0){
        m = matrix[0].size();
    }
    int acum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            if(esPico(matrix, i, j)){
                acum++;
            }
        }
    }
    return acum;
}

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
bool esTierra(int t){
    return t>=0;
}
int islas(vector<vector<int>> terreno){
    // Islas: terreno completamente rodeado por agua
    // Obs:
    //     descarto bordes
    vector<int> isla;
    int casilla;
    int n = terreno.size();
    int m = 0;
    if(n > 0){
        m = terreno[0].size();
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            // por cada casillero, busco en los de alrededor
            casilla = terreno[i][j];
            if(esTierra(casilla)){
                isla.push_back((i,j));
            }
        }
    }
    return 0;
}
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

//#endif //UNTITLED_MATRIX_UTILITIES_H
