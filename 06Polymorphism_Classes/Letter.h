#pragma once
#include "Parcel.h"
class Letter :
    public Parcel
{
  public:
    Letter();
    int getDeliveryDay() const;
    double setInsured(bool);
    double setRush(bool);
    void read(istream&);

  private:
};

