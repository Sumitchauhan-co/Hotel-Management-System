#pragma once
#include "customer.h"

class Room : public Customer
{
protected:
    vector<string> Ac;
    vector<int> cost;
    vector<string> foodService;
    vector<string> laundryService;
    vector<string> specialService;
    vector<string> booked;
    vector<int> duration;

public:
    void getdata_room();
    void display_room();
    void display_allroom();
};
