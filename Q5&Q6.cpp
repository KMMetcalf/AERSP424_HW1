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
