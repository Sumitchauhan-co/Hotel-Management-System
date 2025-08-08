#pragma once
#include "customer.h"
#include "room.h"
#include "booking.h"
#include "booking.h"
#include "order.h"
#include "billManager.h"

class Storable : public BillManager
{
public:
    Storable();
    bool fileNotEmpty(const string& filepath);

    void toString_customer();
    void toString_room();
    void toString_orderBill();
    void toString_roomBill();
    void toString_feedback();

    void fromString_customer();
    void fromString_room();
    void fromString_orderBill();
    void fromString_roomBill();
    void fromString_feedback();
};
