/* MetroSim.h
 *
 * CS15 project 1 header file declaring class MetroSim
 * 
 * Linh Nguyen (lnguye18)
 * Jun 19 2023
 * 
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"
#include "PassengerQueue.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Station {
    string name_station;
    PassengerQueue p_queue;
};

class MetroSim {
public:

    MetroSim(string stationFile);

    void runTrain(ostream &output, istream &input);

private:
    vector<Station> the_station;
    vector<PassengerQueue> the_train;

    int num_ppl;
    int curr_station;
    string query;
    int p_arrival;
    int p_departure;
    bool metroEnd;

    void read_file(string filename);
    void print();
    void get_command(ostream &output, istream &input);
    void print_inaccurate_command(string command);

    void addP();
    void moveTrain(ostream &output);

};

#endif
