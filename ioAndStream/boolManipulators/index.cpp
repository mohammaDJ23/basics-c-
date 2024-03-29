#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "noboolalpha - default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha - default (10 == 20): " << (10 == 20) << std::endl;

    // set to true/false formatting
    std::cout << std::boolalpha;
    
    std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "boolalpha (10 == 20): " << (10 == 20) << std::endl;

    std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "boolalpha (10 == 20): " << (10 == 20) << std::endl;

    // toggle to 0/1
    std::cout << std::noboolalpha;

    std::cout << "noboolalpha (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha (10 == 20): " << (10 == 20) << std::endl;

    // set back to true/false using setf method
    std::cout.setf(std::ios::boolalpha);

    std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "boolalpha (10 == 20): " << (10 == 20) << std::endl;

    // resets to default which is 0/1 from true/false
    std::cout << std::resetiosflags(std::ios::boolalpha);

    std::cout << "noboolalpha - default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha - default (10 == 20): " << (10 == 20) << std::endl;
    
    return 0;
}
