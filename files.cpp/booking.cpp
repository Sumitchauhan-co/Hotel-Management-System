#include "booking.h"
#include <algorithm>
#include <iomanip>
#include <algorithm>
#include "errorHandling.h"
using namespace std;

void Booking::entry()
{
    for (size_t i = 0; i < roomNum.size(); i++)
    {
        if (booked[i] != "Booked")
        {
            cout << "\nHello! Your heartedly welcome on the Parasite Hotel of Sumit :D \n";
            cout << "\nYour room number is : " << roomNum[i] << endl;
            return;
        }
    }
    cout << "\n\nSorry, we dont have any rooms avaialable right now, please check later :( \n";
}

void Booking::display_book()
{
    cout << "\n\n---------- Hotel Room Booking ----------\n\n";

    cout << left << setw(10) << "Room No."
         << setw(10) << "AC"
         << setw(15) << "Food service"
         << setw(15) << "Laundry service"
         << setw(10) << "Cost"
         << setw(20) << "Booking"
         << setw(10) << "Duration" << endl;

    for (size_t i = 0; i < roomNum.size(); i++)
    {
        cout << setw(10) << roomNum[i]
             << setw(10) << Ac[i]
             << setw(15) << foodService[i]
             << setw(15) << laundryService[i]
             << setw(10) << cost[i]
             << setw(20) << booked[i]
             << setw(10) << duration[i] << endl;
    }
}

void Booking::preBook()
{
    while (true)
    {
        cout << "\n\nPlease enter the following features of your room \n";

        string customer_Ac;
        int customer_cost;
        string customer_foodService;
        string customer_laundryService;

        cout << "\nEnter AC(Yes/No) : ";
        errorHandling::input(customer_Ac);

        transform(customer_Ac.begin(), customer_Ac.end(), customer_Ac.begin(), ::tolower);

        cout << "\nEnter budget : ";
        errorHandling::input(customer_cost);

        cout << "\nEnter food service(Yes/No) : ";
        errorHandling::input(customer_foodService);

        transform(customer_foodService.begin(), customer_foodService.end(), customer_foodService.end(), ::tolower);

        cout << "\nEnter laundry service(Yes/No) : ";
        errorHandling::input(customer_laundryService);

        transform(customer_laundryService.begin(), customer_laundryService.end(), customer_laundryService.end(), ::tolower);

        string lower_Ac;
        string lower_foodService;
        string lower_laundryService;
        bool roomFound = false;

        for (size_t i = 0; i < roomNum.size(); i++)
        {
            lower_Ac = Ac[i];

            transform(lower_Ac.begin(), lower_Ac.end(), lower_Ac.begin(), ::tolower);

            lower_foodService = foodService[i];

            transform(lower_foodService.begin(), lower_foodService.end(), lower_foodService.end(), ::tolower);

            lower_laundryService = laundryService[i];

            transform(lower_laundryService.begin(), lower_laundryService.end(), lower_laundryService.end(), ::tolower);

            if (lower_Ac == customer_Ac &&
                cost[i] >= customer_cost &&
                lower_foodService == customer_foodService &&
                lower_laundryService == customer_laundryService)
            {
                cout << "\n\nRoom number : " << roomNum[i]
                     << "\nAc available : " << Ac[i]
                     << "\nFood service available : " << foodService[i]
                     << "\nLaundry service available : " << laundryService[i]
                     << "\ncost : " << cost[i]
                     << "\nBooking : " << booked[i] << endl;

                roomFound = true;
                break;
            }
        }

        if (!roomFound)
        {
            cout << "\nSorry, there is no such room available with the given features\n";
            cout << "\nChoose your dream room from below : ";

            display_book();

            cout << "\nIs there any room that you wanna preBook?\nEnter its number : ";

            int choice;
            errorHandling::input(choice);

            if (choice < 1 || choice > 50)
            {
                cout << "\nInvalid room number, try again!\n";
                continue;
            }

            bool found = false;

            for (size_t i = 0; i < roomNum.size(); i++)
            {
                if (roomNum[i] == choice)
                {
                    booked[i] = "Booked";
                    cout << "\nYour room number " << roomNum[i] << " is booked\n";
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "\nNo such room found\n";
                continue;
            }
            break;
        }
    }
}

void Booking::food()
{
    while (true)
    {

        string item;
        int qty;

        cout << "\nChoose from the menu ->\n";

        display_order();

        cout << "\n\nEnter your food request : ";
        errorHandling::input(item);

        transform(item.begin(), item.end(), item.begin(), ::tolower);

        cout << "\nEnter its quantity : ";
        errorHandling::input(qty);

        if (qty < 1 )
        {
            cout << "\nInvalid quantity, please enter a valid number\n";
            continue;
        }

        string choice;
        bool found = false;

        for (size_t i = 0; i < itemName.size(); i++)
        {
            string normal = itemName[i];

            transform(normal.begin(), normal.end(), normal.begin(), ::tolower);

            if (normal == item && itemQty[i] >= qty)
            {
                cout << "\nPrice of " << item << " : " << itemPrice[i];
                cout << "\nTotal price : " << itemPrice[i] * qty;
                cout << "\nConfirm the order?(yes/no) : ";

                errorHandling::input(choice);

                transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

                if (choice == "yes" && itemQty[i] - qty >=0)
                {
                    cout << "\nYour request has accepted and your " << item << " is getting ready, it will be delivered soon...";

                    itemQty[i] -= qty;
                    orderedQty[i] = qty;
                    sold[i] = "sold";
                    
                    found = true;
                    break;
                }
                else{
                    break;
                }
            }
        }
        if(choice != "yes"){
            continue;
        }
        if (!found)
        {
            cout << "\n\nSorry, " << item << " : " << qty << " is currently not available on us\n";
            continue;
        }
        
        cout << "\n\nDo you want to order more food?(yes/no) : ";
        string more;
        errorHandling::input(more);

        if (more == "Yes" || more == "yes")
        {
            continue;
        }
        else
        {
            cout << "\nThank you for ordering with us!\n";
            break;
        }
    }
}
