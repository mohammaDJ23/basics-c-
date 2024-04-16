#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <iomanip>
#include <sstream>

void display_word(const std::map<std::string, int>& words)
{
    std::cout << std::setw(15) << std::left << "Word"
        << std::setw(7) << std::right << "Count" << std::endl;
    std::cout << "========================================" << std::endl;
    for (const auto& pair : words)
        std::cout << std::setw(15) << std::left << pair.first
            << std::setw(7) << std::right << pair.second << std::endl;
}

void display_word(const std::map<std::string, std::set<int>>& words)
{
    std::cout << std::setw(15) << std::left << "Word"
        << std::setw(7) << std::right << "Occurences" << std::endl;
    std::cout << "========================================" << std::endl;
    for (const auto& pair : words)
    {
        std::cout << std::setw(15) << std::left << pair.first << std::left << "[ ";
        for (const auto& i : pair.second)
            std::cout << i << " ";
        std::cout << "]" << std::endl;
    }
}

std::string clean_string(const std::string& s)
{
    std::string result;
    for (const char c : s)
    {
        if (c == '.' || c == ',' || c == ';' || c == ':' || c == '!' || c == '?')
            continue;
        else
            result += c;
    }
    return result;
}

void partOne()
{
    std::ifstream in_file {"./romeoAndJuliet.txt"};

    if (in_file)
    {
        std::map<std::string, int> words;
        std::string line;
        std::string word;

        while (std::getline(in_file, line))
        {
            std::istringstream iss {line};

            while (iss >> word)
            {
                word = clean_string(word);
                words[word]++;
            }
        }

        in_file.close();
        display_word(words);
    }
    else
        std::cout << "Error opening input file." << std::endl;
}

void partTwo()
{
    std::ifstream in_file {"./romeoAndJuliet.txt"};
    
    if (in_file)
    {
        std::map<std::string, std::set<int>> words;
        std::string line;
        std::string word;
        int line_number {0};

        while (std::getline(in_file, line))
        {
            std::istringstream iss {line};

            line_number++;

            while (iss >> word) 
            {
                word = clean_string(word);
                words[word].insert(line_number);
            }
        }

        in_file.close();
        display_word(words);
    }
    else
        std::cout << "Error opening input file." << std::endl;
}

int main()
{
    partOne();
    partTwo();
    
    return 0;
}
