
#ifndef HEAP_H
#define HEAP_H
namespace DSLab
{
    enum HeapType {MaxHeap = 0, MinHeap};
    template <class T>
    class Heap{
        private:
            T* arr;
            HeapType heapType = MaxHeap;
            int capacity = 10;
            int count = 0;
            int Parent(int i)
            {
                if(i <= 0 || i > count) return -1;
                return (i-1)/2;
            }

            int LeftChild(int i)
            {
                if(i < 0 || i > count) return -1;
                int pos = 2*i+1;
                return pos > count -1 ? -1 : pos;
            }

            int RightChild(int i)
            {
                if(i < 0 || i > count) return -1;
                int pos = 2*i+2;
                return pos > count - 1 ? -1 : pos;
            }

        public:
            void BuildHeap(T array[], int iCount, int iCapacity)
            {
                this->capacity = iCapacity;
                arr = new T[capacity];
                this->count = iCount;
                for(int i = 0; i < iCount; i ++)
                {
                    arr[i] = array[i];
                }
                for(int i = (iCount-2)/2; i >= 0; i --)
                {
                    PercolateDown(i);
                }
            }

            void PercolateDown(int i)
            {
                int l = LeftChild(i);
                int r = RightChild(i);

                int max = i;

                if(l != -1 && arr[l] > arr[max]) max = l;
                if(r != -1 && arr[r] > arr[max]) max = r;
                
                if(max != i)
                {
                    T temp = arr[i];
                    arr[i] = arr[max];
                    arr[max] = temp;
                    PercolateDown(max);
                }
            }

            T DeleteMax()
            {
                T max = arr[0];
                arr[0] = arr[count-1];
                count --;
                PercolateDown(0);
                return max;
            }

    };
}
#endif