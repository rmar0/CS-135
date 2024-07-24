/*
Name: Ruth Marroquin, 5008310315#, 1003, Assignment #1
Description: This program will prompt the user for a float and an integer
Input: The program should have integer and float inputs
Output: The program should output the calculated costs
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

//initializing + storing variables
const int BULK_CRATE_SIZE = 10000;
const int BOX_SIZE = 100;
const float MARKUP = 1.6;

// store calulated values
int TOTAL_NAILS = 0;
int TOTAL_BOXES = 0;
double SINGLE_NAIL_COST = 0.0;
double SINGLE_NAIL_SALE_PRICE = 0.0;
double BOX_COST = 0.0;
double BOX_PROFIT = 0.0;
double TOTAL_PROFIT = 0.0;
double SINGLE_NAIL_PROFIT = 0.0;
double BOX_SALE_PRICE = 8.0;

//fixed point
cout << fixed << setprecision (2);

//variables for user input
int input_bulk_crate_qty = 0;
float input_bulk_crate_cost = 0.0;

//read the price into a floating-point variable in main memory
//ask for bulk crates
cout << "Enter today's bulk crate price: ";
cin >> input_bulk_crate_cost;

//ask for the quantity of bulk crates wanted
cout << "Enter the quantity of bulk crates wanted: "; 
cin >> input_bulk_crate_qty;


//total nails being purchased
TOTAL_NAILS = BULK_CRATE_SIZE * input_bulk_crate_qty; 

//total boxes of 100 
TOTAL_BOXES = TOTAL_NAILS / BOX_SIZE;

//single nail from distributor
SINGLE_NAIL_COST = input_bulk_crate_cost / BULK_CRATE_SIZE;

//single nail price
SINGLE_NAIL_SALE_PRICE = SINGLE_NAIL_COST * MARKUP;

//profit from single nail
SINGLE_NAIL_PROFIT = SINGLE_NAIL_SALE_PRICE - SINGLE_NAIL_COST;

//cost of a box of nails (from distributor)
BOX_COST = SINGLE_NAIL_COST * BOX_SIZE;

//profit on a single nail
BOX_PROFIT = BOX_SALE_PRICE - BOX_COST;

//total profit
TOTAL_PROFIT = BOX_PROFIT * TOTAL_BOXES;


//output values
cout << "\nTotal quantity to order: " << TOTAL_NAILS << endl;
    cout << "Number of boxes of 100: " << TOTAL_BOXES << endl;
    cout << "Single nail cost: " << SINGLE_NAIL_COST << endl;
    cout << "Single nail sale price: " << SINGLE_NAIL_SALE_PRICE << endl;
    cout << "Single nail profit: " << SINGLE_NAIL_PROFIT << endl;
    cout << "Box cost: " << BOX_COST << endl;
    cout << "Box sale price: " << BOX_SALE_PRICE << endl;
    cout << "Box profit: " << BOX_PROFIT << endl;
    cout << "Total profit: " << TOTAL_PROFIT << endl;
} 



