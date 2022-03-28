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

//Print
void KArray::Print()
{
    if (m_IntArray == nullptr)
    {
        return;
    }
    for(unsigned int i = 0; i < m_Count; i++)
    {
        cout << m_IntArray[i] << " ";
    }
    cout << endl;
}

//Insert
void KArray::Insert(unsigned int index, int value)
{
    if(index > m_Count)
    {
        return;
    }
    if(m_Count == m_Length)
    {
        Reserve(m_Length + 1);
    }
    for(unsigned int i = m_Count; i > index; i--)
    {
        m_IntArray[i] = m_IntArray[i - 1];
    }
    m_IntArray[index] = value;
    m_Count++;
}