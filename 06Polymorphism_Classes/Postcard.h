#pragma once
#include "Parcel.h"
class Postcard :
    public Parcel
{
  public:
    Postcard();
    int getDeliveryDay();
    double getInsured(bool);
    double getRush(bool);
    double getCost();
    void read(istream& rcIn);
    void print(ostream&) const;
  private:
    string mMessage;
};

