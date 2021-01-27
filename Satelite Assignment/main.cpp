/*
* Module Name: Satelite Assignment
* Date: 09/30/2020
* Author: Rishi Villa
*
* Module Purpose: The lab simulates a program thar reads telemtry in a satelite
* and stores the input recieved into apporpriate place so it can be displayed later.
*
* Module design description
*
* Inputs:
* Enumerated field to determine type of input
* Status Information Values
* Exprimental Information Values
*
* Outputs
* Summary Information
* Current elements of information values in array
* Min and Max temp values
* Total Radiation counts
* Total Latchup event counts
*
* Modifications list: None
*
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdint.h>
#include <string>

using namespace std;

#define GroundStationOutputChannel cout

const string TELEMETRY_RECIEVER_INPUT_CHANNEL = "inputDataAntenna.txt";

enum class MESSAGE_ID { SATELLITE_INFO_MESSAGE = 1, EXPERIMENT_INFO_MESSAGE = 2, SEND_SUMM_INFO = 3 };
MESSAGE_ID messageID;

enum InformationType { SATELLITE_INFORMATION, EXPERIMENT_INFORMATION, EMPTY };
const uint8_t ARRAY_DATA_STORAGE_SIZE = 5;

// hold the different types of data from telemetry
struct SatelliteInformation
{
    float_t temperature;
    float_t voltage;
};

struct ExperimentInformation
{
    uint16_t radiationCount;
    uint16_t latchupEventsCount;
};

union MasterUnion
{
    SatelliteInformation satelliteInformation;
    ExperimentInformation experimentInformation;
};

struct MasterInformation
{
    InformationType infoType;
    MasterUnion masterUnion;
};

//The main function is responsible for applying thee structs to store data in the 
//appropriate places and displaying the output after formatting it.
int main()
{
    MasterInformation infoArray[ARRAY_DATA_STORAGE_SIZE];
    uint8_t initiaPosIndex = 0;
    MasterInformation masterInformation;
    ifstream telemetryInputAntennaReceiverChannel;

    telemetryInputAntennaReceiverChannel.open(TELEMETRY_RECIEVER_INPUT_CHANNEL, ios::in);

    if (telemetryInputAntennaReceiverChannel.fail())
    {
        cout << "File " << TELEMETRY_RECIEVER_INPUT_CHANNEL << " could not be opened!" << endl;
        cout << "Press enter key to continue..." << endl; cin.ignore(); cin.get();
        exit(EXIT_FAILURE);
    }
    GroundStationOutputChannel << setprecision(1) << fixed << showpoint;

    for (uint8_t i = 0; i < ARRAY_DATA_STORAGE_SIZE; i++)
    {
        infoArray[i].infoType = EMPTY;
    }

    uint16_t messageId;

    //Reading data for input stream
    while (telemetryInputAntennaReceiverChannel >> messageId)
    {
        messageID = MESSAGE_ID(messageId);
        switch (messageID)
        {
        case MESSAGE_ID::SATELLITE_INFO_MESSAGE:
            masterInformation.infoType = SATELLITE_INFORMATION;
            telemetryInputAntennaReceiverChannel >>
                masterInformation.masterUnion.satelliteInformation.temperature >>
                masterInformation.masterUnion.satelliteInformation.voltage;
            infoArray[initiaPosIndex] = masterInformation;
            initiaPosIndex = (initiaPosIndex == 4) ? 0 : ++initiaPosIndex;
            break; 

        case MESSAGE_ID::EXPERIMENT_INFO_MESSAGE:
            masterInformation.infoType = EXPERIMENT_INFORMATION;
            telemetryInputAntennaReceiverChannel >>
                masterInformation.masterUnion.experimentInformation.radiationCount >>
                masterInformation.masterUnion.experimentInformation.latchupEventsCount;
            infoArray[initiaPosIndex] = masterInformation;
            initiaPosIndex = (initiaPosIndex == 4) ? 0 : ++initiaPosIndex;
            break; 

        case MESSAGE_ID::SEND_SUMM_INFO:
            //information variables
            float_t minTemp = 212;          
            float_t maxTemp = -50;
            float_t minVolt = 100.0;              
            float_t maxVolt = 0.0;

            uint16_t totalRadiationCount = 0;
            uint16_t totalLatchupEventCount = 0;
            uint16_t SICount = 0;
            uint16_t EICount = 0;

            //send SI info where requested
            for (uint8_t index = 0; index < ARRAY_DATA_STORAGE_SIZE; index++)
            {
                switch (infoArray[index].infoType)
                {
                case SATELLITE_INFORMATION:
                    GroundStationOutputChannel <<
                        "Temperature : " <<
                        infoArray[index].masterUnion.satelliteInformation.temperature << endl <<
                        "Voltage     : " <<
                        infoArray[index].masterUnion.satelliteInformation.voltage << endl << endl;
                    SICount++;

                    //assign min and max values
                    if (maxTemp < infoArray[index].masterUnion.satelliteInformation.temperature)
                    {
                        maxTemp = infoArray[index].masterUnion.satelliteInformation.temperature;
                    }

                    if (minTemp > infoArray[index].masterUnion.satelliteInformation.temperature)
                    {
                        minTemp = infoArray[index].masterUnion.satelliteInformation.temperature;
                    }

                    if (maxVolt < infoArray[index].masterUnion.satelliteInformation.voltage)
                    {
                        maxVolt = infoArray[index].masterUnion.satelliteInformation.voltage;
                    }

                    if (minVolt > infoArray[index].masterUnion.satelliteInformation.voltage)
                    {
                        minVolt = infoArray[index].masterUnion.satelliteInformation.voltage;
                    }

                    break;

                case EXPERIMENT_INFORMATION:
                    GroundStationOutputChannel <<
                        "Radiation Count     : " <<
                        infoArray[index].masterUnion.experimentInformation.radiationCount << endl <<
                        "Latchup Event Count : " <<
                        infoArray[index].masterUnion.experimentInformation.latchupEventsCount << endl << endl;
                    EICount++;

                    totalRadiationCount += infoArray[index].masterUnion.experimentInformation.radiationCount;
                    totalLatchupEventCount += infoArray[index].masterUnion.experimentInformation.latchupEventsCount;
                    break; 

                case EMPTY:
                    
                    break; 

                } 
            } 

            //Output Stream Format
            GroundStationOutputChannel <<
                "Summary Information" << endl <<
                "-------------------" << endl <<
                "Number of Satellite  Information Records: " << SICount << endl <<
                "Number of Experiment Information Records: " << EICount << endl <<
                "Total Radiation Count     : " << totalRadiationCount << endl <<
                "Total Latchup Event Count : " << totalLatchupEventCount << endl <<
                "Maximum Temperature       : " << maxTemp << endl <<
                "Minimum Temperature       : " << minTemp << endl <<
                "Maximum Voltage           : " << maxVolt << endl <<
                "Minimum Voltage           : " << minVolt << endl << endl;

            
            cout << "Press the enter key to continue...   "; cin.ignore(); cin.get();
        } 
    } 

    return(EXIT_SUCCESS);
} 