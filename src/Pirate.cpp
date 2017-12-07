#include "../inc/Pirate.h"

Pirate::Pirate() : x(-1), y(-1), portee(0), nb_dep(1)
{
    //ctor
    nom = "Pirate";
}

Pirate::Pirate(int x, int y) : x(x), y(y), portee(0), nb_dep(1)
{
    //ctor
    nom = "Pirate";
}

Pirate::~Pirate()
{
    //dtor
}

std::string Pirate::get_nom()
{
    return nom;
}

void Pirate::show()
{
    std::cout << "nom: " << nom << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "portee: " << portee << std::endl;
    std::cout << "nombre de deplacements: " << nb_dep << std::endl;
}

bool Pirate::deplacer(bool z, bool q, bool s, bool d)
{
    bool noError = false;
    if (z) { if (!s) {noError = true; y += 1;}}
    if (q) { if (!d) {noError = true; x -= 1;}}
    if (s) { if (!z) {noError = true; y -= 1;}}
    if (d) { if (!q) {noError = true; x += 1;}}

    return noError;
}
