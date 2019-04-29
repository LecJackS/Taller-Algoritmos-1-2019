#include <iostream>
#include "ejercicios.h"

using namespace std;

int main() {
    // ejercicio 32
    vector<int> v;

    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(6); // < pico (ej36)
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    v.push_back(7);
    cout << "Secuencia: " << endl;
    for(int i=0; i<v.size(); i++){ cout << v[i] << " ";}
    cout << endl;
    cout << "indice_min_subsec: " << indice_min_subsec(v, 0, 4) << endl<< endl;

    // ejercicio 33
    cout << "Sumatoria: " << endl;
    cout << sumatoria(v) << endl << endl;

    // 34
    cout << "MCD: " << endl;
    cout << mcd(36,12) << endl<< endl;

    // 35
    cout << "Division: " << endl;
    //unPar = make_pair(0,0);
    int q = division(7,3).first;
    int r = division(7,3).second;
    cout << "Cociente: "<< q << endl << "Resto: " << r << endl << endl;

    // 36
    cout << "Existe pico: " << endl;
    cout << existePico(v) << endl << endl;

    // 37
    cout << "Ordenar: " << endl;
    vector<int> vOri(v.size());
    vOri = v;
    ordenar(v); // orders in place
    for(int i=0; i<v.size(); i++){ cout << vOri[i] << " ";}
    cout << endl;
    for(int i=0; i<v.size(); i++){ cout << v[i] << " ";}







    return 0;
}