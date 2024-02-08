/* MetroSim.cpp
 *
 * Implementation of MetroSim class methods
 * 
 * Linh Nguyen (lnguye18)
 * Jun 19 2023
 */

#include "MetroSim.h"

// constructor
MetroSim::MetroSim(string stationFile) {
    num_ppl = 0;
    curr_station = 0;
    query = "";
    p_arrival = 0;
    p_departure = 0;
    metroEnd = false;

    read_file(stationFile);
}

// MetroSim::~MetroSim() {}

/* 
 * read_file
 * Input: name of the data file.
 * Description: Read data from the provided file into the data structure.
 * Output:
 */
void MetroSim::read_file(string filename) {
    
    // check error open file
    ifstream stationFile(filename);
    if (stationFile.fail()) {
        cerr << "Error: could not open file " << filename << endl;
        exit(EXIT_FAILURE);
    }

    string n_s;
    while (getline(stationFile, n_s)) {

        Station temp;
        temp.name_station = n_s;
        the_station.push_back(temp);

        PassengerQueue pq;
        the_train.push_back(pq); 
    }

    stationFile.close();
}

/* 
 * runTrain
 * Input: ostream and istream address
 * Description: operate the MetroSim program
 * Output: 
 */
void MetroSim::runTrain(ostream &output, istream &input) {
   while (not metroEnd) { 
        // print data to terminal/ main tream
        print();

        // get command and prompt query
        get_command(output, input);
    }
    cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
}

/* 
 * print
 * Input:
 * Description: print out the station and passenger data
 * Output:
 */
void MetroSim::print() {
    cout << "Passengers on the train: {";
    int num_stations = the_station.size();
    for (int i = 0; i < num_stations; i++) {
        the_train[i].print(cout);
    }
    cout << "}" << endl;

    
    for (int i = 0; i < num_stations; i++) {
        // Print the current location of the train.
        if (curr_station == i) {
            cout << "TRAIN: ";
        } else {
            cout << "       ";
        }

        cout << "[" << i << "]" << " "
               << the_station[i].name_station << " ";

        cout << "{";
        the_station[i].p_queue.print(cout);
        cout << "}" << endl;
    }

    cout << "Command? ";
}

/*
 * get_command
 * Input: ostream and istream address
 * Description: get command from the input stream and run the program
 *      based on the input.
 * Output:
 */
void MetroSim::get_command(ostream &output, istream &input) {
    query = "";
    p_arrival = 0;
    p_departure = 0;
    
    int station_size = the_station.size();
    string input_line;
    if (getline(input, input_line)) { 
        istringstream command_line;
        command_line.str(input_line);

        if (input_line != "m f") {
            if (input_line == "m m") {
                // call function moveTrain
                moveTrain(output);
            } else {
                command_line >> query >> p_arrival >> p_departure;

                // check if the command is accurate
                if (query != "p" or p_arrival < 0 or p_arrival > station_size 
                    or p_departure < 0 or p_departure > station_size) {
                    print_inaccurate_command(input_line);
                } else {
                    // call function addPassenger
                    addP();
                }
            }
        } else {
            metroEnd = true;
        }
    }
}

/*
 * addP
 * Input:
 * Description: add new passenger into the corresponding station's
 *      passenger queue and increment the number of passenger.
 * Output:
 */
void MetroSim::addP() {
    num_ppl++;
    Passenger new_p(num_ppl, p_arrival, p_departure);
    the_station[p_arrival].p_queue.enqueue(new_p);
}

/*
 * moveTrain
 * Input: output stream
 * Description: move passenger from the station to the train and
 *      move the passengers who reach their destination out of 
 *      the train.
 * Output:
 */
void MetroSim::moveTrain(ostream &output) {
    // passengers waiting in the station enter the train.
    while (the_station[curr_station].p_queue.size() != 0) {
        Passenger temp = the_station[curr_station].p_queue.front();
        the_station[curr_station].p_queue.dequeue();
        the_train[temp.to].enqueue(temp);
    }
    

    // train moves to the next station
    int station_size = the_station.size();
    curr_station = (curr_station + 1) % station_size;

    // passengers leave the train
    while (the_train[curr_station].size() != 0) {
        // print into the output file
        output << "Passenger " << the_train[curr_station].front().id
               << " left train at station " 
               << the_station[curr_station].name_station << endl;
        the_train[curr_station].dequeue();
    }
}

/*  
 * print_inaccurate_command
 * Input: the inaccurate command
 * Description: print message
 * Output: 
 */
void MetroSim::print_inaccurate_command(string command) {
    int station_size = the_station.size();
    cout << "Command [" << command << "] not recognized.\n";
    cout << "        Use p x y with valid integer station IDs x and y.\n";
    cout << "        Use m m to move the train.\n";
    cout << "        Use m f to exit.\n";
    cout << "        Valid station IDs: 0 ... " << station_size << endl;
    cout << "Note: students do not need to handle invalid commands.\n";

}