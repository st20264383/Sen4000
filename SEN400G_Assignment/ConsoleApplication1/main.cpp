#include <iostream>
#include <cstdlib>
#include "Dimensions.h"

int main(int argc, char** argv)
{
    std::cout << "Hello World!" << std::endl;

    Dimensions* d = new Dimensions();
    d->setWidth(0);
    

    exit(EXIT_SUCCESS);
}
