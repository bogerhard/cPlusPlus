#include <iostream>
#include <cmath>

using namespace std;

int main() {

  long long num, digit, sum;

  cout << "Enter an integer -- ";
  cin >> num;

  num = fabs(num);

  cout << "Individual digits -- ";
  sum = 0;

  while (num > 0)
  {
    digit = num % 10;
    cout << digit << " ";
    sum += digit;
    num = num / 10;
  }

  cout << endl;
  cout << "Sum of digit -- " << sum << endl;

  return 0;
}
