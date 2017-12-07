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
		Objet(string name, int case_x, int case_y, int p, int c, bool visib);
		string getNameobj();
		int getCase_x();
		int getCase_y();
		int getPortee();
		int getChance();
		bool getVisibilite();	
};


