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

		//! Constructeur sans argument
		Plateau () ;
		//! Constructeur avec arguments
		/*!
			\param nouveauPlateau Un tableau représentant le plateau
			\param Joueur Le vecteur qui comporte tous les joueurs de la partie
			\param Objet Le vecteur qui comporte tous les objets de la partie
			\param Flibustier Le vecteur qui comporte tous les flibustiers de la partie
			\param Boucanier Le vacteur qui comporte tous les boucaniers de la partie
		*/
		Plateau(char ** nouveauPlateau, vector <Player> Joueur, vector <Objet> Objet, vector <Pirate> Flibustier, vector <Pirate> Boucanier ) ;
		//! Getter taille du plateau
		int getTaille () ;
		//! Case disponible
		/*!
			\param row La ligne de la case voulu
			\col La colonne de la case voulu
			\return bool true = la case est dispo, false = elle n'est pas dispo
			On verifie si la case rentré en paramètre est disponible ou pas.
		*/
		bool CaseDispo (int row, int col) ;
		//! Nombre de joueur dans la partie
		/*!
			On demande à l'utilisateur combien il veut de joueur dans la partie 
			On vérifie que ce nombre soit compris entre 1 et 35.
			Tant que le nnombre est faut on rappelle la fonction.
			/sa nombreJ()
		*/
		void nombreJ() ;
		//! Initialisation des joueurs
		/*!
			On initialise les joueurs dans le vecteur joueur.
			/sa CaseDispo (int row, int col)
		*/
		void initJ() ;
		//! Choix de la difficulté du jeu
		/*!
			On demande au joueur d'entrer la difficulté qu'il souhaite 
			puis on créé un certain nombre de pirates en fonction de ce nombre et du nombre de case diponible.
			\sa countDispo().
		*/
		void choixDiff() ;
		//! Comptage du nombre de case disponible sur le plateau
		/*!
			\return count Le nombre de case disponible
		*/
		int countDispo() ;
		//! Modification du plateau
		/*!
			On met à jour le plateau.
			Cela nous permet de mettre à jour le plateau après chaque modification des vecteurs.
			Pour pouvoir afficher le bon plateau par la suite.
		*/
		void Modif() ;
} ;


