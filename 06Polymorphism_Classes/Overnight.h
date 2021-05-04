//***************************************************************************
// File name:  Overnight.h
// Author:     Portia Bailey
// Date:       4/27/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Header file for class Overnight
//***************************************************************************
#pragma once
#include "Parcel.h"
class Overnight :
    public Parcel
{
  public:
    Overnight ();
    int getDeliveryDay ();
    double getInsured (bool);
    double getRush (bool);
    double getBaseCost ();
    void read (istream&);
    void print (ostream&);
    double getCost ();
    void setInsured (bool);
    void setRush (bool);
    void setCost (double);

  private:
    int mVolume;
};

