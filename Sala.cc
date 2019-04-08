/** @file Sala.cc
    @brief Implementació de la classe Sala
*/

#include "Sala.hh"
#include <algorithm>
#include <string>
using namespace std;


Sala::Sala () {
    f = 0;
    c = 0;
    contador = 0;
    vector<string> v;
    prestatgeria = v;
}

Sala::Sala (int a, int b) {
    vector<string> v (a*b, "NULL");
    prestatgeria = v;
    f = a;
    c = b;
    contador = 0;
}

void Sala::compactar_prestatgeria () {
	int mida = f*c;
	int j = 0;
	
	/*Inv: els elements de prestatgeria[0..i-1] estan compactats,
	0 <= i <= mida */
	
	for (int i = 0; i < mida; i++) {
		if (prestatgeria[i]!="NULL") {
			prestatgeria[j] = prestatgeria[i];
			++j;
		}
	}  

	//Si hi ha forats a la prestatgeria, omplenem l'espai que queda desde j fins
	//a l'última posició amb forats
	
	while (j < mida) {
		prestatgeria[j] = "NULL";
		++j;
	}
}

void Sala::reorganitzar_prestatgeria () {
	//Cost: N*log2(N)
    compactar_prestatgeria();
    int i = 0;
    int x = busca_item (i, "NULL");
    if (x == -1) sort (prestatgeria.begin(), prestatgeria.end());
    else {
        int m = prestatgeria.size() - x; //Última posicio no-buida
        sort (prestatgeria.begin(), prestatgeria.end() - m);        
    }
}

void Sala::redimensionar_prestatgeria (int new_f, int new_c) {
	//resize té cost lineal sobre el nombre d'elements 
    //insertats/el·liminats del vector
	if (contador > new_f*new_c) cout << "  " << "error" << endl;
	else {
        compactar_prestatgeria();
        prestatgeria.resize (new_f*new_c, "NULL"); //Si la nova prestatgeria és mes gran, 
                                                   //omplenarem les noves posicions amb "NULL"
        f = new_f; c = new_c;                                           
    }
}	
	
void Sala::coloca_item (string item, int pos) {
    prestatgeria[pos] = item;
    if (item == "NULL") --contador;
    else ++contador;
}

bool Sala::esta_ple () const {
    if (f*c > contador) return false;
    else return true;
}

bool Sala::esta_buit () const {
    if (contador == 0) return true;
    else return false;
}

int Sala::busca_item (int& ini, string item) {
	//Búsqueda lineal desde ini
	bool found = false;
	
	/*Inv: 0<=ini<=prestatgeria.size(), el subvector prestatgeria[0..i-1]
	no conté item, si found és true, llavors prestatgeria[i]==item */
	
	while (ini < prestatgeria.size() and !found) { 
        if (prestatgeria[ini] == item) found = true;
        ++ini;
    }
	if (!found) return -1;
    else return ini-1;
}

void Sala::escriu_prestatgeria () const {
    int salt = 1;  //variable auxiliar per a la representació matricial de la prestatgeria
    cout << " ";
    map<string, int> M;
	
	//Imprimim la prestatgeria d'abaix a adalt, i d'esquerra a dreta
    for (int i = f-1; i >= 0; i--) {  
        for (int j = 0; j < c; j++) {
        cout << ' ' << prestatgeria[(i*c)+j];
        if (prestatgeria[(i*c)+j]!="NULL") ++M[prestatgeria[(i*c)+j]];
            if (salt == c) {
                cout << endl;
                cout << ' ';
                salt = 0;
            }
            ++salt; 
        }
    }
    cout << " " << contador << endl;
    for (map<string, int>::iterator it = M.begin(); it != M.end(); ++it) {
        cout << "  " << it->first << " " << it->second; 
        cout << endl;
    }
}

string Sala::consultar_pos_prestatgeria (int a, int b) const {
    if (a > f or b > c) return "SEGMENTATION_FAULT";
    else {
        a = a-f;
        if (a < b) a = (a)*(-1);
        return prestatgeria[(a*c)+(b-1)];
    }
}
