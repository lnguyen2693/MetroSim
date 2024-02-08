/*
 *  unit_tests.h
 *  Linh Nguyen
 *  Jun 19 2023
 *
 *  CS 15 project 1 unit test
 *
 *  FILE PURPOSE HERE
 *
 */

#include "PassengerQueue.h"
#include <cassert>
#include <iostream>

using namespace std;

// test PassengerQueue enqueue() and print()
void test1() {
    PassengerQueue queue;
    Passenger ppl_1(1, 3, 8);
    queue.enqueue(ppl_1);
    Passenger ppl_2(2, 4, 6);
    queue.enqueue(ppl_2);

    stringstream ss;
    queue.print(ss);
    assert(ss.str() == "{[1, 3->8][2, 4->6]}");
}

