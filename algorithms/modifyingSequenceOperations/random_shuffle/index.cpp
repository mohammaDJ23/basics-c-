#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

template<class RandomIt>
void random_shuffle(RandomIt first, RandomIt last)
{
    typedef typename std::iterator_traits<RandomIt>::difference_type diff_t;
 
    for (diff_t i = last - first - 1; i > 0; --i)
    {
        using std::swap;
        swap(first[i], first[std::rand() % (i + 1)]);
        // rand() % (i + 1) is not actually correct, because the generated number is
        // not uniformly distributed for most values of i. The correct code would be
        // a variation of the C++11 std::uniform_int_distribution implementation.
    }
}

template<class RandomIt, class RandomFunc>
void random_shuffle(RandomIt first, RandomIt last, RandomFunc&& r)
{
    typedef typename std::iterator_traits<RandomIt>::difference_type diff_t;
 
    for (diff_t i = last - first - 1; i > 0; --i)
    {
        using std::swap;
        swap(first[i], first[r(i + 1)]);
    }
}
 
int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 
    std::random_device rd;
    std::mt19937 g(rd());
 
    std::shuffle(v.begin(), v.end(), g);
 
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}