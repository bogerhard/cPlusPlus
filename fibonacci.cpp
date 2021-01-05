// This program computes the sequence of Fibonacci modulus 10

#include <iostream>

using namespace std;

int main() {

  int m1, m2, current, numberOfTerms;
  int count;
  char message;

  cout << "This is the Fibonacci Sequence mod 10 fact checker." << endl;

  do {

    cout << "How many terms do you wish to check? ";
    cin >> numberOfTerms;

    if (numberOfTerms >= 0)
    {
      m1 = 1;
      m2 = 1;

      if (numberOfTerms >= 1)
        cout << "1: " << m1 << endl;
      if (numberOfTerms >= 2)
        cout << "2: " << m2 << endl;

      for (count = 3; count <= numberOfTerms; count++)
      {
        current = (m1 + m2) % 10;
        cout << count << ": " << current;

        if (count % 3 == 0 && current % 2 == 0)
          cout << " - even";
        if (count % 5 == 0 && current % 5 == 0)
          cout << " - divisible by 5";
        if (count % 15 == 0 && current == 0)
          cout << " - is zero";

        cout << endl;

        m1 = m2;
        m2 = current;
      } //end for
    }// end if
    else
      cout << "Fibonacci sequence length should be a positive number." << endl;

    cout << "Would you try again (Y/y to run again)? ";
    cin >> message;

  } while (message == 'Y' || message == 'y');

  return 0;
}
