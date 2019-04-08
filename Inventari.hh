/** @file Inventari.hh
    @brief Especificació de la classe Inventari
*/

#ifndef INVENTARI_HH
#define INVENTARI_HH

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#include <iostream>
using namespace std;
#endif

/** @class Inventari
    @brief Representa l'inventari del magatzem

    Conté funcions d'E/S i consultes del conjunt d'elements 
	del magatzem. Enregistra l'addició i el·liminacio de productes.
*/

class Inventari {
    
public:
	//Constructores
	
  /** @brief Creadora per defecte. 

      \pre Cert
      \post Creem un inventari completament buit
  */   
	Inventari ();
	
    //Modificadores

  /** @brief Incrementador de l'inventari. 

      \pre id es un producte que no s'ha declarat previament
      \post S'afegeix id a l'inventari amb contingut = 0
  */   
    void poner_prod (string id);

  /** @brief Decrementadora de l'inventari. 

      \pre id es un producte que existeix i té 0 elements
      \post id s'el·limina de l'inventari
  */   
    void quitar_prod (string id);
	
  /** @brief Modifica la quantitat d'stock. 

      \pre id existeix
      \post Augmentem o decrementem id en un factor igual a quantitat
  */   	
	 void modifica_stock (string id, int quantitat);
	 
	//Consultores
	
  /** @brief Consultora de l'stock d'un producte. 

      \pre id s'ha declarat prèviament
      \post Tornem la quantitat de id al magatzem
  */	
    int consultar_prod (string id) const;
    
  /** @brief Consultora d'existència d'un producte. 

      \pre Cert
      \post Indiquem si el producte existeix o no a l'inventari
  */	    
    bool existeix_producte (string id) const;
	
	//Escriptura
	
  /** @brief Consultora de tot l'inventari. 

      \pre Cert
      \post Escribim l'identificador i la quantitat de tots els
	  productes de l'inventari
  */
	 void inventario () const;
     
	
private:

  /** @brief Representació de l'inventari
     
     Tenim un map que conté, en tot moment, el nom de cada producte
     del magatzem i la seva quantitat
  */    
    map <string, int> llista_identificacio;  
};

#endif