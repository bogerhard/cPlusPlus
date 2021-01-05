// This program display the types of the roots of a quadratic equation,
// ax^2 + bx + c = 0, where a != 0
// Input: a, b, c
// Output: The types of the roots of the equation

#include <iostream>
#include <cmath>

using namespace std;

// Constant Declarations
const double ERROR = .000001;

int main() {

  double a, b, c;
  double discr;

  cout << "Enter a, b, c -- ";
  cin >> a >> b >> c;

  discr = pow(b, 2) - (4 * a * c);

  if (fabs(discr) < ERROR)
    cout << "single root" << endl;
  else if (discr > 0.0)
    cout << "two real roots" << endl;
  else
    cout << "two complex roots" << endl;

  return 0;
}