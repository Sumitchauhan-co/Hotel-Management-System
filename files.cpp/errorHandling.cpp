#include "errorHandling.h"
#include <iostream>
using namespace std;

void errorHandling::input(string& val)
{
    getline(cin>>ws,val);
}

void errorHandling::input(int& val)
{
    cin >> val;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"\nInvalid input, try again!\n";
        cin>>val;
    }
}

void errorHandling::input(char& val)
{
    cin >> val;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"\nInvalid input, try again!\n";
        cin>>val;
    }
}

void errorHandling::input(double& val)
{
    cin >> val;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"\nInvalid input, try again!\n";
        cin>>val;
    }
}

void errorHandling::input(bool& val)
{
    cin >> val;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"\nInvalid input, try again!\n";
        cin>>val;
    }
}
