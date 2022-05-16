#include "KRingBuffer.h"

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
    }
}