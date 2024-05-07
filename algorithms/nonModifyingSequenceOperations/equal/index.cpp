#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string_view>

template<class InputIt1, class InputIt2>
constexpr bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
{
    for (; first1 != last1; ++first1, ++first2)
        if (!(*first1 == *first2))
            return false;
 
    return true;
}

template<class InputIt1, class InputIt2, class BinaryPred>
constexpr bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPred p)
{
    for (; first1 != last1; ++first1, ++first2)
        if (!p(*first1, *first2))
            return false;
 
    return true;
}

namespace Details
{
    // random-access iterator implementation (allows quick range size detection)
    template<class RandomIt1, class RandomIt2>
    constexpr bool equal(RandomIt1 first1, 
        RandomIt1 last1, 
        RandomIt2 first2, 
        RandomIt2 last2,
        std::random_access_iterator_tag, 
        std::random_access_iterator_tag)
    {
        if (last1 - first1 != last2 - first2)
            return false;
 
        for (; first1 != last1; ++first1, ++first2)
            if (!(*first1 == *first2))
                return false;
 
        return true;
    }
 
    // input iterator implementation (needs to manually compare with “last2”)
    template<class InputIt1, class InputIt2>
    constexpr bool equal(InputIt1 first1, 
        InputIt1 last1, 
        InputIt2 first2, 
        InputIt2 last2,
        std::input_iterator_tag,
        std::input_iterator_tag)
    {
        for (; first1 != last1 && first2 != last2; ++first1, ++first2)
            if (!(*first1 == *first2))
                return false;
 
        return first1 == last1 && first2 == last2;
    }
}
 
template<class InputIt1, class InputIt2>
constexpr bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
{
    return Details::equal(first1, last1, first2, last2,
        typename std::iterator_traits<InputIt1>::iterator_category(),
        typename std::iterator_traits<InputIt2>::iterator_category());
}

namespace Details
{
    // random-access iterator implementation (allows quick range size detection)
    template<class RandomIt1, class RandomIt2, class BinaryPred>
    constexpr bool equal(RandomIt1 first1, 
        RandomIt1 last1, 
        RandomIt2 first2, 
        RandomIt2 last2, 
        BinaryPred p, 
        std::random_access_iterator_tag, 
        std::random_access_iterator_tag)
    {
        if (last1 - first1 != last2 - first2)
            return false;
 
        for (; first1 != last1; ++first1, ++first2)
            if (!p(*first1, *first2))
                return false;
 
        return true;
    }
 
    // input iterator implementation (needs to manually compare with “last2”)
    template<class InputIt1, class InputIt2, class BinaryPred>
    constexpr bool equal(InputIt1 first1, 
        InputIt1 last1,
        InputIt2 first2, 
        InputIt2 last2, 
        BinaryPred p,
        std::input_iterator_tag, 
        std::input_iterator_tag)
    {
        for (; first1 != last1 && first2 != last2; ++first1, ++first2)
            if (!p(*first1, *first2))
                return false;
 
        return first1 == last1 && first2 == last2;
    }
}
 
template<class InputIt1, class InputIt2, class BinaryPred>
constexpr bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, BinaryPred p)
{
    return Details::equal(first1, last1, first2, last2, p,
        typename std::iterator_traits<InputIt1>::iterator_category(),
        typename std::iterator_traits<InputIt2>::iterator_category());
}
 
constexpr bool is_palindrome(const std::string_view& s)
{
    return std::equal(s.cbegin(), s.cbegin() + s.size() / 2, s.crbegin());
}
 
void test(const std::string_view& s)
{
    std::cout << std::quoted(s)
        << (is_palindrome(s) ? " is" : " is not")
        << " a palindrome\n";
}
 
int main()
{
    test("radar");
    test("hello");

    return 0;
}