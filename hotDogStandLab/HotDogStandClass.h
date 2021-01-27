/*
* Module Name: HotDogStand Lab
* Date: 10/26/2020
* Author: Rishi Villa
*
* Module Purpose: The lab performs basic operations to keep track of hot dog inventory
* and the purchases made at different hot dog stands.
*
* Module design description
*
* Inputs:
* Class objects of the HotDogStandClass.
* HotdogBuy method
* Inventory Count
* Stock Count
*
* Outputs
* Location of the Hot Dog Stand
* Id of the Hot dog stand
* Number of Hot dogs left on inventory
* Number of hot dogs added or purchased
* Final inventory list of all the stands
*
* Modifications list: None
*
*/
#ifndef HOTDOG_STAND_CLASS_H
#define HOTDOG_STAND_CLASS_H

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

class HotDogStandClass
{
private:
    string id;
    string loc;
    float cost;
    unsigned trackInventory;
    unsigned soldCount;
    static unsigned globalSalesCount;

public:
    HotDogStandClass(string const& id, string const& loc, float cost)
        : HotDogStandClass(id, loc, cost, 0) {}

    HotDogStandClass(string const& id, string const& loc, float cost, unsigned int trackInventory)
    {
        this->id = id;
        this->loc = loc;
        this->cost = cost;
        this->soldCount = 0;
        this->trackInventory = trackInventory;
    }

    const string& getId() const { return id; }
    void setId(const string& id) { HotDogStandClass::id = id; }

    const string& getLocation() const { return loc; }
    void setLocation(const string& loc) { HotDogStandClass::loc = loc; }

    float getCost() const { return cost; }
    void setCost(float cost) { HotDogStandClass::cost = cost; }

    unsigned getSoldCount() const { return soldCount; }
    unsigned getInventoryCount() const { return trackInventory; }
    static unsigned getGlobalSalesCount() { return HotDogStandClass::globalSalesCount; }

    void hotDogsBuy(int count);
    void stockInventory(int stockCount);

};

#endif