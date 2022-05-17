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
    void Push(const char* value, int length);
    void Print();
    void Pop(char* outValue, int size);

    private:
    int bufferSize;
    int currentSize;

    char* memAddr;
    char* head;
    char* tail;

    void InitBufferSize(int size);
    void ResetBufferSize(int size);
    void PushChar(const char value);
    char PopChar();
};

#endif