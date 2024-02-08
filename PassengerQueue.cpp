/* PassengerQueue.cpp
 *
 * Implementation of PassengerQueue class methods
 * 
 * Linh Nguyen (lnguye18)
 * Jun 19 2023
 */

#include "PassengerQueue.h"

// constructor
PassengerQueue::PassengerQueue() {
}

/* 
 * deconstructor
 */
PassengerQueue::~PassengerQueue() {
    p_list.clear();
}

/*
 * front
 * Input:
 * Description: return the first element of the list.
 * Output:
 */
Passenger PassengerQueue::front() {
    return p_list.front();
}

/*
 * dequeue
 * Input:
 * Description: pop the first element out of the list.
 * Outpur:
 */
void PassengerQueue::dequeue() {
    p_list.pop_front();
}

/*
* enqueue
 * Input: new element
 * Description: add new element into the list.
 * Output:
 */
void PassengerQueue::enqueue(const Passenger &passenger) {
    p_list.push_back(passenger);
}

/*
 * size
 * Input: 
 * Description: return size of the list.
 * Output:
 */
int PassengerQueue::size() {
    return p_list.size();
}

/*
 * print
 * Input: output stream
 * Description: print the list.
 * Output:
 */
void PassengerQueue::print(std::ostream &output) {
    list<Passenger> temp_list;
    temp_list = p_list;
    
    while (not temp_list.empty()) {
        temp_list.front().print(cout);
        temp_list.pop_front();
    }

}
