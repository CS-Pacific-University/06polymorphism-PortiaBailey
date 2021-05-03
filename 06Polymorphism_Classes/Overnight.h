#pragma once
#include "Parcel.h"
class Overnight :
    public Parcel
{
public:
  Overnight();
  int getDeliveryDay() const;
  double setInsured(bool);
  double setRush(bool);
  void read(istream&);
  void print(ostream&) const;
private:
  int mVolume;
};

