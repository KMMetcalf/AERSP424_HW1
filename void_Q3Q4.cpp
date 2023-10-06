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
