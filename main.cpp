//============================================================================
// Name        : main.cpp
// Author      : Pim, Michael, Minh en Siebe
// Version     : 1.0
// Copyright   : Talen en Automaten - BA1 Informatica - University of Antwerp
// Description : QFA stimulation in C++
//============================================================================
#include <iostream>
#include "QFA.h"

int main() {
    // create a QFA object
    QFA qfa;

    // define the states, alphabet, transition function, start state, and accept states of the QFA
    // ...

    // simulate the QFA on an input string
    std::string input = "010101";
    /*bool isAccepted = qfa.simulate(input);

    // print the result
    if (isAccepted) {
        std::cout << "The input string " << input << " is accepted by the QFA." << std::endl;
    } else {
        std::cout << "The input string " << input << " is not accepted by the QFA." << std::endl;
    }*/

    return 0;
}
