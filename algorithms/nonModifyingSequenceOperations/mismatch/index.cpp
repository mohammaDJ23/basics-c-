#include <algorithm>
#include <iostream>
#include <string>

template<class InputIt1, class InputIt2>
std::pair<InputIt1, InputIt2> mismatch(InputIt1 first1, InputIt1 last1, InputIt2 first2)
{
    while (first1 != last1 && *first1 == *first2)
        ++first1, ++first2;
 
    return std::make_pair(first1, first2);
}

template<class InputIt1, class InputIt2, class BinaryPred>
std::pair<InputIt1, InputIt2> mismatch(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPred p)
{
    while (first1 != last1 && p(*first1, *first2))
        ++first1, ++first2;
 
    return std::make_pair(first1, first2);
}

template<class InputIt1, class InputIt2>
std::pair<InputIt1, InputIt2> mismatch(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
{
    while (first1 != last1 && first2 != last2 && *first1 == *first2)
        ++first1, ++first2;
 
    return std::make_pair(first1, first2);
}

template<class InputIt1, class InputIt2, class BinaryPred>
std::pair<InputIt1, InputIt2> mismatch(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, BinaryPred p)
{
    while (first1 != last1 && first2 != last2 && p(*first1, *first2))
        ++first1, ++first2;
 
    return std::make_pair(first1, first2);
}
 
std::string mirror_ends(const std::string& in)
{
    return std::string(in.begin(), std::mismatch(in.begin(), in.end(), in.rbegin()).first);
}
 
int main()
{
    std::cout << mirror_ends("abXYZba") << '\n'
        << mirror_ends("abca") << '\n'
        << mirror_ends("aba") << '\n';

    return 0;
}