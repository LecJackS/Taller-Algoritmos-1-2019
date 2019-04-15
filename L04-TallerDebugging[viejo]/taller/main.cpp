#include <iostream>
#include "test/cases.h"

using namespace std;


int main()
{
    int exitos = 0;
    int total = 8;

    exitos += test01_estaOrdenado() ? 1 : 0;

    exitos += test02_esPrimo() ? 1 : 0;

    exitos += test03_pertenece() ? 1 : 0;

    exitos += test04_desvioEstandar() ? 1 : 0;

    exitos += test05_fibonacci() ? 1 : 0;

    //exitos += test06_maximoComunDivisor() ? 1 : 0;

    exitos += test07_sumaDoble() ? 1 : 0;

    exitos += test08_cantPalabras() ? 1 : 0;

    cout << "# Ejercicios correctos:" << exitos << endl;
    cout << "# Ejercicios incorrectos: " << total - exitos << endl;

    return 0;
}

