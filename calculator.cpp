// This program emulates a basic integer calculator

#include <iostream>

using namespace std;

int main() {

  int num1, num2, result;
  char op;
  bool divisionByZero = false;

  cout << "Enter an operator between 2 integers" << endl
       << ">";

  cin >> num1 >> op >> num2;

  switch (op)
  {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      if (num2 == 0)
        divisionByZero = true;
      else
        result = num1 / num2;
      break;
    case '%':
      if (num2 == 0)
        divisionByZero = true;
      else
        result = num1 % num2;
      break;
    default:
      cout << "Operator unknown" << endl;
  }

    if (divisionByZero)
      cout << "Error: cannot be divied by zero" << endl;
    else
      cout << num1 << " "<< op << " " << num2 << " = " << result << endl;

  return 0;
}