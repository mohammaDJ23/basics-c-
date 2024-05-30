#include <algorithm>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>
 
struct S
{
    int value{0};
    bool specified_state{true};
 
    S(int v = 0) : value{v} {}
    S(S const& rhs) = default;
    S(S&& rhs) { *this = std::move(rhs); }
    S& operator=(S const& rhs) = default;
    S& operator=(S&& rhs)
    {
        if (this != &rhs)
        {
            value = rhs.value;
            specified_state = rhs.specified_state;
            rhs.specified_state = false;
        }
        return *this;
    }
};
 
template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> const& v)
{
    for (const auto& s : v)
    {
        if constexpr (std::is_same_v<T, S>)
            s.specified_state ? os << s.value << ' ' : os << ". ";
        else if constexpr (std::is_same_v<T, std::string>)
            os << (s.empty() ? "." : s) << ' ';
        else
            os << s << ' ';
    }
    return os;
}
 
int main()
{
    std::cout << std::left;
 
    std::vector<S>           a{1, 2, 3, 4, 5, 6, 7};
    std::vector<int>         b{1, 2, 3, 4, 5, 6, 7};
    std::vector<std::string> c{"α", "β", "γ", "δ", "ε", "ζ", "η"};
 
    std::cout << "vector<S> \tvector<int> \tvector<string>\n";
    std::cout << a << "  " << b << "  " << c << '\n';
 
    std::shift_right(begin(a), end(a), 2);
    std::shift_right(begin(b), end(b), 2);
    std::shift_right(begin(c), end(c), 2);
    std::cout << a << "  " << b << "  " << c << '\n';
}