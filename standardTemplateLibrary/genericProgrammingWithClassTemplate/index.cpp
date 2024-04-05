#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Item final
{
private: 
    std::string name;
    T value;

public:
    Item(std::string name, T value)
        : name(name), value(value) 
    {}

    std::string get_name() const
    {
        return this->name;
    }

    T get_value() const
    {
        return this->value;
    }
};

template <typename T1, typename T2>
struct Pair
{
    T1 first;
    T2 second;
};

int main()
{
    Item<int> item1 {"Jack", 100};
    std::cout << item1.get_name() << " " << item1.get_value() << std::endl;

    Item<std::string> item2 {"Moe", "Professor"};
    std::cout << item2.get_name() << " " << item2.get_value() << std::endl;

    Item<Item<std::string>> item3 {"Frank", {"C++", "Professor"}};
    std::cout << item3.get_name() << " " << item3.get_value().get_name() << " " << item3.get_value().get_value() << std::endl;

    std::vector<Item<double>> vec {};

    vec.push_back(Item<double> {"Larry", 100.0});
    vec.push_back(Item<double> {"Moe", 200.0});
    vec.push_back(Item<double> {"Jack", 200.0});

    for (const auto& item : vec)
        std::cout << item.get_name() << " " << item.get_value() << std::endl;

    Pair<std::string, int> p1 {"Jack", 1000};
    std::cout << p1.first << " " << p1.second << std::endl;

    Pair<double, char> p2 {22.2, 'a'};
    std::cout << p2.first << " " << p2.second << std::endl;
    
    return 0;
}
