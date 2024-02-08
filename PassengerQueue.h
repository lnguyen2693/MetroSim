/* PassengerQueue.h
 *
 * Linh Nguyen (lnguye18)
 * 
 * CS 15 project 1 header file declaring class PassengerQueue.
 * 
 */

#ifndef PASSENGER_QUEUE_H
#define PASSENGER_QUEUE_H

#include "Passenger.h"
#include <list>
#include <iostream>

using namespace std;

class PassengerQueue {
public:
    PassengerQueue();
    ~PassengerQueue();

    Passenger front();
    void dequeue();
    void enqueue(const Passenger &passenger);
    int size();
    void print(std::ostream &output);

private:
    list<Passenger> p_list;
    // Passenger *first;
    // int num_ppl;
    

};

#endif