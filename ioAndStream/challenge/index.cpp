#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <windows.h>

struct City
{
    std::string name;
    long int population;
    double cost;
};

struct Country
{
    std::string name;
    std::vector<City> cities;
};

struct Tour
{
    std::string title;
    std::vector<Country> countries;
};

Tour make_tour()
{
    return {
        "Tour ticket prices from miami",
        {
            {
                "Colombia",
                {
                    {"Bogota", 8778000, 400.98},
                    {"Cali", 2401000, 424.44},
                    {"Medellin", 2464000, 350.98},
                    {"Cartagena", 972000, 345.34}
                }
            },
            {
                "Brazil",
                {
                    {"Rio De Janiero", 135000000, 567.45},
                    {"Sao Paulo", 11310000, 975.45},
                    {"Salvador", 182340000, 855.99}
                }
            },
            {
                "Chile",
                {
                    {"Valdivia", 260000, 569.45},
                    {"Santiago", 7040000, 444.98}
                }
            },
            {
                "Argentian",
                {
                    {"Buenos Aires", 3010000, 339.45}
                }
            }
        }
    };
}

int main()
{
    Tour tours = make_tour();

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;
  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    
    std::cout << std::setw((columns / 2) + (tours.title.length() / 2)) << tours.title << std::endl << std::endl;
    std::cout << std::setw(columns / 4) << std::left << "Country" 
        << std::setw(columns / 4) << std::left << "City" 
        << std::setw(columns / 4) << std::right << "Population" 
        << std::setw(columns / 4) << std::right << "Price" << std::endl;
    std::cout << std::setw(columns) << std::left << std::setfill('=') << "" << std::endl;
    std::cout << std::setfill(' ');
    for (const auto &country : tours.countries)
    {
        for (size_t i {0}; i < country.cities.size(); i++)
        {
            std::cout << std::setw(columns / 4) << std::left << (i == 0 ? country.name : "")
                << std::setw(columns / 4) << std::left << country.cities.at(i).name 
                << std::setw(columns / 4) << std::right << country.cities.at(i).population
                << std::setw(columns / 4) << std::right << country.cities.at(i).cost << std::endl;
        }
    }
    
    return 0;
}
