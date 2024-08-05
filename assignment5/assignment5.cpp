/*
Name: Ruth Marroquin, 5008310315#, 1003, Assignment#5
Description: Prompts file name, outputs conversions 
Input: A file name
Output: A file with metric to imperial conversions
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Function to convert mass to pounds based on the given unit
double convertPounds(double mass, const string& unit) {
    double result = 0.0; // Default value for undefined unit

    // Convert grams to pounds
    if (unit == "g") {
        result = mass / 453.6;
    // Convert kilograms to pounds
    } else if (unit == "kg") {
        result = mass * 2.205;
    // Convert metric tons to pounds
    } else if (unit == "mt") {
        result = mass * 2205;
    } else {
        return 0; 
    }

    return result;
}

int main() {
    ifstream inFile;
    ofstream conversionsFile, totalsFile;
    string fileName;
    string line;
    const int MAX_ENTRIES = 1000; // Define a maximum size for the arrays
    double weights[MAX_ENTRIES];
    string units[MAX_ENTRIES];
    int numEntries = 0;
    double totalPounds = 0;
    int validLines = 0;

    // Prompt user for a valid file name and open the input file
    while (true) {
        cout << "Enter the input file name: ";
        getline(cin, fileName);
        inFile.open(fileName);
        if (!inFile.is_open()) {
            cout << "Error: Invalid filename\n"; // Error message for invalid file name
        } else {
            break;
        }
    }

    

    // Close the input file as we have stored all the data in the arrays
    inFile.close();

    // Open output files
    conversionsFile.open("conversions.txt");
    totalsFile.open("totals.txt");

    // Process the data from the fixed-size arrays
    for (int i = 0; i < numEntries; ++i) {
        double weight = weights[i];
        string unit = units[i];

        double convertedWeight = convertPounds(weight, unit);
        if (convertedWeight < 0) {
            cout << "Error: Invalid unit\n";
            continue;
        }

        conversionsFile << fixed << setprecision(2) << convertedWeight << " lbs" << endl;
        totalPounds += convertedWeight;
        validLines++;
    }

    // Output totals
    totalsFile << "Total number of conversions: " << validLines << endl;
    totalsFile << "Total weight in pounds: " << fixed << setprecision(2) << totalPounds << " lbs" << endl;

    // Close all files
    conversionsFile.close();
    totalsFile.close();

    return 0;
}
