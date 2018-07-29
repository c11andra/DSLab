
#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "BinaryTreeNode.h"
namespace DSLab
{
    template <class T>
    struct BinaryTree{
        BinaryTreeNode<T>* root;
    };
}

#endif