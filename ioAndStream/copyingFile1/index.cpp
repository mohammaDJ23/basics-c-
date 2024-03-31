#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream in_file;
    std::ofstream out_file;

    in_file.open("romeoAndJuliet.txt");

    if (!in_file.is_open())
    {
        std::cout << "The file is not found." << std::endl;
        return 1;
    }

    out_file.open("test.txt");

    if (!out_file.is_open())
    {
        std::cout << "Could not create a file" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(in_file, line))
        out_file << line << std::endl;
    
    in_file.close();
    out_file.close();
    
    return 0;
}
