//***************************************************************************
// File name:  Postcard.h
// Author:     Portia Bailey
// Date:       4/29/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Header file for class postcard
//***************************************************************************
#pragma once
#include "Parcel.h"
class Postcard :
    public Parcel
{
  public:
    Postcard();
    int getDeliveryDay ();
    double getInsured (bool);
    double getRush (bool);
    double getCost ();
    double getBaseCost ();
    void read (istream& rcIn);
    void print (ostream&);
    void setInsured (bool);
    void setRush (bool);
    void setCost (double);

  private:
    string mMessage;
};

