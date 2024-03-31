#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

int main()
{
    std::ifstream in_file;
    std::string word {};
    std::string txt {};
    int match_counter {0};
    int word_counter {0};

    in_file.open("romeoAndJuliet.txt");

    if (!in_file.is_open())
    {
        std::cout << "The file is not found." << std::endl;
        return 1;
    }

    std::cout << "Enter the substring to search for: ";
    std::cin >> txt;

    while (in_file >> word)
    {
        word_counter++;

        if (word.find(txt) != std::string::npos)
        {
            match_counter++;
            std::cout << word << " ";
        }
    }
    
    std::cout << std::endl;
    std::cout << word_counter << " word were searched..." << std::endl;
    std::cout << "The substring " << txt << " was found " << match_counter << " times" << std::endl;
    
    in_file.close();
    
    return 0;
}
