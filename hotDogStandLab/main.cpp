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

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

#include "HotDogStandClass.h"

using namespace std;

ostream& operator<<(ostream& leftSideOutputStream, const HotDogStandClass& hotDogStandObj)
{
    leftSideOutputStream <<
        "Stand Id    : " + hotDogStandObj.getId() << endl <<
        "Location    : " + hotDogStandObj.getLocation() << endl <<
        "Inventory   : " << hotDogStandObj.getInventoryCount() << endl <<
        "Store Sold  : " << hotDogStandObj.getSoldCount() << " at $" << hotDogStandObj.getCost() << "ea." << endl <<
        "Global Sold : " << HotDogStandClass::getGlobalSalesCount() << endl << endl;
    return leftSideOutputStream;
}

int main()
{
    cout << setprecision(2) << fixed << showpoint;

    HotDogStandClass hotDogStand1("1-TX-Preston", "6400 Preston Rd", 12.2f, 3);
    HotDogStandClass hotDogStand2("2-TX-Legacy", "301 Legacy Dr", 10.3f, 3);
    HotDogStandClass hotDogStand3("3-TX-Parker", "6001 Parker Rd", 14.2f, 3);

    cout << "Initial states of stands: " << endl << endl;
    cout << hotDogStand1 << endl;
    cout << hotDogStand2 << endl;
    cout << hotDogStand3 << endl;

    //test add to inventory
    cout << "Add 2 hotdogs to " << hotDogStand1.getId() << "Inventory" << endl;
    hotDogStand1.stockInventory(2);
    cout << hotDogStand1 << endl << endl;

    //test add negative amount to inventory
    cout << "Add -2 hotdogs to " << hotDogStand1.getId() << "inventory" << endl;
    hotDogStand1.stockInventory(-2);
    cout << hotDogStand1 << endl;

    cout << "Test normal purchases :" << endl << endl;

    cout << "Buy 4 hotdogs from " << hotDogStand1.getId() << endl;
    hotDogStand1.hotDogsBuy(4);
    cout << hotDogStand1 << endl;

    cout << "Buy 2 hotdogs from " << hotDogStand2.getId() << endl;
    hotDogStand2.hotDogsBuy(2);
    cout << hotDogStand2 << endl;

    cout << "Buy 3 hotdogs from " << hotDogStand3.getId() << endl;
    hotDogStand3.hotDogsBuy(3);
    cout << hotDogStand3 << endl;

    cout << "Test purchase greater than inventory from " << hotDogStand1.getId() << endl;
    cout << "Buy 5 hotdogs from " << hotDogStand1.getId() << endl;
    hotDogStand1.hotDogsBuy(5);
    cout << hotDogStand1 << endl;

    cout << "Test purchase when no hot dogs left from " << hotDogStand3.getId() << endl;
    cout << "Buy 1 hotdogs from " << hotDogStand3.getId() << endl;
    hotDogStand3.hotDogsBuy(1);
    cout << hotDogStand3 << endl;

    cout << "Test purchase when one hot dogs left " << endl;
    cout << "Buy 1 hotdogs from " << hotDogStand1.getId() << endl;
    hotDogStand1.hotDogsBuy(1);
    cout << hotDogStand1 << endl;

    cout << "Buy 2 hotdogs from " << hotDogStand2.getId() << endl;
    hotDogStand2.hotDogsBuy(2);
    cout << hotDogStand2 << endl;

    cout << "Test negative purchase count " << endl;
    cout << "Buy 1 hotdogs from " << hotDogStand3.getId() << endl;
    hotDogStand3.hotDogsBuy(-2);
    cout << hotDogStand3 << endl;

    cout << "Final sates of stands" << endl << endl;
    cout << hotDogStand1 << endl;
    cout << hotDogStand2 << endl;
    cout << hotDogStand3 << endl;
    cout << endl << endl;

    cout << "Please press enter to continue..."; cin.ignore(); cin.get();

    return 0;
}