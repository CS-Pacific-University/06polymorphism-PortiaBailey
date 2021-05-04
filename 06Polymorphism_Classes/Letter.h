#pragma once
#include "Parcel.h"
class Letter :
    public Parcel
{
  public:
    Letter();
    int getDeliveryDay();
    double getInsured(bool);
    double getRush(bool);
    double getCost();
    void read(istream&);

  private:
};

