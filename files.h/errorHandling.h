#pragma once
#include <iostream>
#include <limits>
using namespace std;

class errorHandling
{
public:
    static void input(string& val);
    static void input(int& val);
    static void input(size_t& val);
    static void input(char& val);
    static void input(double& val);
    static void input(bool& val);
};
