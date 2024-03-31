#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
    std::ifstream in_file;
    std::string line;

    in_file.open("test.txt");

    if (!in_file.is_open() /* or in_file */)
    {
        std::cout << "The file is not found." << std::endl;
        return 1;
    }

    while (std::getline(in_file, line))
        std::cout << line << std::endl;

    in_file.close();
    
    return 0;
}
