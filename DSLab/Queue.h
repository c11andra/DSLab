#include "Node.h"
#ifndef QUEUE_H
#define QUEUE_H
namespace DSLab
{
    template <class T>
    class Queue{
        private:
            Node<T>* front = NULL;
            Node<T>* rear = NULL;
    public:
        void Enqueue(T data)
        {
            if(front == NULL)
            {
                front = new Node<T>();
                front->Data = data;
                rear = front;
            }
            else
            {
                rear->Next = new Node<T>();
                rear->Next->Data = data;
                rear = rear->Next;
            }
            
        }
        
        T Dequeue()
        {
            T data;
            if(IsEmptyQueue())return data;
            Node<T>* temp = front;
            
            front = front->Next;
            data = temp->Data;
            delete(temp);
            return data;
        }
        
        bool IsEmptyQueue()
        {
            if(front == NULL) return true;
            return false;
        }

    };
}
#endif
