#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <string>

int main()
{
    int num {};
    double total {};
    std::string name {};

    std::string info {"Moe 100 123.33"};

    std::istringstream iss {info};
    iss >> name >> num >> total;

    std::cout << std::setw(10) << std::left << name
        << std::setw(10) << std::left << num
        << std::setw(10) << std::left << total
        << std::endl;

    std::ostringstream oss {};

    oss << std::setw(10) << std::left << name
        << std::setw(10) << std::left << num
        << std::setw(10) << std::left << total
        << std::endl;
    std::cout << oss.str() << std::endl;

    int value {};
    std::string result {};
    bool done {false};

    do
    {
        std::cout << "Enter an integer: ";
        std::cin >> result;
        std::istringstream iss {result};
        if (iss >> value)
            {
                done = true;
                std::cout << "You have entered: " << value << std::endl;
            }
        else
            std::cout << "Sorry, " << result << " is not integer." << std::endl;
    
        /*
        
            if the user insert for example 12iosdf or 12.5435 or 12 fasdif oiasjdfi,
            iss >> value will grab 12 from the stinrg and the following strings will be discard.
        
        */
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!done);
    
    return 0;
}
