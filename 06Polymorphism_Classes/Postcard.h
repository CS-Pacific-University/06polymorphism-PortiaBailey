#pragma once
#include "Parcel.h"
class Postcard :
    public Parcel
{
  public:
    Postcard();
    int getDeliveryDay() const;
    double setInsured(bool);
    double setRush(bool);
    void read(istream& rcIn);
    void print(ostream&) const;
  private:
    string mMessage;
};

