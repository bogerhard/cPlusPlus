//
// The purpose of the program is to read a text and output the letters,
//  together with their counts.
// Input: From file -- data
// Output: letters, numSmall, numCapital
// Author: Hana
// Date: December 03, 2020
//

// Header Files
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Struct Definitions
struct letter
{
  int count;
  double percentage;
};

struct letterType
{
  letter small;
  letter capital;
};

// Function Prototypes
void openFile(ifstream&);
void initialize(letterType[]);
void count(ifstream&, letterType[], int&, int&);
void calculatePercentage (letterType[], int, int);
void printResult(const letterType[], int, int);
void closeFile(ifstream&);

// Constant Declarations
const int NUM_LETTER = 26;

int main ()
{
  // Variable declarations
  ifstream inFile;
  int numSmall, numCapital;
  letterType letters[NUM_LETTER];

  // Executable statements
  openFile(inFile);
  initialize(letters);
  count(inFile, letters, numSmall, numCapital);
  calculatePercentage(letters, numSmall, numCapital);
  printResult(letters, numSmall, numCapital);
  closeFile(inFile);

  return 0;
}
// Puprose: opens a file
// Parameters: Inputs --
//             Outputs --
//             I/Os -- ifstream -- i
//
// Returns:
void openFile(ifstream & i) {
  string filename;

  do
  {
    cout << "Enter a filename -- ";
    cin >> filename;
    i.open(filename.c_str());
  } while (i.fail());
}
// Puprose: initialize a letterType array
// Parameters: Innputs --
//             Outputs -- letterType []
//             I/Os --
//
// Returns:
void initialize(letterType l[])
{
  for (int i = 0; i < NUM_LETTER; i++)
  {
    l[i].small.count = 0;
    l[i].small.percentage = 0.0;
    l[i].capital.count = 0;
    l[i].capital.percentage = 0.0;
  }
}
// Purpose: Counts every occurrence of capital letters A-Z and
//          small letters a-z in the text
// Parameter: Input  --
//            Output -- int -- s -- number of small letter
//                   -- int -- c -- number of capital letter
//            I/O    -- ifstream -- i
//                   -- letterType[] -- l
// Returns:
//
void count(ifstream & i, letterType l[], int& s, int& c)
{
  unsigned int j;
  string str;
  s = 0;
  c = 0;

  getline(i, str);

  while(!i.eof()){
    for (j = 0; j < str.length(); j++)
    {
      if (str[j] >= 'a' && str[j] <= 'z'){
        l[static_cast<int>(str[j]) - static_cast<int>('a')].small.count++;
        s++;
      }
      else if (str[j] >= 'A' && str[j] <= 'Z'){
        l[static_cast<int>(str[j]) - static_cast<int>('A')].capital.count++;
        c++;
      }
    }

    getline(i, str);
  }
}
// Purpose: Calculate the percentage of all capital letters A-Z and
//          small letters a-z in the tex
// Parameter: Input  -- int -- s -- number of small letter
//                   -- int -- c -- number of capital letter
//            Output --
//            I/O    -- letterType[] -- l
// Returns:
//
void calculatePercentage (letterType l[], int s, int c)
{
  for (int i = 0; i < NUM_LETTER; i++)
  {
    l[i].small.percentage = static_cast <double> (l[i].small.count) / s * 100;
    l[i].capital.percentage = static_cast <double> (l[i].capital.count) / c * 100;
  }
}
//
// Purpose: To print the number of students have scores in each of the given range.
// Parameter: Input -- letterType[] -- l
//                  -- int -- s -- number of small letter
//                  -- int -- c -- number of capital letter
//            Inputs/Outputs --
// Returns:
//
void printResult(const letterType l[], int s, int c)
{
  cout << "Number of Small Letters: " << s << endl;
  cout << "Number of Capital Letters: " << c << endl;

  cout << fixed << showpoint << setprecision(2);
  for (int i = 0; i < NUM_LETTER; i++)
    cout << setw(2) << static_cast<char>(static_cast<int>('a') + i)
         << setw(2) << ": "
         << setw(5) << l[i].small.percentage << "\%  and  "
         << setw(2) << static_cast<char>(static_cast<int>('A')+ i)
         << setw(2) << ": "
         << setw(5) << l[i].capital.percentage << "\%"
         << endl;
}
// Puprose: closes a file
// Parameters: Inputs --
//             Outputs --
//             Inputs/Outputs -- ifstream -- i
//
// Returns:
void closeFile(ifstream & i) {
  i.close();
}
