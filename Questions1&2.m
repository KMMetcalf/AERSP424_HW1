//Homework 1
//Team: Tom Hansen, Kameron Metcalf, Ian Atkinson
//Professor Thanakorn Khamvilai
//Used chatgpt for guidance but Code is original

#include "HW-1.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

void Q1() {
    cout << "QUESTION 1:" << endl;
    double L_p = -1;   //roll damping coefficient
    double L_delta = 1;  //aileron effectiveness
    double deflect = 1;  //aileron deflection angle
    double p = 1; // rad/s. This is p0 initially
    double p_old = 1; // initial roll rate
    double delta_t = 0.01; //step size

    for (double i = 0; i <= 5; i = (i + delta_t)) { //roll rate prediction over 5 seconds with pilot
        if (i > 2) {
            deflect = 0;
        }
        if (i <= 2) {
            deflect = 1;
        }

        p = p_old + (((L_p * p_old) + (L_delta * deflect)) * delta_t);  //new value of roll

        cout << "Time = " << i << " seconds and roll rate = " << p << " rad/s." << endl; //output of roll rate for every second

        p_old = p; //p_old becomes p
    }
}

void Q2() {
    cout << "QUESTION 2:" << endl;
    int K = 2; // Control gain

    // Resetting the previous variables for a new loop
    double L_p = -1; //roll damping ratio 2
    double L_delta = 1; //aileron effectiveness 2
    double p = 0; //roll rate 2
    double p_old = 0; //initial roll rate 2
    double deflect = -K * p_old; // Redefining the deflection formula  
    double delta_t = 0.01; // stepsize

    for (double i = 0; i <= 5; i = (i + delta_t)) { //roll rate prediction over 5 seconds with autopilot
        if (i > 2) {
            deflect = 0;
        }
        if (i <= 2) {
            deflect = 1;

        p = p_old + (((L_p * p_old) + (L_delta * deflect)) * delta_t); //new value of roll

        cout << "Time = " << i << " seconds and roll rate = " << p << " rad/s." << endl; //output of roll rate for every second

        p_old = p; /p_old becomes p
    }
}
