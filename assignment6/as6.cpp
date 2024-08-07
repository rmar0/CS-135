/*
Name: Ruth Marroquin, 5008310315#, 1003, Assignment #6
Description: Reads CSV file and outputs data
Input: Prompts user for file name
Output: Output file with data
*/


#include <iostream>
#include <fstream>

using namespace std;

const int MAX_FLIGHTS = 50; // limit

int main() {
    // file variables
    ifstream inFile;
    ofstream outFile, statsOutFile, sortedOutFile;
    string fileName;

    // arrays    
    string flightNumbers[MAX_FLIGHTS] = {};
    string airlines[MAX_FLIGHTS] = {};
    int distances[MAX_FLIGHTS];
    int count = 0;

    // prompt user for a valid file name and open file
    while (true) {
        cout << "Enter a file name: ";
        getline(cin, fileName);
      // open file
        inFile.open(fileName);
        if (!inFile.is_open()) {
            cout << "Error: Invalid filename\n" << endl;
        } else {
            break;
        }
    }

    // read the headers from the input file
    string line = "";
    string headers;
    getline(inFile, headers);

    // open the output files and write the headers
    statsOutFile.open("statistics.txt");

    sortedOutFile.open("sortedFlights.csv");
    sortedOutFile << headers << endl;

    // read the data from the input file
    while (getline(inFile, line) && count < MAX_FLIGHTS) {
        // find the first comma position
        int commaPos1 = line.find(',');
        // extract the flight number and store it
        flightNumbers[count] = line.substr(0, commaPos1);
        // find the position of the second comma
        int commaPos2 = line.find(',', commaPos1 + 1);
        // extract the airline name and store it
        airlines[count] = line.substr
          (commaPos1 + 1, commaPos2 - commaPos1 - 1);
        // convert distance to an integer, and store it
        distances[count] = stoi(line.substr(commaPos2 + 1));

        // increment the count
        count++;
    }

    // close the input file after reading
    inFile.close();

    // calculate statistics
    int minDistance = distances[0]; 
    int maxDistance = distances[0];
  // calculate min and max
    int minIndex = -1, maxIndex = -1;
    int totalDistance = 0;
    double averageDistance = 0.0;

  // calculate min and max
    for (int i = 0; i < count; i++) {
        if (distances[i] < minDistance) {
            minDistance = distances[i];
            minIndex = i;
        }
      // calculate max
        if (distances[i] > maxDistance) {
            maxDistance = distances[i];
            maxIndex = i;
        }
      // calculate total distance
        totalDistance += distances[i];
    }
  // calculate average
    averageDistance = 
      static_cast<double>(totalDistance) / count;

    // write statistics to the file

  //maximum
    statsOutFile << "MINIMUM\n";
    statsOutFile << "Flight Number: " << flightNumbers[minIndex] << endl;
    statsOutFile << "Airline: " << airlines[minIndex] 
      << endl;
    statsOutFile << "Distance: " << minDistance 
      << endl << endl;
  
//minimum
    statsOutFile << "MAXIMUM\n";
    statsOutFile << "Flight Number: " << flightNumbers[maxIndex] << endl;
    statsOutFile << "Airline: " << airlines[maxIndex] 
      << endl;
    statsOutFile << "Distance: " << maxDistance 
      << endl << endl;

//average  
    statsOutFile << "Total flights: " << count 
      << endl;
    statsOutFile << "Sum of Distances: " << totalDistance 
      << endl;
    statsOutFile << "Average Distance: " 
      << static_cast<int>(averageDistance);

    // close the statistics file
    statsOutFile.close();

    // sort the data
    int tempDistance = 0;
    string tempFlightNumber, tempAirline;

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (distances[j] > distances[j + 1]) {
                // swap distances
                tempDistance = distances[j];
                distances[j] = distances[j + 1];
                distances[j + 1] = tempDistance;

                // swap flight numbers
                tempFlightNumber = flightNumbers[j];
                flightNumbers[j] = flightNumbers[j + 1];
                flightNumbers[j + 1] = tempFlightNumber;

                // swap airlines
                tempAirline = airlines[j];
                airlines[j] = airlines[j + 1];
                airlines[j + 1] = tempAirline;
            }
        }
    }

    // write the sorted data to the sortedFlights.csv file
    for (int i = 0; i < count; i++) {
        sortedOutFile << flightNumbers[i] 
          << "," << airlines[i] << "," << distances[i] << endl;
    }

    // close the output files
    outFile.close();
    sortedOutFile.close();

    return 0;
}
