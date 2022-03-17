#ifndef _KSTRING_H_
#define _KSTRING_H_
#include <iostream>

using namespace std;

class KString
{
    private:
        //Initiate a char array to store the string
        char* m_Chars = nullptr;
        //Initiate a int to store the length of the string
        unsigned int m_Length = 0;

    public:
        KString(const char* chars);
        KString(const KString& ks);
        ~KString();
        char * CharArray();
        operator char*();
        operator const char*();
        KString operator=(const KString& ks);
        int len();
        KString Sub(const int start, const int length);

};
#endif