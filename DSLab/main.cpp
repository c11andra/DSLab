#include <iostream>
#include <stdio.h>
#include "Queue.h"
#include "Stack.h"
#include "CAQueue.h"
#include "LinkedList.h"
#include "BinaryTree.h"

using namespace std;
using namespace DSLab;
void TestQueue()
{
    Queue<int> q;
    q.Enqueue(4);
    q.Enqueue(3);
    
    while(!q.IsEmptyQueue())
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
    
    while(!q.IsEmptyQueue())
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
    
    while(!s.IsEmptyStack())
    {
        int i =  s.Pop();
        cout << i<<endl;
    }
    
}

void LinkedListTest()
{
    LinkedList<int> l;
    l.Insert(1, 0);
    l.Insert(3, 1);
    l.Insert(2, 1);
    l.Insert(4, 3);
    l.Insert(9, 10);
    
    l.PrintAll();
    cout << "Delettion and Print" << endl;
    l.Delete(0);
    l.Delete(2);
    l.Delete(3);

    l.PrintAll();
}
int main(int argc, char **argv)
{
   //TestQueue();
   //TestStack();
   //TestCAQueue();
   LinkedListTest();
	return 0;
}
