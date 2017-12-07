#include <iostream>
#include <vector>
#include "objet.h"
#include "Flibustier.h"
#include "Boucanier.h"


using namespace std ;

class Plateau
{
	private :
		int taille ;
		char ** plateau ;

		

	public :
		int nbJoueur ;
		/*vector <Player> listeJoueur ;*/
		int nbObjet ;
		vector <Objet> listeObjet ;
		int nbPirate ;
		vector <Pirate> listePirate ;


		Plateau (int nbJ, /*vector <Player> listeJ,*/ int nbP) ;
		int getTaille () ;
		bool CaseDispo (int row, int col) ;
} ;


