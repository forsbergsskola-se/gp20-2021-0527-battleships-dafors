#include <iostream>

int main()
{
    size_t iterations;
    std::cout << "enter desired iterations \n>";
    std::cin >> iterations;
    
    int distribution[20]{0};
    srand(time(0));

    for (size_t i = 0; i < iterations; i++)
    {
        distribution[rand() % 20] ++;
    }

    int number{ 1 };
    float deviation_sum{ 0 };
    float deviation_min{ std::numeric_limits<float>::max() };
    float deviation_max{ 0 };
    int min_nr{ 0 };
    int max_nr{ 0 };
    float expected_amount = iterations * 0.05f;

    std::cout << "Expected Amount: " << expected_amount << "\n";
    for (auto amount : distribution) {
        float deviation = 100.0f * abs(1.0f-amount/expected_amount);
        std::cout << "Number " << number << ": " << amount << " times (" << deviation << " %)\n";

        deviation_sum += deviation;
        if (deviation < deviation_min) {
            deviation_min = deviation;
            min_nr = number;
        }
        if (deviation > deviation_max) {
            deviation_max = deviation;
            max_nr = number;
        }
        number++;
    }

    std::cout << "\nMaximum Offset: Number " << max_nr << " (" << deviation_max << " %) \n";
    std::cout << "Minimum Offset: Number " << min_nr << " (" << deviation_min << " %) \n";
    std::cout << "Average Offset: " << deviation_sum / 20.0f << "%";
}