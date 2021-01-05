#include <iostream>

using namespace std;

// Constant Declaration
const int MINUTES_PER_HOUR = 60;
const int HOURS_PER_DAY = 24;

// Struct Definitions
struct timeType {
  int hours;
  int minutes;
};

// Function Prototypes
timeType readTime();   // void readTime (timeType&);
void printTime (timeType);
timeType addTime(timeType, timeType);


int main() {

  timeType time1, time2, time;

  time1 = readTime();
  cout << "Time 1 is ";
  printTime (time1);
  cout << endl;

  time2 = readTime();
  cout << "Time 2 is ";
  printTime (time2);
  cout << endl;

  time = addTime (time1, time2);

  cout << "Time is ";
  printTime (time);
  cout << endl;

  return 0;
}

// Function Definitions

timeType readTime ()
{
  timeType t;

  cout << "Enter a time as 2 ints (hours and minutes) -- ";
  cin >> t.hours >> t.minutes;

  return t;
}


void printTime (timeType t)
{
  cout << " " << t.hours << ":" << t.minutes << " ";
}


timeType addTime (timeType t1, timeType t2)
{
  timeType t;

  t.minutes = (t1.minutes + t2.minutes) % MINUTES_PER_HOUR;
  t.hours = (t1.hours + t2.hours + (t1.minutes + t2.minutes) / MINUTES_PER_HOUR) % HOURS_PER_DAY;

  return t;
}
