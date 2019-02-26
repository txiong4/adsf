#include "UListType.h"
#include "OListType.h"
#include <iostream>

void OListTesting();
void UListTesting();

int main() 
{
    //OListTesting();
    UListTesting();
    return 0;
}

void OListTesting()
{
    OListType<int> Olist; 
 
    Olist.insert(10);
    Olist.insert(30);
    Olist.insert(20);
    Olist.insert(50);
    Olist.insert(2);
    Olist.insert(100);
    Olist.insert(33);

    std::cout << "Ordered List" << std::endl;
    std::cout << Olist << std::endl;
    std::cout << std::endl;
    
    std::cout << "1 = true and 0 = false" << std::endl;
    std::cout << "80 is on the list: " << Olist.find(80) << std::endl;
    std::cout << "2 is on the list: " << Olist.find(2) << std::endl;
    std::cout << std::endl;

    std::cout << "Erased Ordered List" << std::endl;
    Olist.erase(10);
    std::cout << Olist << std::endl;
    std::cout << std::endl;   

}

void UListTesting()
{
    UListType<int> Ulist;  

    Ulist.insert(10);
    Ulist.insert(20);
    Ulist.insert(93);
    Ulist.insert(30);
    Ulist.insert(50);
    Ulist.insert(40);

    std::cout << "Unordered List" << std::endl;
    std::cout << Ulist << std::endl;
    std::cout << std::endl;

    std::cout << "1 is true and 0 is false" << std::endl;
    std::cout << "25 is on the list: " << Ulist.find(25) << std::endl;
    std::cout << "30 is on the list: " << Ulist.find(30) << std::endl;
    std::cout << std::endl;

    Ulist.erase(10);
    Ulist.erase(40);

    std::cout << "Erased Unordered List" << std::endl;
    std::cout << Ulist << std::endl;
    std::cout << std::endl;
}
