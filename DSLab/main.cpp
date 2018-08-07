#include <iostream>
#include <stdio.h>
#include "Queue.h"
#include "Stack.h"
#include "CAQueue.h"
#include "LinkedList.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "Heap.h"

using namespace std;
using namespace DSLab;
void TestQueue()
{
    Queue<int> q;
    q.Enqueue(4);
    q.Enqueue(3);
    
    while(!q.IsEmpty())
    {
        int i =  q.Dequeue();
        cout << i<<endl;
    }
}

void TestCAQueue()
{
    CAQueue<int> q(2);
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.Enqueue(6);

    q.Dequeue();
    q.Dequeue();

    q.Enqueue(7);
    q.Enqueue(8);
    
    while(!q.IsEmpty())
    {
        int i =  q.Dequeue();
        cout << i << endl;
    }
}
void TestStack()
{
    Stack<int> s;
    s.Push(9);
    s.Push(10);
    
    while(!s.IsEmpty())
    {
        int i =  s.Pop();
        cout << i<<endl;
    }
    
}

void TestLinkedList()
{
    LinkedList<int> l;
    l.Insert(1, 0);
    l.Insert(3, 1);
    l.Insert(2, 1);
    l.Insert(4, 3);
    l.Insert(9, 10);
    
    l.PrintAll();
    cout << "Delete and Print" << endl;
    l.Delete(0);
    l.Delete(2);
    l.Delete(3);

    l.PrintAll();
}

void TestBinaryTree()
{
    BinaryTree<int> tree;
    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(3);
    tree.Insert(4);
    tree.Insert(5);
    tree.Insert(6);
    tree.Insert(7);
    tree.Insert(8);
    tree.Insert(9);
    tree.Insert(10);

    cout << "\n---LevelOrder---"<< endl;
    tree.TraverseLevelOrder();

    cout << "---InOrder---"<< endl;
    tree.TraverseInOrder();
    
    cout << "---PreOrder---"<< endl;
    tree.TraversePreOrder();

    cout << "---PostOrder---"<< endl;
    tree.TraversePostOrder();
}


void TestBinarySearchTree()
{
    BinarySearchTree<int> tree;
    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(3);
    tree.Insert(4);
    tree.Insert(5);
    tree.Insert(6);
    tree.Insert(7);
  
    cout << "\n---InOrder---"<< endl;
    tree.TraverseInOrder();
    cout << "\n Max: " << tree.FindMax()<<endl;

    cout << "\n Min: " << tree.FindMin()<<endl;
}

void TestHeap()
{
    Heap<int> h;
    int arr[] = {1,2,3,4,5};
    h.BuildHeap(arr, 5, 10);

    for(int i = 0; i < 5; i++)
    {
        cout << h.DeleteMax() << endl;
    }
}

int main(int argc, char **argv)
{
   //TestQueue();
   //TestStack();
   //TestCAQueue();
  // TestLinkedList();
   //TestBinaryTree();
   //TestBinarySearchTree();
   TestHeap();
   
	return 0;
}
