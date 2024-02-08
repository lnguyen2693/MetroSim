/*
 *
 */

#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"

using namespace std;

int main(int argc, char *argv[]) {

    if (argc < 2) {
        cerr << "Usage: ./MetroSim stationsFile outputFile [commandsFile]";
        cerr << endl;
        exit(EXIT_FAILURE);
    }

    MetroSim my_MetroSim(argv[1]);
    
    ofstream outputFile(argv[2]);
    if (outputFile.fail()) {
            cerr << "Error: could not open file " << argv[2] << endl;
            exit(EXIT_FAILURE);
        }
    
    if (argc == 3) {
        my_MetroSim.runTrain(outputFile, cin);
    } 
    else if (argc == 4) {
        ifstream inputFile(argv[3]);
        if (inputFile.fail()) {
            cerr << "Error: could not open file " << argv[3] << endl;
            exit(EXIT_FAILURE);
        }
        my_MetroSim.runTrain(outputFile, inputFile);
        inputFile.close();
    }
    outputFile.close();

    return 0;
}
