#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <cctype>
#include <string>
#include <tuple>
using namespace std;

/* Ejercicio 3.23*/
bool divide(vector<int> v, int n);
bool divideRec(vector<int> v, int n);
int maximo(vector<int> v);
bool pertenece(int elem, vector<int> v);
void mostrarVector(vector<int> v);
vector<int> limpiarDuplicados(vector<int> v);
vector<int> rotar(vector<int> v, int k);
vector<int> reverso(vector<int> v);
bool estaOrdenado(vector<int> v);
vector<pair<int, int>> cantidadApariciones(vector<int> v);
void mostrarVectorDeBool(vector<bool> v);
vector<int> factoresPrimos(int n);
void sinImpares(vector<int>& v);
void negadorDeBooleanos(vector<bool> &booleanos);
/* Ejercicio 3.24*/
void palindromos(string rutaArchivoIn, string rutaArchivoOut);

void promedios(string rutaArchivoIn1, string rutaArchivoIn2, string rutaArchivoOut);

void promediosHasta(string rutaArchivoIn, string rutaArchivoOut);

void cantidadApariciones(string rutaArchivoIn, string rutaArchivoOut);

int cantidadAparicionesDePalabra(string rutaArchivo, string palabra);

void estadisticas(string rutaArchivo);

void interseccion();
