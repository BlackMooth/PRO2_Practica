/**
 * @mainpage Pràctica de PRO2:  TreeKEA.
 
En aquesta pràctica fem un programa modular que ofereix un sistema per gestionar l'stock d'un magatzem. S'introdueixen les classes <em>Magatzem</em>, <em>Sala</em> i <em>Inventari</em>.
*/

/** @file program.cc
    @brief Programa principal per a la pràctica <em>TreeKEA</em>.
*/

#include "Magatzem.hh"
#include "Inventari.hh"
#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

/** @brief Programa principal per a la pràctca <em>TreeKEA</em>.
*/
int main() {
	int n;
	cin >> n;
	Magatzem M (n);
	Inventari I;
	
	string ordre;
	string identificador;
	int sala, quantitat;
    bool stop = false;
    
    
	while (cin >> ordre and !stop) {
		
		if (ordre == "poner_prod" or ordre == "quitar_prod") {
			cin >> identificador;
            cout << ordre << ' ' << identificador << endl;
			if (ordre == "poner_prod") I.poner_prod (identificador);
			else I.quitar_prod (identificador);
		}
		
		else if (ordre == "poner_items" or ordre == "quitar_items") {
			cin >> sala >> identificador >> quantitat;
            cout << ordre << ' ' << sala << ' ' << identificador << ' ' << quantitat << endl;
            cout << "  ";
			if (ordre == "poner_items") {
				int x = M.poner_items (sala, identificador, quantitat, I);
				if (x==-1) cout << "error" << endl;
				else cout << x << endl;
			}	
			else {
				int x = M.quitar_items (sala, identificador, quantitat, I);
				if (x==-1) cout << "error" << endl;
				else cout << x << endl;
			}
		}					
				
		else if (ordre == "distribuir") {
			cin >> identificador >> quantitat;
            cout << "distribuir" << ' ' << identificador << ' ' << quantitat << endl;
            cout << "  ";            
            bool b = I.existeix_producte (identificador);
            if (!b) cout << "error" << endl;
            else {
			int x = M.distribuir (identificador, quantitat, I);
			cout << x << endl;
            }
		}
		
		else if (ordre == "compactar" or ordre == "reorganizar") {
			cin >> sala;
            cout << ordre << ' ' << sala << endl;
			if (ordre == "compactar") M.compactar (sala);
			else M.reorganizar (sala);
		}
		
		else if (ordre == "redimensionar" or ordre == "consultar_pos") {
			int f, c;
			cin >> sala >> f >> c;
            cout << ordre << ' ' << sala << ' ' << f << ' ' << c << endl;
			if (ordre == "redimensionar") M.redimensionar (sala, f, c);
			else {
                string x = M.consultar_pos (sala, f, c);
                if (x=="SEGMENTATION_FAULT") cout << "  " << "error" << endl;
                else cout << "  " << x << endl;
            }
		}
		
		else if (ordre == "inventario") {
            cout << "inventario" << endl;
            I.inventario ();
        }
		
		else if (ordre == "escribir") {
			cin >> sala;
            cout << ordre << ' ' << sala << endl;
			M.escribir (sala);
		}
		
		else if (ordre == "consultar_prod"){
			cin >> identificador;
            cout << ordre << ' ' << identificador << endl;
            cout << "  ";            
			int x = I.consultar_prod (identificador);
            if (x==-1) cout << "error" << endl;
            else cout << x << endl;
		}
		
		else if (ordre == "fin") {
            cout << "fin" << endl;
            stop = true;
        }
        
        else stop = true;  //Instrucció invàlida
    }
}		
