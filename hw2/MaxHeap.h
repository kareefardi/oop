#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <stdio.h>
#include <string>
#include <iostream>

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
                for (int i = 0; i <= Nel; ++i)
                        array[i] = a.array[i];
        }

        MaxHeap& operator=(const MaxHeap &a)
        {
                if (this != &a) {
                        delete[] array;
                        MaxSize = a.MaxSize;
                        Nel = a.Nel;
                        array = new int[MaxSize + 1];
                        for (int i = 0; i <= Nel; ++i)
                                array[i] = a.array[i];
                }
                return *this;
        }

        MaxHeap& operator+(const MaxHeap &a)
        {
                MaxHeap *res = new MaxHeap(MaxSize + a.MaxSize);
                for (int i = 1; i <= Nel; ++i)
                        res->Insert(array[i]);
                for (int i = 1; i <= a.Nel; ++i)
                        res->Insert(a.array[i]);
                return *res;
        }

        MaxHeap& operator+(const int x)
        {
                MaxHeap *res = new MaxHeap(MaxSize + 1);
                for (int i = 0; i <= Nel; ++i) {
                        res->array[i] = array[i];
                }
                res->Nel = Nel;
                res->MaxSize = MaxSize + 1;
                res->Insert(x);
                return *res;
        }

        void operator+=(const MaxHeap &a)
        {
                int Nel_tmp = Nel;
                int*tmp = new int[Nel];
                for (int i = 0; i < Nel; ++i)
                        tmp[i] = array[i + 1];
                delete []array;
                MaxSize = MaxSize + a.MaxSize;
                array = new int [MaxSize + 1];
                array[0] = 0;
                for (int i = 1; i <= Nel; ++i)
                        array[i] = tmp[i - 1];
                if (this != &a)
                        for (int i = 1; i <= a.Nel; ++i)
                                Insert(a.array[i]);  
                else
                        for (int i = 0; i < Nel_tmp; ++i)
                                Insert(tmp[i]);
        }

        void operator+=(int x) {
                int Nel_tmp = Nel;
                int*tmp = new int[Nel];
                for (int i = 0; i < Nel; ++i)
                        tmp[i] = array[i + 1];
                delete []array;
                MaxSize = MaxSize + 1;
                array = new int [MaxSize + 1];
                array[0] = 0;
                for (int i = 1; i <= Nel; ++i)
                        array[i] = tmp[i - 1];
                Insert(x);  
        }

        int operator[](int x)
        {
                if (x > Nel || x < 1)
                        throw "out of range";
                int *arr = new int[x];
                int tmp = 0;
                for (int i = 0; i < x; ++i) {
                        DelMax(arr[i]);
                }
                for (int i = 0; i < x; ++i)
                        Insert(arr[i]);
                int r = arr[x - 1];
                delete[] arr;
                return r;
        }

        friend std::ostream& operator<< (std::ostream &out, MaxHeap &p)
        {
                for (int i = 0; i <= p.Nel; ++i)
                        out << p.array[i] << " ";
                return out;
        }

        ~MaxHeap() { delete[] array; }
        bool Insert(int item);  // Insert item.
        bool DelMax(int & item); // Delete the maximum.
private:
        int * array; 
        int MaxSize, Nel; // Max. size of the Heap, no.elements 
        void Adjust(int a[], int i, int n);
}; // end class MaxHeap

#endif

bool MaxHeap::Insert(int item) 
{ // Inserts item.
        int i = ++Nel; 
        if (i == ( MaxSize + 1 )) {
                std::cout << "Heap size exceeded" << std::endl;
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
                std::cout << "Heap is empty"<< std::endl; 
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