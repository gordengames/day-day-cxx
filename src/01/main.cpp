#include <iostream>
#include "KString.h"

using namespace std;

int main()
{
    auto str1 = KString("test1");
    auto str2 = KString("test2, test3");
    str1 = "test3";
    KString sub1 = str1.Sub(1,2);
    std::cout << str1.CharArray() << std::endl;
    std::cout << str1.len() << std::endl;
    std::cout << sub1.CharArray() << std::endl;
    return 0;
}