#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

  int toGuess, guess, tries=0;
  bool isGuessed = false;

  srand(time(0));
  toGuess = rand() % 11;  // % n: 0, 1, 2 ... n-1

  while (!isGuessed && tries < 5) {

    cout << "Enter your guess between 0 and 10 -- ";
    cin >> guess;
    tries++;

    if (guess == toGuess) {
      cout << "You guessed it!" << endl;
      isGuessed = true;
    }

  }

    if (!isGuessed)
      cout << "Unfortunately you lost" << endl;

  return 0;
}
