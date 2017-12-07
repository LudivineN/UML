#include "../inc/Flibustier.h"

Flibustier::Flibustier() : Pirate()
{
    //ctor
    portee++;
    nom = "Flibustier";
}

Flibustier::Flibustier(int x, int y) : Pirate(x, y)
{
    //ctor
    portee++;
    nom = "Flibustier";
}

Flibustier::~Flibustier()
{
    //dtor
}
