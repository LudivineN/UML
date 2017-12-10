#include "../inc/Player.h"

int nbPlayer = 0;

Player::Player() : x(-1), y(-1), vivant(true), chance(0)
{
    //ctor
    nbPlayer++;
    nom = "Player " + nbPlayer;
}

Player::Player(int x, int y) : x(x), y(y), vivant(true), chance(0)
{
    //ctor
    nbPlayer++;
    nom = "Player " + nbPlayer;
}

Player::Player(int x, int y, std::string nom) : x(x), y(y), vivant(true), chance(0), nom(nom)
{
    //ctor
    nbPlayer++;
}

Player::Player(int x, int y, std::string nom, bool vivant, int chance, list<Objet> objets) : x(x), y(y), vivant(vivant), chance(chance), nom(nom), objets(objets)
{
    //ctor
    nbPlayer++;
}

void Player::show()
{
    std::cout << "nom: " << nom << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "vivant: " << vivant << std::endl;
    std::cout << "chance: " << chance << std::endl;
}

bool Player::deplacer(bool z, bool q, bool s, bool d)
{
    bool noError = false;
    if (z) { if (!s) {if (y + 1 < 12) {noError = true; y += 1;}}}
    if (q) { if (!d) {if (x - 1 > 0) {noError = true; x -= 1;}}}
    if (s) { if (!z) {if (y - 1 > 0) {noError = true; y -= 1;}}}
    if (d) { if (!q) {if (x + 1 < 12) {noError = true; x += 1;}}}

    return noError;
}

int Player::getCase_x()
{
    return x;
}

int Player::getCase_y()
{
    return y;
}

bool Player::isAlive()
{
    return vivant;
}

Player::~Player()
{
    //dtor
}
