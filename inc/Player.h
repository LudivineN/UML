#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <list>
#include "../inc/objet.h"


class Player
{
    public:
        Player(int, int);
        Player();
        Player(int, int, std::string);
        Player(int, int, std::string, bool, int, std::list<Objet>);
        virtual ~Player();
        void show();
        bool deplacer(bool, bool, bool, bool);
        int getCase_x();
        int getCase_y();
        bool isAlive();

    protected:

    private:
        std::string nom;
        int x;
        int y;
        bool vivant;
        int chance;
        std::list<Objet> objets;
};

#endif // PLAYER_H
