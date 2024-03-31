#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
    std::ifstream in_file;
    std::string line;
    int num1 {};
    double num2 {};

    in_file.open("test.txt");

    if (!in_file.is_open() /* or in_file */)
    {
        std::cout << "The file is not found." << std::endl;
        return 1;
    }

    std::cout << "The file is found." << std::endl;

    while (!in_file.eof() /* or in_file >> line >> num1 >> num2 */)
    {
        in_file >> line >> num1 >> num2;
        std::cout << std::setprecision(2) << std::fixed;
        std::cout << std::setw(10) << std::left << line
            << std::setw(10) << std::left << num1
            << std::setw(10) << std::left << num2
            << std::endl;
    }

    in_file.close();
    
    return 0;
}
