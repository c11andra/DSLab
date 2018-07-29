
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <iostream>
namespace DSLab
{
    template <class T>
    class LinkedList{
        private:
            Node<T>* head = NULL;;
        public:
            int Length()
            {
                int count = 0;
                Node<T>* temp = head;
                while(temp != NULL){
                    temp = temp->Next;
                    ++count;
                }
                return count;
            }

            void Insert(T data, int position)
            {
                Node<T>* newNode = new Node<T>();
                newNode->Data = data;
                if(position == 0)
                {
                    newNode->Next = head;
                    head = newNode;
                    return;
                }

                int currPos = 0;
                Node<T>* temp = head;
                Node<T>* prev = NULL;
                while(temp != NULL)
                {
                    if(currPos == position)
                    {
                        prev->Next = newNode;
                        newNode->Next = temp;
                        return ;
                    }
                    prev = temp;
                    temp = temp->Next;
                    ++currPos;
                }
                if(currPos == position)
                {
                    prev->Next = newNode;
                    return;
                }
                std::cout << "Valid position not found" <<std::endl;
            }

            void Delete(int position)
            {
                
                if(position == 0)
                {
                    Node<T>* temp = head;
                    head = head->Next;
                    delete temp;
                    return;
                }

                Node<T>* prev = NULL;
                Node<T>* temp = head;
                int currPos = 0;
                while(temp != NULL)
                {
                    if(currPos == position)
                    {
                        prev->Next = temp->Next;
                        delete temp;
                        return ;
                    }
                    prev = temp;
                    temp = temp->Next;
                    ++ currPos;
                }
                std::cout <<"Valid Postion to delete not found" << std::endl;
            }

            void PrintAll()
            {
                Node<T>* temp = head;
                while(temp != NULL){
                    std::cout << temp->Data<< std::endl;
                    temp = temp->Next;
                }
            }

    };
}

#endif