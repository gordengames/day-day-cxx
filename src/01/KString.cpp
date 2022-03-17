#include "KString.h"

//Constructor
KString::KString():chars{nullptr}, length{0}
{
    chars = new char[1];
    chars[0] = '\0';
}

//Constructor
KString::KString(const char * const input)
{
    //Initiate a int to store the length of the string
    length = strlen(input);
    //Initiate a char array to store the string
    chars = new char[length + 1];
    //Copy the string to the char array
    strncpy_s(chars, length + 1, input, length);
}

//Copy Constructor
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

//= operator
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

//Get length of char array
int KString::len(void)
{
    return length;
}

//Destructor
KString::~KString()
{
    if(chars != nullptr)
    {
        delete[] chars;
    }
}

