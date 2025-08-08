#pragma once
#include "booking.h"
#include <string>

class BillManager : public Booking
{
protected:
    vector<int> amt;
    vector<int> billId;

public:
    void bill_room();
};
