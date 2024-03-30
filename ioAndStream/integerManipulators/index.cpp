#include <iostream>
#include <iomanip>

int main()
{
    int num {255};

    // displaying using different bases

    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    std::cout << "==============================" << std::endl;

    // display showing the base prefix for hex and oct
    std::cout << std::showbase;

    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    std::cout << "==============================" << std::endl;

    // display hex value in uppercase
    std::cout << std::showbase << std::uppercase;

    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    std::cout << "==============================" << std::endl;

    // display the + sign in front of positive base 10 numbers
    std::cout << std::showpos;
    
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    std::cout << "==============================" << std::endl;

    // setting using the set method (equals to the above)
    std::cout.setf(std::ios::showpos);
    std::cout.setf(std::ios::showbase);
    std::cout.setf(std::ios::uppercase);

    // resetting to defaults
    std::cout << std::resetiosflags(std::ios::basefield); // resetting numbers to dec
    std::cout << std::resetiosflags(std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::showbase);
    std::cout << std::resetiosflags(std::ios::uppercase);

    std::cout << "Enter an integer: ";
    std::cin >> num;

    std::cout << "==============================" << std::endl;

    std::cout << "Deciaml default: " << num << std::endl;

    std::cout << "==============================" << std::endl;

    std::cout << "Hexadecimal: " << std::hex << num << std::endl;
    std::cout << "Hexadecimal uppercase: " << std::hex << std::uppercase << num << std::endl;
    std::cout << "Hexadecimal nouppercase: " << std::hex << std::nouppercase << num << std::endl;

    std::cout << "==============================" << std::endl;

    std::cout << "Octal: " << std::oct << num << std::endl;
    std::cout << "Octal with showbase: " << std::oct << std::showbase << num << std::endl;
    std::cout << "Hexadecimal with uppercase and showbase: " << std::hex << std::uppercase << std::showbase << num << std::endl;
    
    return 0;
}
