#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void print_header()
{
    std::cout << std::setw(15) << std::left << "Name" 
        << std::setw(15) << std::right << "Score"
        << std::endl;
}

void print_line()
{
    std::cout << std::setw(30) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
}

void print_student(const std::string &name, const int &score)
{
    std::cout << std::setw(15) << std::left << name
        << std::setw(15) << std::right << score << std::endl;
}

void print_average_score(const double &average_score)
{
    std::cout << std::setprecision(1) << std::fixed;
    std::cout << std::setw(15) << std::left << "Average score: " 
        << std::setw(15) << std::right << average_score << std::endl;
}

int get_score(const std::string &default_answer, const std::string &answer)
{
    int score {0};

    for (int i {0}; i < default_answer.length() && default_answer.length() == answer.length(); i++)
        if (default_answer.at(i) == answer.at(i))
            score++;

    return score;
}

int main()
{
    std::ifstream in_file;
    std::string default_answer;
    std::string name;
    std::string answer;
    int students_num {0};
    int score {0};
    int scores {0};
    double average_score;

    in_file.open("responses.txt");

    if (!in_file.is_open())
    {
        std::cout << "The file is not found." << std::endl;
        return 1;
    }

    in_file >> default_answer;

    print_header();
    print_line();

    while (in_file >> name >> answer)
    {        
        score = get_score(default_answer, answer);

        print_student(name, score);

        scores += score;
        score = 0;  
        students_num++;
    }

    print_line();

    if (students_num != 0)
        average_score = static_cast<double>(scores) / students_num;

    print_average_score(average_score);
    
    in_file.close();
    
    return 0;
}
