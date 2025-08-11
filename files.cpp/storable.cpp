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
            out << name[i] << " , "
                << contact[i] << " , "
                << ID[i] << " , "
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
        out << to_string(roomNum[i]) << " , "
            << Ac[i] << " , "
            << foodService[i] << " , "
            << laundryService[i] << " , "
            << to_string(cost[i]) << " , "
            << booked[i] << " , "
            << to_string(duration[i]) << " , "
            << specialService[i] << "\n";
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
            out << itemName[i] << " , "
                << to_string(itemPrice[i]) << " , "
                << to_string(orderedQty[i]) << " , "
                << to_string(itemQty[i]) << " , "
                << sold[i] << "\n";
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
            out << to_string(billId[i]) << " , "
                << name[i] << " , "
                << to_string(amt[i]) << " , "
                << to_string(roomNum[i]) << "\n"; 
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
            out << fd << "\n";
        }
    }
}

// lamda function for treaming quotes in input strings
auto trimQuotes = [](string &s)
{
    // if (!s.empty())
    // {
    //     if (s.front() == '"')
    //     {
    //         s.erase(0, 1);
    //     }
    //     if (s.back() == '"')
    //     {
    //         s.pop_back();
    //     }
    // }
};

// lamda function for treaming spaces in input strings
auto trimSpaces = [](string &s)
{
    auto pos1 = s.find_first_not_of(" \t");
    if (pos1 != string::npos)
    {
        s.erase(0, pos1); // remove leading spaces or tab
    }
    else
    {
        s.clear();
        return;
    }

    auto pos2 = s.find_last_not_of(" \t");
    if (pos2 != string::npos)
    {
        s.erase(pos2 + 1); // remove trailing spaces or tab
    }
    else
    {
        s.clear();
        return;
    }
};

void Storable::fromString_customer()
{
    ifstream in("files.txt/customer.txt");

    if (!in)
    {
        return;
    }

    string line;
    int i;

    while (getline(in, line))
    {
        if (line.empty())
        {
            continue; // skips empty record
        }

        istringstream iss(line); // inputs each line
        string nameQuoted, contactStr, idStr, roomStr;

        // Read comma-separated values
        getline(iss, nameQuoted, ',');
        getline(iss, contactStr, ',');
        getline(iss, idStr, ',');
        getline(iss, roomStr);

        // Remove quotes & spaces
        trimQuotes(nameQuoted);
        trimSpaces(nameQuoted);

        trimSpaces(contactStr);

        trimSpaces(idStr);

        trimSpaces(roomStr);

        try
        {
            // Convert other strings to int
            int room = stoi(roomStr);

            i = room - 1;

            // Push to vectors
            name[i] = nameQuoted;
            contact[i] = contactStr;
            ID[i] = idStr;
            roomNum[i] = room;
        }
        catch (const exception &e)
        {
            cout << "Skipping bad data: " << e.what() << " in line: " << line << "\n";
            continue;
        }
    }
    in.close();
}

void Storable::fromString_room()
{
    getdata_room(); // sets initialisation
    ifstream in("./files.txt/room.txt");
    if (!in)
    {
        return;
    }

    string line;
    int i;

    while (getline(in, line))
    {
        if (line.empty())
        {
            continue; // skips empty record
        }

        istringstream iss(line); // inputs each line
        string roomNumStr, acQuoted, foodQuoted, laundryQuoted, costStr, bookedQuoted, durationStr, specialQuoted;

        // Read comma-separated values
        getline(iss, roomNumStr, ',');
        getline(iss, acQuoted, ',');
        getline(iss, foodQuoted, ',');
        getline(iss, laundryQuoted, ',');
        getline(iss, costStr, ',');
        getline(iss, bookedQuoted, ',');
        getline(iss, durationStr, ',');
        getline(iss, specialQuoted);

        // Remove quotes & spaces
        trimSpaces(roomNumStr);

        trimQuotes(acQuoted);
        trimSpaces(acQuoted);

        trimQuotes(foodQuoted);
        trimSpaces(foodQuoted);

        trimQuotes(laundryQuoted);
        trimSpaces(laundryQuoted);

        trimSpaces(costStr);

        trimQuotes(bookedQuoted);
        trimSpaces(bookedQuoted);

        trimSpaces(durationStr);

        trimQuotes(specialQuoted);
        trimSpaces(specialQuoted);

        try
        {
            // Convert other strings to int
            int roomNo = stoi(roomNumStr);
            int costNum = stoi(costStr);
            int durationNum = stoi(durationStr);

            i = roomNo - 1;

            // Push to vectors
            Ac[i] = acQuoted;
            foodService[i] = foodQuoted;
            laundryService[i] = laundryQuoted;
            booked[i] = bookedQuoted;
            specialService[i] = specialQuoted;
            roomNum[i] = roomNo;
            cost[i] = costNum;
            duration[i] = durationNum;
        }
        catch (const exception &e)
        {
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
    {
        return;
    }

    string line;

    while (getline(in, line))
    {
        if (line.empty())
        {
            continue; // skips empty record
        }

        istringstream iss(line); // inputs each line
        string itemQuoted, priceStr, orderedStr;

        // Read comma-separated values
        getline(iss, itemQuoted, ',');
        getline(iss, priceStr, ',');
        getline(iss, orderedStr, ',');

        // Remove quotes & spaces
        trimQuotes(itemQuoted);
        trimSpaces(itemQuoted);

        trimSpaces(priceStr);

        trimSpaces(orderedStr);

        if (!itemQuoted.empty())
        {
            // Match with default list
            for (size_t i = 0; i < itemName.size(); i++)
            {
                if (itemName[i] == itemQuoted)
                {
                    itemQty[i] -= stoi(orderedStr);
                    break;
                }
            }
        }
    }
    in.close();
}

void Storable::fromString_roomBill()
{
    ifstream in("./files.txt/billManager.txt");

    if (!in)
    {
        return;
    }

    string line;
    int i;

    while (getline(in, line))
    {
        if (line.empty())
        {
            continue; // skips empty record
        }

        istringstream iss(line); // inputs each line
        string billIdStr, amtStr, nameQuoted;

        // Read comma-separated values
        getline(iss, billIdStr, ',');
        getline(iss, nameQuoted, ',');
        getline(iss, amtStr, ',');

        // Remove quotes & spaces
        trimSpaces(billIdStr);

        trimQuotes(nameQuoted);
        trimSpaces(nameQuoted);

        trimSpaces(amtStr);

        try
        {
            // Convert other strings to int
            int billIdNum = stoi(billIdStr);
            int amtNum = stoi(amtStr);

            i = billIdNum - 1;

            // Push to vectors
            billId[i] = billIdNum;
            name[i] = nameQuoted;
            amt[i] = amtNum;
        }
        catch (const exception &e)
        {
            cout << "Skipping bad data: " << e.what() << " in line: " << line << "\n";
            continue;
        }
    }
}
