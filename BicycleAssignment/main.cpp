/*
* Module Name: Bicycle Assignment
* Date: 11/04/2020
* Author: Rishi Villa
*
* Module Purpose: This program introduces an abstract method for calculateRentalFees() and
* override inheritance for calculateRentalFees() in extended classes of BicycleRentalClass class.
*
* Module design description
*
* Inputs:
* Class Objects
* Pointers 

* Outputs
* Rental Information
*
* Modifications list: None
*
*/

#include <iostream>
#include <iomanip>
#include<string>

#include "BicycleRentalClass.h"
#include "BicycleRentalSubClasses.h"

using namespace std;

void displayEqualsTest(BicycleRentalClass* obj01Ptr, BicycleRentalClass* obj02Ptr) {
    cout << "Bicycle Id         : " << obj01Ptr->getBicycleId() << endl <<
        "Bicycle Id Compare : " << obj02Ptr->getBicycleId() << endl <<
        "are " << ((obj01Ptr->equals(obj02Ptr)) ? "equal" : "not equal ") << endl << endl;

}


//	main test driver method, create some sample secarious that path test the program

int main() {
    BicycleRentalStandardClass* bikeStandardObjPtr = new BicycleRentalStandardClass(101);
    BicycleRentalRacerClass* bikeRacerObjPtr = new BicycleRentalRacerClass(201);;
    BicycleRentalBMXClass* bikeBMXObjPtr = new BicycleRentalBMXClass(301);

    cout << "Test bike rentals for various days for various bike types" << endl << endl;
    for (auto days : { 1 ,3, 5, 12 }) {
        bikeStandardObjPtr->calculateRentalFees(days);
        bikeStandardObjPtr->displayBikeRentalInformation();
        bikeRacerObjPtr->calculateRentalFees(days);
        bikeRacerObjPtr->displayBikeRentalInformation();
        bikeBMXObjPtr->calculateRentalFees(days);
        bikeBMXObjPtr->displayBikeRentalInformation();
    }

    displayEqualsTest(bikeStandardObjPtr, bikeStandardObjPtr);
    displayEqualsTest(bikeStandardObjPtr, bikeRacerObjPtr);

    cout << endl << "Press the enter key to continue..."; cin.ignore(); cin.get();

}
