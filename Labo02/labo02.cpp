#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
using namespace std;


//ejercicio 11
bool esPrimo(int n){
    //usa posibles divisores a los i < sqrt(n)
    if (n<2){
        return false;
    }
    // los posibles divisores estarán entre 2 y sqrt(n)
    int i=2;
    //for (int i=n; i>1; i--)
    while(i < sqrt(n)){
        if (n % i == 0){
            //cout << n << " no es primo! " << i << " lo divide." << endl;
            return false;
        }
        i++;
    }
    //cout << n << " es primo!" << endl;
    return true;
}

bool esPrimoSlow(int n){
    //verifica que TODOS los numeros menores a n sean divisores
    if (n<2){
        return false;
    }
    // los posibles divisores estarán entre 2 y sqrt(n)
    int i=2;
    //for (int i=n; i>1; i--)
    while(i < n){
        if (n % i == 0){
            //cout << n << " no es primo! " << i << " lo divide." << endl;
            return false;
        }
        i++;
    }
    //cout << n << " es primo!" << endl;
    return true;
}

//Ejercicio 12. Escribir una función escribirArchivo que escriba
// en un archivo salida.txt dos enteros a y b y luego dos
//reales f y g separados con coma en una única linea.
bool escribirArchivo(int a, int b, float f, float g){
    ofstream fout;
    fout.open("salida.txt");
    if (fout.fail()) {
        return false;
    }else{
        fout << a << "," << b << ",";
        fout << f << "," << g;
        fout.close();
    }
    return true;
}

//ej 13
bool leerArchivo(){
    int a;
    float f;
    ifstream fin;
    fin.open("entrada.txt");
    if (!fin.fail()){
        fin >> a >> f;
        cout << "Valores cargados: " << a << " y " << f << endl;
        fin.close();
        return true;
    }
    else{
        cout << "ERROR al leer el archivo." << endl;
        return false;
    }
}

//ej 14
void leerNumerosTxt(){
    int numero;
    ifstream fin;
    fin.open("numeros.txt");
    while(!fin.eof() && !fin.fail()){
        fin >> numero;
        cout << numero << " ";
    }
    fin.close();

    cout << endl << "Archivo leido!" << endl;
}

//ej15
// queda 1/0

//ej16
void swap(int &a, int &b){
    int aux;
    aux = b;
    b = a;
    a = aux;
}



//ej 17
void division(int numero, int divisor, int &cociente, int &resto){
    //16/5=
    resto = numero;
    cociente = 0;
    while(resto >= divisor){
        resto = resto - divisor;
        cociente = cociente +1;
    }
}



//ej 17.recur
//dijo uno de los profes que no se penso bien este problema al formularlo en la practica,
// porque la funcion recursiva se llama a si misma, y los parametros cociente y resto
// serian de entrada salida, y no solo salida como se especifica en el pdf.
void divisionRecu(int numero, int divisor, int &cociente, int &resto){
    /*
    resto = numero;
    cociente = 0;
    while(resto >= divisor){
        resto = resto - divisor;
        cociente = cociente +1;
    }
    */
    int newCoc;
    int newRes;
    if(resto >= divisor){
        //recursion
        newCoc = cociente+1;
        newRes = resto-divisor;
        cout << newCoc << " - " << newRes << endl;
        divisionRecu(numero, divisor, newCoc , newRes);
    }
}

//
void collatz(int n, int &cantPasos){
    cout << n << ": ";
    while(n!=1){
        cantPasos++;
        if(n%2 == 0){
            n = n/2;
        }
        else{
            n = n*3 +1;
        }
        cout << n << " ";
    }
    cout << endl;
}

void sumaNumeros (){
    int suma, valor1, valor2;
    ifstream fin1,fin2;
    ofstream fout;

    fin1.open("numeros1.txt");
    fin2.open("numeros2.txt");
    fout.open("suma.txt");
    if(fin1.fail() || fin2.fail() || fout.fail()){
        cout << "Error al abrir algun archivo!";
        return;
    }
    while(!(fin1.eof() && fin2.eof())){
        fin1 >> valor1;
        fin2 >> valor2;

        suma = valor1 + valor2;
        fout << suma << " ";
    }
    fin1.close();
    fin2.close();
    fout.close();
    cout << "Suma realizada correctamente, guardada en suma.txt" << endl;
}

/* Ejercicio 20. void primosGemelos(int n, int& res1, int& res2)
 * Decimos que a y b son primos gemelos, si ambosson primos y ademas a=b-2.
 * Queremos obtener los iesimos primos gemelos. Por ejemplo, son primos gemelos
 * 3  y 5,
 * 5  y 7,
 * 11 y 13,
 * 17 y 19,
 * 29 y 31,
 * 41 y 43 ... , los 4-esimos primos gemelos son 17 y 19.
 * Adem ́as se debe escribir en un archivo lasecuencia de primos gemelos hasta llegar al i-esimo.
 * Para el ejemplo el archivo debe contener: (3,5) (5,7) (11,13) (17,19)*/

bool escribirPrimos(int a, int b, int count){
    ofstream fout;
    if(count == 1){
        //primer gemelo, crea archivo en blanco
        fout.open("gemelos.txt");
    }
    else{
        //modifica lista de gemelos existente
        fout.open("gemelos.txt", ios_base::app);
    }

    if (fout.fail()) {
        cout << "Falla al abrir el archivo!" << endl;
        return false;
    }else{
        fout << "(" << a << "," << b << ") ";
        fout.close();
    }
    return true;
}

void primosGemelos(int n, int &res1, int &res2){
    /* Estrategia: desde el 1 hacia arriba, busco un 'p' primo, y al encontrarlo, veo si p+2 es primo
    de serlo, son primos gemelos n=1, los guardo en gemelos.txt, sino, sigo buscando primos.
     Si era el n-esimo primo buscado, fin, sino, sigo buscando el proximo.
     */
    clock_t start = clock();

    int numero=1;
    int countGemelos=0;

    while (countGemelos < n && numero < 10000){
        if (esPrimo(numero) && esPrimo(numero+2)){
            // son primos gemelos!
            countGemelos++;
            //cout << countGemelos << "* par de gemelos!: " << numero << " - " << numero+2 << endl;
            escribirPrimos(numero, numero+2, countGemelos);
            res1 = numero;
            res2 = numero+2;
        }
        numero++;
    }
    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    cout << "El tiempo en buscar los gemelos con sqrt fue de: " << 1000.0*elapsed << "ms" << endl;
}

void primosGemelosSlow(int n, int &res1, int &res2){
    /* Estrategia: desde el 1 hacia arriba, busco un 'p' primo, y al encontrarlo, veo si p+2 es primo
    de serlo, son primos gemelos n=1, los guardo en gemelos.txt, sino, sigo buscando primos.
     Si era el n-esimo primo buscado, fin, sino, sigo buscando el proximo.
     */
    clock_t start = clock();

    int numero=1;
    int countGemelos=0;

    while (countGemelos < n && numero < 10000){
        if (esPrimoSlow(numero) && esPrimoSlow(numero+2)){
            // son primos gemelos!
            countGemelos++;
            //cout << countGemelos << "* par de gemelos!: " << numero << " - " << numero+2 << endl;
            escribirPrimos(numero, numero+2, countGemelos);
            res1 = numero;
            res2 = numero+2;
        }
        numero++;
    }
    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    cout << "El tiempo en buscar los gemelos SLOW fue de: " << 1000.0*elapsed << "ms" << endl;
}

int main() {
    int n;
    int k;
    //cin >> n;
    n = 50;
    k = 13;
    cout << "11) Es primo:" << endl;
    esPrimo(n);
    cout << "12) Escribir archivo:" << endl;
    escribirArchivo(1, 6, 10, 20);
    cout << "13) Leer archivo:" << endl;
    leerArchivo();
    cout << "14) Leer numeros:" << endl;
    leerNumerosTxt();
    cout << "15) 1/0" << endl;
    cout << "16) n: " << n << ", k: " << k << endl;
    swap(n, k);
    cout << "    n: " << n << ", k: " << k << endl;
    int c, r;
    n = 50;
    k = 13;
    c = 0;
    r = 0;
    cout << "17) Division de " << n << "/" << k << endl;
    division(n, k, c, r);
    cout << "Cociente: " << c << endl << "Resto: " << r << endl << endl;
    cout << "17b) Division recursiva de " << n << "/" << k << endl;
    n = 50;
    k = 13;
    c = 0;
    r = 50;
    divisionRecu(n, k, c, r);
    cout << "Cociente: " << c << endl << "Resto: " << r << endl << endl;
    cout << "18) Collatz" << endl;
    int cantPasos = 0;
    collatz(n, cantPasos);
    cout << "Cantidad de pasos: " << cantPasos << endl;
    cout << endl;
    //
    sumaNumeros();
    //primos gemelos
    int primo1,primo2;
    primosGemelos(100, primo1, primo2);
    primosGemelosSlow(100, primo1, primo2);
    return 0;
}