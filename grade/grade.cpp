// This program reads student's first and last names followed by their grades
// and outputs student's ranks, names, and grades from the highest to the lowest.
// Input: firstName, lastName, grade
// Output: rank, name, grade
// Author: Hana
// Date: Dec 14, 2020
//

// Header files
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Struct Definitions
struct studentType {
  string first;
  string last;
  double grade;
};

// Function Prototypes
void openFile (ifstream&);
void getData (ifstream&, studentType [], int&);
void sortData (studentType [], int);
void printData (const studentType [], int);
void closeFile (ifstream&);

// Constant Declaration
const int NUM_OF_STUDENTS = 200;

int main() {

  ifstream inFile;
  studentType student[NUM_OF_STUDENTS];
  int size;

  openFile(inFile);

  getData(inFile, student, size);

  sortData(student, size);

  printData(student, size);

  closeFile(inFile);

  return 0;
}

// Function Definition

// Purpose: asks for a file name and opens the file
// Parameters: Input --
//             Output --
//             Input/Outputs -- ifstream -- input file stream
// Returns:
void openFile (ifstream& in)
{
  string filename;
  do {
    cout << "Enter the file name: ";
    cin >> filename;
    in.open(filename.c_str());
  } while (in.fail());
}

// Purpose: Read the first, last names, and grades from a file
// Parameters: Input --
//             Output -- studentType a[] -- struct array containing of first, last, grade
//                       int s -- size of array
//             Input/Outputs -- ifstream -- in
// Returns:
void getData (ifstream& in, studentType a[], int& s)
{
  s = 0;
  in >> a[s].first >> a[s].last >> a[s].grade;
  while (!in.eof()) {
    s++;
    in >> a[s].first >> a[s].last >> a[s].grade;
  }
}

// Purpose: Sorts the struct array in descending order based on the grade
// Parameters: Input -- int s -- size of arrary
//             Output --
//             Input/Output -- studentType a[] -- struct array containing of first, last, grade
// Returns:
void sortData(studentType a[], int s)
{
  int highestIndex;
  studentType temp;

  for (int i = 0; i < s-1; i++)
  {
    highestIndex = i;
    for (int j = i + 1; j < s; j++)
      if (a[highestIndex].grade < a[j].grade)
        highestIndex = j;

    temp = a[highestIndex];
    a[highestIndex] = a[i];
    a[i] = temp;
  }
}

// Function: Displays the first name, last name, grade, and rank
// Parameters: Input -- stduentType a[] -- struct array containing of first, last, grade
//		               -- int s -- size of array
//             Output --
// Returns:
void printData (const studentType a[], int s)
{
  cout << fixed << showpoint << setprecision(2);
  cout << endl;

  for (int i = 0; i < s; i++)
  {
    if (a[i].grade == a[i-1].grade) {
      cout << setw(5) << left << " "
           << setw(20) << left << a[i].last + ", " + a[i].first
           << setw(10) << right << a[i].grade
           << endl;
    }
    else {
      cout << setw(5) << left << i + 1
           << setw(20) << left << a[i].last + ", " + a[i].first
           << setw(10) << right << a[i].grade
           << endl;
    }
  } // end-for
}

// Purpose: closes the file
// Parameters: Input --
//             Output --
//             Input/Outputs -- ifstream -- input data stream
// Returns:
void closeFile(ifstream& in)
{
  in.close();
}
