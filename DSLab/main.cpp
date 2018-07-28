#include <iostream>
#include <stdio.h>
#include "Queue.h"
#include "Stack.h"
#include "CAQueue.h"

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
    q.Enqueue(4);
    q.Enqueue(3);
    
    while(!q.IsEmptyQueue())
    {
        int i =  q.Dequeue();
        cout << i<<endl;
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
int main(int argc, char **argv)
{
   //TestQueue();
   //TestStack();
   TestCAQueue();
	return 0;
}
