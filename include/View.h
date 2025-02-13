#ifndef VIEW_H
#define VIEW_H

#include "Phalanx.h"
#include <iostream>
#include <string>

class Phalanx;

class View {
    public:
        View();
        void operator<<(Phalanx& phalanx);
};

extern View view;

#endif // VIEW_H