//Question 5
// Sigmoid equation for #5
double sigmoid(double z)
{
    //Formula for sigmoid
    double sigma_z = (1.0 / (1.0 + exp(-z)));
    return sigma_z;
}
//function for gradient_sigmoid
double gradient_sigmoid(double z)
{
    double sigma_z = sigmoid(z);
    //formula for gradient sigmoid
    double d_sigma = (sigma_z * (1.0 - sigma_z));
    return d_sigma;
}

void Q5()
{
    cout << "QUESTION 5:" << endl;
    //Variables
    double z = 0.0176835;
    double sigmoid_output = sigmoid(z); //sigmoid output value
    double gradient_output = gradient_sigmoid(z); //gradient sigmoid output value
//Displaying answer to question
    cout << "Sigmoid(" << z << ") = " << sigmoid_output << std::endl;
    cout << "Gradient of the sigmoid(" << z << ") = " << gradient_output << std::endl;
}
//Question 6
//function for gradient cost
double gradient_cost(double y, double y_predict)
{
    //formula for gradient cost
    double dC = 2 * (y_predict - y);
    return dC;
}

void Q6()
{
    //Display
    cout << "QUESTION 6:" << endl;
    //Variables
    double y = 1.0; //variable y
    double y_predicted = 0.504421; //y predicted
    double dC = gradient_cost(y_predicted, y);
//Displaying gradient cost value
    cout << "dC = " << dC << std::endl;
}
