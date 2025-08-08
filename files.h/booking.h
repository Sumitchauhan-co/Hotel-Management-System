#pragma once
#include "room.h"
#include "order.h"

class Booking : public Room, public Order
{
public:
    void entry();
    void display_book();
    void preBook();
    void food();
};
