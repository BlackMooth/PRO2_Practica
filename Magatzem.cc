/** @file Magatzem.cc
    @brief Implementació de la classe Magatzem
*/

#include "Magatzem.hh"

Magatzem::Magatzem (int n) {
   nombre_sales = n;
   magatzem = vector<Sala> (n);
   BinTree<int> p;
   planol = p;
   llegeix_planol_sales (planol);
   
   /*Inv: magatzem[0..i-1] està dimensionat amb prestatgeries de fxc, 0<=i<=n */
   
    for (int i = 0; i < n; i++) {
        int f, c;
        cin >> f >> c;
        Sala s (f, c);
        magatzem[i] = s;
    }
}

void Magatzem::llegeix_planol_sales (BinTree<int>& a) {
  int x;
  cin >> x;
  if (x!=0){
	BinTree<int> l;
	llegeix_planol_sales(l);
	BinTree<int> r;
	llegeix_planol_sales(r);
	a=BinTree<int>(x,l,r);
  }
}

int Magatzem::poner_items (int sala, string id, int quantitat, Inventari& I) {
    int aux_quantitat = quantitat;
    if (!I.existeix_producte (id)) return -1;
    else {
        if (magatzem[sala-1].esta_ple()) return quantitat;
        else {
            int i = 0;  //Primera posició on buscar un forat
			
			/*Inv: i="posició del primer element de la prestatgeria, o de l'últim
			forat trobat". quantitat="nombre d'elements que queda per posar a la sala" */
			
            while (!magatzem[sala-1].esta_ple() and quantitat != 0) {
                int pos = magatzem[sala-1].busca_item (i, "NULL");
                magatzem[sala-1].coloca_item (id, pos);
                --quantitat;
            }
            I.modifica_stock (id, aux_quantitat-quantitat);  //Actualitzem l'inventari
            return quantitat;
        }
    }
}

int Magatzem::quitar_items (int sala, string id, int quantitat, Inventari& I) {
    int aux_quantitat = quantitat;
    if (!I.existeix_producte (id)) return -1;
    else {
        if (magatzem[sala-1].esta_buit()) return quantitat;
        else {
            bool stop = false;
            int i = 0;  //Primera posició on buscar un forat
			
			/*Inv: i="posició del primer element de la prestatgeria, o de l'última aparició
			de id". quantitat="nombre d'elements que encara no s'han tret de la sala" */
			
            while (!stop and quantitat != 0) {
                int pos = magatzem[sala-1].busca_item(i, id);
                if (pos != -1) {
                magatzem[sala-1].coloca_item ("NULL", pos);
                --quantitat;
                }
                else stop = true;
            }
            I.modifica_stock (id, (-1)*(aux_quantitat-quantitat));  //Actualitzem l'inventari
            return quantitat;
        }
    }
}


int Magatzem::distribuir (string id, int quantitat, Inventari& I) {
    int no_capacitat = distr_inmers (planol, id, quantitat, I);
    return no_capacitat;
}

//Inmersió sobre la funció distribuir

int Magatzem::distr_inmers (BinTree<int>& a, string id, int quantitat, Inventari& I) {
    if (a.empty() or quantitat == 0) return quantitat;  //Cas base
    else {
        int x = poner_items (a.value(), id, quantitat, I);  
        BinTree<int> l = a.left();
        BinTree<int> r = a.right();
        if (!l.empty()) {     //tot node té dos fills o no en té cap
                  int a = distr_inmers (l, id, (x/2) + (x)%2, I);  //H.I.: la meitatat de la quantitat x s'ha distribuit al subarbre esquerre, o la meitat + 0,5
                  int b = distr_inmers (r, id, x/2, I); //H.I.: la meitatat de la quantitat x s'ha distribuit al subarbre dret, o la meitat - 0,5 
                  return a+b;
        }   
        else return x;
    }        
}

void Magatzem::compactar (int sala) {
    bool b = existeix_sala (sala);
    if (!b) cout << "  " << "error" << endl;
    else magatzem[sala-1].compactar_prestatgeria();
}

void Magatzem::reorganizar (int sala) {
    bool b = existeix_sala (sala);
    if (!b) cout << "  " << "error" << endl;
    else magatzem[sala-1].reorganitzar_prestatgeria();
}

void Magatzem::redimensionar (int sala, int f, int c) {
    bool b = existeix_sala (sala);
    if (!b) cout << "  " << "error" << endl;
    else magatzem[sala-1].redimensionar_prestatgeria (f, c);
} 

bool Magatzem::existeix_sala (int sala) {
    if (sala > nombre_sales) return false;
    else return true;
}

void Magatzem::escribir (int sala)  {
    bool b = existeix_sala (sala);
    if (!b) cout << "  " << "error" << endl;
    else magatzem[sala-1].escriu_prestatgeria();
}

string Magatzem::consultar_pos (int sala, int f, int c)  {
    bool b = existeix_sala (sala);
    if (!b) return "SEGMENTATION_FAULT";
    else return magatzem[sala-1].consultar_pos_prestatgeria (f, c);
}
