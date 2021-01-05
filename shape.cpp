//
// This program uses a basic UI that allows the user to choose to calculate
// the area of a rectangle, area of a circle, or the volume of a cylinder.
// Input: choice, length, width, radius, height
// Output: result
// Author: Hana
// Date: Nov 20, 2020
//

// Header files
#include <iostream>
#include <iomanip>

using namespace std;

// Function Prototypes
double rectangle (double, double);
double circle (double);
double cylinder (double, double);

// Constant Declaration
const double PI = 3.141519;

int main() {

  // Variable Declaration
  int choice = -1;
  double length, width, radius, height, result;

  cout << fixed << showpoint << setprecision(2) << endl;

  cout << "This program can calculate the area of a rectangle, "
       << "the area of a circle, or the volume of a cylinder. " << endl;

  while (choice != 0)
  {
    cout << "To run this program enter: " << endl;
    cout << "1: To find the area of a rectangle." << endl;
    cout << "2: To find the area of a circle" << endl;
    cout << "3: To find the volume of a cylinder" << endl;
    cout << "0: To terminate the program." << endl;
    cin >> choice;
    cout << endl;

    switch (choice)
    {
      case 1:
        cout << "Enter the lenght and width of a rectangle: ";
        cin  >> length >> width;
        cout << endl;

        result = rectangle(length, width);
        cout << "Area of a retangle = " << result << endl;
        break;

      case 2:
        cout << "Enter the radius of a circle: ";
        cin  >> radius;
        cout << endl;

        result = circle(radius);
        cout << "Area of a circle = " << result << endl;
        break;

      case 3:
        cout << "Enter the radius and height of a cylinder: ";
        cin  >> radius >> height;
        cout << endl;

        result = cylinder(radius, height);
        cout << "Area of a cylinder = " << result << endl;
        break;

      } // end switch
    } // end while



  return 0;
}

// Function Definition

// Purpose: Calculates the area of a rectangle
// Parameters: Input -- double -- length of a rectangle
//             Input -- double -- width of a rectangle
//             Output --
// Returns: double -- area of a rectangle
//
double rectangle (double l, double w)
{
  return l * w;
}

// Purpose: Calculates the area of a circle
// Parameters: Input -- double -- radius of a circle
//             Output --
// Returns: double -- area of a circle
//
double circle (double r)
{
  return PI * r * r;
}

// Purpose: Calculates the area of a cylinder
// Parameters: Input -- double -- radius of a cylinder
//             Input -- double -- height of a cylinder
//             Output --
// Returns: double -- volume of a cylinder
//
double cylinder (double r, double h)
{
  return circle(r) * h;  // PI * r * r * h;
}
