#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//factorial
int fact(int n)
{
    return (n == 1 || n == 0) ? 1 : fact(n - 1) * n;
}

bool esPrimo(int n){
    int divi = int(sqrt(n));
    while(divi > 1){
        if ((n % divi) == 0){
            return false;
        }
        divi--;
    }
    return true;
}

int fiboRecursivo(int n){
    int suma;
    if (n <= 2){
        return n;
    }
    else{
        suma = fiboRecursivo(n-1) + fiboRecursivo(n-2);
        return suma;
    }

}

int fiboIterativoConWhile(int n){
    int i = 0;
    int acumA = 0;
    int acumB =1;
    int temp;
    cout << "Secue: ";
    while (i <= n){
        cout << acumA << " ";
        temp = acumA;
        acumA = acumA + acumB;
        acumB = temp;
        i++;
    }
    return acumA;
}

int fiboIterativoConFor(int n){
    int acumA = 0;
    int acumB =1;
    int temp;
    if(n <= 1){
        return n;
    }
    for(int i=0; i<=n; i++) {
        temp = acumA;
        acumA = acumA + acumB;
        acumB = temp;
    }
    return acumA;
}

int sumaImparesRecursivo(int n) {
    int total = 0;
    //cout << "total: " << total << endl;
    //cout << "    n: " << n << endl;
    if (n < 1){
        return total;
    }
    if (n%2 == 1){
        //n impar
        total = n + sumaImparesRecursivo(n-2);
    }
    else{
        //n par
        total = sumaImparesRecursivo(n-1);
    }
};

int sumaImparesIterativo(int n) {
    int total = 0;
    //cout << "total: " << total << endl;
    //cout << "    n: " << n << endl;
    if (n < 1){
        return total;
    }
    for(int i=n-1; i>0; i--){
        if (i%2 == 1){
            //n impar
            total = total + i;
            //cout << "n: " << i << endl;
        }
    }
    return total;
};

int sumaDivisores(int n){
    int total = 0;
    for (int i=n; i>0; i--){
        if (n%i == 0){
            //printing stuff
            if (i == 1){
                cout << i << " = ";
            }
            else{
                cout << i << " + ";
            }
            total = total + i;
        }
    }
    return total;
};

void printTrianguloCombi (int n, int k){
    int nAux = 0;
    int kAux;
    int accum = 0;

    while (nAux <= n){
        kAux = 0;
        while (kAux <= nAux){
            if (kAux == 0){
                // add n spaces at the start of our line
                for (int i=nAux; i<n; i++){
                    cout << "   ";
                }
            }
            if (nAux==n && kAux==k){
                cout << "[" << nAux << " " << kAux << "]" << "<";
            }else{
                cout << "(" << nAux << " " << kAux << ")" << " ";
            }
            kAux++;
        };
        cout << endl;
        nAux++;
    }
}

int combiCalc (int n, int k){
    return (fact(n)/(fact(k)*fact(n-k)));
}

void printTrianguloNum (int n, int k){
    int nAux = 0;
    int kAux;
    int accum = 0;

    while (nAux <= n){
        kAux = 0;
        while (kAux <= nAux){
            if (kAux == 0){
                // add n spaces at the start of our line
                for (int i=nAux; i<n; i++){
                    cout << "  ";
                }
            }
            if (nAux==n && kAux==k){
                cout << combiCalc(nAux,kAux) << "<  ";
            }else{
                cout << combiCalc(nAux,kAux) << "   ";
            }
            kAux++;
        };
        cout << endl;
        nAux++;
    }
}

int combiRecu(int n, int k){
    int total;
    if (k==0 || n==0 || n==k){
        // "paredes" del triangulo
        return 1;
    }
    else{
        // es un elemento interior, sumo los dos de arriba
        total = combiRecu(n-1, k-1)+combiRecu(n-1, k);
    }
    return total;
}

int combinatorioIterativo (int n, int k){
    printTrianguloCombi(n,k);
    printTrianguloNum(n,k);
    return combiCalc(n,k);
}

void writeToFile(int n){
    ofstream fout;
    fout.open("test.txt");
    fout << n+n << endl;
    fout.close();
}

void collatz(int n, int &cantPasos){
    while (n>1){
        cantPasos++;
        if(n%2 == 0){
            n=n/2;
        }
        else{
            n=n*3+1;
        }
        cout << n << " ";
    }
}

int sumaCondi(int x, int y){
    if(x > y){
        return x+y;
    }
    else{
        return x*y;
    }
}

void ejercicios1al5(int n, int k){
    // Ejercicio 1: recibe n, devuelve n+1
    cout << "Ejercicio 1: " << n << "+1 es " << (n+1) << endl;
    // Ejercicio 2: recibe n,k, devuelve la suma
    cout << "Ejercicio 2: " << n << "+" << k << " es " << (n+k) << endl;
    // Ejercicio 3: recibe dos parametros x e y de tipo int
    // y los sume solo si x > y, encaso contrario el
    // resultado sera el producto.
    cout << "Ejercicio 3: " << sumaCondi(n, k) << endl;
    // Ejercicio 4: Crear otro proyecto...
    // Ejercicio 5:
    cout << "Ejercicio 5: " << endl;
    if (esPrimo(n)){
        cout << n << " es primo!" << endl;
    }
    else {
        cout << n << " no es primo!" << endl;
    }
}
void ejercicios6al10(int n, int k){
    // Ejercicio 6. Escribir la función de Fibonacci que dado un entero n
    //              devuelve el n-ésimo número de Fibonacci. Los números
    //              de Fibonacci empiezan con
    //              F0 = 0 y F1 = 1. Fn = Fn−1 + Fn−2
    cout << "La secue de fibo recur hasta " << n << " es: " << fiboRecursivo(n) << endl;
    cout << "La secue de fibo c/while hasta " << n << " es: " << fiboIterativoConWhile(n) << endl;
    cout << "La secue de fibo c/for hasta " << n << " es: " << fiboIterativoConFor(n) << endl;
    cout << endl;
    // Ejercicio 7. Escribir la función que dado n ∈ N devuelve la suma de
    //              todos los números impares menores que n.
    cout << "La suma de impares menores a " << n << " recur: " << sumaImparesRecursivo(n-1) << endl;
    cout << "La suma de impares menores a " << n << " itera: " << sumaImparesIterativo(n) << endl;
    cout << endl;
    // Ejercicio 8. Escribir la función sumaDivisores que dado n ∈ N,
    //              devuelve la suma de todos sus divisores entre [1, n].
    cout << "La suma de los divisores positivos de " << n << " es: " << sumaDivisores(n) << endl;
    /* comete el fla:
     * en el compilador del celu imprimia primero "La suma de los divisores positivos de " << n << " es: "
     * y luego los valores que se imprimen desde la llamada a la función.
     * Acá es diferente, parece primero llamar a la funcion, imprime lo de adentro, y luego muestra
     * to do el string con la data junta.
      */

    // Ejercicio 9: Escribir una funcion que dados n, k∈N compute el combinatorio:(nk).
    // Hacerlo usando la igualdad
    // (n k) = (n−1 k)+(n−1 k−1)
    cout << "El combinatorio recursivo ( " << n << " " << k << " ) es: " << combiRecu(n,k) << endl;
    cout << "El combinatorio con formula ( " << n << " " << k << " ) es: " << combinatorioIterativo(n, k) << endl;
}

void ejerciciosRandom(int n){
    // Prueba con archivos:
    writeToFile(n);

    //collatz
    /*Ejercicio 18.void collatz(int n, int& cantPasos)
     * La conjetura de Collatz dice que dado un
     * n ́umero naturalny el proceso que describimos a continuaci ́on, sin importar cu ́alsea el
     * n ́umero original, provocar ́a que la serie siempre termine en 1. El proceso:Si n es par
     * lo dividimos por 2Si n es impar lo multiplicamos por 3 y le sumamos 1 al resultadoEn este
     * ejercicio, supondremos que la conjetura es cierta y se pide implementar una funci ́on que
     * devuelva la cantidad depasos que se realizan desde el n ́umero original hasta llegar a 1.
     * Ejemplo: si calculamos collatz de 11, la cantidad de pasos es 15 y la sucesi ́on es
     * 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
     * Resolver este ejercicio en versiones iterativa y recursiva.*/
    int pasos = 0;
    cout << "Collatz: " ;
    collatz(21, pasos);
    cout << pasos << endl;
    //
}

int main () {
    int n = 8;
    int k = 2;
    char reply = (char) "o";
    char a = 'a';
    cout << "'a': Ejercicios del 1 al 5" << endl;
    cout << "'b': Ejercicios del 6 al 10" << endl;
    cout << "'c': Ejercicios random" << endl;
    cout << "'x': Salir" << endl;
    while (reply != 'x'){
        cout << "Elija a/b/c: ";
        cin >> reply;
        cout << endl;
        if (reply == a){
            cout << "Ejercicios del 1 al 5:" << endl;
            ejercicios1al5(n,k);
        }
        else if (reply == 'b'){
            cout << "Ejercicios del 6 al 10:" << endl;
            ejercicios6al10(n,k);
        }
        else if (reply == 'c'){
            cout << "Ejercicios random:" << endl;
            ejerciciosRandom(n);
        }
    }

    return 0;
};