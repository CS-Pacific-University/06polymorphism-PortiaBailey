#include "Letter.h"
#include "Parcel.h"

#include <string>

using namespace std;

Letter::Letter() : Parcel() {
}

int Letter::getDeliveryDay() const {
	const int MINIMUM_DAYS = 1;
	int daysToDeliver = 0;
	const int MAX_MILES = 100;
	int days = 0;
	
	days = mDistance / MAX_MILES;

	if (days > MINIMUM_DAYS && mbRush == true) {
		days = days - 1;
	}
	return days;
} 

double Letter::setInsured(bool bInsured) {
	double insurance = 0.45;
	if (bInsured != mbInsured) {
		mCost = mCost + insurance;
		 mbInsured = true;
	}
	return insurance;
}

double Letter::setRush(bool bRush) {
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

void Letter::read(istream& rcIn) {
	const double COST_PER_OUNCE = 0.45;
	rcIn >> mTrackingId >> mTo >> mFrom
		>> mWeight >> mDistance;
	mCost = mWeight * COST_PER_OUNCE;
}