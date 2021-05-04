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



