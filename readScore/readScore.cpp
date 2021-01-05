//
// The purpose of the program is to read a file consisting of students' test scores in the range 0-200,
//  then it determines the number of students have scores in each of the given range.
// Input: From file -- testScore
// Output: numberOfStudent
// Author: Hana
// Date: November 25, 2020
//

// Header Files
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Function Prototype
void openFile(ifstream&);
void readScore(ifstream&, int&);
void initialize(int []);
void calculate (int [], int);
void display (const int []);
void closeFile(ifstream&);

// Constant Declaration
const int RANGE = 8; // Number of ranges from 0 to 200

int main ()
{
  // Variable declaration
  int testScore, numberOfStudent[RANGE];
  ifstream inFile;

  // Executable statements
  initialize(numberOfStudent);

  openFile(inFile);

  readScore(inFile,testScore);

  while(!inFile.eof()) {

    calculate(numberOfStudent, testScore);

    readScore(inFile, testScore);
  }

  closeFile(inFile);

  display(numberOfStudent);

  return 0;
}
// Puprose: opens a file
// Parameters: Innputs --
//             Outputs --
//             I/Os -- ifstream -- i
//
// Returns:
void openFile(ifstream & i) {
  i.open("readScore.in");
}
// Puprose: reads a scores
// Parameters: Innputs --
//             Outputs -- int a
//             I/Os -- ifstream -- i
//
// Returns:
void readScore(ifstream& i, int& a) {
  i >> a;
}
// Puprose: initialize an array
// Parameters: Innputs --
//             Outputs -- int []
//             I/Os --
//
// Returns:
void initialize(int a[]) {
  for (int i = 0; i < RANGE; i++)
    a[i] = 0;
}
// Purpose: To calculate the number of students have scores in each of the given range.
// Parameter: Input -- score
//            Inputs/Outputs -- int []
// Returns:
//
void calculate(int a[], int score)
{
  if (score >= 0 && score < 200)
    a[score / 25]++;
  else if (score == 200)
    a[7]++;

}
//
// Purpose: To print the number of students have scores in each of the given range.
// Parameter: Input -- a
//            Output --
// Returns:
//
void display (const int a[])
{
  int i;

  cout << "The number of students have scores in each of the given range:"<< endl << endl;

  cout << left << setw(10) << "0-24" << setw(10) << "25-49" << setw(10) << "50-74" << setw(10) << "75-99"
       << setw(10) << "100-124" << setw(10) << "125-149" << setw(10) << "150-174" << setw(10) << "175-200" << endl;

  cout << left << setw(10) << "------" << setw(10) << "------" << setw(10) << "------" << setw(10) << "------"
               << setw(10) << "------" << setw(10) << "------" << setw(10) << "------" << setw(10) << "------" << endl;

  for (i = 0; i < RANGE ; i++)
    cout << setw(10) << a[i];

  cout << endl;
}
// Puprose: closes a file
// Parameters: Inputs --
//
//             Outputs --
//             Inputs/Outputs -- ifstream -- i
//
// Returns:
void closeFile(ifstream & i) {
  i.close();
}
