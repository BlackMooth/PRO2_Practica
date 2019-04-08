/** @file Sala.hh
    @brief Especificació de la classe Sala
*/

#ifndef SALA_HH
#define SALA_HH

#include "Inventari.hh"
#ifndef NO_DIAGRAM
#include <vector>
#endif

/** @class Sala
    @brief Representa una sala del magatzem 

    Conté l'estructura de les prestatgeries, així com funcions que 
	permeten la seva organització, consulta i modificació.
*/

class Sala {
        
public:
    //Constructores
    
 /** @brief Constructora per defecte. 

      \pre Cert
      \post Crea una prestatgeria de 0*0
  */   
    Sala ();       
 
  /** @brief Creadora amb valors concrets. 

      \pre (a > 0 i b > 0) o (a = 0 i b = 0)
      \post Es crea una prestatgeria de dimensions a*b
  */   
    Sala (int a, int b);    
    
    //Modificadores (funcions auxiliars que es criden desde Magatzem)
	
  /** @brief Compacta el contingut d'una prestatgeria. 

      \pre Cert
      \post Es compacta la prestatgeria de la sala introduïda
  */ 	
    void compactar_prestatgeria ();

  /** @brief Reorganitza una prestatgeria
      \pre Cert
      \post La prestatgeria de sala queda compactada i organitzada alfabèticament
  */     
    void reorganitzar_prestatgeria ();
 
   /** @brief Redimensiona una prestatgeria
      \pre Els productes que ja hi són a sala caben amb les noves dimensions
      \post La prestatgeria de sala queda redimensionada amb f i c i es compacta
  */ 
    void redimensionar_prestatgeria (int new_f, int new_c);

    /** @brief Col·loca un element en la prestatgeria
      \pre Cert
      \post La posició pos de la prestatgeria s'omplena amb item
  */    
    void coloca_item (string item, int pos);
    
    //Consultores

    /** @brief Consulta la capacitat d'una prestatgeria
      \pre Cert
      \post Indiquem si la sala que ens arriba esta plena o no
  */       
    bool esta_ple () const;
    
     /** @brief Consulta els elements d'una prestatgeria
      \pre Cert
      \post Indiquem si la sala que ens arriba esta buida o no
  */       
    bool esta_buit () const;   

    /** @brief Busca un item en una prestatgeria a partir de la posició ini
      \pre Cert
      \post Tornem l'índex de la primera aparició de item a la prestatgeria
	   a partir de ini, o -1, si no hi és
  */     
    int busca_item (int& ini, string item); 
    
    //Escriptura
    
    /** @brief Escriu una prestatgeria
      \pre Cert
      \post Imprimim el contingut de la prestatgeria de dalt a abaix i 
      d'esquerra a dreta
  */   
    void escriu_prestatgeria () const;

    /** @brief Escriu el contingut d'una posicio de la prestatgeria
      \pre a < = f i b < = c
      \post Tornem l'element corresponent a la posició
  */       
    string consultar_pos_prestatgeria (int a, int b) const;       
	
	private:
	
    /** @brief Representació d'una prestatgeria
     
     Cada prestatgeria tindrà mida fxc i s'iniciarà 
     amb tot el vector plé de forats
  */         
    vector<string> prestatgeria;
    
    /** @brief Dimensions de la prestatgeria
     
     f és el nombre de files i c el nombre de columnes
  */    
    int f; int c;
    
    /** @brief Unitats en la prestatgeria
     
     contador enmagatzema, en tot moment, el nombre d'elements
     que hi ha a la prestatgeria. Inicialment és 0
  */    
	int contador;
};

#endif