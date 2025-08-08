#pragma once
#include "storable.h"

class Application
{
    Storable&s;
public:
    Application(Storable& shared) : s(shared){}
    void run(Storable& s);
};
