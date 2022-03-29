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
    arr.Push(2);
    arr.Insert(1, 3);
    int index = arr.FindIndex(4);
    cout << "index: " << index << endl; 
    arr.Print();
    return 0;
}
