
#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H
namespace DSLab
{
    template <class T>
    struct BinaryTreeNode{
        T Data;
        BinaryTreeNode<T>* Left = NULL;
        BinaryTreeNode<T>* Right = NULL;
    };
}

#endif