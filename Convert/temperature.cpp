//
// This program converts temperatures from Celsius to Fahrenheit
//

#include <iostream>

using namespace std;

int main()
{
  int celsius;
  int fahrenheit;

  cout << "Enter the temperature in celsius: ";
  cin >> celsius;

  fahrenheit = static_cast<int> (celsius / 5.0 * 9 + 32);

  cout << celsius << " degree C is "
       << fahrenheit << " degree F" << endl;

  return 0;
}
