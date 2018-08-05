#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "BinaryTreeNode.h"
namespace DSLab
{
    template <class T>
    class BinarySearchTree
    {
        private:
            BinaryTreeNode<T>* root = NULL;

            BinaryTreeNode<T>* Insert(BinaryTreeNode<T>* iRoot, T data)
            {
                if(iRoot == NULL)
                {
                    iRoot = new BinaryTreeNode<T>();
                    iRoot->Data = data;
                    return iRoot;
                }
                if(data < iRoot->Data)
                {
                    iRoot->Left = Insert(iRoot->Left, data);
                }
                else
                {
                    iRoot->Right = Insert(iRoot->Right, data);
                }
            }
            
        public:
            void Insert(T data)
            {
                root = Insert(this->root, data);
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
            
            int FindMax()
            {
                if(root == NULL) return -1;
                BinaryTreeNode<T>* temp = root;
                while(temp->Right)
                {
                    temp = temp->Right;
                }
                return temp->Data;
            }

            int FindMin()
            { 
                if(root == NULL) return -1;
                BinaryTreeNode<T>* temp = root;
                while(temp->Left)
                {
                    temp = temp->Left;
                }
                return temp->Data;
            }

            
    };
    
}
#endif