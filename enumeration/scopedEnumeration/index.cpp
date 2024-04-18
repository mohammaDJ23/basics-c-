#include <iostream>
#include <vector>
#include <string>

/*

    test one

*/

enum class Grocery_item : int {Milk = 350, 
    Bread = 250, 
    Apple = 132, 
    Orange = 100};

std::ostream& operator<<(std::ostream& os, const Grocery_item g)
{
    std::underlying_type_t<Grocery_item> value = std::underlying_type_t<Grocery_item>(g);

    switch(g)
    {
        case Grocery_item::Milk: os << "Milk"; break;
        case Grocery_item::Bread: os << "Bread"; break;
        case Grocery_item::Apple: os << "Apple"; break;
        case Grocery_item::Orange: os << "Orange"; break;
        default: os << "Invalid item"; break;
    }

    os << " : " << value;
    
    return os;
}

bool is_valid_grocery_item(const Grocery_item& g)
{
    switch(g)
    {
        case Grocery_item::Milk:
        case Grocery_item::Bread:
        case Grocery_item::Apple:
        case Grocery_item::Orange: return true;
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

void test1()
{
    std::cout << std::endl << "test1============" << std::endl;

    std::vector<Grocery_item> shopping_list;

    shopping_list.push_back(Grocery_item::Apple);
    shopping_list.push_back(Grocery_item::Milk);
    shopping_list.push_back(Grocery_item::Orange);

    // Grocery_item item = 100; // compiler error

    // be careful when casting
    int helicopter {1000};

    shopping_list.push_back(Grocery_item(helicopter)); // invlaid item
    shopping_list.push_back(Grocery_item(350)); // will add milk again

    display_grocery_list(shopping_list);
}

/*

    test two

*/

class Player
{
    friend std::ostream& operator<<(std::ostream &os, const Player& p);

public:
    enum class Mode {Attack, Defense, Idle};
    enum class Direction {North, South, East, West};

    Player(std::string name,
        Mode mode = Mode::Idle,
        Direction direction = Direction::North)
        : name(name), mode(mode), direction(direction) {}

    std::string get_name() const { return this->name; }
    void set_name(std::string name) { this->name = name; }

    Mode get_mode() const { return this->mode; }
    void set_mode(Mode mode) { this->mode = mode; }

    Direction get_direction() const { return this->direction; }
    void set_direction(Direction direction) { this->direction = direction; }

private:
    std::string name;
    Mode mode;
    Direction direction;
};

std::string get_player_mode(Player::Mode mode)
{
    std::string result;

    switch(mode)
    {
        case Player::Mode::Attack: result = "Attack"; break;
        case Player::Mode::Defense: result = "Defense"; break;
        case Player::Mode::Idle: result = "Idle"; break;
    }
    
    return result;
}

std::string get_player_direction(Player::Direction direction)
{
    std::string result;

    switch(direction)
    {
        case Player::Direction::North: result = "North"; break;
        case Player::Direction::South: result = "South"; break;
        case Player::Direction::East: result = "East"; break;
        case Player::Direction::West: result = "West"; break;
    }
    
    return result;
}

std::ostream& operator<<(std::ostream& os, const Player &p)
{
    os << "Player name: " << p.name << std::endl
        << "Player mode: " << get_player_mode(p.mode) << std::endl
        << "Player direction: " << get_player_direction(p.direction) << std::endl;
    
    return os;
}

void test2()
{
    std::cout << std::endl << "test2============" << std::endl;

    Player p1 ("Cloud Strife", Player::Mode::Attack, Player::Direction::North);
    Player p2 ("Tifa Lockhart", Player::Mode::Defense, Player::Direction::West);
    Player p3 ("Sephiroth", Player::Mode::Idle, Player::Direction::South);

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
}

int main()
{
    test1();
    test2();
    
    return 0;
}
