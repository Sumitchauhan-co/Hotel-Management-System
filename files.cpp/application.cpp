#include "application.h"
#include "customer.h"
#include "room.h"
#include "booking.h"
#include "billManager.h"
#include "storable.h"
#include "order.h"
#include "errorHandling.h"
#include <iostream>
using namespace std;

void Application::run(Storable &s)
{
    errorHandling eh;
    int choice;

    while (true)
    {

        cout << "\n\n---------- Hotel Management System ----------\n\n";

        cout << "1. Hotel data\n";
        cout << "2. Book Room\n";
        cout << "3. Show Customer\n";
        cout << "4. Prebook Room\n";
        cout << "5. Order food\n";
        cout << "6. Generate Bill\n";
        cout << "7. Feedback\n";
        cout << "8. Exit\n";

        cout << "\nEnter your choice: ";
        eh.input(choice);

        if (choice == 1)
        {
            string password;
            cout << "\nEnter staff password : ";
            eh.input(password);

            if (password == "sumit_04m")
            {
                cout << "\n\n1. To display room data of hotel";
                cout << "\n2. To display order data of hotel";
                cout << "\n3. To display customer data of hotel\n";

                int choose;
                cout << "\nEnter your choice : ";
                eh.input(choose);

                if (choose == 1)
                {
                    s.display_allroom();     // to display all rooms
                    continue;
                }

                if (choose == 2)
                {
                    s.display_allorder(); // to display all customers
                    continue;
                }

                if (choose == 3)
                {
                    s.display_allcustomer(); // to display all customers
                    continue;
                }

                else
                {
                    cout << "\nInvalid choice, try again!\n";
                    continue;
                }
            }
            else
            {
                cout << "\nWrong password, try again!\n";
                continue;
            }
        }

        if (choice == 2)
        {
            s.entry();             // to book the room
            s.display_room();      // to display the room feautures
            s.getdata_customer();  // details of the customer
            s.toString_customer(); // to save customer info
            s.toString_room();     // to save room info
            continue;
        }

        if (choice == 3)
        {
            s.display(); // display the details of the customer
            continue;
        }

        if (choice == 4)
        {
            s.preBook();           // to prebook the room
            s.getdata_customer();  // details of the customer
            s.toString_customer(); // to save customer info
            s.toString_room();     // to save room info
            continue;
        }

        if (choice == 5)
        {
            s.food();               // to order the food
            s.toString_orderBill(); // to save the order bill info
            continue;
        }

        if (choice == 6)
        {
            s.bill_room();         // to get the bill
            s.toString_roomBill(); // to save the room bill info
            continue;
        }

        if (choice == 7)
        {
            s.getdata_feedback();  // to get customer feedback
            s.toString_feedback(); // to save the feedback
            continue;
        }

        if (choice == 8)
        {
            cout << "\nThank you for visiting us!\nCome again later...\n";
            return;
        }
    }
}
