#include <iostream>

/*

    this function only should return a valid double.
    but line 13 will not work when gallons is 0.
    so you have to check for this condition to throw an error.
    you could not return a valid result.

*/
double calculate_mpg(int miles, int gallons)
{
    if (gallons == 0)
        throw 0;
    return static_cast<double>(miles) / gallons;
}

int main()
{
    int miles {};
    int gallons {};
    double miles_per_gallon {};

    std::cout << "Enter the miles drives: ";
    std::cin >> miles;
    std::cout << "Enter the gallon used: ";
    std::cin >> gallons;

    try {
        miles_per_gallon = calculate_mpg(miles, gallons);
        std::cout << miles_per_gallon << std::endl;
    } catch(const int &ex) {
        std::cerr << "Could not divide by zero." << std::endl;
    }
    
    std::cout << "Bye" << std::endl;

    return 0;
}
