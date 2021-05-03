#include "Overnight.h"
#include "Parcel.h"
#include <string>

using namespace std;

Overnight::Overnight() : Parcel() {
}

int Overnight::getDeliveryDay() const {
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

double Overnight::setInsured(bool bInsured) {
	const double INSURANCE_AMOUNT = 0.25;
	const double COST_AFTER_INSURANCE = 0.75;
	double addedCost = 0.00;
	if (bInsured != mbInsured) {
		addedCost = mCost * INSURANCE_AMOUNT;
		mCost = mCost * COST_AFTER_INSURANCE;
		mbInsured = true;
	}
	return addedCost;
}

double Overnight::setRush(bool bRush) {
	double costAfterRush = 0.25;
	double rushAmount = 0.75;
	double addedCost = 0.00;
	if (bRush != mbRush) {
		addedCost = mCost * rushAmount;
		mCost = mCost * costAfterRush;
		mbRush = true;
	}
	return addedCost;
}

void Overnight::read(istream& rcIn) {
	const double COST_OVER_MAX = 20.0;
	const double COST_UNDER_MAX = 12.0;
	const int MAX_VOLUME = 100;
	const double COST_PER_OUNCE = 0.45;
	rcIn >> mTrackingId >> mTo >> mFrom
		>> mWeight >> mDistance >> mVolume;
	if (mVolume > MAX_VOLUME) {
		mCost = COST_OVER_MAX;
	}
	else {
		mCost = COST_UNDER_MAX;
	}
}

void Overnight::print(ostream& rcOut) const {
	rcOut << "TID: " << mTrackingId << "	From: " << mFrom << "	To: "
		<< mTo << " " << "OVERNIGHT";
}