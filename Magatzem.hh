/** @file Magatzem.hh
    @brief Especificació de la classe Magatzem 
*/

#ifndef MAGATZEM_HH
#define MAGATZEM_HH

#include "Sala.hh"
#include "Inventari.hh"
#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <list>
#endif

/** @class Magatzem
    @brief Representa un magatzem 

    Conté el plànol d'un magatzem de n sales, cadascuna amb una prestatgeria
	on s'emmagetzemen productes. Aquests productes estan identificats i 
	comptabilitzats en un inventari.
*/

class Magatzem {
        
public:
    //Constructores
    
  /** @brief Creadora amb valors concrets. 

      \pre n > 0 
      \post El resultat és un magatzem amb n sales buides i dimensionades, 
	  junt amb el seu plànol
  */   
   Magatzem (int n);
    
    //Modificadores

  /** @brief Afegeix items a una sala
      \pre id i sala existeixen i quantitat >= 0
      \post tornem el nombre d'elements que no han cabut a la sala. 
       Els demès han estat afegits a partir del primer forat
  */    
   int poner_items (int sala, string id, int quantitat, Inventari &I);

  /** @brief Extrau items a una sala
      \pre id i sala existeixen i quantitat >= 0
      \post tornem el nombre d'elements que no s'han pogut treure. 
	   L'extracció es fa seguint l'ordre d'aparició a la prestatgeria	
  */  	   
    int quitar_items (int sala, string id, int quantitat, Inventari &I);
    
   /** @brief Distribueix un stock segons una politica marcada 
      \pre id consta a l'inventari i quantitat >= 0
      \post tornem el nombre d'elements que no han cabut al magatzem. 
  */     
    int distribuir (string id, int quantitat, Inventari& I);  
    
  /** @brief Compacta el contingut d'una sala. 

      \pre sala existeix al magatzem
      \post Es compacta la sala introduïda
  */ 	
    void compactar (int sala);

  /** @brief Reorganitza una sala
      \pre sala existeix al magatzem
      \post sala s'ha reorganitzat alfabèticament
  */     
    void reorganizar (int sala);
 
   /** @brief Redimensiona una sala
      \pre Cert
      \post sala queda redimensionada i compactada
  */ 
    void redimensionar (int sala, int f, int c); 
    
    //Consultores
    
   /** @brief Consultora d'existència d'una sala
      \pre sala > 0
      \post Indiquem si sala existeix o no al magatzem
  */     
    bool existeix_sala (int sala);
    
    //Escriptura (auxiliar)
    
    /** @brief Escriu el contingut d'una sala
      \pre sala existeix al magatzem
      \post Imprimir pel canal de sortida el contingut de la sala
  */       
    void escribir (int sala);   
    
    /** @brief Escriu el contingut d'una posicio de la sala
      \pre sala existeix al magatzem
      \post Tornem l'element que ocupa la posició (f, c)
  */       
    string consultar_pos (int sala, int f, int c);       
	
	private:

    /** @brief Nombre de sales del magatzem
  */        
    int nombre_sales;
    
    /** @brief Representació del magatzem
     
     Cada posició del vector és una sala del magatzem
  */    
    vector<Sala> magatzem;
    
    /** @brief Representació del plànol del magatzem
     
     planol és un arbre que ens dóna la informació sobre la
     construcció del magatzem. Es necessita per a la funció distribuir
  */    
    BinTree<int> planol;
    
    /** @brief Lectura del plànol
  */    
    static void llegeix_planol_sales (BinTree<int>& a);	
    
    /** @brief Inmersió sobre la funció distribuir
  */    
    int distr_inmers (BinTree<int>& a, string id, int quantitat, Inventari& I);
};

#endif	