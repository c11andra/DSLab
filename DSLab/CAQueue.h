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
            int initialCapacity = 0;
            int rear = -1;
            int front = -1;
            
            bool IsFull()
            {
                int currentSize = CurrentSize();
                return capacity == currentSize ;
            }
            
            int CurrentSize()
            {
                if(front == -1) return 0;
                if(rear > front) return rear - front + 1;
                if(rear == front) return 1;
                return rear + 1 + capacity - front;
            }
            
            void IncreaseSize()
            {
                if(!IsFull()) return;
                int oldCapacity = capacity;
                capacity *= 2;
                T* oldArr = arr;
                arr = new T[capacity];
                if(rear > front)
                {
                    for(int i = 0 ; i < oldCapacity; i++)
                    {
                        arr[i] = oldArr[i];
                    }
                }
                else{
                    int count = 0;
                    for(int i = front; i < oldCapacity; i++)
                    {
                        arr[count++] = oldArr[i];
                    }
                    for(int i= 0; i <= rear; i++){
                        arr[count++] = oldArr[i];
                    }
                    
                }
                delete[] oldArr;
            }
            void DecreaseSize()
            {
                int currentSize = CurrentSize();
                if(currentSize > initialCapacity && currentSize < capacity/2 )
                {
                    int oldCapacity = capacity;
                    capacity /= 2;
                    T* oldArr = arr;
                    arr = new T[capacity];
                    if(rear > front){
                        int count = 0;
                        for(int i = front ; i <= rear; i++)
                        {
                            arr[count++] = oldArr[i];
                        }
                        front = 0;
                        rear = count-1;
                    }
                    else{
                        int count = 0;
                        for(int i = front; i < oldCapacity; i++){
                            arr[count++] = oldArr[i];
                        }
                        for(int i= 0; i <= rear; i++){
                            arr[count++] = oldArr[i];
                        }
                        front = 0;
                        rear = count-1;
                    }
                        
                    delete[] oldArr;
                }
            }
    public:
        CAQueue(int startingCapacity)
        {
            initialCapacity = startingCapacity;
            capacity = startingCapacity;
            arr = new T[capacity];
        }
        
        bool IsEmpty()
        {
            return CurrentSize() == 0;
        }
        
        void Enqueue(T data)
        {
            IncreaseSize();
            rear = (rear + 1) % capacity;
            arr[rear] = data;
            if(front == -1)
            {
                front = rear;
            }
        }
        
        T Dequeue()
        {
            T data;
            if(IsEmpty()){return data;}
            data = arr[front];
            if(front == rear) 
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1)%capacity;
            }
            DecreaseSize();
            return data;
        }
        
        bool IsEmptyQueue()
        {
           return front == -1;
        }
    };
}
#endif
