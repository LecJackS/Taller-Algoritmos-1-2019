#include <iostream>
#include <vector>

using namespace std;

vector<int> bubble_sort(vector<int> lista){
    for(int i=0; i<lista.size(); i++){
        for(int j=0; j<lista.size() - i-1; j++){
            if(lista[j] > lista[j+1]){
               swap(lista[j], lista[j+1]);
            }
        }
    }
    return lista;
}

int minimo(vector<int> lista){
    int el_minimo = lista[0];
    for(int i=1; i<lista.size();i++){
        if(lista[i]<el_minimo){
            el_minimo = lista[i];
        }
    }
    return el_minimo;
}

vector<int> selection_sort(vector<int> lista){
    for(int i=0; i<lista.size(); i++){
        int el_minimo = lista[i];
        int su_idx = i;
        for(int j=i+1; j<lista.size(); j++){
            if(lista[j] < el_minimo){
                el_minimo = lista[j];
                su_idx = j;
            }
        }
        swap(lista[i], lista[su_idx]);
    }
    return lista;
}

vector<int> insertion_sort(vector<int> lista){
    for(int i=1; i<lista.size(); i++){
        int X = lista[i];
        int j=i-1;
        while(j>=0 && X < lista[j]){
            lista[j+1] = lista[j];
            j--;
        }
        lista[j+1] = X;
    }
    return lista;
}

int main(int argc, char **argv) {
    vector<int> lista;
    lista = {3,5,6,8,3,2,5,7,9,32,2,6,884,23,65};
    cout << "Lista desordenada:" << endl;
    for(int i=0; i<lista.size(); i++){
        cout << lista[i] << " ";
    }
    cout << endl;

    cout << "Lista ordenada con Bubble Sort:" << endl;
    vector<int> lista_bubble;
    lista_bubble = bubble_sort(lista);
    for(int i=0; i<lista_bubble.size(); i++){
        cout << lista_bubble[i] << " ";
    }
    cout << endl;

    
    cout << "Lista ordenada con Selection Sort:" << endl;
    vector<int> lista_sel;
    lista_sel = selection_sort(lista);
    for(int i=0; i<lista_sel.size(); i++){
        cout << lista_sel[i] << " ";
    }
    cout << endl;

    
    cout << "Lista ordenada con Insertion Sort:" << endl;
    vector<int> lista_ins;
    lista_ins = insertion_sort(lista);
    for(int i=0; i<lista_ins.size(); i++){
        cout << lista_ins[i] << " ";
    }
    cout << endl;


    return 0;
}