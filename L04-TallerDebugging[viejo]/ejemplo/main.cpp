#include <string>
#include <iostream>

using namespace std;

string dameSubString (string s, int &i, int delim) {
    string res;

    while(i<s.size() && s[i] != delim)
        res.push_back(s[i]);
        i++;

    return res;
}

string indice_substring(string s, char delim, int ind) {
    bool encontre = false;
    int i = 0;
    int actual = 0;
    string res;
    while(i < s.size() && !encontre) {
        res = dameSubString(s, i, delim);

        if (ind==actual){
            encontre = true;
        } else {
            res.clear();
            actual++;
        }
    }
    if (encontre || ind == actual)
        return res;
    else
        return "Indice fuera de rango";
}


int main() {
	cout << "indice_substring('esto#es#un#ejemplo','#', 2)" << endl
         << "debería devolver: 'un' y devuelve: " << indice_substring("esto#es#un#ejemplo",'#', 2) << endl << endl;

    cout << "indice_substring('#esto#es#un#ejemplo','#', 2)" << endl
         << "debería devolver: 'es' y devuelve: " << indice_substring("#esto#es#un#ejemplo",'#', 2) << endl << endl;

    cout << "indice_substring('#esto#es#un#ejemplo','#', 0)" << endl
         << "debería devolver: 'vacio' y devuelve: " << indice_substring("#esto#es#un#ejemplo",'#', 0) << endl << endl;

    cout << "indice_substring('#esto##es#un#ejemplo','#', 2)" << endl
         << "debería devolver: 'vacio' y devuelve: " << indice_substring("#esto##es#un#ejemplo",'#', 2) << endl << endl;

}





































string indice_substring_corregido(string s, char delim, int ind) {
    bool encontre = false;
    int i = 0;
    int actual = 0;
    string res;
    while(i < s.size() && !encontre) {
        if(s[i] != delim)
            while(i<s.size() && s[i] != delim){
                res.push_back(s[i]);
                i++;
            }
        if (ind==actual){
            encontre = true;
        } else {
            res.clear();
            i++;
            actual++;
        }
    }
    if (encontre || ind == actual)
        return res;
    else
        return "Indice fuera de rango";
}