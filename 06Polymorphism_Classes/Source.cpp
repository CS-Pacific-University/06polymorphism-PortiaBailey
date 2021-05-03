#include <fstream>
#include <string>
#include <iostream>

#include "Parcel.h"
#include "Postcard.h"
#include "Letter.h"
#include "Overnight.h"

using namespace std;

int main() {
  const string INPUT_FILE = "parcel.txt";
  const char LETTER = 'L';
  const char POSTCARD = 'P';
  const char OVERNIGHT = 'O';
  ifstream inFile;
  char typeOfParcel;
  int i = 0;
  
  Parcel* pcParcels[25];
  inFile.open (INPUT_FILE);
  if (!inFile.is_open()) {
    cout << "Error opening file";
  }
  else {
    cout << "OPENED";
    while (!inFile.eof()) {
      cout << "File opened!";
      inFile >> typeOfParcel;
      if (typeOfParcel == LETTER) {
        pcParcels[i] = new Letter();
        // pcParcels.read(inFile);
      }
      else if (typeOfParcel == POSTCARD) {
        //pcParcels[i] = new Postcard();
      }
      else if (typeOfParcel == OVERNIGHT) {

      }
      ++i;
    }
  }
  cout << "Reached the end!\n";
  return EXIT_SUCCESS;
}