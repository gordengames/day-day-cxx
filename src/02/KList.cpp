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

KNode* KList::Insert(KNode* node, int value)
{
    if (node == nullptr)
    {
        return Push(value);
    }

    KNode* newNode = new KNode(value);
    if(node->m_Prev == nullptr)
    {
        newNode->m_Next = node;
        node->m_Prev = newNode;
        m_Tail = newNode;
    }
    else
    {
        newNode->m_Next = node;
        newNode->m_Prev = node->m_Prev;
        node->m_Prev->m_Next = newNode;
        node->m_Prev = newNode;
    }
    return newNode;
}

KNode* KList::Find(int value)
{
    KNode* node = m_Tail;
    while(node != nullptr)
    {
        if(node->m_Value == value)
        {
            return node;
        }
        node = node->m_Prev;
    }
    return nullptr;
}

void KList::Remove(KNode* node)
{
    if(node == nullptr)
    {
        return;
    }

    if(node->m_Next == nullptr)
    {
        node->m_Prev->m_Next = nullptr;
    }
    else
    {
        if(node->m_Prev == nullptr)
        {
            node->m_Next->m_Prev = nullptr;
        }
        else
        {
            node->m_Prev->m_Next = node->m_Next;
            node->m_Next->m_Prev = node->m_Prev;
        }
    }

    delete node;
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

