#include "UListType.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

int main() {
    UListType<int> asdf;
    asdf.insert(10);
    asdf.insert(20);
    asdf.insert(30);
    asdf.insert(40);
    std::cout << asdf << std::endl;
    return EXIT_SUCCESS;
}