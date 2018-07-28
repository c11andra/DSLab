/*
 *Queue implemented using circular array
 * */
#include "Node.h"
#ifndef CAQUEUE_H
#define CAQUEUE_H
namespace DSLab
{
    template <class T>
    class CAQueue{
    private:
            T *arr;
            int capacity = 0;
            int rear = -1;
            int front = -1;
            
            bool IsQueueFull()
            {
                return capacity == ((rear + 1)%capacity);
            }
            void IncreaseCapacity()
            {
                
            }
    public:
        CAQueue(int startingCapacity)
        {
            capacity = startingCapacity;
            arr = new T[capacity];
        }
        
        bool IsQueueEmpty()
        {
            return front == -1;
        }
        
        void Enqueue(T data)
        {
            if(IsQueueFull())
            {
                IncreaseCapacity();
            }
            arr[++rear] = data;
            if(front == -1)
            {
                front = rear;
            }
        }
        
        T Dequeue()
        {
            T data;
            if(IsQueueEmpty()){return data;}
            data = arr[front];
            if(front == rear) 
            {
                front = rear = -1;
            }
            else
            {
                front = (front +1)%capacity;
            }
            return data;
        }
        
        bool IsEmptyQueue()
        {
           return front == -1;
        }

    };
}
#endif
