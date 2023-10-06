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
    double dotproduct = inner_product(a.begin(), a.end(), b.begin(), 0); // Using inner_product from <numeric>
    return dotproduct;
}

void Q4() 
{
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
    cout << "QUESTION 6:" << endl;
    double y = 1.0;
    double y_predicted = 0.504421;

    double dC = gradient_cost(y_predicted, y);

    cout << "dC = " << dC << std::endl;
}

double gradient_weights(double sigma, double x, double y, double w)
{
    double dwi = (2 * (sigma * (w * x) - y) * (sigma * (w * x) * (1 - sigma * (w * x))));
}

void update_weights(vector<double>& w, const vector<double>& dw, double alpha) 
{
    if (w.size() != dw.size()) 
    {
        throw invalid_argument("Vector sizes must be the same");
    }

    for (size_t i = 0; i < w.size(); ++i) 
    {
        w[i] -= alpha * dw[i];
    }
}

void Q7() 
{
    vector<double> w = { 0.0001, 0.0001, 0.0001 };
    vector<double> x = { 124, 31.89, 20.945 };
    double y = 1.0;
    double alpha = 0.001;

    // Calculate the gradient of the cost function
    vector<double> dw = gradient_weights(w, x, y);

    // Update the weights
    update_weights(w, dw, alpha);

    // Print the updated weights
    cout << "Updated weights: ";
    for (size_t i = 0; i < w.size(); ++i) {
        cout << w[i] << " ";
    }
    cout << endl;
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
    /*Q8();
    Q9();*/

    return 0;
}
