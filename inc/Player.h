#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "../inc/objet.h"


class Player
{
    public:
        Player(int, int);
        Player();
        Player(int, int, std::string);
        Player(int, int, std::string, bool, int, std::vector<Objet>);
        virtual ~Player();
        void show();
        bool deplacer(bool, bool, bool, bool);
		std::string getNom();
        int getCase_x();
        int getCase_y();
        bool isAlive();
        int getChance();
        std::vector<Objet> getObjets();
        bool combat();
        bool AddObjet(Objet);
        bool checkObjet(std::string);

    protected:

    private:
        std::string nom;
        int x;
        int y;
        bool vivant;
        int chance;
        std::vector<Objet> objets;
};

#endif // PLAYER_H
