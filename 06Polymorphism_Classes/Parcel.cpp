#include "Parcel.h"

Parcel::Parcel() {
	mTrackingId = 0;
	mTo = nullptr;
	mFrom = nullptr;
	mWeight = 0;
	mDistance = 0;
	mbInsured = false;
	mbRush = false;
}

int Parcel::getWeight() const {
	return mWeight;
}

int Parcel::getDistance() const {
	return mDistance;
}

int Parcel::getTid() const {
	return mTrackingId;
}

bool Parcel::getInsured() const {
	return mbInsured;
}

bool Parcel::getRush() const {
	return mbRush;
}

void Parcel::setCost(double cost) {
	mCost = cost;
}

double Parcel::getCost() const {
	return mCost;
}

int Parcel::getDeliveryDay() const {
	int deliveryDay = 0;
	return deliveryDay;
}

void Parcel::read(istream& rcIn) {
	rcIn >> mTrackingId >> mTo >> mFrom
		>> mWeight >> mDistance;
}

void Parcel::print(ostream& rcOut) const {
	rcOut << "TID: " << mTrackingId << "	From: " << mFrom << "	To: "
		<< mTo;
}