#ifndef PIRATE_H
#define PIRATE_H

#include <iostream>
#include <string>


class Pirate
{
    public:
        Pirate();
        Pirate(int, int);
        virtual ~Pirate();
        void show();
        bool deplacer(bool, bool, bool, bool);
        std::string get_nom();
        int getCase_x();
        int getCase_y();

    protected:
        int portee;
        int nb_dep;
        int x, y;
        std::string nom;

    private:

};

#endif // PIRATE_H
