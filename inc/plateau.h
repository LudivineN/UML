#include <iostream>
#include <vector>
//#include "objet.h"
#include "Flibustier.h"
#include "Boucanier.h"
#include "Player.h"


using namespace std ;

class Plateau
{
	private :
		int taille ;
			

	public :
		char ** plateau ;
		int nbJoueur ;
		vector <Player> listeJoueur ;
		int nbObjet ;
		vector <Objet> listeObjet ;
		int nbPirate ;
		vector <Pirate> listeFlibustier ;
		vector <Pirate> listeBoucanier ;


		Plateau () ;
		Plateau(char ** nouveauPlateau, vector <Player> Joueur, vector <Objet> Objet, vector <Pirate> Flibustier, vector <Pirate> Boucanier ) ;
		int getTaille () ;
		bool CaseDispo (int row, int col) ;
		void nombreJ() ;
		void initJ() ;
		void choixDiff() ;
		int countDispo() ;
		void Modif() ;
} ;


