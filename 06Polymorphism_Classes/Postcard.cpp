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
Postcard::Postcard() : Parcel () {
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
int Postcard::getDeliveryDay() {
	const int MINIMUM_DAYS = 1;
	int daysToDeliver = 0;
	const int MAX_MILES = 10;
	int days = 0;
	
	days = mDistance / MAX_MILES;

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
double Postcard::getInsured(bool bInsured) {
	double insurance = 0.15;
	if (bInsured != mbInsured) {
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
double Postcard::getRush(bool bRush) {
	double rush = 0.25;
	if (bRush != mbRush) {
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
void Postcard::read(istream& rcIn) {
	const double COST_PER_OUNCE = 0.45;
	rcIn >> mTrackingId >> mTo >> mFrom
		>> mWeight >> mDistance >> mMessage;
	mCost = 0.15;
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
void Postcard::print(ostream& rcOut) const {
	rcOut << "TID: " << mTrackingId << "\tFrom: " << mFrom << "\tTo: "
		<< mTo << "\t" << mMessage << endl;
}

double Postcard::getCost() {
	double cost = 0.15;
	if (mbRush == true) {
		cost += getRush(mbRush);
	}
	if (mbInsured == true) {
		cost += getInsured(mbInsured);
	}

	return cost;
}