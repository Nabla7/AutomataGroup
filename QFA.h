//============================================================================
// Name        : QFA.h
// Author      : Pim, Michael, Minh en Siebe
// Version     : 1.0
// Copyright   : Talen en Automaten - BA1 Informatica - University of Antwerp
// Description : QFA stimulation in C++
//============================================================================
#ifndef AUTOMATAGROUP_QFA_H
#define AUTOMATAGROUP_QFA_H

#include <iostream>
#include <vector>
#include <complex>

using namespace std;

class QFAState {
private:
    complex<double> alpha;
    complex<double> beta;

public:
    QFAState();

    QFAState(complex<double> a, complex<double> b);

    const complex<double> &getAlpha() const;

    void setAlpha(const complex<double> &alpha);

    const complex<double> &getBeta() const;

    void setBeta(const complex<double> &beta);

    void print() const {
        cout << alpha << "|0> + " << beta << "|1>" << endl;
    }
};

class QFA {
private:
    vector<QFAState> states;

public:
    QFA();

    void addState(QFAState state);

    QFAState getState(int index) const;

    void printStates() const;

    bool accepts(string input);
};

#endif //AUTOMATAGROUP_QFA_H
