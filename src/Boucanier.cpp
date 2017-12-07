#include "../inc/Boucanier.h"

Boucanier::Boucanier() : Pirate()
{
    //ctor
    nb_dep++;
    nom = "Boucanier";
}

Boucanier::Boucanier(int x, int y) : Pirate(x, y)
{
    //ctor
    nb_dep++;
    nom = "Boucanier";
}

Boucanier::~Boucanier()
{
    //dtor
}
