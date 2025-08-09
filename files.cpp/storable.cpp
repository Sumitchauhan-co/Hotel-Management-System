#include "storable.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include "errorHandling.h"
using namespace std;

Storable::Storable()
{
    name.resize(50);
    contact.resize(50);
    ID.resize(50);
    roomNum.resize(50);
    Ac.resize(50);
    foodService.resize(50);
    laundryService.resize(50);
    cost.resize(50);
    booked.resize(50);
    duration.resize(50);
    specialService.resize(50);
    itemName.resize(50);
    itemPrice.resize(50);
    itemQty.resize(50);
    orderedQty.resize(50);
    sold.resize(50);
    billId.resize(50);
    amt.resize(50);
}

bool Storable::fileNotEmpty(const string &filePath)
{
    ifstream in(filePath);

    return in && in.peek() != ifstream::traits_type::eof();
}

void Storable::toString_customer()
{
    ofstream out("files.txt/customer.txt", ios::trunc);

    for (size_t i = 0; i < name.size(); i++)
    {
        if (!name[i].empty())
        {
            out << "\"" << name[i] << "\","
                << contact[i] << ","
                << ID[i] << ","
                << roomNum[i] << "\n";
        }
    }
    out.close();
}

void Storable::toString_room()
{
    ofstream out("files.txt/room.txt", ios::trunc);

    for (size_t i = 0; i < Ac.size(); i++)
    {
        if (booked[i] == "Booked")
        {
            out << to_string(roomNum[i]) << ","
                << "\"" << Ac[i] << "\","
                << "\"" << foodService[i] << "\","
                << "\"" << laundryService[i] << "\","
                << to_string(cost[i]) << ","
                << "\"" << booked[i] << "\","
                << to_string(duration[i]) << ","
                << "\"" << specialService[i] << "\"" << "\n";
        }
    }
    out.close();
}

void Storable::toString_orderBill()
{
    ofstream out("files.txt/order.txt", ios::trunc);

    for (size_t i = 0; i < itemName.size(); i++)
    {
        if (sold[i] == "sold" && orderedQty[i] > 0)
        {
            out << "\"" << itemName[i] << "\","
                << to_string(itemPrice[i]) << ","
                << to_string(orderedQty[i]) << ","
                << to_string(itemQty[i]) << ","
                << "\"" << sold[i] << "\"\n";
        }
    }
    out.close();
}

void Storable::toString_roomBill()
{
    ofstream out("files.txt/billManager.txt", ios::trunc);

    for (size_t i = 0; i < billId.size(); i++)
    {
        if (!name[i].empty())
        {
            out << to_string(billId[i]) << ","
                << "\"" << name[i] << "\","
                << to_string(roomNum[i]) << ","
                << to_string(amt[i]) << "\n";
        }
    }
    out.close();
}

void Storable::toString_feedback()
{

    ofstream out("files.txt/feedback.txt", ios::app);

    for (const auto &fd : feedBack)
    {
        if (!fd.empty())
        {
            out << "\"" << fd << "\"\n";
        }
    }
}

void Storable::fromString_customer()
{
    ifstream in("files.txt/customer.txt");

    if (!in)
    {
        return;
    }

    string line;
    int i = 0;

    while (getline(in, line))
    {
        if(line.empty()){
            continue;  //skips empty record
        }

        istringstream iss(line);
        string nameQuoted, contactStr, idStr, roomStr;

        // Read comma-separated values
        getline(iss, nameQuoted, ','); // e.g., "\""Sumit Chauhan"\""
        getline(iss, contactStr, ',');
        getline(iss, idStr, ',');
        getline(iss, roomStr);

        // Remove quotes from name
        if (nameQuoted.front() == '"')
        {
            nameQuoted.erase(0, 1);
        }
        if (nameQuoted.back() == '"')
        {
            nameQuoted.pop_back();
        }

        try
        {
            // Convert other strings to int
            int room = stoi(roomStr);

            // Push to vectors
            name[i] = nameQuoted;
            contact[i] = contactStr;
            ID[i] = idStr;
            roomNum[i] = room;
            
            i++;
        }
        catch (const exception& e) {
            cout << "Skipping bad data: " << e.what() << " in line: " << line << "\n";
            continue;
        }
    }
    in.close();
}

void Storable::fromString_room()
{
    getdata_room(); //sets initialisation
    ifstream in("./files.txt/room.txt");
    if (!in) return;

    string line;
    int i = 0;

    while (getline(in, line))
    {
        if(line.empty()){
            continue;  //skips empty record
        }

        istringstream iss(line);
        string roomNumStr, acQuoted, foodQuoted, laundryQuoted, costStr, bookedQuoted, durationStr, specialQuoted;

        getline(iss, roomNumStr, ',');
        getline(iss, acQuoted, ',');
        getline(iss, foodQuoted, ',');
        getline(iss, laundryQuoted, ',');
        getline(iss, costStr, ',');
        getline(iss, bookedQuoted, ',');
        getline(iss, durationStr, ',');
        getline(iss, specialQuoted);

        try {
            // Convert other strings to int
            int roomNo = stoi(roomNumStr);
            int costNum = stoi(costStr);
            int durationNum = stoi(durationStr);

            // Push to vectors
            Ac[i] = acQuoted;
            foodService[i] = foodQuoted;
            laundryService[i] = laundryQuoted;
            booked[i] = bookedQuoted;
            specialService[i] = specialQuoted;
            roomNum[i] = roomNo;
            cost[i] = costNum;
            duration[i] = durationNum;

            i++;
        }
        catch (const exception& e) {
            cout << "Skipping bad data: " << e.what() << " in line: " << line << "\n";
            continue;
        }
    }
    in.close();
}

void Storable::fromString_orderBill()
{
    getdata_order(); // sets initialisation
    ifstream in("files.txt/order.txt");

    if (!in)
        return;

    string line;
    int i = 0;

    while (getline(in, line))
    {
        if(line.empty()){
            continue;  //skips empty record
        }

        istringstream iss(line);
        string itemQuoted, soldQuoted, priceStr, orderedStr, qtyStr;

        // Read comma-separated values
        getline(iss, itemQuoted, ',');
        getline(iss, priceStr, ',');
        getline(iss, orderedStr, ',');
        getline(iss, qtyStr, ',');
        getline(iss, soldQuoted);

        // Remove quotes from name
        if (itemQuoted.front() == '"')
        {
            itemQuoted.erase(0, 1);
        }
        if (itemQuoted.back() == '"')
        {
            itemQuoted.pop_back();
        }

        if (soldQuoted.front() == '"')
        {
            soldQuoted.erase(0, 1);
        }
        if (soldQuoted.back() == '"')
        {
            soldQuoted.pop_back();
        }

        try
        {
            // Convert other strings to int
            int priceNum = stoi(priceStr);
            int orderedNum = stoi(orderedStr);
            int qtyNum = stoi(qtyStr);

            // Push to vectors
            itemName[i] = itemQuoted;
            itemPrice[i] = priceNum;
            orderedQty[i] = orderedNum;
            itemQty[i] = qtyNum;
            sold[i] = soldQuoted;

            i++;
        }
        catch (const exception& e) {
            cout << "Skipping bad data: " << e.what() << " in line: " << line << "\n";
            continue;
        }
    }
    in.close();
}

void Storable::fromString_roomBill()
{
    ifstream in("./files.txt/billManager.txt");

    if (!in)
        return;

    string line;
    int i = 0;

    while (getline(in, line))
    {
        if(line.empty()){
            continue;  //skips empty record
        }

        istringstream iss(line);
        string billIdStr, roomStr, amtStr;
        string nameQuoted;

        // Read comma-separated values
        getline(iss, billIdStr, ',');
        getline(iss, nameQuoted, ',');
        getline(iss, roomStr, ',');
        getline(iss, amtStr);

        // Remove quotes from name
        if (nameQuoted.front() == '"')
        {
            nameQuoted.erase(0, 1);
        }
        if (nameQuoted.back() == '"')
        {
            nameQuoted.pop_back();
        }

        try
        {
            // Convert other strings to int
            int billIdNum = stoi(billIdStr);
            int roomNo = stoi(roomStr);
            int amtNum = stoi(amtStr);

            // Push to vectors
            billId[i] = billIdNum;
            name[i] = nameQuoted;
            roomNum[i] = roomNo;
            amt[i] = amtNum;

            i++;
        }
        catch (const exception& e) {
            cout << "Skipping bad data: " << e.what() << " in line: " << line << "\n";
            continue;
        }
    }
}
