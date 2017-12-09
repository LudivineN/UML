#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>


class Player
{
    public:
        Player(int, int);
        Player();
        Player(int, int, std::string);
        virtual ~Player();
        void show();
        bool deplacer(bool, bool, bool, bool);

    protected:

    private:
        std::string nom;
        int x;
        int y;
        bool vivant;
        int chance;
};

#endif // PLAYER_H
