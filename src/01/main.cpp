#include <iostream>
#include "KString.h"

using namespace std;

int main()
{
    KString ks("aaa");
    std::cout << ks.CharArray() << std::endl;
    return 0;
}