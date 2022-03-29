#ifndef _KARRAY_H_
#define _KARRAY_H_
#include <iostream>

using namespace std;

//我还不会模板，我先写个整形数组的
class KArray
{
    private:
    int* m_IntArray = nullptr;
    unsigned int m_Count= 0; //real count of the array
    unsigned int m_Length = 0; //length that the array can hold
    

    public:
    KArray();
    KArray(const KArray& ka);
    ~KArray();
    void Reserve(unsigned int length);
    unsigned int const GetCount() const {return m_Count;}
    unsigned int const GetLength() const {return m_Length;}
    void Push(int value);
    void Print();
    void Insert(unsigned int index, int value);
    void Remove(unsigned int index);
    void Pop();
    void Clear();
    int FindIndex(int value);
};

#endif