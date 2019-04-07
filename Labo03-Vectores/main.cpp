
#include <iostream>
#include "ejercicios.h"

using namespace std;

int main() {
    /* Ejercicio 3.23 */
    int show = 24;

    if (show == 23){
        cout << "A probar se ha dicho!" << endl;
        cout << "DIVIDE" << endl;

        vector<int> v;
        v.push_back(-10);
        v.push_back(10);
        v.push_back(20);
        vector<int> v2 = v;
        v2.push_back(31);
        v2.push_back(32);
        v2.push_back(32);
        v2.push_back(32);
        v2.push_back(5);

        cout << "21.1 Divide: " << endl;
        cout << divide(v, 10) << endl;
        cout << divide(v2, 10) << endl;
        cout << endl;

        // COMPLETAR CON MAS PRUEBAS

        //divideRec
        cout << "21.1 DivideRec: " << endl;
        cout << divideRec(v, 10) << endl;
        cout << divideRec(v2, 10) << endl;
        cout << endl;
        //max
        cout << "21.2 Maximo: " << endl;
        cout << maximo(v) << endl;
        cout << maximo(v2) << endl;
        cout << endl;

        //pertenece
        cout << "21.3 Pertenece: " << endl;
        cout << pertenece(3, v) << endl;
        cout << pertenece(3, v2) << endl;
        cout << endl;

        //mostrar vector
        cout << "22.1 Mostrar vector: " << endl;
        mostrarVector(v);
        mostrarVector(v2);
        cout << endl;

        //limpia dupli
        cout << "22.2 limpiarDuplicados: " << endl;
        mostrarVector(limpiarDuplicados(v));
        mostrarVector(limpiarDuplicados(v2));
        cout << endl;

        //rota secue
        cout << "22.3 rotar: " << endl;
        mostrarVector(rotar(v,30));
        mostrarVector(rotar(v2,3));
        cout << endl;

        //rota toda la secue
        cout << "22.4 reverso: " << endl;
        mostrarVector(reverso(v));
        mostrarVector(reverso(v2));
        cout << endl;

        //rota toda la secue
        cout << "22.5 factoresPrimos: " << endl;
        mostrarVector(factoresPrimos(2*2*3*12*7*19*5));
        mostrarVector(factoresPrimos(37));
        cout << endl;

        //rota toda la secue
        cout << "22.6 estaOrdenado: " << endl;
        cout << estaOrdenado(v) << endl;
        cout << estaOrdenado(v2) << endl;
        cout << endl;

        //rota toda la secue
        cout << "22.7 negadorDeBooleanos: " << endl;
        vector<bool> booleanos(5,true);
        mostrarVectorDeBool(booleanos);
        negadorDeBooleanos(booleanos);
        mostrarVectorDeBool(booleanos);
        cout << endl;

        //rota toda la secue
        cout << "22.8 sinImpares: " << endl;
        sinImpares(v);
        sinImpares(v2);
        mostrarVector(v);
        mostrarVector(v2);
        cout << endl;

        //rota toda la secue
        cout << "22.9 cantidadCaracteres: " << endl;
        vector<pair<int,int>> apariciones;
        apariciones = cantidadApariciones(v);
        for(int i=0; i< apariciones.size(); i++){
            cout << "(" << apariciones[i].first << "," << apariciones[i].second << "), ";
        }
        cout << endl;
        apariciones = cantidadApariciones(v2);
        for(int i=0; i< apariciones.size(); i++){
            cout << "(" << apariciones[i].first << "," << apariciones[i].second << "), ";
        }
        cout << endl;
        cantidadApariciones(v2);
        cout << endl;
    }
    else{
        /* Ejercicio 3.24*/
        palindromos("palabras.txt","palindromos.txt");
        //
        promedios("lista-numeros1.txt", "lista-numeros2.txt", "lista-promedios.txt");
        promediosHasta("lista-numeros1.txt", "lista-promedios-hasta.txt");
        cantidadApariciones("lista-numeros1.txt", "lista-cant-apariciones.txt");
        cout << "Cant. apariciones de 'pala': " << cantidadAparicionesDePalabra("lista-palabras.txt", "pala") << endl;
        estadisticas("lista-palabras.txt");
        interseccion();
        cout << endl;
    }


    return 0;
}