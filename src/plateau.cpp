#include <iostream>
#include <vector>
#include "../inc/plateau.h"
#include <cstdlib>
#include <string>



using namespace std ;


Plateau :: Plateau ()
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

	nombreJ() ;
	initJ() ;

	this->nbObjet = 3 * nbJoueur + 1 ;
	for (int j = 0 ; j < nbJoueur; j++)
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
		plateau [ligne1][colonne1] = 'C' ;
		while (!CaseDispo(ligne2, colonne2))
		{
			ligne2 = rand() % 12 ;
			colonne2 = rand() % 12 ;
		}
		plateau [ligne2][colonne2] = 'C' ;
		while (!CaseDispo(ligne3, colonne3))
		{
			ligne3 = rand() % 12 ;
			colonne3 = rand() % 12 ;
		}
		plateau [ligne3][colonne3] = 'C' ;
		Objet tmp1 ("pelle", ligne1, colonne1) ;
		Objet tmp2 ("mousquet", ligne2, colonne2) ;
		Objet tmp3 ("armure", ligne3, colonne3) ;
		this->listeObjet.push_back(tmp1) ;
		this->listeObjet.push_back(tmp2) ;
		this->listeObjet.push_back(tmp3) ;
	}
	int ligne = rand() % 12 ;
	int colonne = rand() % 12 ;
	while (!CaseDispo(ligne, colonne))
	{
		ligne = rand() % 12 ;
		colonne = rand() % 12 ;
	}
	plateau[ligne][colonne] = 'C' ;
	Objet treasure ("tresor", ligne, colonne) ;
	this->listeObjet.push_back(treasure) ;

	choixDiff() ;

	for (int i = 0 ; i < nbPirate ; i ++)
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
			plateau[ligne][colonne] = 'F' ;
			this->listeFlibustier.push_back(tmp) ;
		}
		else if (choix == 1)
		{
			Boucanier tmp (ligne, colonne) ;
			plateau[ligne][colonne] = 'B' ;
			this->listeBoucanier.push_back(tmp) ;
		}
	}
}

Plateau :: Plateau(char ** nouveauPlateau, vector <Player> Joueur, vector <Objet> Objet, vector <Pirate> Flibustier, vector <Pirate> Boucanier)
{
	taille = 12 ;
	plateau = nouveauPlateau ;
	listeJoueur = Joueur ;
	nbJoueur = listeJoueur.size() ;
	listeObjet = Objet ;
	nbObjet = listeObjet.size() ;
	listeFlibustier = Flibustier ;
	listeBoucanier = Boucanier ;
	nbPirate = listeFlibustier.size() + listeBoucanier.size() ;
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

void Plateau :: nombreJ()
{
	cout << "Entrer nombre de joueurs :" << endl ;
	cin >> this->nbJoueur ;
	if ((nbJoueur > 35) || (nbJoueur ==0))
	{
		return nombreJ() ;
	}
}

void Plateau :: initJ()
{
	for (int i = 0 ; i < nbJoueur ; i++)
	{
		int ligne = rand() % 12 ;
		int colonne = rand() % 12 ;	
		while (!CaseDispo(ligne, colonne))
		{
			ligne = rand() % 12 ;
			colonne = rand() % 12 ;
		}
		string nom ;
		cout << "Nom joueur" << endl ;
		cin >> nom ;
		this->plateau[ligne][colonne] = 'J' ;
		Player tmp (ligne, colonne, nom) ;
		listeJoueur.push_back(tmp) ;
			
	}
}

void Plateau :: choixDiff()
{
	int difficulte ;
	cout << "1 : facile" << endl ;
	cout << "2 : moyen" << endl ;
	cout << "3 : difficile" << endl ;
	cout << "4 : expert" << endl ;
	cout << "5 : hardcore" << endl ;
	cin >> difficulte ;
	while ((difficulte < 1) || (difficulte >5))
	{
		choixDiff() ;
	}
	int disponibilite = countDispo() ;
	disponibilite = disponibilite / 5 ; 
	cout << disponibilite << endl ;
	this->nbPirate = difficulte * disponibilite ;
}

int Plateau :: countDispo()
{
	int count = 0 ;
	for (int i = 0 ; i < taille ; i++)
	{
		for (int j = 0 ; j < taille ; j++ )
		{
			if (CaseDispo(i,j))
			{
				count ++ ;
			}
		} 
	}
	return count ;
}

void Plateau :: Modif()
{
	nbJoueur = listeJoueur.size() ;
	nbObjet = listeObjet.size() ;
	nbPirate = listeFlibustier.size() + listeBoucanier.size() ;

	for (int a = 0 ; a < taille ; a++ )
	{
		for (int b = 0 ; b < taille ; b++)
		{
			plateau[a][b] = '-' ;
		}
	}
	for (int a = 0 ; a < taille ; a++ )
	{
		for (int b = 0 ; b < taille ; b++)
		{
			for (int c = 0 ; c < listeObjet.size() ; c++)
			{
				if ((a == listeObjet[c].getCase_x()) && (b == listeObjet[c].getCase_y()))
				{
					plateau[a][b] = 'C' ;
				}
			}
			for (int d = 0 ; d < listeBoucanier.size() ; d++)
			{
				if ((a == listeBoucanier[d].getCase_x()) && (b == listeBoucanier[d].getCase_y()))
				{
					if (plateau[a][b] == 'C')
					{
						plateau[a][b] = 'A' ;
					}
					else
					{
						plateau[a][b] = 'B';
					}
				}
			}
			for (int e = 0 ; e < listeFlibustier.size() ; e++)
			{
				if ((a == listeFlibustier[e].getCase_x()) && (b == listeFlibustier[e].getCase_y()))
				{
					if (plateau[a][b] == 'C')
					{
						plateau[a][b] = 'D' ;
					}
					else if (plateau[a][b] == 'A')
					{
						plateau[a][b] = 'E' ;
					}
					else if (plateau[a][b] == 'B')
					{
						plateau[a][b] = 'G' ;
					}
					else
					{
						plateau[a][b] = 'F';
					}
				}
			}
			for (int f = 0 ; f < listeJoueur.size() ; f++)
			{
				if ((a == listeJoueur[f].getCase_x()) && (b == listeJoueur[f].getCase_y()))
				{
					if (plateau[a][b] == 'C')
					{
						plateau[a][b] = 'H' ;
					}
					else if (plateau[a][b] == 'A')
					{
						plateau[a][b] = 'I' ;
					}
					else if (plateau[a][b] == 'B')
					{
						plateau[a][b] = 'K' ;
					}
					else if (plateau[a][b] == 'F')
					{
						plateau[a][b] = 'L' ;
					} 
					else if (plateau[a][b] == 'D')
					{
						plateau[a][b] = 'M' ;
					}
					else if (plateau[a][b] == 'E')
					{
						plateau[a][b] = 'N' ;
					}
					else if (plateau[a][b] == 'G')
					{
						plateau[a][b] = 'O' ;
					}
					else
					{
						plateau[a][b] = 'J' ;
					}
				}
			}
		}
	}
}

