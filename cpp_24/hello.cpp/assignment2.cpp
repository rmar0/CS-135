/*
Name: Ruth Marroquin, 5008310315#, 1003, Assignment #2
Description: The user will be prompted to input a floating point number and the program will output a calculated table of the area, 
circumference, and radius.
Input: A floating point number by the user.
Output: A table of calculated values. 
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    // Initialize side length
    double side_length = 0.0;

    // Prompt
    cout << "Enter octagon’s side length: ";
    cin >> side_length;

    // Function to calculate the area of an octagon
    double area = 2 * pow(side_length, 2) * (1 + sqrt(2));

    // Calculate the circumference
    double circumcircle_radius = (0.5 * side_length) * sqrt(4 + 2 * sqrt(2));

    // Calculate circle radius
    double incircle_radius = (0.5 * side_length) * (1 + sqrt(2));

    // Calculation table
    cout << "+--------------+--------------+--------------+--------------+\n";
    // Fixed point
    cout << fixed << setprecision(2) << right;
    cout << "| side length  | area         | circumcircle | incircle     |\n";
    cout << "+--------------+--------------+--------------+--------------+\n";
    cout << "| " << setw(12) << side_length 
         << " | " << setw(12) << area 
         << " | " << setw(12) << circumcircle_radius 
         << " | " << setw(12) << incircle_radius 
         << " |\n";
    cout << "+--------------+--------------+--------------+--------------+\n";

    return 0;
}

