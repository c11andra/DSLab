#include <iostream>
#include <stdio.h>
#include "Queue.h"
using namespace std;
using namespace DSLab;

int main(int argc, char **argv)
{
    Queue<int> q;
    q.Enqueue(1);
    q.Enqueue(3);
    
    while(!q.IsEmptyQueue())
    {
        int i =  q.Dequeue();
        cout << i<<endl;
    }

	return 0;
}
