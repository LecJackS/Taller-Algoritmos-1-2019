#include <iostream>
#include <string>
#include <vector>
using namespace std;

int get_all_digits(vector<char> num_palabra){
    string digitos = "";
    for(int i=0; i<num_palabra.size(); i++){
        if(isdigit(num_palabra[i])){
            digitos += num_palabra[i];
        }
    }
    return stoi(digitos);
}


int main() {
    string palabra = "11";
    //cout << stol(palabra, nullptr, 36) << endl;
    vector<string> palabras = {"version-1.9", "asd", "version-2.0", "123.45","version-1.11", "version-1.10"};
    //cout << palabras[2] << endl;


    int nPal = palabras.size();
    cout << "Palabras sin ordenar: " << endl;
    for(int i=0; i < nPal; i++) {
        cout << palabras[i] << " ";
    }
    cout << endl << endl;

    int numP0, numP1,num_char_0 ,num_char_1 ;
    char char_0, char_1;
    // bubblesort
    for(int i=0; i < nPal; i++){
        for(int j=0; j < nPal-i-1; j++){
            //numP0 = stol(palabras[j], nullptr, 100);
            //numP1 = stol(palabras[j+1], nullptr, 100);
            string palabra_0 = palabras[j];
            string palabra_1 = palabras[j+1];
            int menor_palabra = min(palabra_0.size(), palabra_1.size());

            for(int c=0; c<menor_palabra; c++){
                // comparo char a char:
                char_0 = palabras[j][c];
                char_1 = palabras[j+1][c];
                //cout << menor_palabra << " " << stof(char_0[0]) << endl;
                //num_char_0 = stol(char_0, nullptr, 36);
                //num_char_1 = stol(char_1, nullptr, 36);
                // MUERTE
                bool ambos_numeros = isdigit(char_0) && isdigit(char_1);
                if(ambos_numeros){
                    string sub_palabra_0 = copy(palabras[j],   c, palabras[j].size());
                    string sub_palabra_1 = copy(palabras[j+1],   c, palabras[j+1].size())
                    int num_palabra_0 = get_all_digits(sub_palabra_0);
                    int num_palabra_1 = get_all_digits(sub_palabra_1);
                    if (num_palabra_0 > num_palabra_1){
                        palabras[j].swap(palabras[j+1]);
                        break;
                    }
                }else{
                    if(char_0 > char_1){
                        //cout << "char0 > char1: " << palabras[j] << " " << palabras[j+1] << endl;
                        palabras[j].swap(palabras[j+1]);
                        break;
                    }
                    if(char_0 < char_1) {
                        //listo, ordenado
                        break;
                    }
                }

            }
        }
    }


    cout << "Palabras ordenadas:" << endl;
    for(int i=0; i < nPal; i++) {

        cout << palabras[i] << " ";
    }
    cout << endl;


    return 0;
}
