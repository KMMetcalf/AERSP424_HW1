//Homework 1
//Team: Tom Hansen, Kameron Metcalf, Ian Atkinson
//Professor Thanakorn Khamvilai

#include "HW-1.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

void question1() {
    double L_p = -1;
    double L_delta = 1;
    double deflect = 1;
    double p = 1; // rad/s. This is p0 initially
    double p_old = 1;
    double delta_t = 0.01;

    for (double i = 0; i <= 5; i = (i + delta_t)) {
        if (i > 2) {
            deflect = 0;
        }
        if (i <= 2) {
            deflect = 1;
        }

        p = p_old + (((L_p * p_old) + (L_delta * deflect)) * delta_t);

        cout << "Time = " << i << " seconds and roll rate = " << p << " rad/s." << endl;

        p_old = p;
    }
}

void question2() {
    cout << "QUESTION 2:" << endl;
    int K = 2; // Control gain

    // Resetting the previous variables for a new loop
    double L_p = -1;
    double L_delta = 1;
    double p = 0;
    double p_old = 0;
    double deflect = -K * p_old; // Redefining the deflection formula
    double delta_t = 0.01;

    for (double i = 0; i <= 5; i = (i + delta_t)) {
        if (i > 2) {
            deflect = 0;
        }
        if (i <= 2) {
            deflect = 1;
        }

        p = p_old + (((L_p * p_old) + (L_delta * deflect)) * delta_t);

        cout << "Time = " << i << " seconds and roll rate = " << p << " rad/s." << endl;

        p_old = p;
    }
}
