#include <iostream>
#include <string>
#include "../inc/objet.h"

using namespace std;
Objet :: Objet (string  nameobj, int x, int y, int portee, int chance, bool visibilite)
{
	this -> nameobj = nameobj;
	this -> x = x;
	this -> y = y;
	this -> portee = portee; 
	this -> chance = chance;
	this -> visibilite = visibilite;   

}


Objet :: Objet(string name, int case_x, int case_y)
{
	nameobj = name;
	x = case_x;
	y = case_y;
	if (nameobj == "pelle")
	{
		portee = 0;
		chance = 0;
		visibilite = true;
	}
	if (nameobj == "mousquet")
	{
		portee = 1;
		chance = 50;
		visibilite = true;
	}
	if (nameobj == "tresor")
	{
		portee = -1;
		chance = 0;
		visibilite = false;
	}	
	if (nameobj == "armure")
	{
		portee = -1;
		chance = 90;
		visibilite = true;
	}

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


