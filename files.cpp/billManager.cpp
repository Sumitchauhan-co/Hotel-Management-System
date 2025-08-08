#include "billManager.h"
#include <sstream>
#include <fstream>
#include <algorithm>
#include "errorHandling.h"
using namespace std;

void BillManager::bill_room()
{
    while (true)
    {
        int customer_room;
        string customer_name;

        cout << "\nEnter your room number: ";
        errorHandling::input(customer_room);

        if (customer_room < 1 || customer_room > 50)
        {
            cout << "\nInvalid room number, try again!\n";
            continue;
        }

        cout << "\nEnter your name: ";
        errorHandling::input(customer_name);

        transform(customer_name.begin(), customer_name.end(), customer_name.begin(), ::tolower);
        bool found = false;

        for (size_t i = 0; i < roomNum.size(); i++)
        {
            string lower_name = name[i];

            transform(lower_name.begin(), lower_name.end(), lower_name.begin(), ::tolower);

            if (roomNum[i] == customer_room && lower_name == customer_name)
            {

                int total_charge = cost[i] * duration[i];

                if (foodService[i] == "Yes")
                {
                    total_charge += 150 * duration[i];
                }

                if (laundryService[i] == "Yes")
                {
                    total_charge += 50 * duration[i];
                }

                if (specialService[i] != "None")
                {
                    total_charge += 300;
                }

                float discount_amt = total_charge * 0.15;
                float gst_amt = total_charge * 0.18;
                float final_amt = total_charge - discount_amt + gst_amt;

                billId[i] = i + 1;
                amt[i] = final_amt;

                cout << "\n\nBill Generated Successfully:";
                cout << "\nBill ID          : " << i + 1;
                cout << "\nCustomer Name    : " << name[i];
                cout << "\nRoom No          : " << roomNum[i];
                cout << "\nDuration         : " << duration[i] << " days";
                cout << "\nBase Charge      : Rs" << cost[i] * duration[i];
                cout << "\nFood Service     : " << foodService[i];
                cout << "\nLaundry Service  : " << laundryService[i];
                cout << "\nSpecial Service  : " << specialService[i];
                cout << "\nTotal Charge     : Rs" << total_charge;
                cout << "\nDiscount (15%)   : Rs" << discount_amt;
                cout << "\nGST (18%)        : RS" << gst_amt;
                cout << "\nFinal Amount     : RS" << final_amt << "\n";
                
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "\nNo such customer found, try again!\n";
            continue;
        }
        break;
    }
}