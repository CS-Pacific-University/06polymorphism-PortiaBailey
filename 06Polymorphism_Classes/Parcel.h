#pragma once
#include <string>
#include <iostream>

using namespace std;

class Parcel {
	public:
		Parcel();
		int getWeight() const;
		int getDistance() const;
		bool getInsured() const;
		bool getRush() const;
		int getTid() const;
		void setCost(double);
		void read(istream& rcIn);
		void print(ostream& rcOut) const;
		double getCost() const;
		int getDeliveryDay() const;
	protected:
		int mTrackingId;
		string mTo;
		string mFrom;
		int mWeight;
		int mDistance;
		double mCost;
		bool mbRush;
		bool mbInsured;
};



