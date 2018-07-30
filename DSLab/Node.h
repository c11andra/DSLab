
#ifndef NODE_H
#define NODE_H
namespace DSLab
{
    template <class T>
    struct Node{
        T Data;
        Node* Next = NULL;
    };
}

#endif