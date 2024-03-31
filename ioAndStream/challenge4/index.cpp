#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

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
        std::cout << "Could not create a file." << std::endl;
        return 1;
    }

    std::string line;
    int line_counter {0};
    while (std::getline(in_file, line))
    {
        
        if (line.length() > 0)
        {
            line_counter++;
            out_file << line_counter << "   " << line << std::endl;
        }
        else
            out_file << line << std::endl;
    }
    
    
    in_file.close();
    out_file.close();
    
    return 0;
}
