#define _CRT_SECURE_NO_WARNINGS
#include "KRingBuffer.h"
#include "string.h"

KRingBuffer::KRingBuffer()
{
    InitBufferSize(DEFAULT_BUFFER_SIZE);
}

KRingBuffer::KRingBuffer(int size)
{
    InitBufferSize(size);
}

KRingBuffer::~KRingBuffer()
{
    free(memAddr);
}

void KRingBuffer::InitBufferSize(int size)
{
    char* p = (char*)malloc(sizeof(char) * (size));
    if(p)
    {
        bufferSize = size;
        memAddr = p;
        memset(memAddr, 0, sizeof(char) * (size));
        head = memAddr;
        tail = memAddr;
        currentSize = 0;
    }
}

void KRingBuffer::ResetBufferSize(int size)
{
    char* p = (char*)realloc(memAddr, sizeof(char) * (size));
    if(p)
    {
        bufferSize = size;
        memAddr = p;
        head = memAddr;
        tail = memAddr + currentSize;
        memset(memAddr + currentSize + 1, 0, sizeof(char) * (size) - currentSize);
    }
}

void KRingBuffer::Push(const char* value, int length)
{
    int addSize = length - 1;
    if (currentSize + addSize > bufferSize)
    {
        ResetBufferSize(bufferSize + addSize * 2);
        std::cout << "buffersize:" << bufferSize << std::endl;
    }
    currentSize += addSize;
    int index = 0;
    const char* temp = value;
    while (index < addSize)
    {
        PushChar(temp[index]);
        index++;
    }
}

void KRingBuffer::PushChar(const char value)
{
    auto PushExc = [&]()
    {
        tail[0] = value;
        tail++;
    };
    if(tail > head)
    {
        if(memAddr + bufferSize >= tail + 1)
        {
            PushExc();
        }
        else
        {
            tail = memAddr;
            PushExc();
        }
    }
    else if (tail < head)
    {
        if (tail + 1 == head)
        {
            std::cout << "over range 1" << std::endl;
        }
        else
        {
            PushExc();
        }
    }
    else
    {
        PushExc();
    }
}

void KRingBuffer::Print()
{
    std::cout << currentSize << std::endl;
    int count = 0;
    while(count < bufferSize)
    {
        if (memAddr[count])
        {
            std::cout << memAddr[count];
        }
        else
        {
            std::cout << 0;
        }
        count++;
    }
}

char KRingBuffer::PopChar()
{
    char returnChar = head[0];
    head[0] = 0;

    if(head + 1 >= memAddr + bufferSize)
    {
        head = memAddr;
    }
    else
    {
        head++;
    }
    return returnChar;
}

void KRingBuffer::Pop(char* outValue, int size)
{
    if(size > currentSize)
    {
        size = currentSize;
    }
    currentSize -= size;

    int index = 0;
    while (index < size)
    {
        char temp = PopChar();
        outValue[index] = temp;
        index ++;
    }
    if (bufferSize - currentSize > DEFAULT_BUFFER_SIZE * 2)
    {
        ResetBufferSize(currentSize + DEFAULT_BUFFER_SIZE);
    }
}