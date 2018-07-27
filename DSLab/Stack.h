#include "Node.h"
#ifndef STACK_H
#define STACK_H
namespace DSLab
{
    template <class T>
    class Stack
    {
        private:
            Node<T>* head = NULL;
        public:
            void Push(T data)
            {
                Node<T>* temp = new Node<T>();
                temp->Data = data;
                if(head == NULL) head = temp;
                else
                {
                    temp->Next = head;
                    head = temp;
                }
            }
            
            T Pop()
            {
                T data;
                if(IsEmptyStack()) return data;
                data = head->Data;
                Node<T>* temp = head;
                head = head->Next;
                delete(temp);
                return data;
            }
            
            bool IsEmptyStack()
            {
                return head == NULL;
            }
        
    };
}
#endif