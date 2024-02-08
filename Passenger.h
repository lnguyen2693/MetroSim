/* Passenger.h
 *
 * Linh Nguyen (lnguye18)
 * 
 * CS 15 project 1 header file declaring struct Passenger
 * 
 */


#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>
#include <string> 
#include <sstream>
using namespace std;

struct Passenger
{

        int id, from, to;
        
        Passenger()
        {
                id   = -1;
                from = -1;
                to   = -1;
        }

        Passenger(int newId, int arrivalStation, int departureStation)
        {
                id   = newId;
                from = arrivalStation;
                to   = departureStation;
        }

        void print(std::ostream &output);
        string toString() const;

};

#endif
