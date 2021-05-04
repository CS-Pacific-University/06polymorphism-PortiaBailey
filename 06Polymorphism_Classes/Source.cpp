//***************************************************************************
// File name:  Source.cpp
// Author:     Portia Bailey
// Date:       4/29/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Read in a file of parcels and allow the user to select choices
//             from menu to interact with data
//***************************************************************************
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>

#include "Parcel.h"
#include "Postcard.h"
#include "Letter.h"
#include "Overnight.h"

using namespace std;

const int CHOICE_ONE = 1;
const int CHOICE_TWO = 2;
const int CHOICE_THREE = 3;
const int CHOICE_FOUR = 4;
const int CHOICE_FIVE = 5;
const int CORRECT_INDEX = 1;

bool openFileForRead(ifstream& rcInFile, string fileName, bool &bOpened);
void printMenu();
void getChoice(int &menuChoice);
void printParcels(Parcel* apcParcels[], int& numParcels);
void getTID(int &trackingID);
void deliverParcel(Parcel* apcParcels[], int trackingID);
void insureParcel(Parcel* apcParcels[], int trackingID, bool bInsured);
void rushParcel(Parcel* apcParcels[], int trackingID);
bool checkTID(Parcel* apcParcels[], int TID, int& numParcels);

//***************************************************************************
// Function:    main
//
// Description: allows user to interact with data
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main() {
  const string INPUT_FILE = "parcels.txt";
  const int MAX_PARCELS = 25;
  const char LETTER = 'L';
  const char POSTCARD = 'P';
  const char OVERNIGHT = 'O';
  int choice = 0;
  int numParcels = 0;
  int TID = 0;
  ifstream rcInFile;
  char typeOfParcel;
  bool bFileOpened = false;
  bool bIsInsured = false;
  bool bRush = false;
  Parcel** apcParcels = new Parcel * [MAX_PARCELS];

  cout << "Mail Simulator!\n\n";

  openFileForRead(rcInFile, INPUT_FILE, bFileOpened);

   if (bFileOpened == true) {
     while (!rcInFile.eof() && numParcels < MAX_PARCELS) {
       rcInFile >> typeOfParcel;

       if (typeOfParcel == LETTER) {
          apcParcels[numParcels] = new Letter;
          apcParcels[numParcels]->read(rcInFile);
        }
        else if (typeOfParcel == POSTCARD) {
          apcParcels[numParcels] = new Postcard;
          apcParcels[numParcels]->read(rcInFile);
        }
        else if (typeOfParcel == OVERNIGHT) {
          apcParcels[numParcels] = new Overnight;
          apcParcels[numParcels]->read(rcInFile);
        }

        ++numParcels;
     }
    }

   rcInFile.close();
   cout << fixed << setprecision(2);

  do {
    do {
      printMenu();
      getChoice(choice);
      cout << endl;
    } while (CHOICE_ONE != choice && CHOICE_TWO != choice &&
      CHOICE_THREE != choice && CHOICE_FOUR != choice &&
      CHOICE_FIVE != choice);

    if (choice == CHOICE_ONE) {
      printParcels(apcParcels, numParcels);
    }
    else if (choice == CHOICE_TWO) {
      bool bIsInsured = true;
      getTID(TID);
      cout << "TID> ";
      cin >> TID;
      insureParcel(apcParcels, TID, bIsInsured);
    }
    else if (choice == CHOICE_THREE) {
      getTID(TID);
      if (checkTID(apcParcels, TID, numParcels) == true) {
        rushParcel(apcParcels, TID);
      }
    }
    else if (choice == CHOICE_FOUR) {
      getTID(TID);
      deliverParcel(apcParcels, TID);
    }
    else if (choice == CHOICE_FIVE) {

    }
  } while (choice != CHOICE_FIVE);

  for (int i = 0; i < MAX_PARCELS; i++) {
    if (apcParcels[i] != nullptr) {
      delete apcParcels[i];
    }
  }

  return EXIT_SUCCESS;
}

//***************************************************************************
// Function:    openFileForRead
//
// Description: opens input file
//
// Parameters:  rcInFile - input file
//              INPUT_FILE - file name
//              bOpened - bool thats true if file opens and false if not
//
// Returned:    bOpened - bool thats true if file opens and false if not
//***************************************************************************
bool openFileForRead(ifstream& rcInFile, string INPUT_FILE, bool &bOpened) {
  rcInFile.open(INPUT_FILE);
  if (!rcInFile.is_open()) {
    cout << "Error opening file.";
  }
  else {
    bOpened = true;
  }
  return bOpened;
}

//***************************************************************************
// Function:    printMenu
//
// Description: prints choice menu to ostream
//
// Parameters:  None
//
// Returned:    none
//***************************************************************************
void printMenu() {
  cout << "1. Print All\n" << "2. Add Insurance\n";
  cout << "3. Add Rush\n" << "4. Deliver\n" << "5. Quit\n\n";
}

//***************************************************************************
// Function:    getChoice
//
// Description: asks user for menu choice
//
// Parameters:  menuChoice - choice made by user
//
// Returned:    none
//***************************************************************************
void getChoice(int &menuChoice) {
 cout << "Choice> ";
 cin >> menuChoice;
}

//***************************************************************************
// Function:    printParcels
//
// Description: prints all the parcels in the array
//
// Parameters:  apcParcels - array of pointer parcels
//              numParcels - number of parcels in array
//
// Returned:    days - days to deliver
//***************************************************************************
void printParcels(Parcel* apcParcels[], int& numParcels) {
  for (int i = 0; i < numParcels; i++) {
    if (apcParcels[i] != nullptr) {
      apcParcels[i]->print(cout);
    }
  }

  cout << endl;
}

//***************************************************************************
// Function:    getTID
//
// Description: gets tracking id of parcel from user
//
// Parameters:  trackingID - tracking ID of parcel
//
// Returned:    none
//***************************************************************************
void getTID(int &trackingID) {
  cout << "TID> ";
  cin >> trackingID;
}

//***************************************************************************
// Function:    deliverParcel
//
// Description: delivers parcel
//
// Parameters:  apcParcels - array of parcel pointers
//              trackingID - tracking ID of parcel
//
// Returned:    none
//***************************************************************************
void deliverParcel(Parcel *apcParcels[], int trackingID) {
  int index = trackingID - CORRECT_INDEX;
  cout << "Delivered!\n";
  apcParcels[index]->getDeliveryDay();
  cout << ", ";
  apcParcels[index]->getCost();
  apcParcels[index]->print(cout);
}

//***************************************************************************
// Function:    insureParcel
//
// Description: outputs parcel insurance
//
// Parameters:  apcParcels - array of parcel pointers
//              trackingID - tracking ID of parcel
//
// Returned:    none
//***************************************************************************
void insureParcel(Parcel* apcParcels[], int trackingID, bool bInsured) {
  int index = trackingID - CORRECT_INDEX;
  bInsured = true;
  cout << "Added Insurance for $";
  apcParcels[index]->getInsured(bInsured);
}

//***************************************************************************
// Function:    rushParcel
//
// Description: outputs rush added to parcel
//
// Parameters:  apcParcels - array of parcel pointers
//              trackingID - tracking ID of parcel
//
// Returned:    none
//***************************************************************************
void rushParcel(Parcel* apcParcels[], int trackingID, bool bRush) {
  bRush = true;
  int index = trackingID - CORRECT_INDEX;
  cout << "Added Rush for $";
  apcParcels[index]->getRush(bRush);
}

//***************************************************************************
// Function:    checkTID
//
// Description: checks to see if user entered existing TID
//
// Parameters:  apcParcels - array of parcel pointers
//              TID - tracking ID of parcel
//              numParcels - number of parcels in array
//
// Returned:    bGoodTID - true if TID exits, false if not
//***************************************************************************
bool checkTID(Parcel* apcParcels[], int TID, int& numParcels) {
  bool bGoodTID = false;
  for (int i = 0; i < numParcels; ++i) {
    if (apcParcels[i]->getTid() == TID && apcParcels[i] != nullptr) {
      bGoodTID = true;
    }
  }
  return bGoodTID;
}

