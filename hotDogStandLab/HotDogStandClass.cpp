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
#ifndef HOTDOG_STAND_CLASS_CPP
#define HOTDOG_STAND_CLASS_CPP

#include "HotDogStandClass.h"

using namespace std;

unsigned HotDogStandClass::globalSalesCount = 0;

void HotDogStandClass::hotDogsBuy(int count)
{
    if (count <= 0)
    {
        cout << "*Invalid amount of hotdogs requested*" << endl;
        return;
    }
    else if (trackInventory == 0)
    {
        cout << "*There are no more hotdogs left to be sold*" << endl;
        return;
    }
    else if (trackInventory < count)
    {
        cout << "*We only have " << trackInventory << " hotdog" << (trackInventory > 1 ? "s left.*" : " left.*") << endl;
        return;
    }
    trackInventory -= count;
    soldCount += count;
    globalSalesCount += count;
}

void HotDogStandClass::stockInventory(int stockCount)
{
    if (stockCount <= 0)
    {
        cout << "*Invalid amount for hotdogs stockCount given*" << endl;
        return;
    }
    trackInventory += stockCount;
}

#endif
