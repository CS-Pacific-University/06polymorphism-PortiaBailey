#include "Postcard.h"
#include "Parcel.h"

#include <string>
using namespace std;

Postcard::Postcard() : Parcel() {
}

int Postcard::getDeliveryDay() const {
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

double Postcard::setInsured(bool bInsured) {
	double insurance = 0.15;
	if (bInsured != mbInsured) {
		mCost = mCost + insurance;
		mbInsured = true;
	}
	return insurance;
}

double Postcard::setRush(bool bRush) {
	double rush = 0.25;
	if (bRush != mbRush) {
		mCost = mCost + rush;
		mbRush = true;
	}
	return rush;
}

void Postcard::read(istream& rcIn) {
	const double COST_PER_OUNCE = 0.45;
	rcIn >> mTrackingId >> mTo >> mFrom
		>> mWeight >> mDistance >> mMessage;
	mCost = 0.15;
}

void Postcard::print(ostream& rcOut) const {
	rcOut << "TID: " << mTrackingId << "	From: " << mFrom << "	To: "
		<< mTo << " " << mMessage;
}