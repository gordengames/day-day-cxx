#ifndef _KARRAY_H_
#define _KARRAY_H_
#include <iostream>

using namespace std;

//我还不会模板，我先写个整形数组的
class KArray
{
    private:
    int* m_IntArray = nullptr;
    unsigned int m_Length = 0;
    unsigned int m_Count= 0;

    public:
    KArray();
    KArray(const KArray& ka);
    ~KArray();

};

#endif