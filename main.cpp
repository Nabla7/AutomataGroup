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
    // Create the QFA
    QFA qfa;
    qfa.addState(QFAState(1, 0));
    qfa.addState(QFAState(0, 1));

    // Test the QFA on some inputs
    cout << "QFA recognizes the inputs" << endl;
    cout << "ab: " << (qfa.accepts("ab") ? "accept" : "reject") << endl;
    cout << "ba: " << (qfa.accepts("ba") ? "accept" : "reject") << endl;
    cout << "aaa: " << (qfa.accepts("aaa") ? "accept" : "reject") << endl;
    cout << "bbb: " << (qfa.accepts("bbb") ? "accept" : "reject") << endl;
    cout << "ababba: " << (qfa.accepts("ababba") ? "accept" : "reject") << endl;
    cout << "bbabb: " << (qfa.accepts("bbabb") ? "accept" : "reject") << endl;

    return 0;
}
