#include <iostream>
#include "KString.h"

using namespace std;
using std::cout;

int main()
{
    auto str1 = KString("test1");
    auto str2 = KString("test3,append");
    auto str3 = KString('c',10);
    str1 = "test3";
    KString sub1 = str1.Sub(1,2);
    str1.Append("append");
    bool equal = str1 == str2;
    int index = str1.Find("es");
    KString* ret = str2.Split(",");
    cout << str1.CharArray() << std::endl;
    cout << str1.len() << std::endl;
    cout << sub1.CharArray() << std::endl;
    cout << equal << std::endl;
    cout << index << std::endl;
    cout << ret[0].CharArray() << std::endl;
    cout << str3.CharArray()<< std::endl;
    return 0;
}