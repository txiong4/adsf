#include "UListType.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

template<class T>
bool getInput(T &x);

void ULIST();

int main()
{
    std::cout << "UNORDERED LIST\n";
    ULIST();
    return EXIT_SUCCESS;
}

void ULIST()
{
    srand(time(NULL));
    UListType<int> asdf;
    for(int i = 0; i < 15; i++)
        asdf.insert(rand()%1000 - 500);
    std::cout << asdf << std::endl;
    unsigned short int valuesToFind = 2;
    for(auto i = valuesToFind; i > 0; i--)
    {
        std::cout << "Find " << i << " values.\n";
        int item;
        while(!getInput(item));

        if(!asdf.find(item))
            std::cout << item << " not found.\n";
        else
            std::cout << item << " found.\n";
    }

    /* Copy constructor */
    UListType<int> fdsa(asdf);
    std::cout << fdsa << std::endl;
    std::cout << "Size of fdsa: " << fdsa.size() << std::endl;

    /* Copy via operator overload */
    UListType<int> fdsa_ = asdf;
    std::cout << fdsa_ << std::endl;
    std::cout << "Size of fdsa_: " << fdsa_.size() << std::endl;
}

template<class T>
bool getInput(T &x)
{
    bool goodInput = false;
    std::cout << "  >>> ";
    std::cin >> x;
    std::cin.ignore();
    if(!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(256, '\n');
    }
    else
        goodInput = true;
    return goodInput;
}