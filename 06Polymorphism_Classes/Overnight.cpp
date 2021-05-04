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