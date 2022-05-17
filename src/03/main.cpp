#include <iostream>
#include<time.h>
#include "KRingBuffer.h"
#include "string.h"

using namespace std;
using std::cin;
using std::cout;

int main()
{
    cout << "hello 03"<<std::endl;
    int initSize = 256;
    const char* data = "123456789";
    auto buffer = new KRingBuffer(initSize);
    srand(int(time(NULL)));

    int length = (int)strlen(data) + 1;

    std::cout << length << std::endl;

    int pushCount = 4;
    std::cout << pushCount << std::endl;
    for (int j = 0; j < pushCount; j++)
    {
        buffer->Push(data, length);
    }
    buffer->Print();
    char out[128];
    int popCount = 1;
    std::cout << sizeof(out) << std::endl;
    for (int j = 0; j < popCount; j++)
    {
        buffer->Pop(&out[0], sizeof(out));
    }
    buffer->Print();
}
