// Worked with: Tom Hansen & Kameron Metcalf
// Used ChatGPT for some guidance but code is original

#include "HW-1.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

void Q1() 
{
    cout << "QUESTION 1:" << endl;
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

void Q2() 
{
    cout << endl;
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

void Q3() 
{
    cout << endl;
    cout << "QUESTION 3:" << endl;
    int K = 0; 
    int K_old = 2; // Control gain beginning
    int alpha = 1; // adaptive rate

    // Resetting the previous variables for a new loop
    double L_p = -1;
    double L_delta = 1;
    double p = 0;
    double p_old = 0;
    double deflect = -K * p_old; // Redefining the deflection formula
    double delta_t = 0.01;

    for (double i = 0; i <= 5; i = (i + delta_t)) {
        if (i > 2.0) {
            deflect = 0;
        }
        if (i <= 2.0) {
            deflect = 1;
        }
        K = K_old + alpha * (p * p);

        p = p_old + (((L_p * p_old) + (L_delta * deflect)) * delta_t);

        cout << "Time = " << i << " seconds and roll rate = " << p << " rad/s." << endl;

        K_old = K;
        p_old = p;
    }
}

// dot product function used for Q4
double dot_product(vector<double> a, vector<double> b)
{
    double dotproduct = 0;

    //vector<vector<double>> verticalVector = { {1}, {2}, {3} };

    for (int i = 0; i < a.size(); i++)
    {
        dotproduct += a[i] * b[i];
    }
    return dotproduct;
}

//vector<double> transposer(vector<double> vect)
//{
//    vector<vector<double>> test = { {1}, {2}, {3} };
//
//    for (int i = 0; i < vect.size(); i++)
//    {
//        
//        /*for (int j = 0; j < vect[i].size(); j++)
//        {
//            vect[j][i] = vect[i][j];
//        }*/
//    }
//    for (int i = 0; i < 3; ++i)
//        for (int j = 0; j < 1; ++j)
//            test[i * 6 + j] = vect[j * 6 + i];
//    return vect;
//}

void Q4() 
{
    cout << endl;
    cout << "QUESTION 4:" << endl;
    vector<double> w = { 0.0001, 0.0001, 0.0001 };
    vector<double> x = { 124, 31.89, 20.945 };

    double z = dot_product(w, x);
    cout << "The dot product z = " << z << endl;
}

// Sigmoid equation for #5
double sigmoid(double z) 
{
    double sigma_z = (1.0 / (1.0 + exp(-z)));
    return sigma_z;
}

double gradient_sigmoid(double z) 
{
    double sigma_z = sigmoid(z);
    double d_sigma = (sigma_z * (1.0 - sigma_z));
    return d_sigma;
}

void Q5() 
{
    cout << endl;
    cout << "QUESTION 5:" << endl;
    double z = 0.0176835;

    double sigmoid_output = sigmoid(z);
    double gradient_output = gradient_sigmoid(z);

    cout << "Sigmoid(" << z << ") = " << sigmoid_output << std::endl;
    cout << "Gradient of the sigmoid(" << z << ") = " << gradient_output << std::endl;
}

double gradient_cost(double y, double y_predict)
{
    double dC = 2 * (y_predict - y);
    return dC;
}

void Q6() 
{
    cout << endl;
    cout << "QUESTION 6:" << endl;
    double y = 1.0;
    double y_predicted = 0.504421;

    double dC = gradient_cost(y_predicted, y);

    cout << "dC = " << dC << std::endl;
}

vector<double> gradient_weights(double sigma, vector<double> x, double y, const vector<double> w)
{
    double z = dot_product(w, x);
    vector<double> dw = { 0, 0, 0 };
    for (int i = 0; i < 2; ++i) // multiplying each value in dw by x
    {
        dw[i] = (2 * (sigma * (z) - y) * (sigma * (z) * (1 - sigma * (z)))) * x[i];
    }
    return dw;
}

vector<double> update_weights(vector<double> w, const vector<double> dw, double alpha) /*(vector<double> wi, double a, double dwi)*/
{
    for (int i = 0; i < 3; ++i) // multiplying each value in w x
    {
        w[i] = w[i] - alpha * dw[i];
    }
    return w;
}

void Q7() 
{
    cout << endl;
    cout << "QUESTION 7:" << endl;
    //Reused from 4
    vector<double> w = { 0.0001, 0.0001, 0.0001 };
    vector<double> x = { 124, 31.89, 20.945 };
    double y = 1.0;
    double alpha = 0.001;

    //Copying from Q5
    double z = 0.0176835;
    double sigmoid_output = sigmoid(z);

    // Calculate the gradient of the cost function
    vector<double> dw = gradient_weights(sigmoid_output, x, y, w);

    // Update the weights
    w = update_weights(w, dw, alpha);

    // Print the updated weights
    cout << "Updated weights: ";
    for (int i = 0; i < w.size(); ++i) {
        cout << w[i] << " ";
    }
    cout << endl;
}

void Q8()
{
    cout << endl;
    cout << "QUESTION 8:" << endl;
    vector<double> w = { 0.0001, 0.0001, 0.0001 };
    double alpha = 0.001;
    //double x[8][3] = { {124, 31.89, 20.945}, {74, 51.08, 9.170}, {103, 34.67, 8.3}, {77, 52, 9.4}, {104, 35.63, 13}, {92, 56, 12.5}, {130, 31.29, 17.637}, {73, 52, 9.6} };
    //double y[8][1] = {1, 0, 1, 0, 1, 0, 1, 0};

    vector<vector<double>> aircraftData = {
        {124, 31.89, 20.945},
        {74, 51.08, 9.170},
        {103, 34.67, 8.3},
        {77, 52, 9.4},
        {104, 35.63, 13},
        {92, 56, 12.5},
        {130, 31.29, 17.637},
        {73, 52, 9.6}
    };
}

void Q9()
{
    cout << endl;
    cout << "QUESTION 9:" << endl;
    vector<double> wi = { 0.0001, 0.0001, 0.0001 }; // w from question 8
    double y = 1; //1 is a placeholder for the type of engine
    string airplane = " "; //used to display what type of plane has the found type of engine

    for (int i = 1; i <= 4; ++i) {
        // code block to be executed

      //SF50 Vision
        for (int j = 0; j < 150; j++)
        {
            if (i = 1)
             {
              vector<double> x = { 87.0, 38.67, 6.000 };
              airplane = "SF50";
             EngineDetermination(airplane, w, x);
             return;
        }

        //208 Caravan
        if (i = 2)
        {
            vector<double> x = { 79.0, 52.08, 8.000 };
            airplane = "208 Caravan";
            EngineDetermination(airplane, w, x);
            return;
        }

        if (i = 3)
        {
            //Aero L-29 Delfin
            vector<double> x = { 92.0, 33.75, 7.804 };
            airplane = "Aero L - 29 Delfin";
            EngineDetermination(airplane, w, x);
            return;
        }

        if (i = 4)
        {
            //AT-802U
            vector<double> x = { 91.0, 59.25, 16.000 };
            airplane = "AT - 802U";
            EngineDetermination(airplane, w, x);
            return;
        }
        }
        
    }
}

void EngineDetermination(string airplane, vector<double> w, vector<double> x) 
{  //function to determine which engine type the plane posesses
    //math to find y to determine engine type 
    
    // Reusing sigma equations from earlier
    double z = 0.0176835;
    double sigmoid_output = sigmoid(z);
    //vector<double> w = RESULT FROM 8;
    //vector<double> x = { 124, 31.89, 20.945 };

    double dot = dot_product(w, x);

    double y = (sigmoid_output * (dot));

    if (y > 0.5) 
    {
        cout << "The engine of a " << airplane << " is a Turbojet Engine." << endl;
    }

    if (y < 0.5)
    {
        cout << "The engine of a " << airplane << " is a Turboprop engine." << endl;
    }

    else
    {
        cout << "This plane doesn't work." << endl;
    }
}

int main() {
    // Calling the functions for each question to run them
    Q1();
    Q2();
    Q3();
    Q4();
    Q5();
    Q6();
    Q7();
    Q8();
    Q9();

    return 0;
}