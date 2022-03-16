#include <iostream>
#include "KString.h"
#include <string>
using namespace std;

int main()
{
    auto str1 = KString("test1");
    auto str2 = KString("test2, test3");
    str1 = "test3";
    std::cout << str1.CharArray() << std::endl;
    std::cout << str1.len() << std::endl;
    return 0;
}