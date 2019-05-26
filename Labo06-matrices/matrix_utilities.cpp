#include "matrix_utilities.h"
using namespace std;


/*
vector<vector<int>> rand_int_matrix(int n, int m){
    vector<vector<int>> ret;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            ret[i][j] = rand();
    return ret;
}
*/
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

vector<int> matrizPorIesimaFila(vector<vector<int>> matriz, int i) {
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

vector<vector<int>> matrizPorTranspuesta(vector<vector<int>> matriz) {
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

vector<vector<int>> redimensionar(vector<vector<int>> matriz, int n, int m) {
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

bool esPico(vector<vector<float>> matrix, int i, int j) {
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

int contarPicos(vector<vector<float>> matrix) {
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

// aca arranca terreno e islas

vector<vector<int>> mostrarIndiceUnico(vector<vector<int>> terreno) {
    int n=terreno.size();
    int m=0;
    if(n > 0){
        m=terreno[0].size();
    }
    vector<vector<int>> res(n, vector<int>(m, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++) {
            res[i][j] = m * i + j;
        }
    }
    return res;
}

bool esTierra(int t) {
    return t>=0;
}

void mostrarVector(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << "_";
    }
    cout << endl;
}

// busca un indice unico en una matriz de areas, y devuelve al area
int buscarArea(vector<vector<int>> areas, int indice){
    for(int a=0; a<areas.size(); a++){
        if(vecContiene(areas[a], indice)){
            return a;
        }
    }
    return -1;
}

void mostrarVisitas(vector<vector<char>> mapa, vector<vector<int>> areas) {
    int n = mapa.size();
    int m = 0;
    if (n>0){
        m = mapa[0].size();
    }
    char valor;
    int indice;
    vector<char> nombres;
    nombres = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
               'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
               '1','2','3','4','5','6','7','8','9','0'};
    int a;

    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            valor = mapa[i][j];
            indice = i * m + j;
            a = buscarArea(areas, indice);

            if(a != -1){
                a = a % nombres.size(); // si encuentro mas areas que la cant de nombres, repite nombres usados
                cout << "[" << nombres[a] << "]" << "\t";
            }
            else{
                cout << " " << valor << " " << "\t";
            }
        }
        cout << "\n";
    }
}

void verContorno(vector<vector<int>> terreno, vector<int> &visitadas, int i, int j) {
    bool VERBOSE = false;
    int casilla = terreno[i][j];
    bool no_es_borde;
    int cx;
    int cy;
    int n = terreno.size();
    int m = 0;
    if(n > 0){
        m = terreno[0].size();
    }
    // map (i,j) > indice unico:i*n+j
    int indice = i * m + j;

    vector<vector<int>> contorno(4, vector<int>(2));
    contorno.assign({{1,0}, {0,1}, {-1,0}, {0,-1}});
    if(esTierra(casilla) && !vecContiene(visitadas, indice)){
        visitadas.push_back(indice);
        //mostrarVector(visitadas);
        for(int c=0; c<4; c++){
            cx = i + contorno[c][0];
            cy = j + contorno[c][1];
            indice = cx * m + cy;
            no_es_borde = (cx < n) && (cy < m) && (cx >= 0) && (cy >= 0);
            if(!vecContiene(visitadas, indice) && no_es_borde){
                // analizo los elementos del contorno de manera recursiva
                vector<vector<int>> areas;
                areas.push_back(visitadas);
                // Verbose step by step en el armado de areas
                if(VERBOSE){
                    mostrarVisitas(discretizarTerreno(terreno), areas);
                    cout << endl;
                }
                verContorno(terreno, visitadas, cx, cy);
            }
        }
    }
}

vector<int> indiceUnicoAIJ(int idx, int m){
    // Algo tipo euclides para obtener las variables i,j
    // a partir del resultado de su combinacion lineal: indice unico
    int i=0;
    int j;
    while(idx > m){
        idx -= m;
        i++;
    }
    // j sera
    j = idx;
    return {i, j};
}

bool esIsla(vector<vector<int>> terreno, vector<int> area){
    bool en_rango;
    bool es_propio_terreno;
    bool centro_borde;
    int cx, cy;
    int n = terreno.size();
    int m = 0;
    if(n > 0){
        m = terreno[0].size();
    }
    int i, j;
    vector<int> idxIJ(2); //contiene indices i, j
    vector<vector<int>> contorno(4, vector<int>(2));
    contorno.assign({{1, 0}, {1, 1},  {0, 1}, {-1, 1},
                     {-1,0}, {-1,-1}, {0,-1}, {1, -1}});
    for(int a=0; a<area.size(); a++){
        // Busca en el contorno completo  DE CADA celda
        // Si es agua o terreno de SU area, sigue
        // Si no, NO es isla
        for(int c=0; c<8; c++){
            // area contiene indices unicos, vuelvo a i,j; indice = i*m+j;
            // necesito convertirlo a los i j de la matriz nuevamente
            idxIJ = indiceUnicoAIJ(area[a], m);
            i = idxIJ[0];
            j = idxIJ[1];
            cx = i + contorno[c][0];
            cy = j + contorno[c][1];
            // por cada celda-contigua pregunto
            en_rango = (cx < n) && (cy < m) && (cx >= 0) && (cy >= 0);
            es_propio_terreno = vecContiene(area, cx*m + cy);
            centro_borde = (i == n-1) || (j == m-1);

            if(centro_borde || (en_rango && !es_propio_terreno && esTierra(terreno[cx][cy]))){
                // no es una isla!
                return false;
            }
        }
    }
    // es una isla!
    return true;
}


void buscarIslas(vector<vector<int>> terreno, vector<vector<int>> areas, vector<vector<int>> &islas) {
    // Dada una lista de areas, cuenta las islas
    // Isla: area COMPLETAMENTE rodeada por agua,
    // esto implica > contorno de isla es agua o terreno de SU area
    for(int a=0; a<areas.size(); a++){
        // cada area contiene una lista de casilleros que lo componen
        if(esIsla(terreno, areas[a])){
            // guardo area como isla
            islas.push_back(areas[a]);
        }
    }
}

int islas(vector<vector<int>> terreno) {
    bool VERBOSE = false;
    // Islas: terreno completamente rodeado por agua
    // Areas: celdas de tierra conectadas directamente en x o y (no en diagonal)
    vector<vector<int>> islas;
    int casilla;
    int indice;
    vector<int> visitadas;
    vector<vector<int>> areas;

    int n = terreno.size();
    int m = 0;
    if(n > 0){
        m = terreno[0].size();
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            // por cada casillero, busco en los de alrededor
            casilla = terreno[i][j];
            indice = i * m + j;
            //cout << endl;
            if(esTierra(casilla) && buscarArea(areas, indice)==-1 ){
                visitadas = {};
                verContorno(terreno, visitadas, i, j);
                areas.push_back(visitadas);
                if(VERBOSE){
                    cout << "Nuevo area agregada: #" << areas.size() << endl;
                }

            }
        }
    }
    buscarIslas(terreno, areas, islas);
    //
    cout << "Areas encontradas: " << areas.size() << endl;
    mostrarVisitas(discretizarTerreno(terreno), areas);
    cout << endl;
    //mostrarMatriz(areas);
    cout << "Islas encontradas: " << islas.size()  << endl;
    mostrarVisitas(discretizarTerreno(terreno), islas);
    cout << endl;
    cout << "Islas contadas: "<< endl;
    return islas.size();
}


vector<vector<char>> discretizarTerreno(vector<vector<int>> terreno) {
    int n=terreno.size();
    int m=0;
    if(n > 0){
        m=terreno[0].size();
    }
    vector<vector<char>> res(n, vector<char>(m, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(terreno[i][j] >= 0){
                // tierra
                res[i][j]='O';
            }
            else{
                // agua
                res[i][j]='~';
            }
        }
    }
    return res;
}
