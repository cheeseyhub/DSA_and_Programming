#include <iostream>
#include <random>
#include <vector>
#include <numeric>

double square(double x)
{
    return 2 * x;
}

double random_constant_weight()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 50);
    return distr(gen);
}

void print_vector(const std::vector<double> &v)
{

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " : ";
    }
    std::cout << std::endl;
}
int main()
{

    const double learning_rate = 0.00005;
    const int epochs = 50000;
    std::vector<int> inputs = {1, 2, 3, 4};
    std::vector<double> acutal_outputs;

    double random_weight = random_constant_weight();

    // Acutal outputs
    for (int i = 0; i < inputs.size(); i++)
    {
        acutal_outputs.push_back(square(inputs[i]));
    }

    // Using epochs to train the weight

    for (int i = 0; i < epochs; i++)
    {
        std::vector<double> predict_outputs;
        for (int i = 0; i < inputs.size(); i++)
        {
            predict_outputs.push_back(random_weight * inputs[i]);
        }

        std::vector<double> error;
        for (int i = 0; i < predict_outputs.size(); i++)
        {
            error.push_back(predict_outputs[i] - acutal_outputs[i]);
        }
        std::vector<double> dw;
        for (int i = 0; i < error.size(); i++)
        {
            dw.push_back(2 * error[i] * inputs[i]);
        }
        double average_dw = std::accumulate(dw.begin(), dw.end(), 0.0) / dw.size();

        random_weight = random_weight - (average_dw * learning_rate);
    }

    std::cout << random_weight << " X" << std::endl;

    return 0;
}