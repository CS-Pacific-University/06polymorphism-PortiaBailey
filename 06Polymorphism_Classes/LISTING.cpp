//############################################################################
//Letter.h 
//############################################################################
//***************************************************************************
// File name:  Letter.h
// Author:     Portia Bailey
// Date:       4/29/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Header file for class letter
//***************************************************************************
#pragma once
#include "Parcel.h"
class Letter :
    public Parcel
{
  public:
    Letter();
    int getDeliveryDay ();
    double getInsured (bool);
    double getRush (bool);
    double getCost ();
    double getBaseCost ();

    void read (istream& rcIn);
    void print (ostream& rcOut);

    void setInsured (bool);
    void setRush (bool);
    void setCost (double);

  private:
};

   
  
 
//############################################################################
//Overnight.h 
//############################################################################
//***************************************************************************
// File name:  Overnight.h
// Author:     Portia Bailey
// Date:       4/27/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Header file for class Overnight
//***************************************************************************
#pragma once
#include "Parcel.h"
class Overnight :
    public Parcel
{
  public:
    Overnight ();
    int getDeliveryDay ();
    double getInsured (bool);
    double getRush (bool);
    double getBaseCost ();
    void read (istream&);
    void print (ostream&);
    double getCost ();
    void setInsured (bool);
    void setRush (bool);
    void setCost (double);

  private:
    int mVolume;
};

   
  
 
//############################################################################
//Parcel.h 
//############################################################################
//***************************************************************************
// File name:  Parcel.h
// Author:     Portia Bailey
// Date:       4/29/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Header file for base class Parcel
//***************************************************************************
#pragma once
#include <string>
#include <iostream>

using namespace std;

class Parcel {
	public:
		Parcel (int TID = 0, int weight = 0, int distance = 0, 
					 string to = "", string from = "");
		int getWeight () const;
		int getDistance () const;
		int getTid () const;

		virtual double getInsured (bool) = 0;
		virtual double getRush (bool) = 0;
		virtual double getCost () = 0;
		virtual double getBaseCost () = 0;
		virtual int getDeliveryDay () = 0;

		virtual void setInsured (bool) = 0;
		virtual void setRush (bool) = 0;
		virtual void setCost (double) = 0;

		virtual void read (istream& rcIn);
		virtual void print (ostream& rcOut);
		
	protected:
		int mTrackingId;
		string mTo;
		string mFrom;
		int mWeight;
		int mDistance;
		double mCost;
		bool mbRush = false;
		bool mbInsured = false;
};



   
  
 
//############################################################################
//Postcard.h 
//############################################################################
//***************************************************************************
// File name:  Postcard.h
// Author:     Portia Bailey
// Date:       4/29/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Header file for class postcard
//***************************************************************************
#pragma once
#include "Parcel.h"
class Postcard :
    public Parcel
{
  public:
    Postcard();
    int getDeliveryDay ();
    double getInsured (bool);
    double getRush (bool);
    double getCost ();
    double getBaseCost ();
    void read (istream& rcIn);
    void print (ostream&);
    void setInsured (bool);
    void setRush (bool);
    void setCost (double);

  private:
    string mMessage;
};

   
  
 
//############################################################################
//Letter.cpp 
//############################################################################
//***************************************************************************
// File name:  Letter.cpp
// Author:     Portia Bailey
// Date:       4/27/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Defines functions for the subclass Letter
//***************************************************************************
#include "Letter.h"
#include "Parcel.h"

#include <string>

using namespace std;

//***************************************************************************
// Constructor:    Letter
//
// Description:		 Letter default constructor
//
// Parameters:		 None
//
// Returned:			 None
//***************************************************************************
Letter::Letter () : Parcel () {
}

//***************************************************************************
// Function:    getDeliveryDay
//
// Description: Calculates amount of days to deliver
//
// Parameters:  None
//
// Returned:    days - days to deliver
//***************************************************************************
int Letter::getDeliveryDay () {
	const int MINIMUM_DAYS = 1;
	const int MAX_MILES = 100;
	int days = 0;
	
	days = mDistance / MAX_MILES;
	if (days <= MINIMUM_DAYS) {
		days = MINIMUM_DAYS;
	}

	if (days > MINIMUM_DAYS && mbRush == true) {
		days = days - MINIMUM_DAYS;
	}

	return days;
} 

//***************************************************************************
// Function:    setInsured
//
// Description: sets insurance amount 
//
// Parameters:  bInsured - bool to determine if parcel is insured
//
// Returned:    insurance - amount of insurance cost added
//***************************************************************************
double Letter::getInsured (bool bInsured) {
	double insurance = 0.45;

	if ((bInsured == true && mbInsured == false) || mbInsured == true) {
		mCost = mCost + insurance;
		mbInsured = true;
	}

	return insurance;
}

//***************************************************************************
// Function:    getRush
//
// Description: sets rush amount 
//
// Parameters:  bRush - bool to determine if parcel is rushed
//
// Returned:    rush - amount of rush cost added
//***************************************************************************
double Letter::getRush (bool bRush) {
	double rushAmount = 0.1;
	double addedCost = 0.00;
	double cost = 0.00;
	cost = getBaseCost ();
	if ((bRush == true && mbRush == false) || mbRush == true) {
		addedCost = cost * rushAmount;
		mbRush = true;
	}

	return addedCost;
}

//***************************************************************************
// Function:    read
//
// Description: reads data from input file 
//
// Parameters:  rcIn - input file
//
// Returned:    none
//***************************************************************************
void Letter::read (istream& rcIn) {
	rcIn >> mTrackingId >> mTo >> mFrom >> mWeight >> mDistance;
}

//***************************************************************************
// Function:    getCost
//
// Description: calculates cost of postcard
//
// Parameters:  none
//
// Returned:    cost - cost of parcel
//***************************************************************************
double Letter::getCost () {
	double cost = 0.00;
	double rushAmount = 0.1;
	double costAfterRush = 0.00;

	cost = getBaseCost ();
	if (mbInsured == true) {
		cost += getInsured (mbInsured);
	}

	if (mbRush == true) {
		cost += getRush (mbRush);
	}
	return cost;
}

//***************************************************************************
// Function:    print
//
// Description: prints data to output stream
//
// Parameters:  rcOut - output 
//
// Returned:    none
//***************************************************************************
void Letter::print (ostream& rcOut) {
	rcOut << "TID: " << mTrackingId << "\tFrom: " << mFrom << "\tTo: "
				<< mTo;
	if (mbRush == true) {
		cout << "\tRUSH";
	}

	if (mbInsured == true) {
		cout << "\tINSURED";
	}

	cout << endl;
}

//***************************************************************************
// Function:    setInsured
//
// Description: sets bInsured to false
//
// Parameters:  bInsured - bool that gets set to false if not insured
//
// Returned:    none
//***************************************************************************
void Letter::setInsured (bool bInsured) {
	bInsured = false;
}

//***************************************************************************
// Function:    setRush
//
// Description: sets bRush to false
//
// Parameters:  bRush - bool that gets set to false if parcel is not rushed
//
// Returned:    none
//***************************************************************************
void Letter::setRush (bool bRush) {
	bRush = false;
}

//***************************************************************************
// Function:    setCost
//
// Description: sets member mCost = cost of parcel
//
// Parameters:  cost - cost of parcel
//
// Returned:    none
//***************************************************************************
void Letter::setCost (double cost) {
	mCost = cost;
}

//***************************************************************************
// Function:    getBaseCost
//
// Description: gets the base cost of a parcel without insurance or rush
//
// Parameters:  none
//
// Returned:    base cost of the letter
//***************************************************************************
double Letter::getBaseCost () {
	const double COST_PER_OUNCE = 0.45;
	return mWeight * COST_PER_OUNCE;
}   
  
 
//############################################################################
//Overnight.cpp 
//############################################################################
//***************************************************************************
// File name:  Overnight.cpp
// Author:     Portia Bailey
// Date:       4/27/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Defines functions for the subclass Overnight
//***************************************************************************
#include "Overnight.h"
#include "Parcel.h"
#include <string>

using namespace std;

//***************************************************************************
// Constructor:    Overnight
//
// Description:		 overnight default constructor
//
// Parameters:		 None
//
// Returned:			 None
//***************************************************************************
Overnight::Overnight () : Parcel () {
	mVolume = 0;
}

//***************************************************************************
// Function:    getDeliveryDay
//
// Description: Calculates amount of days to deliver
//
// Parameters:  None
//
// Returned:    days - days to deliver
//***************************************************************************
int Overnight::getDeliveryDay () {
	const int MILES_PER_DAY = 1000;
	const int ONE_DAY = 1;
	const int TWO_DAYS = 2;
	int days = 0;

	if (mbRush == true && mDistance <= MILES_PER_DAY) {
		days = ONE_DAY;
	}
	else {
		days = TWO_DAYS;
	}

	return days;
}

//***************************************************************************
// Function:    getInsured
//
// Description: gets insurance amount 
//
// Parameters:  bInsured - bool to determine if parcel is insured
//
// Returned:    insurance - amount of insurance cost added
//***************************************************************************
double Overnight::getInsured (bool bInsured) {
	const double INSURANCE_AMOUNT = 0.25;
	double addedCost = 0.00;
	double cost = 0.00;
	
	cost = getBaseCost ();
	if ((bInsured == true && mbInsured == false) || mbInsured == true) {
		addedCost = cost * INSURANCE_AMOUNT;
		mbInsured = true;
	}
	return addedCost;
}

//***************************************************************************
// Function:    getRush
//
// Description: gets rush amount 
//
// Parameters:  bRush - bool to determine if parcel is rushed
//
// Returned:    rush - amount of rush cost added
//***************************************************************************
double Overnight::getRush (bool bRush) {
	const double RUSH_AMOUNT = 0.75;
	double addedCost = 0.00;
	double cost = 0.00;

	cost = getBaseCost ();
	if ((bRush == true && mbRush == false) || mbRush == true) {
		addedCost = cost * RUSH_AMOUNT;
		mbRush = true;
	}

	return addedCost;
}

//***************************************************************************
// Function:    read
//
// Description: reads data from input file 
//
// Parameters:  rcIn - input file
//
// Returned:    none
//***************************************************************************
void Overnight::read (istream& rcIn) {
	rcIn >> mTrackingId >> mTo >> mFrom
		>> mWeight >> mDistance >> mVolume;
}

//***************************************************************************
// Function:    print
//
// Description: prints data to output stream
//
// Parameters:  rcOut - output 
//
// Returned:    none
//***************************************************************************
void Overnight::print (ostream& rcOut) {
	Parcel::print (rcOut);
	if (mbRush == true) {
		cout << "\tRUSH";
	}

	if (mbInsured == true) {
		cout << "\tINSURED";
	}

	cout << "\t" << "OVERNIGHT!" << endl;
}

//***************************************************************************
// Function:    getCost
//
// Description: calculates cost of postcard
//
// Parameters:  none
//
// Returned:    cost - cost of parcel
//***************************************************************************
double Overnight::getCost () {
	double cost = 0.00;
	cost = getBaseCost() + getInsured(mbInsured) + getRush(mbRush);
	return cost;
}

//***************************************************************************
// Function:    setInsured
//
// Description: sets bInsured to false
//
// Parameters:  bInsured - bool that gets set to false if not insured
//
// Returned:    none
//***************************************************************************
void Overnight::setInsured (bool bInsured) {
	bInsured = false;
}

//***************************************************************************
// Function:    setRush
//
// Description: sets bRush to false
//
// Parameters:  bRush - bool that gets set to false if parcel is not rushed
//
// Returned:    none
//***************************************************************************
void Overnight::setRush (bool bRush) {
	bRush = false;
}

//***************************************************************************
// Function:    setCost
//
// Description: sets member mCost = cost of parcel
//
// Parameters:  cost - cost of parcel
//
// Returned:    none
//***************************************************************************
void Overnight::setCost (double cost) {
	mCost = cost;
}

//***************************************************************************
// Function:    getBaseCost
//
// Description: gets the base cost of a parcel without insurance or rush
//
// Parameters:  none
//
// Returned:    BASE_COST - initial cost of parcel
//***************************************************************************
double Overnight::getBaseCost () {
	const double COST_OVER_MAX = 20.0;
	const double COST_UNDER_MAX = 12.0;
	const int VOLUME = 100;
	double cost = 0.00;

	if (mVolume > VOLUME) {
		cost = COST_OVER_MAX;
	}
	else {
		cost = COST_UNDER_MAX;
	}

	return cost;
}   
  
 
//############################################################################
//Parcel.cpp 
//############################################################################
//***************************************************************************
// File name:  Parcel.cpp
// Author:     Portia Bailey
// Date:       4/27/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Defines functions for the class Parcel
//***************************************************************************
#include "Parcel.h"

//***************************************************************************
// Constructor:    Parcel
//
// Description:		 Parcel default constructor
//
// Parameters:		 None
//
// Returned:			 None
//***************************************************************************
Parcel::Parcel (int TID, int weight, int distance, string to, string from) {
	mTrackingId = TID;
	mTo = to;
	mFrom = from;
	mWeight = weight;
	mDistance = distance;
	mbInsured = false;
	mbRush = false;
}

//***************************************************************************
// Function:    getWeight
//
// Description: gets member variable weight
//
// Parameters:  None
//
// Returned:    mWeight - weight of parcel
//***************************************************************************
int Parcel::getWeight () const {
	return mWeight;
}

//***************************************************************************
// Function:    getDistance
//
// Description: gets distance parcel travels
//
// Parameters:  None
//
// Returned:    mDistance - distance parcel travels
//***************************************************************************
int Parcel::getDistance () const {
	return mDistance;
}

//***************************************************************************
// Function:    getTid
//
// Description: gets the tracking number of the parcel
//
// Parameters:  None
//
// Returned:    mTrackingId - tracking ID of parcel
//***************************************************************************
int Parcel::getTid () const {
	return mTrackingId;
}

//***************************************************************************
// Function:    setCost
//
// Description: allows for a modification of cost of parcel
//
// Parameters:  None
//
// Returned:    none
//***************************************************************************
void Parcel::setCost (double cost) {
	mCost = cost;
}

//***************************************************************************
// Function:    read
//
// Description: reads in data from file
//
// Parameters:  rcIn - input file
//
// Returned:    none
//***************************************************************************
void Parcel::read (istream& rcIn) {
	rcIn >> mTrackingId >> mTo >> mFrom
			 >> mWeight >> mDistance;
}

//***************************************************************************
// Function:    print
//
// Description: prints to stream
//
// Parameters:  rcOut - output stream
//
// Returned:    none
//***************************************************************************
void Parcel::print (ostream& rcOut) {
	rcOut << "TID: " << mTrackingId << "\tFrom: " << mFrom << "\tTo: "
		<< mTo;
}   
  
 
//############################################################################
//Postcard.cpp 
//############################################################################
//***************************************************************************
// File name:  Postcard.cpp
// Author:     Portia Bailey
// Date:       4/27/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Defines functions for the subclass Postcard
//***************************************************************************
#include "Postcard.h"
#include "Parcel.h"

#include <string>
#include <iostream>
using namespace std;

//***************************************************************************
// Constructor:    Postcard
//
// Description:		 Postcard default constructor
//
// Parameters:		 None
//
// Returned:			 None
//***************************************************************************
Postcard::Postcard () : Parcel () {
	mMessage = "";
}

//***************************************************************************
// Function:    getDeliveryDay
//
// Description: Calculates amount of days to deliver
//
// Parameters:  None
//
// Returned:    days - days to deliver
//***************************************************************************
int Postcard::getDeliveryDay () {
	const int MINIMUM_DAYS = 1;
	int daysToDeliver = 0;
	const int MAX_MILES = 10;
	int days = 0;
	int zeroDays = 0;
	
	days = mDistance / MAX_MILES;
	if (days == zeroDays) {
		days += MINIMUM_DAYS;
	}

	if (days > MINIMUM_DAYS && mbRush == true) {
		days = days - 1;
	}
	return days;
}

//***************************************************************************
// Function:    setInsured
//
// Description: sets insurance amount 
//
// Parameters:  bInsured - bool to determine if parcel is insured
//
// Returned:    insurance - amount of insurance cost added
//***************************************************************************
double Postcard::getInsured (bool bInsured) {
	double insurance = 0.15;
	if ((bInsured == true && mbInsured == false) || mbInsured == true) {
		mbInsured = true;
	}
	return insurance;
}

//***************************************************************************
// Function:    getRush
//
// Description: sets rush amount 
//
// Parameters:  bRush - bool to determine if parcel is rushed
//
// Returned:    rush - amount of rush cost added
//***************************************************************************
double Postcard::getRush (bool bRush) {
	double rush = 0.25;
	if ((bRush == true && mbRush == false) || mbRush == true) {
		mbRush = true;
	}
	return rush;
}

//***************************************************************************
// Function:    read
//
// Description: reads data from input file 
//
// Parameters:  rcIn - input file
//
// Returned:    none
//***************************************************************************
void Postcard::read (istream& rcIn) {
	rcIn >> mTrackingId >> mTo >> mFrom >> mWeight >> mDistance >> mMessage;
}

//***************************************************************************
// Function:    print
//
// Description: prints data to output stream
//
// Parameters:  rcOut - output 
//
// Returned:    none
//***************************************************************************
void Postcard::print (ostream& rcOut) {
	Parcel::print (rcOut);

	if (mbInsured == true) {
		cout << "\tINSURED";
	}

	if (mbRush == true) {
		cout << "\tRUSH";
	}

	cout << "\t" << mMessage << endl;
}

//***************************************************************************
// Function:    getCost
//
// Description: calculates cost of postcard
//
// Parameters:  none
//
// Returned:    cost - cost of parcel
//***************************************************************************
double Postcard::getCost () {
	double cost = 0.00;
	cost = getBaseCost ();
	if (mbRush == true) {
		cost += getRush (mbRush);
	}
	if (mbInsured == true) {
		cost += getInsured (mbInsured);
	}

	return cost;
}

//***************************************************************************
// Function:    setInsured
//
// Description: sets bInsured to false
//
// Parameters:  bInsured - bool that gets set to false if not insured
//
// Returned:    none
//***************************************************************************
void Postcard::setInsured (bool bInsured) {
	bInsured = false;
}

//***************************************************************************
// Function:    setRush
//
// Description: sets bRush to false
//
// Parameters:  bRush - bool that gets set to false if parcel is not rushed
//
// Returned:    none
//***************************************************************************
void Postcard::setRush (bool bRush) {
	bRush = false;
}

//***************************************************************************
// Function:    setCost
//
// Description: sets member mCost = cost of parcel
//
// Parameters:  cost - cost of parcel
//
// Returned:    none
//***************************************************************************
void Postcard::setCost (double cost) {
	mCost = cost;
}

//***************************************************************************
// Function:    getBaseCost
//
// Description: gets the base cost of a parcel without insurance or rush
//
// Parameters:  none
//
// Returned:    BASE_COST - initial cost of parcel
//***************************************************************************
double Postcard::getBaseCost () {
	double BASE_COST = 0.15;
	return BASE_COST;
}   
  
 
//############################################################################
//Source.cpp 
//############################################################################
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
const int MAX_PARCELS = 25;

bool openFileForRead (ifstream& rcInFile, string fileName, bool &bOpened);
void printMenu ();
void getChoice (int &menuChoice);
void printParcels (Parcel* apcParcels[], int& numParcels);
void getTID (int &trackingID);
void deliverParcel (Parcel* apcParcels[], int trackingID);
void insureParcel (Parcel* apcParcels[], int trackingID, bool bInsured);
void rushParcel (Parcel* apcParcels[], int trackingID, bool bRush);
bool checkTID (Parcel* apcParcels[], int TID, int& numParcels);
void readIntoArray (Parcel* apcParcels[], int& numParcels, ifstream &inFile);

//***************************************************************************
// Function:    main
//
// Description: allows user to interact with data
//
// Parameters:  none
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main  () {
  const string INPUT_FILE = "parcels.txt";
  const int ZERO_PARCELS = 0;
  int choice = 0;
  int numParcels = 0;
  int TID = 0;
  char typeOfParcel;
  bool bFileOpened = false;
  bool bIsInsured = false;
  bool bRush = false;
  ifstream rcInFile;
  Parcel** apcParcels = new Parcel * [MAX_PARCELS];

  cout << "Mail Simulator!\n\n";

  openFileForRead (rcInFile, INPUT_FILE, bFileOpened);

   if (bFileOpened == true) {
     readIntoArray  (apcParcels, numParcels, rcInFile);
    }

   rcInFile.close();

   cout << fixed << setprecision(2);

   if (numParcels != ZERO_PARCELS) {
     do {
       do {
         printMenu  ();
         getChoice  (choice);
         cout << endl;
       } while (CHOICE_ONE != choice && CHOICE_TWO != choice &&
         CHOICE_THREE != choice && CHOICE_FOUR != choice &&
         CHOICE_FIVE != choice);

       if (choice == CHOICE_ONE) {
         printParcels (apcParcels, numParcels);
       }
       else if (choice == CHOICE_TWO) {
         bool bIsInsured = true;
         getTID(TID);

         if (checkTID (apcParcels, TID, numParcels) == true) {
           insureParcel (apcParcels, TID, bIsInsured);
         }
       }
       else if (choice == CHOICE_THREE) {
         getTID (TID);
         if (checkTID (apcParcels, TID, numParcels) == true) {
           rushParcel (apcParcels, TID, bRush);
         }
       }
       else if (choice == CHOICE_FOUR) {
         getTID (TID);
         if (checkTID (apcParcels, TID, numParcels) == true) {
           deliverParcel  (apcParcels, TID);
         }
       }
       else if (choice == CHOICE_FIVE) {
       }

     } while (choice != CHOICE_FIVE);
   }
   else {
     cout << "You have no parcels to deliver!";
   }

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
bool openFileForRead  (ifstream& rcInFile, string INPUT_FILE, bool &bOpened) {
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
// Function:    readIntoArray
//
// Description: reads information from file into array of parcel pointers
//
// Parameters:  apcParcels - array of parcel pointers
//              numParcels - number of parcels in file
//              inFile     - input file
//
// Returned:    none
//***************************************************************************
void readIntoArray (Parcel* apcParcels[],int& numParcels, ifstream &inFile) {
  const char LETTER = 'L';
  const char POSTCARD = 'P';
  const char OVERNIGHT = 'O';
  char typeOfParcel;

  while (!inFile.eof() && numParcels < MAX_PARCELS) {
    inFile >> typeOfParcel;

    if (typeOfParcel == LETTER) {
      apcParcels[numParcels] = new Letter;
      apcParcels[numParcels]->read (inFile);
    }
    else if (typeOfParcel == POSTCARD) {
      apcParcels[numParcels] = new Postcard;
      apcParcels[numParcels]->read (inFile);
    }
    else if (typeOfParcel == OVERNIGHT) {
      apcParcels[numParcels] = new Overnight;
      apcParcels[numParcels]->read (inFile);
    }

    ++numParcels;
  }
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
void printMenu () {
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
void getChoice (int &menuChoice) {
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
void printParcels (Parcel* apcParcels[], int& numParcels) {
  for (int i = 0; i < numParcels; i++) {
    if (apcParcels[i] != nullptr) {
      apcParcels[i]->print (cout);
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
void getTID (int &trackingID) {
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
void deliverParcel (Parcel *apcParcels[], int trackingID) {
  int index = trackingID - CORRECT_INDEX;
  cout << "Delivered!\n";
  cout << apcParcels[index]->getDeliveryDay () << " Day, $";
  cout << apcParcels[index]->getCost () << endl;
  apcParcels[index]->print (cout);
  cout << endl;
  delete apcParcels[index];
  apcParcels[index] = nullptr;
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
  cout << apcParcels[index]->getInsured (bInsured) << endl;
  apcParcels[index]->print (cout);
  cout << endl;
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
  if (apcParcels[index] != nullptr) {
    cout << "Added Rush for $";
    cout << apcParcels[index]->getRush (bRush);
    cout << endl;
    apcParcels[index]->print (cout);
    cout << endl;
  }
}

//***************************************************************************
// Function:    checkTID
//
// Description: checks to see if user entered existing TID
//
// Parameters:  apcParcels - array of parcel pointers
//              TID        - tracking ID of parcel
//              numParcels - number of parcels in array
//
// Returned:    bGoodTID - true if TID exits, false if not
//***************************************************************************
bool checkTID(Parcel* apcParcels[], int TID, int& numParcels) {
  bool bGoodTID = false;
  for (int i = 0; i < numParcels; ++i) {
    if (apcParcels[i] != nullptr) {
      if (apcParcels[i]->getTid () == TID) {
        bGoodTID = true;
      }
    }
  }

  return bGoodTID;
}

   
  
 
