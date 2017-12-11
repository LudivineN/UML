#ifndef PIRATE_H
#define PIRATE_H

#include <iostream>
#include <string>
#include <stdlib.h>


class Pirate
{
    public:
        Pirate();
        Pirate(int, int);
        virtual ~Pirate();
        void show();
        bool deplacer();
        bool deplacer_bis(bool, bool, bool, bool);
        std::string get_nom();
        int getCase_x();
        int getCase_y();
		int getPortee();

    protected:
        int portee;
        int nb_dep;
        int x, y;
        std::string nom;

    private:

};

#endif // PIRATE_H
