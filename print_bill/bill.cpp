//
// This program reads in a list of items from a file "bill.in" and print out the bill.
//

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const float GST = 0.05;

int main() {

  ifstream in;
  float unitPrice, itemTotal, grandTotal, gst;
  int quantity, itemNum;

  in.open("bill.in");

  grandTotal = 0;
  itemNum = 0;

  cout << endl
       << setw(15) << left << "Item Number"
       << setw(15) << right << "Unit Price"
       << setw(15) << right << "Quantity"
       << setw(15) << right << "Item Total"
       << endl;

  cout << fixed << showpoint << setprecision(2);

  in >> unitPrice >> quantity;

  while (!in.eof())
  {
    itemNum++;
    itemTotal = unitPrice * quantity;
    grandTotal += itemTotal;

    cout << setw(5) << right << itemNum
         << setw(25) << right << unitPrice
         << setw(15) << right << quantity
         << setw(15) << right << itemTotal
         << endl;

    in >> unitPrice >> quantity;
  }

  gst = grandTotal * GST;
  grandTotal += gst;

  cout << endl
       << setw(38) << " "
       << setw(12) << left << "GST"
       << setw(10) << right << gst
       << endl;

   cout << endl
        << setw(38) << " "
        << setw(12) << left << "Grand Total"
        << setw(10) << right << grandTotal
        << endl;

  in.close();

  return 0;
}