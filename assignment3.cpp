/*
Name: Ruth Marroquin, 5008310315#, 1003, Assignment #3
Description: Program prompts floating point number, outputs calculations. 
Input: A floating point number by the user.
Output: A list of the available calculations for octagon. 
*/

#include <iostream>
#include <iomanip>
#include <cmath>

    using namespace std;

  int main() {
    // Initialize side length
    double side_length = 0.0;

    // Prompt for side length and handle invalid input
    cout << "Enter octagon’s side length: ";
    cin >> side_length;

    // Check if the input was a valid number
    if (cin.fail()) {
        cout << "Error: Invalid data type." << endl;
        return 0;
    }

    if (side_length <= 0) {
        cout << "Error: Input value must be greater than 0." << endl;
        return 0;
    }

    if (side_length >= 100) {
        cout << "Error: Input value must be less than 100." << endl;
        return 0;
    }

    // Display available calculations
    cout << "\nAvailable Calculations" << endl;
    cout << "1) Area" << endl;
    cout << "2) Circumcircle Radius" << endl;
    cout << "3) Incircle Radius" << endl;
    cout << "Selection: ";

    int selection = 0;
    cin >> selection;

    // Check if the input was a valid number
    if (cin.fail() || (selection < 1 || selection > 3)) {
        cout << "Error: Invalid option." << endl;
        return 0;
    }

    // perform selected calculation using a switch statement
    cout << fixed << setprecision(2);
    switch (selection) {
        case 1: {
            double area = 2 * pow(side_length, 2) * (1 + sqrt(2));
            cout << "Area = " << area << endl;
            break;
        }
        case 2: {
            double circumcircle_radius = (0.5 * side_length) * sqrt(4 + 2 * sqrt(2));
            cout << "Circumcircle Radius = " << circumcircle_radius << endl;
            break;
        }
        case 3: {
            double incircle_radius = (0.5 * side_length) * (1 + sqrt(2));
            cout << "Incircle Radius = " << incircle_radius << endl;
            break;
        }
        default:
            cout << "Error: Invalid option." << endl;
            break;
    }

    return 0;
}