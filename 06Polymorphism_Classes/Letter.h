//***************************************************************************
// File name:  Letter.h
// Author:     Portia Bailey
// Date:       4/29/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Header file for class letter
//***************************************************************************
#pragma once
#include "Parcel.h"
class Letter :
    public Parcel
{
  public:
    Letter();
    int getDeliveryDay ();
    double getInsured (bool);
    double getRush (bool);
    double getCost ();
    double getBaseCost ();

    void read (istream& rcIn);
    void print (ostream& rcOut);

    void setInsured (bool);
    void setRush (bool);
    void setCost (double);

  private:
};

