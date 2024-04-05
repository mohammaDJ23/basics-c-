#include <iostream>
#include <string>

template <typename T, int N>
class Array final
{
private:
    int size {N};
    T values[N];

    friend std::ostream& operator<<(std::ostream& os, const Array<T, N>& rhs)
    {
        os << "[ ";
        for (const auto& value : rhs.values)
            os << value << " ";
        os << "]";
        return os;
    }

public:
    Array() = default;

    Array(T initial_value)
    {
        for (auto& value : this->values)
            value = initial_value;
    }

    void fill(T initial_value)
    {
        for (auto& value : this->values)
            value = initial_value;
    }

    int get_size() const
    {
        return this->size;
    }

    T& operator[](int index)
    {
        return this->values[index];
    }
};

int main()
{
    Array<int, 5> arr1;
    std::cout << arr1.get_size() << " " << arr1 << std::endl;
    arr1.fill(0);
    std::cout << arr1.get_size() << " " << arr1 << std::endl;

    Array<std::string, 10> arr2;
    std::cout << arr2.get_size() << " " << arr2 << std::endl;
    arr2.fill("Frank");
    arr2[0] = "Jack";
    arr2[1] = std::string {"Moe"};
    std::cout << arr2.get_size() << " " << arr2 << std::endl;
    
    return 0;
}
