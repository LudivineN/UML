#include <iostream>
#include <vector>
#include "../inc/plateau.h"
#include <cstdlib>
#include <string>



using namespace std ;


Plateau :: Plateau (int nbJ, /*vector <Player> listeJ,*/ int nbP)
{
	taille = 12 ;
	plateau = new char * [taille] ;
	for (int i = 0 ; i < taille ; i++)
	{
		plateau[i] = new char [taille] ;
		for (int j = 0 ; j < taille ; j ++)
		{
			plateau[i][j] = '-' ;
		}
	}

	nbJoueur = nbJ ;
	/*listeJoueur = listeJ ;*/

	nbObjet = 3 * nbJ + 1 ;
	for (int j = 0 ; j < nbJ; j++)
	{
		int ligne1 = rand() % 12 ;
		int colonne1 = rand() % 12 ;
		int ligne2 = rand() % 12 ;
		int colonne2 = rand() % 12 ;
		int ligne3 = rand() % 12 ;
		int colonne3 = rand() % 12 ;

		while (!CaseDispo(ligne1, colonne1))
		{
			ligne1 = rand() % 12 ;
			colonne1 = rand() % 12 ;
		}
		plateau [ligne1][colonne1] = 'c' ;
		while (!CaseDispo(ligne2, colonne2))
		{
			ligne2 = rand() % 12 ;
			colonne2 = rand() % 12 ;
		}
		plateau [ligne2][colonne2] = 'c' ;
		while (!CaseDispo(ligne3, colonne3))
		{
			ligne3 = rand() % 12 ;
			colonne3 = rand() % 12 ;
		}
		plateau [ligne3][colonne3] = 'c' ;
		Objet tmp1("pelle", ligne1, colonne1) ;
		Objet tmp2("mousquet", ligne2, colonne2) ;
		Objet tmp3("armure", ligne3, colonne3) ;
		listeObjet.push_back(tmp1) ;
		listeObjet.push_back(tmp2) ;
		listeObjet.push_back(tmp3) ;
	}
	int ligne = rand() % 12 ;
	int colonne = rand() % 12 ;
	while (!CaseDispo(ligne, colonne))
	{
		ligne = rand() % 12 ;
		colonne = rand() % 12 ;
	}
	plateau[ligne][colonne] = 'c' ;
	Objet treasure("tresor", ligne, colonne) ;
	listeObjet.push_back(treasure) ;

	nbPirate = nbP ;
	for (int i = 0 ; i < nbP ; i ++)
	{
		int choix = rand() % 2 ;
		int ligne = rand() % 12 ;
		int colonne = rand() % 12 ;
		while (!CaseDispo(ligne, colonne))
		{
			ligne = rand() % 12 ;
			colonne = rand() % 12 ;
		}
		if (choix == 0)
		{
			Flibustier tmp (ligne, colonne) ;
			plateau[ligne][colonne] = 'f' ;
			listePirate.push_back(tmp) ;
		}
		else if (choix == 1)
		{
			Boucanier tmp (ligne, colonne) ;
			plateau[ligne][colonne] = 'b' ;
			listePirate.push_back(tmp) ;
		}
	}
}


int Plateau :: getTaille()
{
	return taille ;
}

bool Plateau :: CaseDispo (int row, int col)
{
	if (plateau[row][col] == '-')
	{
		return true ;
	}
	else
	{
		return false ;
	}
}

int main()
{
}
