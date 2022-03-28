#include <iostream>
#include "KArray.h"

using namespace std;
using std::cin;
using std::cout;

int main()
{
    cout << "hello 02"<<std::endl;
    auto arr = KArray();
    arr.Reserve(10);
    arr.Push(1);
    return 0;
}
