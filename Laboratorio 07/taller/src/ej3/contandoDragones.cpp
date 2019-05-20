#include <vector>
#include <iostream>
using namespace std;

int contandoDragones(int T, int d1, int d2, int d3) {
    vector<int> dragones(T, 0);
    int cuenta = 0;
    //Cuanto travesuras a cada dragon
    for(int i=0; i<T; i++){
        if(i%d1==0){
            dragones[i] += 1;
        }
        if(i%d2==0){
            dragones[i] += 1;
        }
        if(i%d3==0){
            dragones[i] += 1;
        }
    }

    for(int j=0; j < T; j++){
        if(dragones[j] == 0){
            cuenta++;
        }
    }
    return cuenta;
}
