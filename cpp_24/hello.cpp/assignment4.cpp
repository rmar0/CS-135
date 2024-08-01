/*
Name: Ruth Marroquin, 5008310315#, 1003, Assignment #4
Description: Prompts floating point number, outputs loop. 
Input: A floating point number by the user.
Output: Loop if invalid input or until user ends loop. 
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// function to clear the input stream in case of an error
void clearInput() {
    cin.clear();
    cin.ignore(10000, '\n'); 
}

// function to get the side length of the octagon from the user
double getSide() {
    double side_length;
    while (true) {
        cout << "Enter octagon’s side length: ";
        cin >> side_length;
        
        if (cin.fail()) { 
            cout << "Error: Invalid data type." << endl;
         // clear the input stream
            clearInput();
        // check if the input is less than or equal to 0
        } else if (side_length <= 0) {
            cout << "Error: Input value must be greater than 0." << endl;
        // check if the input is 100 or more
        } else if (side_length >= 100) {
            cout << "Error: Input value must be less than 100." << endl;
        } else {
            // valid input, return the side length
            return side_length;
        }
    }
}

// function to get the calculation selection from the user
int getSelection() {
    int selection;
    while (true) {
        cout << "\nAvailable Calculations\n";
        cout << "1) Area\n";
        cout << "2) Circumcircle Radius\n";
        cout << "3) Incircle Radius\n";
        cout << "Selection: ";
        cin >> selection;
// check if the input is not an integer or not in the valid range
        if (cin.fail() || selection < 1 || selection > 3) { 
            cout << "Error: Invalid option." << endl;
            clearInput(); // Clear the input stream
        } else {
            return selection; // valid input, return the selection
        }
    }
}

// function to prompt the user if they want to continue or exit
bool promptContinue() {
    char choice;
    cout << "\nEnter y/Y to continue. Enter any other key to exit: ";
    cin >> choice;
     // return true if the user enters 'y' or 'Y', otherwise false
    return choice == 'y' || choice == 'Y';
}

int main() {
    do {
        // get the side length from the user
        double side_length = getSide(); 
        // get the calculation selection from the user
        int selection = getSelection(); 

        // fixed-point notation 2 decimal places
        cout << fixed << setprecision(2);
        switch (selection) {
            case 1: {
                // area of the octagon
                double area = 2 * pow(side_length, 2) * (1 + sqrt(2));
                cout << "Area = " << area << endl;
                break;
            }
            case 2: {
                // circumcircle radius of the octagon
                double circumcircle_radius = (0.5 * side_length) * sqrt(4 + 2 * sqrt(2));
                cout << "Circumcircle Radius = " << circumcircle_radius << endl;
                break;
            }
            case 3: {
                // incircle radius of the octagon
                double incircle_radius = (0.5 * side_length) * (1 + sqrt(2));
                cout << "Incircle Radius = " << incircle_radius << endl;
                break;
            }
            default:
                cout << "Error: Invalid option." << endl;
                break;
        }
        // prompt the user to continue or exit
    } while (promptContinue());

    return 0; // exit the program
}
