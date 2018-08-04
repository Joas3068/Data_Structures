#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include "main.h"


class MinHeap
{
private:
    Data *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap

public:

    MinHeap(int capacity);
 

    void MinHeapify(int );
 
    int parent(int i) { return (i-1)/2; }
 
    int left(int i) { return (2*i + 1); }
    
    int right(int i) { return (2*i + 2); }
 
    Data extractMin();

    Data getMin() { return harr[0]; }
 
    void insertKey(Data k);

    void readAndBuildStruct(std::string filename);

    void sortStruct();

    Data sorted[DATA_SIZE];

    void print();
    void pop();
};
 

#endif