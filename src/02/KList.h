#ifndef _KLIST_H_
#define _KLIST_H_

#include <iostream>

using namespace std;

//我还不会模板，我先写个整形链表的
struct KNode
{
    int m_Value;
    KNode* m_Next = nullptr;
    KNode* m_Prev = nullptr;

    KNode() = default;
    KNode(int value)
    {
        m_Value = value;
    }
    ~KNode()
    {
        m_Prev = nullptr;
        m_Next = nullptr;
    }
};

class KList
{
    private:
    KNode* m_Tail = nullptr;

    public:
    KList() = default;
    KList(const KList& kl) =default;
    KNode* Push(int value);
    void PopAll();
    ~KList();
};

#endif