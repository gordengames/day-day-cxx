#include "KArray.h"

//Constructor
KArray::KArray()
{
    m_Count = 0;
    m_Length = 0;
    m_IntArray = nullptr;
}

KArray::KArray(const KArray& ka)
{
    if(this == &ka)
    {
        return;
    }
    Reserve(ka.GetLength());
    m_Length = ka.GetLength();
    m_Count = ka.GetCount();
    for(unsigned int i = 0; i < m_Count; i++)
    {
        m_IntArray[i] = ka.m_IntArray[i];
    }
}

//Destructor
KArray::~KArray()
{
    if(m_IntArray != nullptr)
    {
        delete[] m_IntArray;
    }
}

//Reserve
void KArray::Reserve(unsigned int length)
{
    if(m_Length < length)
    {
        int* temp = new int[length];
        for(unsigned int i = 0; i < m_Count; i++)
        {
            temp[i] = m_IntArray[i];
        }
        delete[] m_IntArray;
        m_IntArray = temp;
        m_Length = length;
    }
}

//Push
void KArray::Push(int value)
{
    if(m_Count == m_Length)
    {
        Reserve(m_Length + 1);
    }
    m_IntArray[m_Count] = value;
    m_Count++;
}