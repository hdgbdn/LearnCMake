#include <iostream>

void Foo()
{
    std::cout << "Hello Compile Lib Flags!" << std::endl;

#ifdef FLAG_1
    std::cout << "The lib is FLAG_1 !" << std::endl;
#endif

#ifdef FLAG_2
    std::cout << "The lib is FLAG_2 !" << std::endl;
#endif
}