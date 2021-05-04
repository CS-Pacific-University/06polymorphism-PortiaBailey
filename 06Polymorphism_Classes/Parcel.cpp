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