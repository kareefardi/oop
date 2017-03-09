#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <string>
using namespace std;

class MaxHeap 
{
public:
        MaxHeap(int Msize) : MaxSize(Msize)
        {
                array = new int[MaxSize + 1]; Nel = 0;
        }

        MaxHeap(MaxHeap &a)
        {
                MaxSize = a.MaxSize;
                Nel = a.Nel;
                array = new int[MaxSize + 1];
                for (int i = 0; i <= MaxSize; ++i)
                        array[i] = a.array[i];
        }

        MaxHeap& operator=(const MaxHeap a)
        {
                delete[] array;
                MaxSize = a.MaxSize;
                Nel = a.Nel;
                array = new int[MaxSize + 1];
                for (int i = 0; i <= MaxSize; ++i)
                        array[i] = a.array[i];
                        return this;
        }

        MaxHeap& operator+(const MaxHeap a)
        {
        }

        MaxHeap& operator[] (const int i)
        {
                int *arr_tmp = new int[MaxSize + 1];
                int e = 0;
                for (int i = 0; i <= MaxSize; ++i)
        }

        MaxHeap& operator+(const MaxHeap a, const int b)
        {
                if((Nel + 1) = MaxSize)
                        // max size exceeded
                else
                        Insert(b);
                return this;
        }

        MaxHeap& operator
        ~MaxHeap() { delete[] array; }
        bool Insert(int item);  // Insert item.
        bool DelMax(int & item); // Delete the maximum.
private:
        int * array; 
        int MaxSize, Nel; // Max. size of the Heap, no.elements 
        void Adjust(int a[], int i, int n);
}; // end class MaxHeap

#endif MAXHEAP_H

bool MaxHeap::Insert(int item) 
{ // Inserts item.
        int i = ++Nel; 
        if (i == ( MaxSize + 1 )) {
                cout << "Heap size exceeded" << endl;
                Nel--; 
                return false; 
        }
        while ((i > 1) && (array[i / 2] < item)) {
                array[i] = array[i/2]; 
                i /= 2; 
        } 
        array[i] = item; 
        return true; 
} 

bool MaxHeap::DelMax(int & item) 
{
        if (!Nel) {
                cout << "Heap is empty"<< endl; 
                return false; 
        }
        item = array[1]; 
        array[1] = array[Nel--];
        Adjust(array, 1, Nel); 
        return true;
}

void MaxHeap::Adjust(int a[], int i, int n) 
// The complete binary trees with roots 2*i and 2*i+1 are 
// combined with node i to form a Heap rooted at i. No 
// node has an address greater than n or less than 1.
{
        int j = 2*i, item = a[i]; 
        while (j <= n) { 
        if ((j<n) && (a[j] < a[j+1]))
                j++;
        // Compare left and right child
        // and let j be the larger child.
        if (item >= a[j]) 
                break;
                // A position for item is found.
                a[j/2] = a[j];
                j *= 2;
        }
        a[j/2] = item; 
}