#include "KRingBuffer.h"

KRingBuffer::KRingBuffer()
{
    initBufferSize(DEFAULT_BUFFER_SIZE);
}

KRingBuffer::KRingBuffer(int size)
{
    initBufferSize(size);
}

KRingBuffer::~KRingBuffer()
{
    free(memAddr);
}

void KRingBuffer::initBufferSize(int size)
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