
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
            
            void TraversePreOrder()
            {
                Stack<BinaryTreeNode<T>*> s;
                BinaryTreeNode<T>* temp = root;
                while(1)
                {
                    while(temp != NULL)
                    {
                        std::cout << temp->Data<<std::endl;
                        s.Push(temp); 
                        temp = temp->Left;
                    }

                    if(!s.IsEmpty())
                    {
                        temp = s.Pop();
                        temp = temp->Right;
                    }
                    else
                        break;
                    
                }
            }

            void TraversePostOrder()
            {
                if(!root)
                {
                     std::cout<< "Tree is empty";
                     return;
                }
                Stack<BinaryTreeNode<T>*> s;
                BinaryTreeNode<T>* temp = root;

                int rootEncountered = 0;
                while(1)
                {
                    while(temp)
                    {
                        s.Push(temp); 
                        temp = temp->Left;
                    }

                    if(s.Top()->Right == NULL)
                    {
                        temp = s.Pop();
                        std::cout << temp->Data << std::endl;
                        if(s.Top()->Right == temp)
                        {
                            std::cout << s.Pop()->Data << std::endl;
                        }
                    }

                    if(!s.IsEmpty())
                    {
                        if(s.Top() == root)
                        {
                            if(++rootEncountered == 2)
                            {
                                std::cout << s.Pop()->Data << std::endl;
                                break;
                            }
                        }
                        
                        temp = s.Top()->Right;
                    } 
                    
                }
            }
    };
}

#endif