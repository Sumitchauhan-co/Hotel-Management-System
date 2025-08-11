#include "room.h"
#include <limits>
#include <iomanip>
#include <algorithm>
#include "errorHandling.h"
using namespace std;

void Room::getdata_room()
{
    for (size_t i = 0; i < roomNum.size(); i++)
    {
        int base = 2000;
        roomNum[i] = i + 1; // room no. starts from 1
        booked[i] = "No booking yet";
        duration[i] = 0;
        specialService[i] = "None";

        if (i % 2 == 0)
        {
            Ac[i] = "No";
        }
        else
        {
            Ac[i] = "Yes";
        }

        if (i % 3 == 0)
        {
            laundryService[i] = "No";
        }
        else
        {
            laundryService[i] = "Yes";
        }

        if (i % 4 == 0)
        {
            foodService[i] = "No";
        }
        else
        {
            foodService[i] = "Yes";
        }

        if (Ac[i] == "Yes")
        {
            base += 500;
        }

        if (foodService[i] == "Yes")
        {
            base += 300;
        }

        if (laundryService[i] == "Yes")
        {
            base += 200;
        }

        if (specialService[i] != "None")
        {
            base += 1000;
        }

        cost[i] = base;
    }
    cout << "\nRoom data initialised successfully\n";
}

void Room::display_room()
{
    int customer_room;
    int time;
    string ss;
    char option;

    while (true)
    {
        cout << "\nPlease enter your room no. : ";
        errorHandling::input(customer_room);

        if (customer_room < 1 || customer_room > 50)
        {
            cout << "\nInvalid room number, try again!\n";
            continue;
        }

        cout << "\nEnter your stay duration(in days) : ";
        errorHandling::input(time);

        if (time < 1)
        {
            cout << "\nInvalid duration, please enter a valid number\n";
            continue;
        }

        cout << "\nDo you want any special service? (Yes/No) : ";
        errorHandling::input(ss);

        transform(ss.begin(), ss.end(), ss.begin(), ::tolower);

        if (ss == "yes")
        {
            cout << "\nWe will try our best to provide the special gesture...Thank you!\n\n";
        }
        else
        {
            cout << "\nNo problem, we will not provide any special service\n\n";
            ss = "None";
        }

        bool found = false;

        cout << left << setw(10) << "Room No."
             << setw(10) << "Ac"
             << setw(15) << "Food service"
             << setw(20) << "Laundry service"
             << setw(10) << "Cost"
             << setw(20) << "Booking" << endl;

        for (size_t i = 0; i < roomNum.size(); i++)
        {
            if (roomNum[i] == customer_room)
            {
                cout << left << setw(10) << roomNum[i]
                     << setw(10) << Ac[i]
                     << setw(15) << foodService[i]
                     << setw(20) << laundryService[i]
                     << setw(10) << cost[i]
                     << setw(20) << booked[i] << endl;

                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "\nRoom not found. Try again.\n";
            continue;
        }

        cout << "\nDo you like this room? (Y/N) : ";
        errorHandling::input(option);
        option = tolower(option);

        if (option == 'y')
        {
            booked[customer_room - 1] = "Booked";
            cout << "\nRoom confirmed! Room number: " << customer_room << endl;
            duration[customer_room - 1] = time;
            specialService[customer_room - 1] = ss;
            break;
        }
        else
        {
            for (size_t i = 0; i < roomNum.size(); i++)
            {
                if (booked[i] != "'Booked'" && roomNum[i] > customer_room)
                {
                    cout << "Value: [" << booked[i] << "]" << endl;
                    for (unsigned char c : booked[i])
                    {
                        cout << (int)c << " ";
                    }
                    cout << endl;
                    customer_room = roomNum[i];
                    break;
                }
            };
            cout << "\nYour next room : " << customer_room << endl;
            continue;
        }
    }
}

void Room::display_allroom()
{
    cout << "\n\n---------- Hotel Room Details ----------\n\n";

    cout << left << setw(15) << "\nRoom No."
         << setw(10) << "Ac"
         << setw(15) << "Food service"
         << setw(20) << "Laundry service"
         << setw(10) << "Cost"
         << setw(20) << "Booking" << endl;

    for (size_t i = 0; i < roomNum.size(); i++)
    {
        if (booked[i] != "Booked")
        {
            continue; // Skip rooms that are not booked
        }

        cout << left << setw(15) << roomNum[i]
             << setw(10) << Ac[i]
             << setw(15) << foodService[i]
             << setw(20) << laundryService[i]
             << setw(10) << cost[i]
             << setw(20) << booked[i] << endl;
    }
}