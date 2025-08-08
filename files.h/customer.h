#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Customer
{
protected:
    vector<string> name;
    vector<string> contact;
    vector<string> ID;
    vector<int> roomNum;
    vector<string> feedBack;

public:
    void getdata_customer();
    void getdata_feedback();
    void display();
    void display_allcustomer();
};
