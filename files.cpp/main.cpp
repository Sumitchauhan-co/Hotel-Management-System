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

int main()
{
    Storable s;

    if (s.fileNotEmpty("files.txt/room.txt"))
    {
        s.fromString_room();
    }

    if (s.fileNotEmpty("files.txt/customer.txt"))
    {
        s.fromString_customer();
    }

    if (s.fileNotEmpty("files.txt/order.txt"))
    {
        s.fromString_orderBill();
    }

    if (s.fileNotEmpty("files.txt/billManager.txt"))
    {
        s.fromString_roomBill();
    }

    // Hotel data initialization
    if (!s.fileNotEmpty("files.txt/room.txt"))
    {
        s.getdata_room();
    }

    if (!s.fileNotEmpty("files.txt/order.txt"))
    {
        s.getdata_order();
    }

    Application app(s);
    app.run(s);

    return 0;
}