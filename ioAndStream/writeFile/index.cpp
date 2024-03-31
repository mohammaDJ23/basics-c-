#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ofstream out_file;

    // std::ios::app means append any text to the file
    // default is std::ios::trunc which means repalce any text with new text
    out_file.open("test.txt", std::ios::app);

    if (!out_file.is_open())
    {
        std::cout << "Could not create a file" << std::endl;
        return 1;
    }

    std::string line;
    std::cout << "Enter something to the file: ";
    std::getline(std::cin, line);

    out_file << line << std::endl;
    
    out_file.close();
    
    return 0;
}
