//
// This program converts the height from feet/inches to meters/centimeters
//

#include <iostream>

using namespace std;

// Constant Declarations
const int INCHES_PER_FOOT = 12;
const float CMS_PER_INCH = 2.54;
const int CMS_PER_METER = 100;

int main() {

  int feet, inches, meters, cms, totalCms;

  cout << "Enter the height in feet and inches (sperated by space): ";
  cin >> feet >> inches;

  totalCms = static_cast<int> ((feet * INCHES_PER_FOOT + inches) * CMS_PER_INCH);
  meters = totalCms / CMS_PER_METER;
  cms = totalCms % CMS_PER_METER;

  cout << feet << " foot/feet " << inches << " inch(es) = "
       << meters << " meter(s) "<< cms << " centimeter(s)"
       << endl;

   return 0;
}
