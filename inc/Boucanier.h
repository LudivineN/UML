#ifndef BOUCANIER_H
#define BOUCANIER_H

#include <iostream>
#include <string>
#include "../inc/Pirate.h"


class Boucanier : public Pirate
{
    public:
        Boucanier();
        Boucanier(int, int);
        virtual ~Boucanier();

    protected:

    private:
};

#endif // BOUCANIER_H
