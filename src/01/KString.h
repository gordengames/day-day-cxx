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
#endif