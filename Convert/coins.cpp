// Given an amount of change between 0 and 100 cents
// this program converts in minimum number of coins

#include <iostream>

using namespace std;

//constant declarations
const int DOLLAR = 100;
const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;

int main() {

  int amount;
  int dollar, quarters, dime, nickel;
  int left;

  cout << "Enter an amount of change in cents -- ";
  cin >> amount;

  left = amount + 2;

  dollar = left / DOLLAR;
  left = left % DOLLAR;

  quarters = left / QUARTER;
  left = left % QUARTER;

  dime = left / DIME;
  left = left % DIME;

  nickel = left / NICKEL;

  cout << "To the amount of change " << amount << " cents "
       << " corresponds \n"
       << dollar << " dollar \n "
       << quarters << " quarter(s) " << endl
       << dime << " dime(s) " << endl
       << nickel << " nickel. "
       << endl;

    return 0;
}
