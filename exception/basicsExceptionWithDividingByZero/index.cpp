/*
    - exception used for synchronous prgraming.

    - exception handing
        - dealing with extraordinary situations
        - indicates that an extraordinary situation has been detected or has occured
        - program can deal with the extraordinary situations in a suitable mannter

    - what causes exceptions?
        - insuffcient resouces
        - missing resources
        - invalid operations
        - range violations
        - underflows and overflows
        - illegal data and many others

    - at the example below may occures the following:
        double result {};

        result = 0 / 0; => program will crash

        result  = 0.0 / 0; => nan

        result = 120.0 / 0; => inf

        result = -120.0 / 0; => inf

*/

#include <iostream>

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
        if (gallons == 0)
            throw 0;

        // miles_per_gallon = miles / gallons;
        miles_per_gallon = static_cast<double>(miles) / gallons;
        std::cout << miles_per_gallon << std::endl;
    } catch(const int &ex) {
        std::cerr << "Could not divide by zero." << std::endl;
    }
    
    std::cout << "Bye" << std::endl;

    return 0;
}
