#include "order.h"
#include <map>
#include <iomanip>
#include "errorHandling.h"
using namespace std;

void Order::getdata_order()
{
    map<string, int> menu = 
    {
        {"Pizza", 250},
        {"Burger", 150},
        {"Fries", 80},
        {"Pasta", 200},
        {"Sandwich", 90},
        {"Noodles", 130},
        {"FriedRice", 120},
        {"Manchurian", 160},
        {"SpringRolls", 100},
        {"PaneerTikka", 180},
        {"Samosa", 30},
        {"Dosa", 70},
        {"Idli", 40},
        {"Vada", 35},
        {"Poha", 50},
        {"CholeBhature", 90},
        {"RajmaRice", 110},
        {"MIx Veg", 120},
        {"Salad", 60},
        {"Veg Biryani", 150},
        {"Kofta", 140},
        {"Paratha", 25},
        {"AlooTikki", 40},
        {"Soup", 70},
        {"Maggi", 50},
        {"Wrap", 100},
        {"Tandoori", 180},
        {"Cutlet", 60},
        {"Momos", 90},
        {"ColdCoffee", 80},
        {"Milkshake", 100},
        {"Tea", 20},
        {"Coffee", 30},
        {"Juice", 70},
        {"Soda", 30},
        {"Lassi", 60},
        {"Thali", 200},
        {"Kadhi Chawal", 100},
        {"Pudding", 80},
        {"IceCream", 60},
        {"GulabJamun", 40},
        {"Rasgulla", 40},
        {"Cake", 100},
        {"Donut", 60},
        {"Pastry", 70},
        {"Chocolate", 40},
        {"Brownie", 90},
        {"Custard", 70},
        {"Dal Tadka", 100},
        {"Paneer Bhurji", 150}
        };

    size_t i=0;
    for (auto &item : menu)
    {
        if(i>itemName.size()){
            break;  // avoid out of bounds access
        }

        itemName[i]=item.first;
        itemPrice[i]=item.second;
        i++;
    }
    for (size_t i = 0; i < itemName.size(); i++)
    {
        itemQty[i]=i % 5 + 1;
    }
    cout <<"\nOrder data initialised successfully\n";
}

void Order::display_order()
{
    cout << left << setw(15) << "Item"
            << setw(10) << "Price"
            << setw(10) << "Quantity" << endl;

    for (size_t i = 0; i < itemName.size(); i++)
    {
        cout << left << setw(15) << itemName[i]
            << setw(10) << itemPrice[i]
            << setw(10) << itemQty[i] << endl;
    }
}

void Order::display_allorder()
{
    cout << "\n\n---------- Hotel Food Menu ----------\n\n";

    cout << left << setw(15) << "Item"
            << setw(10) << "Price"
            << setw(10) << "Quantity" << endl;

    for (size_t i = 0; i < itemName.size(); i++)
    {
        if(sold[i]!= "Sold")
        {
            continue; // Skip items that are not sold
        }
        cout << left << setw(15) << itemName[i]
            << setw(10) << itemPrice[i]
            << setw(10) << itemQty[i] << endl;
    }
}
