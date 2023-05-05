//============================================================================
// Name        : QFA.cpp
// Author      : Pim, Michael, Minh en Siebe
// Version     : 1.0
// Copyright   : Talen en Automaten - BA1 Informatica - University of Antwerp
// Description : QFA stimulation in C++
//============================================================================

#include "QFA.h"



/**
 * QFAState
 */
QFAState::QFAState() {
    alpha = 0;
    beta = 0;
}

QFAState::QFAState(complex<double> a, complex<double> b) {
    alpha = a;
    beta = b;
}

const complex<double> &QFAState::getAlpha() const {
    return alpha;
}

void QFAState::setAlpha(const complex<double> &alpha) {
    QFAState::alpha = alpha;
}

const complex<double> &QFAState::getBeta() const {
    return beta;
}

void QFAState::setBeta(const complex<double> &beta) {
    QFAState::beta = beta;
}

/**
 * QFA
 */
QFA::QFA() {}


void QFA::addState(QFAState state) {
    states.push_back(state);
}

QFAState QFA::getState(int index) const {
    return states[index];
}

void QFA::printStates() const {
    for(unsigned int i = 0; i < states.size(); i++) {
        cout << "State " << i << ": ";
        states[i].print();
    }
}

bool QFA::accepts(string input) {
    // Initialize the starting state
    QFAState current_state(1, 0);

    // Loop over the input string
    for (char c : input) {
        // Apply the transition function based on the current state and input character
        if (std::norm(current_state.getAlpha()) > 0.5) {
            if (c == 'a') {
                current_state.setBeta(0);
            } else {
                current_state.setAlpha(0);
            }
        } else {
            if (c == 'a') {
                current_state.setAlpha(0);
            } else {
                current_state.setBeta(0);
            }
        }
    }

    // Check if the final state is an accepting state (i.e., the last character was 'a')
    return (std::norm(current_state.getAlpha()) > 0.5);
}