//
// This program opens a file called "lab7.txt" reads the line
// and prints out the name, sin number, user id and mypassword
// where in the sin number and password's charaters are replaced by 'x's
// Input: inFile
// Output: userInfo
// Author: Hana
// Date: Nov 22, 2020

// Header files
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function Prototypes
void openFile (ifstream&);
void readData (ifstream&, string&);
void deleteSin (string&);
void deletePassword (string&);
void closeFile (ifstream&);

int main() {

  // Variable Declaration
  string userInfo;
  ifstream inFile;

  openFile(inFile);

  readData(inFile, userInfo);

  deleteSin(userInfo);

  deletePassword(userInfo);

  cout << userInfo << endl;

  closeFile(inFile);

  return 0;
}

// Function Definition

// Purpose     : opens the lab example readData
// Parameters  : Inputs --
//               Outputs --
//               Inputs/Outputs -- fstream : stream for the example data
// Returns     :

void openFile (ifstream& in)
{
  in.open("userInfo.in");
}

// Purpose     : Reads the line from the file stream
// Parameters  : Inputs --
//               Outputs --
//               Inputs/Outputs -- ifstream -- file stream of lab example data
//                              -- string -- data from the file
// Returns     :

void readData (ifstream& in, string& str)
{
  getline(in, str);
}

// Purpose     : Deletes the sin number and replaces the digits with 'x'
// Parameters  : Inputs --
//               Outputs --
//               Inputs/Outputs -- string -- reference to the person's data
// Returns     :

void deleteSin (string& str)
{
  int i, idx;

  i = str.find(" ");

  while (i != string::npos)
  {
    // shift the idx forward by 1 so that we are
    // starting on the idx after the character " " we found
    idx = i + 1;

    str.erase(idx, 3);
    str.insert(idx, 3, 'x');

    i = str.find("-", idx);
  }
}

// Purpose     : Deletes the password and replaces the digits with 'x'
// Parameters  : Inputs --
//               Outputs --
//               Inputs/Outputs -- string -- reference to the person's data
// Returns     :

void deletePassword (string& str)
{
  int i, idx, passwdLength;

  i = str.find(" ");

  while (i != string::npos)
  {
    idx = i + 1;
    i = str.find(" ", idx);
  }
  passwdLength = str.length() - idx;
  str.erase(idx, passwdLength);
  str.insert(idx, passwdLength, 'x');

}

// Purpose     : close the lab example data
// Parameters  : Inputs --
//               Outputs --
//               Inputs/Outputs -- ifstream -- i
// Returns     :

void closeFile (ifstream& in)
{
  in.close();
}
