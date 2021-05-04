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
Letter::Letter() : Parcel () {
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
int Letter::getDeliveryDay() {
	const int MINIMUM_DAYS = 1;
	int daysToDeliver = 0;
	const int MAX_MILES = 100;
	int days = 0;
	
	days = mDistance / MAX_MILES;

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
double Letter::getInsured(bool bInsured) {
	double insurance = 0.45;
	if (bInsured != mbInsured) {
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
double Letter::getRush(bool bRush) {
	double costAfterRush = 0.9;
	double rushAmount = 0.1;
	double addedCost = 0.00;
	if (bRush != mbRush) {
		addedCost = mCost * rushAmount;
		mCost = mCost * costAfterRush;
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
void Letter::read(istream& rcIn) {
	const double COST_PER_OUNCE = 0.45;
	rcIn >> mTrackingId >> mTo >> mFrom
		>> mWeight >> mDistance;
	mCost = mWeight * COST_PER_OUNCE;
}

double Letter::getCost() {
	double costPerOunce = 0.45;
	double insuranceCost = 0.45;
	double cost = 0.00;
	double rushAmount = 0.1;
	double costAfterRush = 0.00;

	cost = mWeight * costPerOunce;
	if (mbInsured == true) {
		cost += getInsured(mbInsured);
	}

	if (mbRush == true) {
		costAfterRush = cost * rushAmount;
		cost = cost + costAfterRush;
		cost += getRush(mbRush);
	}
	return cost;
}