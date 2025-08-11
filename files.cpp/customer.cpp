#include "customer.h"
#include <iomanip>
#include <algorithm>
#include "errorHandling.h"
using namespace std;

void Customer::getdata_customer()
{
    while (true)
    {

        string customer_name;
        string customer_contact;
        string customer_ID;

        cout << "\nEnter your room number again : ";
        int customer_room;
        errorHandling::input(customer_room);

        if (customer_room < 1 || customer_room > 50)
        {
            cout << "\nInvalid room number, try again!\n";
            continue;
        }
        
        for (int i = 0; i < 50; i++)
        {
            if (roomNum[i] == customer_room)
            {
                cout << "\nPlease enter the folowing details(*mandatory) \n";

                cout << "\nYour name : ";
                errorHandling::input(customer_name);
                name[i] = customer_name;

                cout << "\nYour contact no. : ";
                errorHandling::input(customer_contact);
                contact[i] = customer_contact;

                cout << "\nYour ID proof : ";
                errorHandling::input(customer_ID);
                ID[i] = customer_ID;

                break;
            }
        }
        break;
    }
    cout << "\nYour information has been saved\n";
}

void Customer::display()
{
    while (true)
    {
        cout << "\nTo get the personal info, please verify urself\n";

        cout << "\nEnter your room number : ";
        int customer_room;
        errorHandling::input(customer_room);

        cout << "\nEnter your name : ";
        string customer_name;
        errorHandling::input(customer_name);

        transform(customer_name.begin(), customer_name.end(), customer_name.begin(), ::tolower);

        bool found = false;
        string lower_name = customer_name;

        transform(lower_name.begin(), lower_name.end(), lower_name.begin(), ::tolower);

        cout << left << setw(20) << "\nName"
             << setw(20) << "Contact"
             << setw(20) << "Id"
             << setw(10) << "Room" << endl;

        for (size_t i = 0; i < roomNum.size(); i++)
        {
            string lower_name = name[i];

            transform(lower_name.begin(), lower_name.end(), lower_name.begin(), ::tolower);

            cout<<roomNum[i]<<customer_room<<" "<<lower_name<<customer_name<<endl;    //error check
            if (roomNum[i] == customer_room && lower_name == customer_name)
            {
                cout << left << setw(20) << name[i]
                     << setw(20) << contact[i]
                     << setw(20) << ID[i]
                     << setw(10) << roomNum[i] << endl;

                found = true;
                break;
            }
        }
        
        if (!found)
        {
            cout << "\nCustomer not found, try again\n";
            continue;
        }
        break;
    }
}

void Customer::display_allcustomer()
{
    cout << "\n\n---------- Hotel Customer Details ----------\n\n";

    cout << left << setw(20) << "\nName"
         << setw(20) << "Contact"
         << setw(20) << "Id"
         << setw(10) << "Room" << endl;

    for (size_t i = 0; i < roomNum.size(); i++)
    {
        if (name[i].empty())
        {
            continue; // Skip empty entries
        }

        cout << left << setw(20) << name[i]
             << setw(20) << contact[i]
             << setw(20) << ID[i]
             << setw(10) << roomNum[i] << endl;
    }
}

void Customer ::getdata_feedback()
{
    while (true)
    {
        cout << "\nPlease enter your feedback : ";
        string word;
        errorHandling::input(word);
        feedBack.push_back(word);
        break;
    }
    cout << "\nThank you for your valuable feedback!";
    cout << "\nWe will try to improve our services based on your suggestions\n";
}
