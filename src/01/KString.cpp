#include "KString.h"

int GetLength(const char* chars)
{
    if(chars == nullptr)
    {
        return -1;
    }
    int length = 0;
    while (chars[length] != '\0')
    {
        length++;
    }
    return length;
}

//Constructor
KString::KString(const char * input)
{
    if(input == nullptr)
    {
        m_Length = 1;
        m_Chars = new char[m_Length];
        m_Chars[0] = '\0';
    }
    else
    {
        //Initiate a int to store the length of the string
        int length = GetLength(input);
        m_Length = length;
        //Initiate a char array to store the string
        m_Chars = new char[m_Length + 1];
        char* temp = m_Chars;
        for(int i = 0; i < length; i++)
        {
            *temp = *input;
            temp++;
            input++;
        }
        m_Chars[m_Length] = '\0';
    }
}

//Copy Constructor
KString::KString(const KString &ks)
{
    if(this == &ks)
    {
        return;
    }
    m_Length = ks.m_Length;
    m_Chars = new char[ks.m_Length + 1];
    memcpy(m_Chars, ks.m_Chars, ks.m_Length);
    m_Chars[m_Length] = '\0';
}

char * KString::CharArray()
{
    return m_Chars;
}

KString::operator char*()
{
    return m_Chars;
}

KString::operator const char* ()
{
    return m_Chars;
}

//= operator
KString KString::operator =(const KString &ks)
{
    if(this != &ks)
    {
        if(m_Chars != nullptr)
        {
            delete[] m_Chars;
        }
        m_Length = ks.m_Length;
        m_Chars = new char[m_Length + 1];
        memcpy(m_Chars, ks.m_Chars, m_Length);
        m_Chars[m_Length] = '\0';
    }
    return *this;
}

//Get m_Length of char array
int KString::len(void)
{
    return m_Length;
}

//Substring
KString KString::Sub(const int start, const int length)
{
    char* sub_Chars = new char[length + 1];
    char* pTemp = sub_Chars;
    char* pStart = m_Chars + start;
    int count = 0;
    while (count < length)
    {
        *pTemp = *pStart;
        pTemp++;
        pStart++;
        count++;
    }
    sub_Chars[length] = '\0';
    return(KString(sub_Chars));
}

//Append
void KString::Append(const char* chars)
{
    int length = GetLength(chars);
    char* temp = new char[m_Length + length + 1];
    memcpy(temp, m_Chars, m_Length);
    memcpy(temp + m_Length, chars, length);
    temp[m_Length + length] = '\0';
    m_Chars = temp;
    m_Length += length;
}

bool KString::operator==(const KString &ks)
{
    if(m_Length != ks.m_Length)
    {
        return false;
    }
    for(unsigned int i = 0; i < m_Length; i++)
    {
        if(m_Chars[i] != ks.m_Chars[i])
        {
            return false;
        }
    }
    return true;
}

//Find
int KString::Find(const char* chars)
{
    int length = GetLength(chars);
    for(unsigned int i = 0; i < m_Length - length + 1; i++)
    {
        if(memcmp(m_Chars + i, chars, length) == 0)
        {
            return i;
        }
    }
    return -1;
}

//Split
KString* KString::Split(const char* chars)
{
    int index = 0;
    int length = GetLength(m_Chars);
    KString* temp = new KString[length];
    KString subString = KString(*this);
    KString* pTemp = temp;
    int count = 0;
    while (index != -1)
    {
        index = subString.Find(chars);
        if(index > 0)
        {
            auto str1 = subString.Sub(0, index);
            subString = subString.Sub(index + 1, subString.len() - index);
            *pTemp = str1;
            count++;
            pTemp++;
        }
    }
    if (count == 0)
    {
        delete[] temp;
        return nullptr;
    }
    else
    {
        KString* result = new KString[count];
        for(int i = 0; i < count; i++)
        {
            result[i] = temp[i];
        }
        delete[] temp;
        return result;
    }
}

//Destructor
KString::~KString()
{
    if(m_Chars != nullptr)
    {
        delete[] m_Chars;
    }
}