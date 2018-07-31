
#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
#include "BinaryTreeNode.h"
#include "Queue.h"
namespace DSLab
{
    template <class T>
    class BinaryTree{
        private:
            BinaryTreeNode<T>* root = NULL;
        public:
            void Insert(T data)
            {
               BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>();
               newNode->Data = data;

               if(root == NULL)
               {
                   root = newNode;
                   return ;
               } 
               
               Queue<BinaryTreeNode<T>*> q;
               BinaryTreeNode<T>* temp = root;
               q.Enqueue(temp);
 
               while(!q.IsEmpty())
               {
                   temp = q.Dequeue();
                   if(temp->Left != NULL) 
                   {
                       q.Enqueue(temp->Left);
                   }
                   else
                   {
                       temp->Left = newNode;
                       return;
                   }
                   if(temp->Right != NULL) 
                   {
                        q.Enqueue(temp->Right);
                   }
                   else
                   {
                       temp->Right = newNode;
                       return;
                   }
               }
            }

            void TraverseLevelOrder()
            {
               Queue<BinaryTreeNode<T>*> q;
               BinaryTreeNode<T>* temp = root;
               q.Enqueue(temp);

               while(!q.IsEmpty())
               {
                  temp = q.Dequeue();
                   std::cout << temp->Data << std::endl;
                   if(temp->Left != NULL)
                   {
                        q.Enqueue(temp->Left);
                   } 
                   if(temp->Right != NULL)
                   {
                        q.Enqueue(temp->Right);
                   } 
               }
            }

            void TraverseInOrder()
            {
                Stack<BinaryTreeNode<T>*> s;
                BinaryTreeNode<T>* temp = root;
                while(1)
                {
                    while(temp != NULL)
                    {
                        s.Push(temp); 
                        temp = temp->Left;
                    }

                    if(!s.IsEmpty())
                    {
                        temp = s.Pop();
                        std::cout << temp->Data<<std::endl;
                        temp = temp->Right;
                    }
                    else
                        break;
                    
                }
            }
    };
}

#endif