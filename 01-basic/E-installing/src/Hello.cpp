#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Hello.h"

void Hello::print()
{
    std::ifstream file;
    file.exceptions(std::ifstream::failbit);
    try
    {
        file.open("content.txt");
        std::stringstream stream;
        stream << file.rdbuf();
        file.close();
        std::string content = stream.str();
        std::cout << content << std::endl;
    }
    catch (std::ifstream::failure& e)
    {
        std::cout << e.what() << std::endl;
    }
}