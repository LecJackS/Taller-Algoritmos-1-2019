#include "ejercicios.h"

bool divide(vector<int> v, int n){
    //cout << "Implementame!" << endl;
    for(int i=0; i< v.size(); i++){
        if(v[i]%n != 0){
            return false;
        }
    }
    return true;
}

bool divideRec(vector<int> v, int n){
    //cout << "Implementame!" << endl;
    if (v.size()==0){
        return true;
    }
    if (v[v.size()-1] % n == 0){
        // si divide al ultimo elemento, lo remuevo y veo los otros
        v.pop_back();
        return divideRec(v, n);
    }
    return false;
}

int maximo(vector<int> v){
    //cout << "Implementame!" << endl;
    int maxValor = v[0];
    for(int i=0; i < v.size(); i++){
        if(v[i] > maxValor){
            maxValor = v[i];
        }
    }
    return maxValor;
}

int maximoRec(vector<int> v){
    cout << "Implementame!" << endl;

    return 0;
}

bool pertenece(int elem, vector<int> v){
    //cout << "Implementame!" << endl;
    for(int i=0; i < v.size(); i++){
        if(v[i] == elem){
            return true;
        }
    }
    return false;
}

bool perteneceRec(int elem, vector<int> v){
    cout << "Implementame!" << endl;

    return false;
}

void mostrarVector(vector<int> v){
    //cout << "Implementame!" << endl;
    for(int i=0; i< v.size(); i++){
        if(i==0){
            cout << "[";
        }
        cout << v[i];
        if(i < (v.size()-1)){
            //comas entre elementos menos el ultimo
            cout << ", ";
        }
        else{
            //ultimo elemento
            cout << "]";
        }
    }
    cout << endl;

}

void mostrarVectorDeBool(vector<bool> v){
    //cout << "Implementame!" << endl;
    for(int i=0; i< v.size(); i++){
        if(i==0){
            cout << "[";
        }
        cout << v[i];
        if(i < (v.size()-1)){
            //comas entre elementos menos el ultimo
            cout << ", ";
        }
        else{
            //ultimo elemento
            cout << "]";
        }
    }
    cout << endl;
}

vector<int> limpiarDuplicados(vector<int> v){
    //cout << "Implementame!" << endl;
    vector<int> res;
    for(int i=0; i < v.size(); i++){
        if(!pertenece(v[i], res)){
            res.push_back(v[i]);
        }
    }
    return res;
}

vector<int> rotar(vector<int> v, int k){
    //cout << "Implementame!" << endl;
    int size = v.size();
    int mitad;
    if (size%2==0){
        mitad = size/2;
    }
    else{
        mitad = (size+1)/2;
    }
    vector<int> res(size);
    for(int i=0; i < mitad; i++){
        if(i < k){
            res[i]        = v[size-1 - i];
            res[size-1 - i] = v[i];
        }
        else{
            res[i]        = v[i];
            res[size-1 - i] = v[size-1 - i];
        }
    }
    return res;
}

vector<int> reverso(vector<int> v){
    //cout << "Implementame!" << endl;
    vector<int> res;
    res = rotar(v, v.size());
    return res;
}

vector<int> reversoRec(vector<int> v){
    cout << "Implementame!" << endl;

    vector<int> res;
    return res;
}

bool esPrimo(int n){
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

vector<int> factoresPrimos(int n){
    //cout << "Implementame!" << endl;
    vector<int> res;
    for(int i=2; i <= n; i++){
        if(esPrimo(i) && (n%i == 0)){
            //cout << i << endl;
            res.push_back(i);
        }
    }
    return res;
}

bool esCreciente(vector<int> v){
    for(int i=0; i < v.size()-1; i++){
        if(v[i] > v[i+1]){
            return false;
        }
    }
    return true;
}

bool esDecreciente(vector<int> v){
    for(int i=0; i < v.size()-1; i++){
        if(v[i] < v[i+1]){
            return false;
        }
    }
    return true;
}

bool estaOrdenado(vector<int> v){
    //cout << "Implementame!" << endl;
    if(esCreciente(v) || esDecreciente(v)){
        //cout << i << endl;
        return true;
    }
    return false;
}

void negadorDeBooleanos(vector<bool> &booleanos){
    //cout << "Implementame!" << endl;
    for(int i=0; i < booleanos.size(); i++){
        booleanos[i] = !booleanos[i];
    }
}

void sinImpares(vector<int>& v){
    //cout << "Implementame!" << endl;
    for(int i=0; i < v.size(); i++){
        if(v[i]%2==1){
            v[i]=0;
        }
    }
}

int apareceEnTupla(int n, vector<pair<int,int>> vecTup){
    for(int i=0; i < vecTup.size(); i++){
        if(n == vecTup[i].first){
            return i;
        }
    }
    return -1;
}

vector<pair<int, int>> cantidadApariciones(vector<int> v){
    //es como un diccionario
    //cout << "Implementame!" << endl;
    vector<pair<int, int> > vecTup;
    int indexApa;
    for(int i=0; i < v.size(); i++){
        indexApa = apareceEnTupla(v[i], vecTup);
        if(indexApa >= 0){
            // aparece en lista de tuplas
            vecTup[indexApa] = make_pair(vecTup[indexApa].first, vecTup[indexApa].second + 1);
        }
        else{
            vecTup.push_back(make_pair(v[i],1));
        }
    }
    return vecTup;
}

void mostrarString(string s){

}
/* Ejercicio 3.24 */

string invertirPalabra(string palabra){
    char letra;
    int longi = palabra.size();
    for(int i=0; i<longi/2; i++){
        //invierto las letras de la palabra
        letra = palabra[i];
        palabra[i] = palabra[longi-1-i];
        palabra[longi-1-i] = letra;
    }
    return palabra;
}
bool esPalindromo(string palabra){
    if(palabra == invertirPalabra(palabra)){
        return true;
    }
    return false;
}

/* void palindromos(string rutaArchivoIn, string rutaArchivoOut)
 * Este procedimiento debe leer un archivo que contiene una lista de strings
 * y crear uno nuevo dejando s ́olo lospal ́ındromos. Adem ́as, debe transformar
 * las palabras a may ́uscula.Ayuda: Buscar la funci ́on toupper definida encctype.
 * Utilizar como ejemplo el archivo palindromos.txt. */
void palindromos(string rutaArchivoIn, string rutaArchivoOut){
    string palabra;
    vector<string> listaPalin;
    ofstream fout;
    ifstream fin;
    fin.open(rutaArchivoIn);
    if (fin.fail()){
        cout << "Error opening rutaArchivoIn, creando uno nuevo..." << endl;
        fout.open(rutaArchivoIn);
        fout.close();
    }
    while(!fin.eof()){
        fin >> palabra;
        if(esPalindromo(palabra)){
            //
            listaPalin.push_back(palabra);
        }
    }
    fin.close();

    fout.open(rutaArchivoOut);
    if (fout.fail()){
        cout << "Error opening rutaArchivoOut: ";
        return;
    }
    cout << listaPalin.size() << " palindromo/s encontrado/s!" << endl;
    for(int i=0; i<listaPalin.size(); i++){
        fout << listaPalin[i] << " ";
    }
    cout << "Archivo guardado exitosamente!" << endl;

    fout.close();
}

/* 2. void promedios(string rutaArchivoIn1, string rutaArchivoIn2,
 * string rutaArchivoOut)Dados dos archivos en los que cada uno contiene
 * una secuencia de enteros (ambas con la misma longitud), guardar elpromedio
 * de cada par de n ́umeros que se encuentran en la misma posici ́on en el
 * archivo de salida. Por ejemplo: sitenemos dos secuencias
 * “1 2 3 4” y “1 25 3 12” el resultado debe ser “1 13.5 3 8” */
void promedios(string rutaArchivoIn1, string rutaArchivoIn2, string rutaArchivoOut){
    vector<float> secue;
    int elem1, elem2;
    ifstream fin1;
    ifstream fin2;
    ofstream fout;
    fin1.open(rutaArchivoIn1);
    fin2.open(rutaArchivoIn2);
    fout.open(rutaArchivoOut);
    if(fin1.fail() || fin2.fail() || fout.fail()){
        cout << "Error al leer un archivo!" << endl;
        return;
    }
    while(!fin1.eof() && !fin2.eof()){
        fin1 >> elem1;
        fin2 >> elem2;
        fout << ((elem1+elem2)/2.0) << " ";
    }
    fin1.close();
    fin2.close();
    fout.close();
    cout << "Promedios guardados exitosamente!" << endl;
}

/* void promediosHasta(string rutaArchivoIn, string rutaArchivoOut)
 * Dado un archivorutaArchivoIn, que contiene una lista de n ́umeros
 * separados por espacios, calcular una lista depromedios de la misma
 * longitud donde cada elemento corresponde al promedio de todos los
 * anteriores de la listaoriginal (incluyendo dicho elemento). La lista
 * de promedios debe ser guardada en el archivo indicado porrutaArchivoOut.
 * Por ejemplo, dada la secuencia “1 2 3 2 1”, el resultado debe ser “1 1.5 2 2 1.8”. */
void promediosHasta(string rutaArchivoIn, string rutaArchivoOut){
    vector<float> secue;
    int elemOri;
    float elemOut;
    ifstream fin;
    ofstream fout;
    fin.open(rutaArchivoIn);
    fout.open(rutaArchivoOut);
    if(fin.fail() || fout.fail()){
        cout << "Error al leer un archivo!" << endl;
        return;
    }
    while(!fin.eof()){
        fin >> elemOri;
        secue.push_back(elemOri);
        elemOut = 0;
        for(int i=0; i<secue.size(); i++){
            elemOut = elemOut + secue[i];
        }
        elemOut = elemOut/secue.size();
        fout << elemOut << " ";
    }
    fin.close();
    fout.close();
    cout << "Promedios hasta guardados exitosamente!" << endl;
}

/* 4.void cantidadApariciones(string rutaArchivoIn, string rutaArchivoOut)
 * Dado un archivorutaArchivoIn, que contiene una lista de n ́umeros separados
 * por espacios, contar la cantidad deapariciones de cada uno y escriberutaArchivoOutcon
 * una l ́ınea por cada n ́umero encontrado, un espacio y lacantidad de apariciones.
 * Por ejemplo: si el “1” aparece 44 veces y el “2” 20 veces, la salida deber ́ıa
 * contener dosl ́ıneas: “1 44” y “2 20”. */
tuple<int,vector<int>> cuentaYRemueveApariciones(int n, vector<int> secue){
    //devuelve la cantidad de apariciones de n en secue
    int cant = 0;
    vector<int> newSecue;
    for(int i=0; i<secue.size(); i++) {
        if (secue[i] == n) {
            cant++;
        } else {
            newSecue.push_back(secue[i]);
        }
    }
    return {cant, newSecue};
}

void cantidadApariciones(string rutaArchivoIn, string rutaArchivoOut){
    int elem, cant;
    tuple<int,vector<int>> result;
    vector<int> secue, newSecue;
    ifstream fin;
    ofstream fout;
    fin.open(rutaArchivoIn);
    fout.open(rutaArchivoOut);

    while(!fin.eof()){
        fin >> elem;
        secue.push_back(elem);
    }
    newSecue = secue;
    while(newSecue.size() > 0){
        elem = newSecue[0];
        tie(cant, newSecue) = cuentaYRemueveApariciones(elem, newSecue);
        fout << elem << " " << cant << endl;
    }
    cout << "Cant de apariciones guardadas exitosamente!" << endl;
}

/* 5.int cantidadAparicionesDePalabra(string rutaArchivo, string palabra)
 * Dada una palabra y un archivo de texto devuelve la cantidad de apariciones
 * de la palabra en el archivo. */
int cantidadAparicionesDePalabra(string rutaArchivo, string palabra){
    string palabraEnArchivo;
    int result=0;
    ifstream fin;
    fin.open(rutaArchivo);
    while(!fin.fail() && !fin.eof()){
        fin >> palabraEnArchivo;
        if(palabraEnArchivo == palabra){
            result++;
        }
    }
    return result;
}

/* 6.void estadisticas(string rutaArchivo)
 * Dado un archivo de texto, mostrar por pantalla las estad ́ısticas
 * de cantidad de palabras con longitud 1,2,3. . .hastael m ́aximo.
 * Por ejemplo:
 * Palabras de longitud 1: 100
 * Palabras de longitud 2: 12
 * Palabras de longitud 3: 6 */
int indiceDeLaLongi(int longitud, vector<tuple<int, int>> data){
    // devuelve el indice de la longitud, -1 si no la encuentra
    int newLong, newCant;
    tuple<int,int> newVals;
    for(int i=0; i<data.size(); i++){
        if(longitud == get<0>(data[i])){
            //longitud guardada previamente!
            newLong = get<0>(data[i]);
            newCant = get<1>(data[i]) + 1;
            newVals = make_tuple(newLong, newCant);
            data[i].swap(newVals);
            return i;
        }
    }
    return -1;
}

void estadisticas(string rutaArchivo){
    int longitud,idx;
    string palabra;
    tuple<int, int> newVals;
    vector<string> secue;
    // tuple<longitud,apariciones>
    vector<tuple<int, int>> data;
    ifstream fin;
    fin.open(rutaArchivo);
    while(!fin.eof()){
        fin >> palabra;
        longitud = palabra.size();
        idx = indiceDeLaLongi(longitud, data);
        if(idx >= 0){
            // longitud guardada previamente
            newVals = {get<0>(data[idx]), get<1>(data[idx])+1};
            data[idx].swap(newVals);
        }
        else{
            // longitud nueva
            newVals = {longitud, 1};
            data.push_back(newVals);
        }
    }
    // y ahora a imprimirlos
    cout << "Estadisticas:" << endl;
    for(int i=0; i<data.size(); i++){
        cout << "Palabras de longitud " << get<0>(data[i]) << ": " << get<1>(data[i]) << endl;
    }
}

/* 7. void intersecion()
 * Procedimiento que pide al usuario que se ingresen dos nombres
 * de archivos que contengan s ́olo n ́umeros enterosseparados por
 * espacios, luego calcula la intersecci ́on (n ́umeros que se encuentran
 * en ambos archivos) e imprime porpantalla el resultado. */
bool elementoNOEnResult(int elem1, vector<int> result){
    for(int i=0;i<result.size();i++){
        if(result[i]==elem1){
            return false;
        }
    }
    return true;
}
void interseccion(){
    int elem1,elem2;
    vector<int> secue2, result;
    string rutaArchivo1, rutaArchivo2;
    cin >> rutaArchivo1;
    //cin >> rutaArchivo2;
    rutaArchivo1 = "lista-numeros1.txt";
    rutaArchivo2 = "lista-numeros2.txt";
    ifstream fin1, fin2;
    fin1.open(rutaArchivo1);
    fin2.open(rutaArchivo2);
    if(fin1.fail() || fin2.fail()){
        cout << "Error al leer algun archivo";
        return;
    }
    while(!fin2.eof()){
        fin2 >> elem2;
        secue2.push_back(elem2);
    }
    while(!fin1.eof()){
        fin1 >> elem1;
        for(int i=0;i<secue2.size();i++){
            if(secue2[i]==elem1){
                if(elementoNOEnResult(elem1, result)){
                    result.push_back(elem1);
                    cout << elem1 << " ";
                }

            }
        }
    }
}