#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// for_each => non-modifying sequence operation
void test1()
{
    std::cout << std::endl << "test1===============" << std::endl;

    std::vector<int> nums {10, 20, 30, 40, 50};

    std::for_each(nums.begin(),
        nums.end(),
        [] (int num) { std::cout << num << " "; });
    std::cout << std::endl;
}

// is_permutation => non-modifying sequence operation
void test2()
{
    std::cout << std::endl << "test2===============" << std::endl;

    struct Point
    {
        int x;
        int y;
    };

    Point pt1 {1, 2};
    Point pt2 {4, 3};
    Point pt3 {3, 5};
    Point pt4 {3, 1};

    std::vector<Point> triangle1 {pt1, pt2, pt3};
    std::vector<Point> triangle2 {pt2, pt3, pt1};
    std::vector<Point> triangle3 {pt1, pt2, pt4};

    if (std::is_permutation(triangle1.begin(),
        triangle1.end(),
        triangle2.begin(),
        [] (Point lhs, Point rhs) { return lhs.x == rhs.x && lhs.y == rhs.y; }))
        std::cout << "Triangle1 and Triangle2 are equivalant" << std::endl;
    else
        std::cout << "Triangle1 and Triangle2 are not equivalant" << std::endl;

    if (std::is_permutation(triangle1.begin(),
        triangle1.end(),
        triangle3.begin(),
        [] (Point lhs, Point rhs) { return lhs.x == rhs.x && lhs.y == rhs.y; }))
        std::cout << "Triangle1 and Triangle3 are equivalant" << std::endl;
    else
        std::cout << "Triangle1 and Triangle3 are not equivalant" << std::endl;
}

// transform => modifying sequence operation
void test3()
{
    std::cout << std::endl << "test3===============" << std::endl;

    std::vector<int> scores {93, 88, 75, 68, 65};
    int bonus_points {5};

    std::transform(scores.begin(),
        scores.end(), 
        scores.begin(),
        [bonus_points] (int score) { return score += bonus_points; });

    std::for_each(scores.begin(),
        scores.end(),
        [] (int score) { std::cout << score << " "; });
    std::cout << std::endl;
}

// remove_if => modifying sequence operation
void test4()
{
    std::cout << std::endl << "test4===============" << std::endl;

    std::vector<int> nums {1, 2, 3, 4, 5};
    int bonus_points {5};

    nums.erase(std::remove_if(nums.begin(),
            nums.end(),
            [] (int num) { return num % 2 == 0; }),
        nums.end());

    std::for_each(nums.begin(), nums.end(),
        [] (int num) { std::cout << num << " "; });
    std::cout << std::endl;
}

class Person
{
    friend std::ostream& operator<<(std::ostream& os, const Person& p);

private:
    std::string name;
    int age;

public:
    Person() = default;
    Person(std::string name, int age) : name(name), age(age) {}
    Person(const Person& p) = default;
    ~Person() = default;

    std::string get_name() const { return this->name; }
    int get_age() const { return this->age; }
    void set_name(std::string name) { this->name = name; }
    void set_age(int age) { this->age = age; }
};

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << "[Person: " << p.name << " : " << p.age << "]";
    return os;
}

// sorting => modifying sequence operation
void test5()
{
    std::cout << std::endl << "test5===============" << std::endl;

    Person person1 ("Larry", 18);
    Person person2 ("Moe", 30);
    Person person3 ("Curly", 25);

    std::vector<Person> people {person1, person2, person3};

    std::sort(people.begin(), people.end(),
        [] (const Person& p1, const Person& p2) { return p1.get_name() < p2.get_name(); });

    std::for_each(people.begin(), people.end(),
        [] (const Person& person) { std::cout << person << " "; });
    std::cout << std::endl;

    std::sort(people.begin(), people.end(),
        [] (const Person& p1, const Person& p2) { return p1.get_age() > p2.get_age(); });

    std::for_each(people.begin(), people.end(),
        [] (const Person& person) { std::cout << person << " "; });
    std::cout << std::endl;
}

bool is_between(const std::vector<int>& nums, int start, int end)
{
    return std::all_of(nums.begin(),
        nums.end(),
        [start, end] (int num) { return num >= start && num <= end; });
}

// all_of => non-modifying sequence operation
void test6()
{
    std::cout << std::endl << "test6===============" << std::endl;

    std::vector<int> nums (10);
    std::iota(nums.begin(), nums.end(), 1);

    std::cout << std::boolalpha;
    std::cout << is_between(nums, 50, 60) << std::endl;
    std::cout << is_between(nums, 1, 10) << std::endl;
    std::cout << is_between(nums, 5, 7) << std::endl;
}

class Password_validator1
{
private:
    char restricted_symbol {'$'};

public:
    bool is_valid(std::string password)
    {
        return std::all_of(password.begin(), 
            password.end(),
            [this] (char c) { return c != this->restricted_symbol; });
    }
};

class Password_validator2
{
private:
    std::vector<char> restricted_symbols {'!', '$', '+'};

public:
    bool is_valid(std::string password)
    {
        return std::all_of(password.begin(), 
            password.end(),
            [this] (char c) { 
                return std::none_of(this->restricted_symbols.begin(),
                    this->restricted_symbols.end(),
                    [c] (char symbol) { 
                        return c != symbol; 
                    });    
            });
    }
};

void test7()
{
    std::cout << std::endl << "test7===============" << std::endl;

    std::string password {"holywood1$"};

    Password_validator1 pv1;
    if (pv1.is_valid(password))
        std::cout << password << " is valid" << std::endl;
    else    
        std::cout << password << " is not valid" << std::endl;

    password = "holywood1";
    if (pv1.is_valid(password))
        std::cout << password << " is valid" << std::endl;
    else    
        std::cout << password << " is not valid" << std::endl;

    password = "C++Rocks!";
    Password_validator2 pv2;
    if (pv2.is_valid(password))
        std::cout << password << " is valid" << std::endl;
    else    
        std::cout << password << " is not valid" << std::endl;

    password = "CPlusPlusRocks!";
    if (pv2.is_valid(password))
        std::cout << password << " is valid" << std::endl;
    else    
        std::cout << password << " is not valid" << std::endl;

    password = "CPlusPlusRocks";
    if (pv2.is_valid(password))
        std::cout << password << " is valid" << std::endl;
    else    
        std::cout << password << " is not valid" << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    
    return 0;
}
