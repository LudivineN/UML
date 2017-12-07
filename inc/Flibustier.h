#ifndef FLIBUSTIER_H
#define FLIBUSTIER_H

#include <iostream>
#include <string>
#include "../inc/Pirate.h"


class Flibustier : public Pirate
{
    public:
        Flibustier();
        Flibustier(int, int);
        virtual ~Flibustier();

    protected:

    private:
};

#endif // FLIBUSTIER_H
