/*
* Module Name: Sort By Pointers
* Date: 09/16/2020
* Author: Rishi Villa
*
* Module Purpose: Reads in numbers from a text file and sorts the array
* of pointers based on the values its pointing to.
*
* Module design description
*
* Inputs:
* Text File with numbers
* Size of array
* Values of the elements
*
* Outputs
* List of values after they have been sorted 
* List of the values that were read first.
*
* Modifications list: None
*
*/

#include <stdio.h>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

void DisplayArrayData(int[], unsigned);
void PrintArrayPointer(int* [], unsigned);
bool ReadIntoDataArray(int[], int* [], ifstream&, unsigned&);
void SwapIntPtr(int*&, int*&);
void SortElements(unsigned, int* []);

/*
* The main funtion is responsible for calling the other functions, prompting the user
* for input and displaying the list of sorted values in the array.
*/
int main()
{
    //constants are declared
    const string READ_FROM_FILE = "arrayData.txt";
    const unsigned MAX_SIZE = 10;

    unsigned maximumElements = 0;

    int dataArray[MAX_SIZE];
    int* pointerArray[MAX_SIZE];

    ifstream inFileStreamObject;

    inFileStreamObject.open(READ_FROM_FILE, ios::in);

    if (inFileStreamObject.fail())
    {
        cout << "File" << READ_FROM_FILE << " could not be opened !" << endl;
        cout << "Press any key to continue ..."; cin.ignore();
        cin.get();
        exit(EXIT_FAILURE);
    }

    while (!ReadIntoDataArray(dataArray, pointerArray, inFileStreamObject, maximumElements))
    {
        SortElements(maximumElements, pointerArray);
        PrintArrayPointer(pointerArray, maximumElements);
        DisplayArrayData(dataArray, maximumElements);
        cout << endl << "Press any key to continue..." << endl; cin.ignore();
        cin.get();
        cout << endl << endl;
    }

    inFileStreamObject.close();
    return EXIT_SUCCESS;
}

//Reads the data from the file and stores it.
bool ReadIntoDataArray(int dataArray[], int* pointerArray[], ifstream& inFileStreamObject, unsigned& maximumElements)
{
    if (!(inFileStreamObject >> maximumElements))
        return true;

    for (unsigned key = 0; key < maximumElements; key++)
    {
        inFileStreamObject >> dataArray[key];
        pointerArray[key] = &dataArray[key];
    }
    return(false);
}

//Shows the elements that were read initially.
void DisplayArrayData(int dataArray[], unsigned maximumElements)
{
    cout << "Data Array elements are:" << endl;
    for (unsigned i = 0; i < maximumElements; i++)
        cout << dataArray[i] << setw(6);
    cout << endl << endl;
}

//Shows the elements after they are sorted based on pointers.
void PrintArrayPointer(int* pointerArray[], unsigned maximumElements)
{
    cout << "The Pointer Array of sorted pointer elements:" << endl;
    for (unsigned i = 0; i < maximumElements; i++)
        cout << *pointerArray[i] << setw(6);
    cout << endl << endl;;
}

//sorts the values in the array.
void SortElements(unsigned maximumElements, int* pointerArray[])
{
    for (unsigned i = 0; i < maximumElements; i++)
        for (unsigned j = i + 1; j < maximumElements; j++)
            if (*pointerArray[j] < *pointerArray[i])
                SwapIntPtr(pointerArray[j], pointerArray[i]);
}

//Swaps the pointer values to ints.
void SwapIntPtr(int*& x, int*& y)
{
    int* temp = x;
    x = y;
    y = temp;
}