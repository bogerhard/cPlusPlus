//
// This program takes a date in the following format: December 25th, 2018
// and extracts the day, month, and year as 3 integers.
// Then display them in day/month/year format
//
#include <iostream>
#include <string>

using namespace std;

// Function Prototypes
void getDate(string&);
void extract(string, int&, int&, int&);
int convertDigits(string);
int convertMonths(string);

int main() {

   char decision;
   string date;
   int month, day, year;

   do {
      getDate(date);
      extract(date, month, day, year);
      cout << day << "/" << month<< "/" << year << endl;
      cout << "Try again (Y/N) -- ";
      cin >> decision;
      cin.ignore(100, '\n');
   } while(decision == 'Y' || decision == 'y');

   return 0;

}

// Purpose : This function prompts a user to enter a date as a string
// Parameters : I/O -- string for date
// Returns :
void getDate(string& date) {
   cout <<"Enter a date -- ";
   getline(cin, date);
}

// Purpose : This function extracts the day, month, and year
//           as 3 integers from a date string
// Parameters : I   -- string for date
//              I/O -- int for month
//              I/O -- int for day
//              I/O -- int for year
// Returns :
void extract(string date, int& month, int&  day, int& year) {

   string monthText = "";
   string dayText = "";
   string yearText = "";

   int pos;

   for(pos = 0; pos < date.length()&& date[pos] != ' '; pos++)
       monthText += date[pos];


   for(pos = pos + 1 ; pos < date.length() && date[pos] != ' '; pos++)
       if ( isdigit(date[pos]) )
            dayText += date[pos];



   for(pos = pos + 1; pos < date.length(); pos++)
        yearText += date[pos];


   month = convertMonths(monthText);
   day = convertDigits(dayText);
   year = convertDigits(yearText);
}
// Purpose : This function takes a string of digits
//           and converts it to an int.
// Parameters : I -- string for digit
// Returns : This function returns an integer value after
//           converting the string of digits.
int convertDigits(string digitString) {

   int num = 0;

   for(int i = 0; i < digitString.length(); i++)
    num = num * 10 + static_cast<int>(digitString[i]) - static_cast<int>('0');

   return num;
}

// Purpose : This function takes a month as a string
//           and returns a corresponding number from 1 to 12.
// Parameters : I -- string for month
// Returns : This function returns a corresponding number
//           from 1 to 12 for the given month.
int convertMonths(string month) {
   if (month == "January")
      return 1;
   else if (month == "February")
      return 2;
   else if (month == "March")
      return 3;
   else if (month == "April")
      return 4;
   else if (month == "May")
      return 5;
   else if (month == "June")
      return 6;
   else if (month == "July")
      return 7;
   else if (month == "August")
      return 8;
   else if(month == "September")
      return 9;
   else if (month == "October")
      return 10;
   else if (month == "November")
      return 11;
   else if (month == "December")
      return 12;
   else
      return 0;
}
