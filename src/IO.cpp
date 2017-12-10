#include <iostream>
#include <string>
//#include "../inc/IO.h"
#include <cstdlib>
#include <vector>
#include "../inc/plateau.h"
#include <fstream>


using namespace std ;


void affiche(Plateau terrain)
{
	cout << " __ __ __ __ __ __ __ __ __ __ __ __" << endl ;
	for (int i = 0; i <terrain.getTaille() ; i++)
	{
		for (int j = 0 ; j < terrain.getTaille() ; j++)
		{
			if (terrain.plateau[i][j] == '-')
			{
				cout << "|  " ;
			}
			else if (terrain.plateau[i][j] == 'A')
			{
				cout << "| B" ;
			}
			else if (terrain.plateau[i][j] == 'B')
			{
				cout << "| B" ;
			}
			else if (terrain.plateau[i][j] == 'C')
			{
				for (int k = 0 ; k < terrain.listeObjet.size() ; k++)
				{
					if ((i == terrain.listeObjet[k].getCase_x()) && (j == terrain.listeObjet[k].getCase_y()))
					{
						if (terrain.listeObjet[k].getVisibilite())
						{
							cout << "| C" ;
						}
						else
						{
							cout << "|  " ;
						}
					}
				}
				
			}
			else if (terrain.plateau[i][j] == 'D')
			{
				cout << "| F" ;
			}
			else if (terrain.plateau[i][j] == 'E')
			{
				cout << "| F" ;
			}
			else if (terrain.plateau[i][j] == 'F')
			{
				cout << "| F" ;
			}
			else if (terrain.plateau[i][j] == 'G')
			{
				cout << "| F" ;
			}
			else if (terrain.plateau[i][j] == 'H')
			{
				for (int k = 0 ; k < terrain.listeObjet.size() ; k++)
				{
					if ((i == terrain.listeObjet[k].getCase_x()) && (j == terrain.listeObjet[k].getCase_y()))
					{
						if (terrain.listeObjet[k].getVisibilite())
						{
							cout << "|JC" ;
						}
						else
						{
							cout << "|J " ;
						}
					}
				}
			}
			else if (terrain.plateau[i][j] == 'I')
			{
				cout << "|JB" ;
			}
			else if (terrain.plateau[i][j] == 'J')
			{
				cout << "|J " ;
			}
			else if (terrain.plateau[i][j] == 'K')
			{
				cout << "|JB" ;
			}
			else if (terrain.plateau[i][j] == 'L')
			{
				cout << "|JF" ;
			}
			else if (terrain.plateau[i][j] == 'M')
			{
				cout << "|JF" ;
			}
			else if (terrain.plateau[i][j] == 'N')
			{
				cout << "|JF" ;
			}
			else if (terrain.plateau[i][j] == 'O')
			{
				cout << "|JF" ;
			}
		}
		cout << "|" << endl;
		cout << "|__|__|__|__|__|__|__|__|__|__|__|__|" << endl ;
	}
}

void Mecanisme (Plateau terrain)
{
}

bool conditionFin(Plateau terrain)
{
	if (terrain.listeJoueur.size() == 0)
	{
		return true ;
	}
	else if (terrain.listeObjet[terrain.listeObjet.size()-1].getNameobj() == "tresor")
	{
		return true ;
	}
	else 
	{
		return false ;
	}
}

void NewGame()
{
	Plateau jeu ;
	affiche(jeu) ;
	Mecanisme(jeu) ;
}

void SavedGame(char number)
{
	char ** grille ;
	vector <Player> Joueur ;
	vector <Objet> lObjet ;
	vector <Pirate> Fli ;
	vector <Pirate> Bouc ;
	string Map = string("../bin/save/plateau/plateau") + number + ".txt" ;
	string saveJoueur = string("../bin/save/joueur/joueur") + number + ".txt" ;
	string saveObjet = string("../bin/save/objet/objet") + number + ".txt" ;
	string saveF = string("../bin/save/flibustier/flibustier") + number + ".txt" ;
	string saveB = string("../bin/save/boucanier/boucanier") + number + ".txt" ;

	// Récupératio carte
	ifstream saveMap(Map, ios::in) ;
	if (saveMap)
	{
		grille = new char * [12] ;
		for (int i = 0 ; i < 12 ; i++)
		{
			string ligne ;
			getline(saveMap, ligne);
			grille[i] = new char [12] ;
			for (int j = 0 ; j < 12 ; j ++)
			{
				grille[i][j] = ligne[j] ;
			}
		}
		saveMap.close() ;
	}
	else
	{
		cout << "Erreur d'ouverture de la sauvegarde" << endl ;
		return ;
	}

	// Récupération Joueur
	ifstream savePlayer(saveJoueur, ios ::in) ;
	if (savePlayer)
	{
		char c ;
		int count = 0 ;
		string nom ;
		string CaseX ;
		string CaseY ;
		bool Vie ;
		string Chance ;
		vector <Objet> Obj ;
		
		while (!savePlayer.eof())
		{
			savePlayer.get(c) ;
			if ( c  == '\n' )
			{
				count = 0 ;
				int x = atoi(CaseX.c_str()) ;
				int y = atoi(CaseY.c_str()) ;
				int ChanceJ = atoi(Chance.c_str()) ;
				Player tmpJ(x, y, nom, Vie, ChanceJ, Obj) ;
				Joueur.push_back(tmpJ) ;

				// Réinitialisation variables
				nom = "" ;
				CaseX = "" ;
				CaseY = "" ;
				Chance = "" ;
				for (int i = 0 ; i < Obj.size() ; i++)
				{
					Obj.pop_back() ;
				}
			}
			else if ( c  == '/' )
			{
				count ++ ;
			}
			else if (count == 0)
			{
				nom = nom + c ;
			}
			else if (count == 1)
			{
				CaseX = CaseX + c ;
			}		
			else if (count == 2)
			{
				CaseY = CaseY + c ;
			}
			else if (count == 3)
			{
				if (c == '1')
				{
					Vie = true ;
				}
				if (c == '0')
				{
					Vie = false ;
				}
			}
			else if (count == 4)
			{
				Chance = Chance + c ;
			}
			else if (count == 5)
			{
				int countO = 0 ;
				string nomO ;
				string CaseOX ;
				string CaseOY ;
				string Porte ;
				string ChanceO ;
				bool Visible ;
				if (countO == 6)
				{
					countO == 0 ;
					int X = atoi(CaseOX.c_str()) ;
					int Y = atoi(CaseOY.c_str()) ;
					int P = atoi(Porte.c_str()) ;
					int C = atoi(ChanceO.c_str()) ;
					Objet tmp(nomO, X, Y, P, C, Visible) ;
					Obj.push_back(tmp) ;

					// Réinitialisation variables
					nomO = "" ;
					CaseOX = "" ;
					CaseOY = "" ;
					Porte = "" ;
					ChanceO = "" ;
				}
				else if (c == '|')
				{
					countO ++ ;
				}
				else if (countO == 0)
				{
					nomO = nomO + c ;
				}
				else if (countO == 1)
				{
					CaseOX = CaseOX + c ;
				}		
				else if (countO == 2)
				{
					CaseOY = CaseOY + c ;
				}
				else if (countO == 3)
				{
					Porte = Porte + c ;
				}
				else if (countO == 4)
				{
					ChanceO = ChanceO + c ;
				}
				else if (countO == 5)
				{
					if (c == '1')
					{
						Visible = true ;
					}
					if (c == '0')
					{
						Visible = false ;
					}
				}
			}
		}
	}
	else
	{
		cout << "Erreur d'ouverture de la sauvegarde" << endl ;
		return ;
	}
	savePlayer.close() ;

	// Récupération Objet sur Carte
	ifstream saveObject(saveObjet, ios::in) ;
	if(saveObject)
	{
		char carac ;
		int countOC = 0 ;
		string nomOC ;
		string CaseOCX ;
		string CaseOCY ;
		string PorteC ;
		string ChanceOC ;
		bool VisibleC ;
		while (!saveObject.eof())
		{
			saveObject.get(carac) ;
			if (carac == '\n')
			{
				countOC == 0 ;
				int XC = atoi(CaseOCX.c_str()) ;
				int YC = atoi(CaseOCY.c_str()) ;
				int PC = atoi(PorteC.c_str()) ;
				int CC = atoi(ChanceOC.c_str()) ;
				Objet tmpC(nomOC, XC, YC, PC, CC, VisibleC) ;
				lObjet.push_back(tmpC) ;

				// Réinitialisation chaines
				nomOC = "" ;
				CaseOCX = "" ;
				CaseOCY = "" ;
				PorteC = "" ;
				ChanceOC = "" ;
			}
			else if (carac == '|')
			{
				countOC ++ ;
			}
			else if (countOC == 0)
			{
				nomOC = nomOC + carac ;
			}
			else if (countOC == 1)
			{
				CaseOCX = CaseOCX + carac ;
			}		
			else if (countOC == 2)
			{
				CaseOCY = CaseOCY + carac ;
			}
			else if (countOC == 3)
			{
				PorteC = PorteC + carac ;
			}
			else if (countOC == 4)
			{
				ChanceOC = ChanceOC + carac ;
			}
			else if (countOC == 5)
			{
				if (carac == '1')
				{
					VisibleC = true ;
				}
				if (carac == '0')
				{
					VisibleC = false ;
				}
			}
		}
	}
	else
	{
		cout << "Erreur d'ouverture de la sauvegarde" << endl ;
		return ;
	}
	saveObject.close() ;

	// Récupération flibustier
	ifstream saveFlibustier(saveF, ios::in) ;
	if (saveFlibustier)
	{
		char car ;
		string coord1 ;
		string coord2 ;
		int countF = 0 ;
		while (!saveFlibustier.eof())
		{
			saveFlibustier.get(car) ;
			if (car == '\n')
			{
				countF = 0 ;
				int coordx = atoi(coord1.c_str()) ;
				int coordy = atoi(coord2.c_str()) ;
				Flibustier tmp(coordx, coordy) ;
				Fli.push_back(tmp) ;

				// Réinitialisation variables
				coord1 = "" ;
				coord2 = "" ;
			}
			else if (car == '/')
			{
				countF++ ;
			}
			else if (countF == 0)
			{
				coord1 = coord1 + car ;
			}
			else if (countF == 1)
			{
				coord2 = coord2 +car ;
			}
		}
	}
	else
	{
		cout << "Erreur d'ouverture de la sauvegarde" << endl ;
		return ;
	}
	saveFlibustier.close() ;

	// Récupération Boucanier
	ifstream saveBoucanier(saveB, ios::in) ;
	if (saveBoucanier)
	{
		char cara ;
		string coord1b ;
		string coord2b ;
		int countB = 0 ;
		while (!saveBoucanier.eof())
		{
			saveBoucanier.get(cara) ;
			if (cara == '\n')
			{
				countB = 0 ;
				int coordxb = atoi(coord1b.c_str()) ;
				int coordyb = atoi(coord2b.c_str()) ;
				Boucanier tmp(coordxb, coordyb) ;
				Bouc.push_back(tmp) ;

				// Réinitialisation variables
				coord1b = "" ;
				coord2b = "" ;
			}
			else if (cara == '/')
			{
				countB++ ;
			}
			else if (countB == 0)
			{
				coord1b = coord1b + cara ;
			}
			else if (countB == 1)
			{
				coord2b = coord2b + cara ;
			}
		}
	}
	else
	{
		cout << "Erreur d'ouverture de la sauvegarde" << endl ;
		return ;
	}
	saveBoucanier.close() ;

	// Création du jeu
	Plateau jeu(grille, Joueur, lObjet, Fli, Bouc) ;	
	Mecanisme(jeu) ;
}


void save (Plateau current)
{
	int position = 0 ;
	cout << "choisir le numéro de la sauvegarde" << endl ;
	cin >> position ;
	while ((position < 0) || (position > 9))
	{
		cout << "Numéro invalide" << endl << "Entre 1 et 9 compris)" <<endl ;
		cin >> position ;
	}
	string fichierplateau = string("../bin/save/plateau/plateau") + to_string(position) + ".txt" ;
	string fichierJoueur = string("../bin/save/joueur/joueur") + to_string(position) + ".txt" ;
	string fichierObjet = string("../bin/save/objet/objet") + to_string(position) + ".txt" ;
	string fichierFlibustier = string("../bin/save/flibustier/flibustier") + to_string(position) + ".txt" ;
	string fichierBoucanier = string("../bin/save/boucanier/boucanier") + to_string(position) + ".txt" ;

	// Ecriture plateau
	ofstream saveplateau(fichierplateau, ios ::trunc) ;
	if (saveplateau)
	{
		for (int i = 0 ; i < current.getTaille(); i++)
		{
			for (int j = 0 ; j < current.getTaille(); j++)
			{
				saveplateau << current.plateau[i][j] ;
			}
			saveplateau << '\n' ;
		}
	}
	else
	{
		cout << "Erreur d'ouverture de la sauvegarde" << endl ;
		return ;
	}
	saveplateau.close() ;

	// Ecriture joueurs
	ofstream saveJoueur(fichierJoueur, ios ::trunc) ;
	if (saveJoueur)
	{
		for (int a = 0 ; a < current.listeJoueur.size() ; a++)
		{
			string nomJ = current.listeJoueur[a].getNom() ;
			string CaseXJ = to_string(current.listeJoueur[a].getCase_x()) ;
			string CaseYJ = to_string(current.listeJoueur[a].getCase_y()) ;
			string vivantJ ;
			if (current.listeJoueur[a].isAlive() == true)
			{
				vivantJ = "1" ;
			}
			else if (current.listeJoueur[a].isAlive() == false)
			{
				vivantJ == "0" ;
			}
			string ChanceJ = to_string(current.listeJoueur[a].getChance()) ;
			string ObjetJ ;
			for (int k = 0 ; k < current.listeJoueur[a].getObjets().size() ; k++)
			{
				string nomOb = current.listeJoueur[a].getObjets()[k].getNameobj() ;
				string caseXOb = to_string(current.listeJoueur[a].getObjets()[k].getCase_x()) ;
				string caseYOb = to_string(current.listeJoueur[a].getObjets()[k].getCase_y()) ;
				string porteOb = to_string(current.listeJoueur[a].getObjets()[k].getPortee()) ;
				string chanceOb = to_string(current.listeJoueur[a].getObjets()[k].getChance()) ; 				
				string visibleOb ;
				string currentObj ;
				if (current.listeJoueur[a].getObjets()[k].getVisibilite() == true)
				{
					visibleOb = "1" ;
				}
				else if (current.listeJoueur[a].getObjets()[k].getVisibilite() == false)
				{
					visibleOb == "0" ;
				}
				if (current.listeJoueur[a].getObjets().size()-1 == k)
				{
					currentObj = nomOb + "|" + caseXOb + "|" + caseYOb + "|" + porteOb + "|" + chanceOb + "|" + visibleOb ;
				}
				else
				{
					currentObj = nomOb + "|" + caseXOb + "|" + caseYOb + "|" + porteOb + "|" + chanceOb + "|" + visibleOb + "|" ;
				}
				ObjetJ = ObjetJ + currentObj ;
			} 
			saveJoueur << nomJ << "/" << CaseXJ << "/" << CaseYJ << "/" << vivantJ << "/" << ChanceJ << "/" << ObjetJ << '\n';
		}
	}
	else
	{
		cout << "Erreur d'ouverture de la sauvegarde" << endl ;
		return ;
	}
	saveJoueur.close() ; 

	// Ecriture Objet
	ofstream saveObjet(fichierObjet, ios ::trunc) ;
	if (saveObjet)
	{
		for (int b = 0 ; b < current.listeObjet.size() ; b++)
		{
			string nomO = current.listeObjet[b].getNameobj() ;
			string CaseXO = to_string(current.listeObjet[b].getCase_x()) ;
			string CaseYO = to_string(current.listeObjet[b].getCase_y()) ;
			string PorteeO = to_string(current.listeObjet[b].getPortee()) ;
			string visibleO ;
			if (current.listeObjet[b].getVisibilite() == true)
			{
				visibleO = "1" ;
			}
			else if (current.listeObjet[b].getVisibilite() == false)
			{
				visibleO == "0" ;
			}
			string ChanceO = to_string(current.listeObjet[b].getChance()) ;
			saveObjet << nomO << "/" << CaseXO << "/" << CaseYO << "/" << PorteeO << "/" << visibleO << "/" << ChanceO << '\n';
		}
	}
	else
	{
		cout << "Erreur d'ouverture de la sauvegarde" << endl ;
		return ;
	}
	saveObjet.close() ; 

	// Ecriture Flibustier
	ofstream saveFlibustier(fichierFlibustier, ios ::trunc) ;
	if (saveFlibustier)
	{
		for (int c = 0 ; c < current.listeFlibustier.size() ; c++)
		{
			string CaseXF = to_string(current.listeFlibustier[c].getCase_x()) ;
			string CaseYF = to_string(current.listeFlibustier[c].getCase_y()) ;
			saveFlibustier << CaseXF << "/" << CaseYF << '\n';
		}
	}
	else
	{
		cout << "Erreur d'ouverture de la sauvegarde" << endl ;
		return ;
	}
	saveFlibustier.close() ;

	// Ecriture Boucanier
	ofstream saveBoucanier(fichierBoucanier, ios ::trunc) ;
	if (saveBoucanier)
	{
		for (int d = 0 ; d < current.listeBoucanier.size() ; d++)
		{
			string CaseXD = to_string(current.listeBoucanier[d].getCase_x()) ;
			string CaseYD = to_string(current.listeBoucanier[d].getCase_y()) ;
			saveBoucanier << CaseXD << "/" << CaseYD << '\n';
		}
	}
	else
	{
		cout << "Erreur d'ouverture de la sauvegarde" << endl ;
		return ;
	}
	saveBoucanier.close() ; 

}

bool choixValide(int choix2)
{
	string saveExiste = string("../bin/save/plateau/plateau/") + to_string(choix2) + ".txt" ;
	ifstream testsave(saveExiste, ios :: in) ;
	if (!testsave)
	{
		int choix3 ;
		cout << "Sauvegarde inexistante !" << endl << "Voulez-vous choisir une autre sauvegarde" << endl << "1 : OUI" << endl << "2 : NON" << endl ;
		cin >> choix3 ;
		while ((choix3 < 1) || (choix3 > 2))
		{
			int choix4 ;
			cout << "Nous n'avons pas compris votre choix" << endl << "Sauvegarde inexistante !" << endl << "Voulez-vous changer de sauvegarde" << endl << "1 : OUI" << endl << "2 : NON" << endl ;
			cin >> choix4 ;
			choix3 = choix4 ;
		}
		if (choix3 == 1)
		{
			cout << "choisir le numéro de la sauvegarde" << endl ;
			cin >> choix2 ;
			choixValide(choix2) ;
		}
		else if (choix3 == 2)
		{
cerr << "test" << endl ;
			return false;
cerr << "test2" << endl ;
		}
	}
	testsave.close() ;
	return true ;
}

void chooseGame(int & choix)
{
	cout << "1 : Nouvelle Partie" << endl << "2 : Partie enregistré" << endl ;
	cin >> choix ;
	while ((choix < 1) || (choix > 2))
	{
		cout << "Nous n'avons pas compris votre choix" << endl << "1 : Nouvelle Partie" << endl << "2 : Partie enregistré" << endl ;
		cin >> choix ;
	}
	if (choix == 1)
	{
		NewGame() ;
	}
	else if (choix == 2)
	{
		int choix2 = 0 ;
		cout << "choisir le numéro de la sauvegarde" << endl ;
		cin >> choix2 ;
		while ((choix2 < 0) || (choix2 > 9))
		{
			cout << "Numéro invalide" << endl << "Entre 1 et 9 compris)" <<endl ;
			cin >> choix2 ;
		}
		while (choixValide(choix2))
		{
cerr << "while" << endl ;
			return chooseGame(choix) ;
cerr << "while2" << endl ;
		}
		SavedGame(choix2) ;
		return ;
	}
}

int main()
{
	cout << "Bienvenue dans" << endl << "L'île au trésor" << endl ;
	int choix = 0 ;
	chooseGame(choix) ;
	
		
}
