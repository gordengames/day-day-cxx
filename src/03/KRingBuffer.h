#ifndef _KRINGBUFFER_H_
#define _KRINGBUFFER_H_
#include <iostream>

using namespace std;

const int DEFAULT_BUFFER_SIZE = 256;

class KRingBuffer
{
    public:
    KRingBuffer();
    KRingBuffer(int size);
    ~KRingBuffer();

    private:
    int bufferSize;
    int currentSize;

    char* memAddr;
    char* head;
    char* tail;

    void initBufferSize(int size);
};

#endif