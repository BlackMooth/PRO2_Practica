/** @file Inventari.cc
    @brief Implementació de la classe Inventari
*/

#include "Inventari.hh"

Inventari::Inventari () {
    map <string, int> l;
    llista_identificacio = l;
}

void Inventari::poner_prod (string id) {
    map <string, int>::const_iterator it = llista_identificacio.find (id); 
    if (it == llista_identificacio.end()) {
      llista_identificacio[id] = 0;
    }
    else cout << "  " << "error" << endl;
}

void Inventari::quitar_prod (string id) {
    map <string, int>::const_iterator it = llista_identificacio.find (id); 
    if (it == llista_identificacio.end()) cout << "  " << "error" << endl;
        else {            
            if (llista_identificacio[id] != 0) cout << "  " << "error" << endl;            
            else llista_identificacio.erase (id);
        }
}

void Inventari::modifica_stock (string id, int quantitat) {
    llista_identificacio[id]+=quantitat;
}

int Inventari::consultar_prod (string id) const{
    bool b;
    b = existeix_producte (id);
    if (!b) return -1;
    else {
        map <string, int>::const_iterator it = llista_identificacio.find (id);
        return it->second;
    }
}

bool Inventari::existeix_producte (string id) const{
    map <string, int>::const_iterator it = llista_identificacio.find(id);
    if (it == llista_identificacio.end()) return false;
    else return true;
}

void Inventari::inventario() const {
    map <string, int>::const_iterator it;
    for (it = llista_identificacio.begin(); it!=llista_identificacio.end(); ++it) {
        cout << "  " << it->first << ' ' << it->second << endl;
    }
}
