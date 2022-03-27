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
    m_Length = ka.m_Length;
    m_Count = ka.m_Count;
    for(unsigned int i = 0; i < ka.m_Length; i++)
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