/*

    by default all variable in [] of the lambda is constant
    to be changable you have to use mutable keyword.

*/

#include <iostream>
#include <vector>
#include <algorithm>

int global_x {1000};

/*

    capture by value
    the global variable global_x cannot be captured becuase it is not
    whithin the reaching scope of the lambda. it can however still be
    accessed from within the lambda using normal name lookup rules.

*/
void test1()
{
    std::cout << std::endl << "test1=================" << std::endl;

    int local_x {100};

    auto l = 
        [local_x] ()
        {
            std::cout << local_x << std::endl;
            std::cout << global_x << std::endl;
        };
    l();
}

void test2()
{
    std::cout << std::endl << "test2=================" << std::endl;

    int x {100};

    auto l = 
        /* 

            - [x]: x inside [] will be created just once
                and each time of calling lambda the body
                will be execute. so here the result of the x
                at the first call will be 200 and at the second
                time x will be 300

            - mutable means x can be modify in the lambda 
        
        */
        [x] () mutable
        {
            x+= 100;
            std::cout << x << std::endl;
        };
    l();
    std::cout << x << std::endl;

    l();
    std::cout << x << std::endl;
}

void test3()
{
    std::cout << std::endl << "test3=================" << std::endl;

    int x {100};

    auto l =
        [&x] () mutable
        {
            x += 100;
            std::cout << x << std::endl;
        };
    l();
    std::cout << x << std::endl;
}

void test4()
{
    std::cout << std::endl << "test4=================" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    auto l =
        /*
        
            [=] means capture all the variable by value

        */
        [=] () mutable
        {
            x += 100;
            y += 100;
            std::cout << x << std::endl;
            std::cout << y << std::endl;
        };
    l();
    std::cout << x << std::endl;
    std::cout << y << std::endl;
}

void test5()
{
    std::cout << std::endl << "test5=================" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    auto l =
        /*
        
            [&] means capture all the variable by reference

        */
        [&] ()
        {
            x += 100;
            y += 100;
            z += 100;
            std::cout << x << std::endl;
            std::cout << y << std::endl;
            std::cout << z << std::endl;
        };
    l();
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

void test6()
{
    std::cout << std::endl << "test6=================" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    auto l =
        /*
        
            [=, &y] means capture all the variable by value except y capture by reference

        */
        [=, &y] () mutable
        {
            x += 100;
            y += 100;
            z += 100;
            std::cout << x << std::endl;
            std::cout << y << std::endl;
            std::cout << z << std::endl;
        };
    l();
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

void test7()
{
    std::cout << std::endl << "test7=================" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    auto l =
        /*
        
            [&, x, y] means capture all the variable by reference except x and z capture by value

        */
        [&, x, z] () mutable
        {
            x += 100;
            y += 100;
            z += 100;
            std::cout << x << std::endl;
            std::cout << y << std::endl;
            std::cout << z << std::endl;
        };
    l();
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
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

    /* 
    
        all of these versions will work 
        but always using the first version [this] for lambda

    */
    auto change_person1() {
        return [this] (std::string name, int age) { 
            this->name = name; this->age = age; }; }

    /* 
    
        [=] for lambda is deprecated in c++20

    */
    auto change_person2() {
        return [=] (std::string name, int age) { 
            this->name = name; this->age = age; }; }

    auto change_person3() {
        return [&] (std::string name, int age) { 
            this->name = name; this->age = age; }; }
};

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << "[Person: " << p.name << " : " << p.age << "]";
    return os;
}

void test8()
{
    std::cout << std::endl << "test8=================" << std::endl;

    Person person("Larry", 18);
    std::cout << person << std::endl;

    // used [this] version
    auto change_person1 = person.change_person1();
    change_person1("Moe", 30);
    std::cout << person << std::endl;

    // used [=] version
    auto change_person2 = person.change_person2();
    change_person2("Curly", 25);
    std::cout << person << std::endl;

    // used [&] version
    auto change_person3 = person.change_person3();
    change_person3("Frank", 34);
    std::cout << person << std::endl;
}

class Lambda
{
private:
    int y;

public:
    Lambda(int y) : y(y) {}

    void operator()(int x) const
    {
        std::cout << x + y << std::endl;
    }
};

void test9()
{
    std::cout << std::endl << "test9=================" << std::endl;

    int y {100};
    Lambda lambda1(y);
    auto lambda2 = [y] (int x) { std::cout << x + y << std::endl; };

    lambda1(200);
    lambda2(200);
}

class People
{
    std::vector<Person> people;
    int max_people;

public:
    People(int max = 10) : max_people(max) {}
    People(const People& p) = default;

    void add(std::string name, int age) { people.emplace_back(name, age); }
    void set_max_people(int max) { this->max_people = max; }
    int get_max_people() const { return this->max_people; }

    std::vector<Person> get_people(int max_age) const
    {
        std::vector<Person> result;
        int count {0};
        std::copy_if(this->people.begin(),
            this->people.end(),
            std::back_inserter(result),
            [this, &count, max_age] (const Person& p)
            {
                return p.get_age() > max_age && ++count <= this->max_people;
            });
        return result;
    }
};

void test10()
{
    std::cout << std::endl << "test10=================" << std::endl;

    People friends;

    friends.add("Larry", 18);
    friends.add("Curly", 25);
    friends.add("Moe", 35);
    friends.add("ّFrank", 28);
    friends.add("James", 65);

    auto result = friends.get_people(17);
    for (const auto& p : result)
        std::cout << p << std::endl;

    friends.set_max_people(3);

    result = friends.get_people(17);
    std::cout << std::endl;
    for (const auto& p : result)
        std::cout << p << std::endl;

    result = friends.get_people(50);
    std::cout << std::endl;
    for (const auto& p : result)
        std::cout << p << std::endl;
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
    test8();
    test9();
    test10();
    
    return 0;
}
