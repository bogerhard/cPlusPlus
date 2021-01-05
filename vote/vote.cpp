//
// This program receives data from a file that contains
// a list of election candidates and their total votes
// It sorts these candidates based on vote,
// and displays them in a descending order
// and output the winner of the election
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Function Prototypes
void openFile(ifstream&);
void closeFile(ifstream&);
void getData(ifstream&, string [], int [], int &);
void computePercentages(const int [], float [], int &, int);
void sortVotes(string [], int [], float [], int);
void display(const string [], const int [], const float [], int, int);
void displayWinner(string);


// Constant Declarations
const int NUM_OF_CANDIDATES = 100;

int main() {
	int size;
	int totalVotes;
	string candidateNames[NUM_OF_CANDIDATES];
	int votes[NUM_OF_CANDIDATES];
	float percentages[NUM_OF_CANDIDATES];
	ifstream inData;

	openFile(inData);
	getData(inData, candidateNames, votes, size);
	computePercentages(votes, percentages, totalVotes, size);
	sortVotes(candidateNames, votes, percentages, size);
	display(candidateNames, votes, percentages, totalVotes, size);
	displayWinner(candidateNames[0]);

	closeFile(inData);

        return 0;
}
// Function: asks for a file name and opens the file
// Parameters: I/O -- ifstream -- input file stream
// Returns:
void openFile(ifstream& in) {

   string filename;
   do {
      cout << endl << "Enter the file name: ";
      cin >> filename;
      in.open(filename.c_str());
   } while (in.fail());
}
// Function: closes the file
// Parameters: I/O -- ifstream -- input data stream
// Returns:
void closeFile(ifstream& in) {
   in.close();
}
// Function: extracts the names and votes from the file
// Parameters: I/O --  ifstream -- input data stream
// 		             --  string [] -- names
// 		             --  int [] -- number of votes
//		             --  int -- size
// Returns:
void getData(ifstream& in, string c[], int v[], int & s) {
   s = 0;
   in >> c[s] >> v[s];
   while (!in.eof()) {
      s++;
      in >> c[s] >> v[s];



   }
}
// Function: calculates the percentage of total votes for each candidate
// Parameters: I -- votes -- int []: a list of vote totals
// 		        I/O -- percents -- float []: a list of percentages
// 		        I/O -- TotalVotes int: the total number of votes in the election
//		        I -- size int: the number of candidates
// Returns:
void computePercentages(const int v[], float p[], int & t, int s) {
   t = 0;
   for (int i = 0; i < s; i++)
      t = t + v[i];

   for (int i = 0; i < s; i++)
      p[i] = 100. * v[i] / t;
}
// Function: sorts the parallel arrays in descending number of votes
// Parameters: I/O -- names -- string []: a list of names
// 		             -- votes -- int []: a list of votes
//		         I -- size -- int: the number of candidates
// Returns:
void sortVotes(string c[], int v[], float p[], int s) {
   int highestIndex;
   int tempI;
   float tempF;
   string tempS;

   for (int i = 0; i < s - 1; i++) {
      highestIndex = i;
      for (int j = i + 1; j < s; j++)
	 if (v[j] > v[highestIndex])
	    highestIndex = j;

      tempI = v[highestIndex];
      v[highestIndex] = v[i];
      v[i] = tempI;

      tempF = p[highestIndex];
      p[highestIndex] = p[i];
      p[i] = tempF;

      tempS = c[highestIndex];
      c[highestIndex] = c[i];
      c[i] = tempS;

   }
}

// Function: displays the name, votes, and percentages of each candidate
// Parameters: I -- string []-- a list of names
// 		           -- int [] -- a list of votes
// 		           --  float [] -- a list of percentages
//		           --  int -- total number of votes in election
//		           -- int -- the number of candidates
// Returns:
void display(const string c[], const int v[], const float p[], int t, int s) {

   cout << fixed << setprecision(2) << endl;

   cout << left << setw(20) << "Candidate"
      	<< right << setw(15) << "Votes Received"
      	<< right << setw(20) << "% of Total Votes"
	      << endl;

   for (int i = 0; i < s; i++)
      cout << left << setw(20) << c[i]
	         << right << setw(11) << v[i]
	         << right << setw(20) << p[i]
	         << endl;

   cout << endl;

   cout << left << setw(20) << "Total"
      	<< right << setw(11) << t
      	<< endl << endl;
}

// Function: displays the name of the candidate with the most votes
// Parameters: I -- string -- winner of the election
// Returns:
void displayWinner(string w) {

   cout << "The Winner of the Election is "
	      << w << endl << endl;
}
