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