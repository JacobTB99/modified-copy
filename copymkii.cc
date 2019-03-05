/*
 *        File: copy_file.cc
 *      Author: Nasseef Abukamail
 *      Modified: Jacob Beauchamp
 *        Date: March 04, 2019
 * Description: Demonstrate output streams
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

//function prototypes
void clone(ifstream &inStream, ofstream &outStream);
/*
* Function: clone
* Purpose: Copies an input file line by line to an output file.
* Parameters: Takes an inStream object and outStream object as parameters.
* Preconditions: inStream must be a valid input file.
* Postconditions: inStream has been copied to the outStream file.
*/

int main(int argc, char const *argv[]) {
    ifstream inStream;
    ofstream outStream;
    string inFileName, outFileName;
    cout << "Enter the input file name: ";
    cin >> inFileName;
    inStream.open(inFileName.c_str());
    //check for failure
        if(inStream.fail()) {
            cout << "Invalid file." << endl;
            exit(1);
        }
    cout << "Enter the output file name: ";
    cin >> outFileName;
    outStream.open(outFileName.c_str());
    //check for failure
    if(inStream.fail()) {
            cout << "Invalid file." << endl;
            exit(1);
        }
        // call function
    clone(inStream, outStream);
    inStream.close();
    outStream.close();
    return 0;
}// main

// modification start
void clone(ifstream &inStream, ofstream &outStream) {
    string line; // declare string holding variable
    getline(inStream, line); // initialize line
    // loop until eof
    while(!(inStream.eof())) {
        outStream << line << endl;
        getline(inStream, line);
    }
}

