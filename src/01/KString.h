#ifndef _KSTRING_H_
#define _KSTRING_H_
#include <iostream>
using namespace std;

class KString
{
    private:
        //Initiate a char array to store the string
        char *chars = nullptr;
        //Initiate a int to store the length of the string
        unsigned int length = 0;

    public:
        KString();
        KString(const char* const chars);
        KString(KString& ks);
        ~KString();
        char * CharArray();
        operator char*();
        operator const char*();
        KString operator=(const KString& ks);
        int len();

};

KString::KString():chars{nullptr}, length{0}
{
    chars = new char[1];
    chars[0] = '\0';
}

KString::KString(const char * const input)
{
    //Initiate a int to store the length of the string
    length = strlen(input);
    //Initiate a char array to store the string
    chars = new char[length + 1];
    //Copy the string to the char array
    strncpy_s(chars, length + 1, input, length);
}

KString::KString(KString &ks)
{
    if(this == &ks)
    {
        return;
    }
    chars = new char[ks.length + 1];
    strncpy_s(chars, length + 1, ks.chars, length);
}

char * KString::CharArray()
{
    return chars;
}

KString::operator char*()
{
 return chars;
}

KString::operator const char* ()
{
 return chars;
}

KString KString::operator =(const KString &ks)
{
    if(this != &ks)
    {
        if(chars != nullptr)
        {
            delete[] chars;
        }
        length = ks.length;
        chars = new char[length + 1];
        strncpy_s(chars, length + 1, ks.chars, length);
    }
    return *this;
}

int KString::len()
{
    return length;
}

KString::~KString()
{
    if(chars != nullptr)
    {
        delete[] chars;
    }
}

#endif