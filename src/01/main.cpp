#include <iostream>
#include "KString.h"

using namespace std;
using std::cout;

int main()
{
    auto str1 = KString("test1");
    auto str2 = KString("test3append");
    str1 = "test3";
    KString sub1 = str1.Sub(1,2);
    str1.Append("append");
    bool equal = str1 == str2;
    cout << str1.CharArray() << std::endl;
    cout << str1.len() << std::endl;
    cout << sub1.CharArray() << std::endl;
    cout << equal << std::endl;
    return 0;
}