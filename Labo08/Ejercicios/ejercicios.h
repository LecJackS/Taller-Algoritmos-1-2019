#ifndef L07_COMPLEJIDAD_EJERCICIOS_H
#define L07_COMPLEJIDAD_EJERCICIOS_H

#endif //L07_COMPLEJIDAD_EJERCICIOS_H
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>


using namespace std;

void mostrar_vector(vector<int>& v);
vector<int> construir_vector(int n, string disposicion);
bool hayDuplicados ( vector < int >& v );
bool hayDuplicadosEficiente ( vector < int >& v );


bool aux(vector<int>& vec, int i, int sum);
bool algunSubconjSuma(vector<int>& vec, int sum);

bool busqueda_binaria(vector<int> &s, int x);
