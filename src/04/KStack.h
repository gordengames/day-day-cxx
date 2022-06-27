#ifndef _KSTACK_H_
#define _KSTACK_H_
#include <iostream>
#include <stack>
#include <assert.h>

using namespace std;

struct KStackNode
{
    void* data = nullptr;
    std::string typeStr;
};

class KStack
{
    private:
    std::stack<KStackNode> m_stack;

    public:
	template<typename T>
	void push(const T& value)
    {
		KStackNode node;
		node.typeStr = typeid(T).name();
		T* ptr = new T();
		*ptr = value;
		node.data = (void*)ptr;
		m_stack.push(node);
	}

	template<typename T>
	void pop(T& value)
    {
		KStackNode node = m_stack.top();
		if (std::string(typeid(T).name()) != node.typeStr)
		{
			assert(false);
			return;
		}
		T* ptr = (T*)(node.data);
		value = *ptr;
		delete node.data;
		m_stack.pop();
	}
};

#endif
