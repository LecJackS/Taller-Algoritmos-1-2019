#include <fstream>
#include "ejercicios.h"

using namespace std;

int main() {
    int i=1;
    int n=100;
    int paso=1;
    double tiempo;

    ofstream fout;
    fout.open("datos.csv");
    //fout << "n" << "\t" << "tiempo-ej-56" << "\t" << "tiempo-ej-57"<< "\t"<< "tiempo-ej-58-log"<< "\t"<< "tiempo-ej-58-otrolog" << endl;
    //fout << "n" << "\t" << "tiempo-ej-58-nlogn" << "\t" << "tiempo-ej-58-logn" << "\t" << "tiempo-ej-59" << endl;
    fout << "n" << "\t" << "tiempo-ej-59" << endl;
    double c, acumC;
    acumC=0;

    while(i<n){
        vector<int> v = construir_vector(i, "azar");
        // ej 56b
        double t0 = clock();
        //bool res = hayDuplicados(v);
        double t1 = clock();
        //double tiempo56 = (double(t1-t0)/CLOCKS_PER_SEC);
        // t = c*n^2
        // calculo c = t/n^2
        //acumC += tiempo56 / (i*i);
        //if(i==1){ acumC = 0.5; }
        // ej 57 ----------------------------------------
        //t0 = clock();
        //res = hayDuplicadosEficiente(v);
        //t1 = clock();
        //double tiempo57 = (double(t1-t0)/CLOCKS_PER_SEC);
        // ej 58 -n*logn----------------------------------------
        //t0 = clock();
        //for(int j=1; j<i; j++){
         //   // n*logn
        //    busqueda_binaria(v, 1);
        //}
//        t1 = clock();
//        double tiempo58nlogn = (double(t1-t0)/CLOCKS_PER_SEC);
//        // ej 58 -logn----------------------------------------
//        t0 = clock();
//        busqueda_binaria(v, 1);
//        t1 = clock();
//        double tiempo58logn = (double(t1-t0)/CLOCKS_PER_SEC);
        // ej 59 -nosesabe----------------------------------------
        t0 = clock();
        int temp = (i*i);
        algunSubconjSuma(v, temp);
        t1 = clock();
        double tiempo59 = (double(t1-t0)/CLOCKS_PER_SEC);
        //t0 = clock();
        //busqueda_binaria(v, 7);
        //t1 = clock();
        //double tiempo58nlogn7 = (double(t1-t0)/CLOCKS_PER_SEC);

        //fout << i << "\t" << tiempo56 << "\t" << tiempo57 << "\t" << tiempo58nlognrand << "\t" << tiempo58nlogn7 << endl;
        fout << i << "\t" << tiempo59 << endl;
        i += paso;
    }
    fout.close();

    //
    c = acumC / n;
    cout << "Ej55: el c del c*n^2 vale: " << c << endl;

    double tiempoEstimado = 220000000*220000000;

    cout << "Este programa tardaria en años: " << tiempoEstimado/(3600*24*365) << endl;




    return 0;
}