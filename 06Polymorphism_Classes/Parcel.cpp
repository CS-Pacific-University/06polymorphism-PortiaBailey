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
Parcel::Parcel(int TID, int weight, int distance, string to, string from) {
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
int Parcel::getWeight() const {
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
int Parcel::getDistance() const {
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
int Parcel::getTid() const {
	return mTrackingId;
}

//***************************************************************************
// Function:    getInsured
//
// Description: bool that is true if parcel is insured and false if not
//
// Parameters:  None
//
// Returned:    mbInsured - true if parcel is insured, false if not insured
//***************************************************************************
//bool Parcel::getInsured() const {
	//return mbInsured;
//}

//***************************************************************************
// Function:    getDeliveryDay
//
// Description: Calculates amount of days to deliver
//
// Parameters:  None
//
// Returned:    days - days to deliver
//***************************************************************************
//bool Parcel::getRush() const {
	//return mbRush;
//}

//***************************************************************************
// Function:    setCost
//
// Description: allows for a modification of cost of parcel
//
// Parameters:  None
//
// Returned:    none
//***************************************************************************
void Parcel::setCost(double cost) {
	mCost = cost;
}

//***************************************************************************
// Function:    getCost
//
// Description: gets cost of parcel
//
// Parameters:  None
//
// Returned:    mCost - cost of parcel
//***************************************************************************
//double Parcel::getCost() const {
	//return mCost;
//}

//***************************************************************************
// Function:    getDeliveryDay
//
// Description: amount of days to deliver
//
// Parameters:  None
//
// Returned:    deliveryDay - days to deliver
//***************************************************************************
//int Parcel::getDeliveryDay() const {
	//int deliveryDay = 0;
	//return deliveryDay;
//}

//***************************************************************************
// Function:    read
//
// Description: reads in data from file
//
// Parameters:  rcIn - input file
//
// Returned:    none
//***************************************************************************
void Parcel::read(istream& rcIn) {
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
void Parcel::print(ostream& rcOut) const {
	rcOut << "TID: " << mTrackingId << "\tFrom: " << mFrom << "\tTo: "
		<< mTo << endl;
}