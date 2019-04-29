#include "ejercicios.h"
#include <iostream>

// Ejercicio 1
// Devuelve el minimo valor de una subsecuencia desde 0 hasta j
int indice_min_subsec(vector<int> v, int i, int j){
    int min_num = v[i];
    // min_idx es 'l'
    // todo el tiempo debe cumplir que:
    // i-1 <= l <= j
    int min_idx = i-1;
    int res = min_idx + 1;
	for(int k=i; k<j; k++){
        if(v[k] < min_num){
            // es minimo!
            min_num = v[k];
            min_idx = k-1;
        }
	}
	res = min_idx+1;
	return res;
}

// Ejercicio 33
// suma todos los elementos de una lista de la forma mas rebuscada de la vida
int sumatoria(vector<int> s) {
    int mitad = s.size() / 2;
    int suma = s[mitad];
    for(int k=1; k < mitad+1; k++){
        suma = suma + s[mitad-k];
        if(mitad+k >= s.size()){
            suma = suma + 0;
        }
        else{
            suma = suma + s[mitad+k];
        }
    }
	return suma;
}

// Ejercicio 3
int mcd(int m, int n){
    int res=1;
    for(int a=0; a<=m; a++){
        for(int b=0; b<=n; b++){
            if((a>0) && (b>0) && (a==b)
                     && (m%a == 0) && (n%b == 0)
                     && (m%b == 0) && (n%a == 0)){
                if (a > res){
                    // el mayor divisor hasta ahora
                    res = a;
                }
            }
        }
    }
	return res;
}

// Ejercicio 4
pair<int,int> division(int n, int d){
    int r = n%d; //jeje
    int q = n/d;
	return make_pair(q,r);
}

// Ejercicio 5
bool existePico(vector<int> s){
    bool res = false;
    int i=1;
    while(i < s.size()-1){
    //for(int i=1; i < s.size()-1; i++){
        if((s[i] > s[i-1]) && (s[i] > s[i+1])){
            res = true;
        }
        i++;
    }
	return res;
}

// Ejercicio 6
void swap(vector<int>& v, int i, int j){
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp; 
}

void ordenar(vector<int>& v){
    int minDesdeK;
    for(int k=0; k < v.size(); k++){
        minDesdeK = indice_min_subsec(v, k, v.size()-1);
        swap(v, minDesdeK, k);

    }
}























