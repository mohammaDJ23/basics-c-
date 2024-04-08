/*

    std::deque (double-ended queue) is an indexed sequence container that 
    allows fast insertion and deletion at both its beginning and its end. 
    In addition, insertion and deletion at either end of a deque never invalidates pointers or 
    references to the rest of the elements.

    As opposed to std::vector, the elements of a deque are not stored contiguously: 
    typical implementations use a sequence of individually allocated fixed-size arrays, 
    with additional bookkeeping, which means indexed access to deque must perform two pointer dereferences, 
    compared to vector's indexed access which performs only one.

    The storage of a deque is automatically expanded and contracted as needed. 
    Expansion of a deque is cheaper than the expansion of a std::vector because 
    it does not involve copying of the existing elements to a new memory location. 
    On the other hand, deques typically have large minimal memory cost; 
    a deque holding just one element has to allocate its full internal array (e.g. 8 times the object size on 
    64-bit libstdc++; 16 times the object size or 4096 bytes, whichever is larger, on 64-bit libc++).

    The complexity (efficiency) of common operations on deques is as follows:

    Random access - constant O(1).
    Insertion or removal of elements at the end or beginning - constant O(1).
    Insertion or removal of elements - linear O(n).
    std::deque meets the requirements of Container, AllocatorAwareContainer, SequenceContainer and ReversibleContainer.

    Invalidation notes
    When inserting at either end of the deque, references are not invalidated by insert and emplace.
    push_front, push_back, emplace_front and emplace_back do not invalidate any references to elements of the deque.
    When erasing at either end of the deque, references to non-erased elements are not invalidated by erase, pop_front and pop_back.
    A call to resize with a smaller size does not invalidate any references to non-erased elements.
    A call to resize with a bigger size does not invalidate any references to elements of the deque.

*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

template<typename T>
void display(const std::deque<T>& dec)
{
    std::cout << "[ ";
    for (const auto& item : dec)
        std::cout << item << " ";
    std::cout << "]" << std::endl;
}

void test1()
{
    std::cout << "test1==============================" << std::endl;

    std::deque<int> dec {1, 2, 3, 4};
    display(dec);

    dec = {2, 3, 4, 5};
    display(dec);

    std::deque dec2 (10, 100);
    display(dec2);

    dec2.at(0) = 200;
    dec2[1] = 300;
    display(dec2);

    std::cout << std::endl;
}

void test2()
{
    std::cout << "test2==============================" << std::endl;

    std::deque<int> dec {0, 0, 0};
    display(dec);

    dec.push_back(10);
    dec.push_back(20);
    display(dec);

    dec.push_front(100);
    dec.push_front(200);
    display(dec);

    std::cout << "front: " << dec.front() << std::endl;
    std::cout << "back: " << dec.back() << std::endl;
    std::cout << "size: " << dec.size() << std::endl;
    std::cout << "max_size: " << dec.max_size() << std::endl;

    dec.pop_front();
    dec.pop_back();
    display(dec);

    std::cout << std::endl;
}

void test3()
{
    std::cout << "test3==============================" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> dec;

    for (const auto& item : vec)
    {
        if (item % 2 == 0)
            dec.push_back(item);
        else
            dec.push_front(item);
    }
    display(dec);

    std::cout << std::endl;
}

void test4()
{
    std::cout << "test4==============================" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> dec;

    for (const auto& item : vec)
        dec.push_front(item);
    
    display(dec);

    dec.clear();

    for (const auto& item : vec)
        dec.push_back(item);
    
    display(dec);

    std::cout << std::endl;
}

void test5()
{
    std::cout << "test5==============================" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> dec;

    std::copy(vec.begin(), vec.end(), std::front_inserter(dec));
    display(dec);

    dec.clear();

    std::copy(vec.begin(), vec.end(), std::back_inserter(dec));
    display(dec);

    std::cout << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    
    return 0;
}
