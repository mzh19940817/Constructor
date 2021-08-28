#include "Constructor.h"
#include <iostream>

struct Resource
{
    Resource()
    {
        std::cout << "Resource acquired" << std::endl;
    }

    ~Resource()
    {
        std::cout << "Resource destroy" << std::endl;
    }
};

int main()
{
    AutoPtr4<Resource> res1{new Resource()}; // construct local variable

    AutoPtr4<Resource> res2{res1}; // copy construct

    AutoPtr4<Resource> res3;
    res3 = res1; // copy assignment

    AutoPtr4<Resource> res4{new Resource()}; // move constructor

    AutoPtr4<Resource> res5;
    res5 = new Resource(); // move assignment

    return 0;
}
