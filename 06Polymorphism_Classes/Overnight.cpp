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
Overnight::Overnight() : Parcel () {
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
int Overnight::getDeliveryDay() {
	const int MINIMUM_DAYS = 1;
	int daysToDeliver = 0;
	const int MAX_MILES = 1000;
	int days = 0;

	days = mDistance / MAX_MILES;

	if (days > MINIMUM_DAYS && mbRush == true) {
		days = days - 1;
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
double Overnight::getInsured(bool bInsured) {
	const double INSURANCE_AMOUNT = 0.25;
	double addedCost = 0.00;
	if (bInsured != mbInsured) {
		addedCost = mCost * INSURANCE_AMOUNT;
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
double Overnight::getRush(bool bRush) {
	double rushAmount = 0.75;
	double addedCost = 0.00;
	if (bRush != mbRush) {
		addedCost = mCost * rushAmount;
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
void Overnight::read(istream& rcIn) {
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
void Overnight::print(ostream& rcOut) const {
	rcOut << "TID: " << mTrackingId << "\tFrom: " << mFrom << "\tTo: "
		<< mTo << "\tOVERNIGHT!" << endl;
}

double Overnight::getCost() {
	const double COST_OVER_MAX = 20.0;
	const double COST_UNDER_MAX = 12.0;
	const int MAX_VOLUME = 100;
	const double COST_PER_OUNCE = 0.45;
	int distancePerDay = 1000;
	if (mVolume > MAX_VOLUME) {
		mCost = COST_OVER_MAX;
	}
	else {
		mCost = COST_UNDER_MAX;
	}
	if (mbRush == true) {
		mCost += getRush(mbRush);
	}
	if (mbInsured == true) {
		mCost += getInsured(mbInsured);
	}
	return mCost;
}