#include <iostream>
#include <map>
#include <set>

void display(const std::map<std::string, std::set<int>>& m)
{
    std::cout << "[ ";
    for (const auto& item : m)
    {
        std::cout << item.first << ": [ ";
        for (const auto& value : item.second)
            std::cout << value << " ";
        std::cout << "] ";
    }
    std::cout << "]" << std::endl;
}

template <typename T1, typename T2>
void display(const std::map<T1, T2>& m)
{
    std::cout << "[ ";
    for (const auto& item : m)
        std::cout << item.first << ":" << item.second << " ";
    std::cout << "]" << std::endl;
}

void test1()
{
    std::cout << std::endl << "test1=====================" << std::endl;

    std::map<std::string, int> m {{"Larry", 3},
        {"Moe", 1}, 
        {"Curly", 2}};

    display(m);

    m.insert(std::pair<std::string, int>("Anna", 10));
    display(m);

    m.insert(std::make_pair("Joe", 5));
    display(m);

    m["Frank"] = 18;
    display(m);

    m["Frank"] += 10;
    display(m);

    m.erase("Frank");
    display(m);

    std::cout << "Count for joe: " << m.count("Joe") << std::endl;
    std::cout << "Count for Frank: " << m.count("Frank") << std::endl;

    auto it = m.find("Larry");
    if (it != m.end())
        std::cout << "Found: " << it->first << ":" << it->second << std::endl;

    m.clear();
    display(m);

    std::cout << std::endl;
}

void test2()
{
    std::cout << std::endl << "test2=====================" << std::endl;

    std::map<std::string, std::set<int>> m {{"Larry", {100, 90}},
        {"Moe", {94}}, 
        {"Curly", {80, 90, 100}}};

    display(m);

    m["Larry"].insert(95);
    display(m);

    auto it = m.find("Moe");
    if (it != m.end())
        it->second.insert(1000);
    
    display(m);

    std::cout << std::endl;
}

int main()
{
    test1();
    test2();

    return 0;
}
