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

//Remove
void KArray::Remove(unsigned int index)
{
    if(index >= m_Count)
    {
        return;
    }
    for(unsigned int i = index; i < m_Count - 1; i++)
    {
        m_IntArray[i] = m_IntArray[i + 1];
    }
    m_Count--;
}

//Pop
void KArray::Pop()
{
    Remove(0);
}

//Clear
void KArray::Clear()
{
    m_Count = 0;
    delete[] m_IntArray;
    m_IntArray = new int[m_Length];
}

int KArray::FindIndex(int value)
{
    for(unsigned int i = 0; i < m_Count; i++)
    {
        if(m_IntArray[i] == value)
        {
            return i;
        }
    }
    return -1;
}