#include <iostream>
#include <vector>
#include <string>

/*

    test one

*/

enum Direction {North, South, East, West};
// enum Street {Main, North, Elm}; // error, can't use North again.

std::string direction_to_string(Direction direction)
{
    std::string result;

    switch (direction)
    {
        case North: result = "North"; break;
        case South: result = "Soutch"; break;
        case East: result = "East"; break;
        case West: result = "West"; break;
        default: result = "Unknown direction"; break;
    }

    return result;    
}

void test1()
{
    std::cout << std::endl << "test1============" << std::endl;

    Direction direction {North};

    std::cout << "direction: " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;

    direction = West;

    std::cout << "direction: " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;

    // direction = 5; // compiler error

    // be careful casting since the compilter will assume
    // you know what you are doing
    direction = Direction(100);

    std::cout << "direction: " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;

    // be careful casting since the compilter will assume
    // you know what you are doing
    direction = static_cast<Direction>(100);

    std::cout << "direction: " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;
}

/*

    test two

*/

enum Grocery_item {Milk, Bread, Apple, Orange};

std::ostream& operator<<(std::ostream& os, const Grocery_item g)
{
    switch(g)
    {
        case Milk: os << "Milk"; break;
        case Bread: os << "Bread"; break;
        case Apple: os << "Apple"; break;
        case Orange: os << "Orange"; break;
        default: os << "Invalid item"; break;
    }
    
    return os;
}

bool is_valid_grocery_item(const Grocery_item& g)
{
    switch(g)
    {
        case Milk:
        case Bread:
        case Apple:
        case Orange: return true;
        default: return false;
    }
}

void display_grocery_list(const std::vector<Grocery_item>& groceries)
{
    int invalid_item_count {0};
    int valid_item_count {0};

    for (Grocery_item g : groceries)
    {
        std::cout << g << std::endl;

        if (is_valid_grocery_item(g))
            valid_item_count++;
        else 
            invalid_item_count++;
    }

    std::cout << "Valid items: " << valid_item_count << std::endl;
    std::cout << "Invalid items: " << invalid_item_count << std::endl;
    std::cout << "Total items: " << valid_item_count + invalid_item_count << std::endl;
}

void test2()
{
    std::cout << std::endl << "test2============" << std::endl;

    std::vector<Grocery_item> shopping_list;

    shopping_list.push_back(Apple);
    shopping_list.push_back(Apple);
    shopping_list.push_back(Milk);
    shopping_list.push_back(Orange);

    // Grocery_item item = 100; // compiler error

    // be careful when casting
    int helicopter {1000};

    shopping_list.push_back(Grocery_item(helicopter)); // invlaid item
    shopping_list.push_back(Grocery_item(0)); // will add milk again

    display_grocery_list(shopping_list);
}

/*

    test three

*/

enum State {Engine_failure, Increment_weather, Nominal, Unknown};
enum Sequence {Abort, Hold, Launch};

std::istream& operator>>(std::istream& is, State& s)
{
    std::underlying_type_t<State> user_input;
    is >> user_input;

    switch(user_input)
    {
        case Engine_failure:
        case Increment_weather:
        case Nominal:
        case Unknown: s = State(user_input); break;
        default: std::cout << "User input is not a valid launch state." << std::endl; s = Unknown; break;
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const Sequence& s)
{
    switch(s)
    {
        case Abort: os << "Abort"; break;
        case Hold: os << "Hold"; break;
        case Launch: os << "Launch"; break;
    }

    return os;
}

void initiate(Sequence s)
{
    std::cout << "Initiate " << s << " sequence" << std::endl;
}

void test3()
{
    std::cout << std::endl << "test3============" << std::endl;

    State state;
    std::cout << "Launch state: ";
    std::cin >> state;

    switch(state)
    {
        case Engine_failure:
        case Unknown: initiate(Abort); break;
        case Increment_weather: initiate(Hold); break;
        case Nominal: initiate(Launch); break;
    }
}

int main()
{
    test1();
    test2();
    test3();
    
    return 0;
}
