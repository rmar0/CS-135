 /*
Name: Ruth Marroquin, 5008310315#, 1003, Assignment #7
Description: Polygon calculations and output stats file
Input: File names by user
Output: Output file with stats
*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

// function prototypes
void openFile(ifstream &inFile);
void readFile(ifstream &inFile, string types[], double sideLengths[], 
int &readCount, int MAX_SIZE);
void calculateAreas(const string types[], const double sideLengths[], 
double areas[], int SIZE);
int minIndex(const double areas[], int SIZE);
int maxIndex(const double areas[], int SIZE);
void writeAreasToFile(const string types[], const double sideLengths[], 
const double areas[], int SIZE);
void writeStatsToFile(const string types[], const double sideLengths[], 
const double areas[], int min, int max);

//main function
int main() {

    // constant for maximum array size
    const int MAX_SIZE = 100;

    ifstream iFile; 
    string shapeTypes[MAX_SIZE]; 
    double sideLengths[MAX_SIZE]; 
    double areas[MAX_SIZE] = {0};
    int readCount = 0; 

    // open the file
    openFile(iFile);

    // read data from the file
    readFile(iFile, shapeTypes, sideLengths, readCount, MAX_SIZE);

    // calculate areas
    calculateAreas(shapeTypes, sideLengths, areas, readCount);

    // find the minimum and maximum area
    int min = minIndex(areas, readCount);
    int max = maxIndex(areas, readCount);

    // write the areas of all shapes to a file
    writeAreasToFile(shapeTypes, sideLengths, areas, readCount);

    // write the statistics (min and max areas) to another file
    writeStatsToFile(shapeTypes, sideLengths, areas, min, max);

    return 0;
}

// function to open the input file
void openFile(ifstream &inFile) {
    string fileName;
    // prompt user for a valid file name and open file
    while (true) {
        // prompt the user for the file name
        cout << "Enter a file name: "; 
        getline(cin, fileName); 
        inFile.open(fileName); 
        if (!inFile.is_open()) {
            // Display an error if the file cannot be opened
            cout << "Error: Invalid filename\n" << endl; 
        } else {
            break; 
        }
    }
}

// function to read data from the file into arrays
void readFile(ifstream &inFile, string types[], 
double sideLengths[], int &readCount, int MAX_SIZE) {
    // loop through the file reading pairs of data until end of file
    while (inFile >> types[readCount] >> sideLengths[readCount]) {
        readCount++; // increment the count of items read
        if (readCount == MAX_SIZE) {
            cout << "Error: Max input size read in" << endl; 
            break;
        }
    }
    
    inFile.close(); // close the file
}

// function to calculate areas based on the shape type
void calculateAreas(const string types[], 
const double sideLengths[], double areas[], int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        // calculate area based on type of shape
        if (types[i] == "hexagon") {
            // area of hexagon
            areas[i] = (3 * sqrt(3) / 2) * pow(sideLengths[i], 2); 
        } else if (types[i] == "octagon") {
             // area of octagon
            areas[i] = 2 * (1 + sqrt(2)) * pow(sideLengths[i], 2);
        } else if (types[i] == "decagon") {
            // area of decagon
            areas[i] = (5.0 / 2.0) * 
                pow(sideLengths[i], 2) * sqrt(5 + 2 * sqrt(5)); 
        } else {
            // handle unexpected shape type
            areas[i] = 0.0; // Default or error value
        }
    }
}

// function to find the index of the maximum area in the array
int maxIndex(const double areas[], int SIZE) {
    int maxIdx = 0; // assume first element is the maximum
    for (int i = 1; i < SIZE; i++) {
        if (areas[i] > areas[maxIdx]) {
        // update maximum index if a larger area is found
            maxIdx = i; 
        }
    }
    return maxIdx; 
}

// function to find the index of the minimum area in the array
int minIndex(const double areas[], int SIZE) {
    int minIdx = 0; // assume first element is the minimum
    for (int i = 1; i < SIZE; i++) {
        if (areas[i] < areas[minIdx]) {
        // Update minimum index if a smaller area is found
            minIdx = i; 
        }
    }

    return minIdx; 
}

// function to write values to file
void writeAreasToFile(const string types[], 
const double sideLengths[], const double areas[], int SIZE) {
    ofstream outFile("areas.txt"); // open output file
    for (int i = 0; i < SIZE; i++) {
        outFile << fixed << setprecision(2); 
        // write type, side length, and area to the file
        outFile << types[i] << " " 
                << sideLengths[i] << " " << areas[i] << endl; 
    }
    outFile.close(); // close the output file
}

// function to write the statistics to a file
void writeStatsToFile(const string types[], 
const double sideLengths[], const double areas[], int min, int max) {

    //open the output file
    ofstream outFile2("stats.txt"); 
    outFile2 << fixed << setprecision(2); 

    // write minimum area details
    outFile2 << "MINIMUM AREA\n";
    outFile2 << "Index: " << min << endl;
    outFile2 << "Type: " << types[min] << endl;
    outFile2 << "Side Length: " << sideLengths[min] << endl;
    outFile2 << "Area: " << areas[min] << endl << endl;

    // write maximum area details
    outFile2 << "MAXIMUM AREA\n";
    outFile2 << "Index: " << max << endl;
    outFile2 << "Type: " << types[max] << endl;
    outFile2 << "Side Length: " << sideLengths[max] << endl;
    outFile2 << "Area: " << areas[max] << endl;

    outFile2.close(); // Close the output file
}
