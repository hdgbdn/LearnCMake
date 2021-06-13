#include <iostream>
#include <lib.h>

int main(int argc, char *argv[])
{
    std::cout << "Hello Compile Flags!" << std::endl;

#ifdef FLAG_1
    std::cout << "The Main is FLAG_1 !" << std::endl;
#endif

#ifdef FLAG_2
    std::cout << "The Main is FLAG_2 !" << std::endl;
#endif

    Foo();
    return 0;
}
