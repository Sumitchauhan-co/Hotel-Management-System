#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Order
{
protected:
    vector<int> itemPrice;
    vector<string> itemName;
    vector<int> itemQty;
    vector<int> orderedQty;
    vector<string> sold;

public:
    void getdata_order();
    void display_order();
    void display_allorder();
};
