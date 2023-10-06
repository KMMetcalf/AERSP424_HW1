//Question 5
// Sigmoid equation for #5
double sigmoid(double z)
{
    //Formula
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
    //Variables
    double z = 0.0176835;
    double sigmoid_output = sigmoid(z);
    double gradient_output = gradient_sigmoid(z);
//Displaying answer to question
    cout << "Sigmoid(" << z << ") = " << sigmoid_output << std::endl;
    cout << "Gradient of the sigmoid(" << z << ") = " << gradient_output << std::endl;
}
//Question 6
double gradient_cost(double y, double y_predict)
{
    //Equation
    double dC = 2 * (y_predict - y);
    return dC;
}

void Q6()
{
    //Display
    cout << "QUESTION 6:" << endl;
    //Variables
    double y = 1.0;
    double y_predicted = 0.504421;
    double dC = gradient_cost(y_predicted, y);
//Displaying
    cout << "dC = " << dC << std::endl;
}
