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