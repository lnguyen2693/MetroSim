/* Passenger.cpp
 * Linh Nguyen (lnguye18)
 * Implementattion of Passenger.h
 */

// #include <iostream>
// #include <string>
#include "Passenger.h"

/*
 * print
 * Input: output stream
 * Description: print the element.
 * Output:
 */
void Passenger::print(std::ostream &output) {
        output << toString();
}

/*
 * toString
 * Input: 
 * Description: create a string that contains the data.
 * Output: return the string.
 */
string Passenger::toString() const {
        stringstream ss;
        ss << "[" << id << ", " <<  from << "->" << to << "]";
        return ss.str();
}
