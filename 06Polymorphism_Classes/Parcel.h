#pragma once
#include <string>
#include <iostream>

using namespace std;

class Parcel {
	public:
		Parcel(int TID = 0, int weight = 0, int distance = 0, 
						string to = "", string from = "");
		int getWeight() const;
		int getDistance() const;
		int getTid() const;

		virtual double getInsured(bool) const = 0;
		virtual double getRush(bool) const = 0;
		virtual double getCost() const = 0;
		virtual int getDeliveryDay() const = 0;

		virtual void setInsured(bool) const = 0;
		virtual void setRush(bool) const = 0;
		virtual void setCost(double);

		virtual void read(istream& rcIn);
		virtual void print(ostream& rcOut) const;
		
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



