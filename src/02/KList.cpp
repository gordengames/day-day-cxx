#include "KList.h"

KNode* KList::Push(int value)
{
    KNode* node = new KNode(value);
    if(m_Tail == nullptr)
    {
        m_Tail = node;
    }
    else
    {
        m_Tail->m_Next = node;
        node->m_Prev = m_Tail;
        m_Tail = node;
    }
    return node;
}

void KList::PopAll()
{
    while (m_Tail) {
        auto m_Prev = m_Tail->m_Prev;
        delete m_Tail;
        m_Tail = m_Prev;
    }
}

KList::~KList()
{
    PopAll();
}

