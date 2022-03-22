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
        KString(const char* chars = nullptr);
        KString(const KString& ks);
        KString(const char c, const unsigned int length);
        ~KString();
        char * CharArray();
        operator char*();
        operator const char*();
        KString operator=(const KString& ks);
        int len();
        KString Sub(const int start, const int length);
        void Append(const char* chars);
        bool operator==(const KString& ks);
        int Find(const char* chars);
        KString* Split(const char* chars);
        KString operator+(const KString& ks);
        void operator+=(const KString& ks);
        bool empty();
        bool operator!=(const KString& ks);
};
#endif