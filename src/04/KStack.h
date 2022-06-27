#ifndef _KSTACK_H_
#define _KSTACK_H_
#include <iostream>

using namespace std;

struct KStackNode {
    void* data = nullptr;
    KStackNode* next = nullptr;
    int size;

    KStackNode(int valueSize) {
        size = valueSize;
        next = nullptr;
    }
};

class KStack
{
    private:
    KStackNode* top;

    public:
    KStack()
    {
        top = nullptr;
    }

    ~KStack()
    {
        auto currentNode = top;
        while (currentNode) {
            auto nextNode = currentNode->next;
            delete currentNode;
            currentNode = nullptr;
            if (nextNode) {
                currentNode = nextNode;
            }
        }
    }

    template<typename T>
    void push(T value)
    {
        int size = sizeof(value);
        KStackNode* temp = new KStackNode(size);
        temp->data = new T(value);

        if (top) {
            auto currentNode = top;
            while (currentNode) {
                if (currentNode->next) {
                    currentNode = currentNode->next;
                }
                else {
                    break;
                }
            }
            currentNode->next = temp;
        }
        else {
            top = temp;
        }
    }

    template<typename T>
    void pop(T& value)
    {
        if (top == nullptr) {
            return;
        }
        auto temp = top->next;
        T* currentNode = (T*)top->data;
        memcpy(&value, currentNode, top->size);
        delete top->data;
        delete top;
        top = temp;
    }
};

#endif
