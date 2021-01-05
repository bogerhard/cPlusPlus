//
// This program prints an int in reverse (from right to left)
//

#include <iostream>

using namespace std;

// Function Prototypes
void reverseDigit(int, int&);

int main() {

  int num, rev;
  char yes;

  do {

    cout << "Enter an int -- ";
    cin >> num;

    reverseDigit(num, rev);
    cout << num << "reversed is " << rev << endl;

    cout << "Try again (Y/N)? ";
    cin >> yes;

  } while (yes == 'Y' || yes == 'y');

  return 0;
}

// Function Definition
void reverseDigit (int n, int& r)
{
  r = 0;

  while (n != 0)
  {
    r = r * 10 + n % 10;
    n = n / 10;
  }
}
