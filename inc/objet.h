#include <iostream>
#include <string>

using namespace std;

class Objet{

	private:
		string  nameobj;
		int x;
		int y;
		int portee;
		int chance;
		bool visibilite;
	public:
		
		//! Constructeur qu'avec certains argument
		/*!
			\param name Le nom de l'objet
			\param case_x La ligne où se trouve l'objet
			\param case_y La colonne où se trouve l'objet
		*/
		Objet(string name, int case_x, int case_y);
		//! Getter pour le nom.
		string getNameobj();
		//! Getter pour la ligne.
		int getCase_x();
		//! Getter pour la colonne.
		int getCase_y();
		//! Getter pour la portée.
		int getPortee();
		//! Getter pour le pourcentage de chance.
		int getChance();
		//! Getter pour pour la visibilité
		bool getVisibilite();	
		//! Constructeur avec tous les arguments
		/*!
			\param name Le nom de l'objet
			\param case_x La ligne où se trouve l'objet
			\param case_y La colonne où se trouve l'objet
			\param portee La portée qu'a un objet
			\param chance La chance de rester en vie et de tuer l'adversaire
			\param visibilite La visibilité des objets
		*/
		Objet (string  nameobj, int x, int y, int portee, int chance, bool visibilite) ;

};


