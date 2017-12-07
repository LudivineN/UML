#include <iostream>
#include <string>
#include "../inc/objet.h"

using namespace std;

Objet :: Objet(string name, int case_x, int case_y, int p, int c, bool visib)
{
	nameobj = name;
	x = case_x;
	y = case_y;
	portee = p;
	chance = c;
	visibilite = visib;
}

string Objet :: getNameobj()
{
	return nameobj;
}

int Objet :: getCase_x()
{
	return x;
}

int Objet :: getCase_y()
{
	return y;
}

int Objet :: getPortee()
{
	return portee;
}

int Objet :: getChance()
{
	return chance;
}

bool Objet :: getVisibilite()
{
	return visibilite;
}

int main()
{

}

