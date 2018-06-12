#include "minHeap.h"
#include "main.h"
#include <iostream>
#include <fstream>
#include <sstream> 
#include<climits>
//#include "main.h"
using namespace std;

//This code was provided by https://www.geeksforgeeks.org/binary-heap/
//To implement this code I had to create my own swap funciton and combine funtion

void swapHeap(string * swap1,int *count1,int *count3,string *swap2,int *count2,int *count4);

 
 int combine(int a, int b) 
 {
   int times = 1;
   while (times <= b)
      times *= 10;
   return a*times + b;
} 


MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new Data[cap];
}
 
void MinHeap::print()
{
    for(int i =0; i< heap_size;i++)
        cout<<harr[i].name<<endl;
}


void MinHeap::insertKey(Data k)
{    
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
 
    
    heap_size++;
    int i = heap_size - 1;
    int j = heap_size-1;
    harr[i] = k;
    
    // Fix the min heap property if it is violated
    while (i != 0 && combine(harr[parent(i)].priority,harr[parent(i)].treatment) > combine(harr[i].priority,harr[i].treatment))
    {
  
       swapHeap(&harr[i].name,&harr[i].priority,& harr[i].treatment,&harr[parent(i)].name,&harr[parent(i)].priority,&harr[parent(i)].treatment);
       i = parent(i);
       
    }
    // if(heap_size == DATA_SIZE)
    // {
    //     for(int i =0; i<DATA_SIZE;i++)
    //     cout<<i+1<<". "<<harr[i].name<<", "<<harr[i].priority<<",  "<<harr[i].treatment<<endl;
    // }

}
 


Data MinHeap::extractMin()
{
    if (heap_size <= 0)
        return harr[0] ;

    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
 

    Data root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);


    return root;
}
 

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);

    int smallest = i;

    if (l < heap_size && combine(harr[l].priority,harr[l].treatment) < combine(harr[i].priority,harr[i].treatment))
    {
 
        smallest = l;
    }

    if (r < heap_size && combine(harr[r].priority,harr[r].treatment) < combine(harr[smallest].priority,harr[smallest].treatment))
    {

        smallest = r;
    }


    if (smallest != i)
    {

        swapHeap(&harr[i].name,&harr[i].priority,& harr[i].treatment,&harr[smallest].name,&harr[smallest].priority,&harr[smallest].treatment);

        MinHeapify(smallest);
    }

}

 

void swapHeap(string * swap1,int *count1,int *count3,string *swap2,int *count2,int *count4) //swap 1 to 2, 3 to 4
{

int tempI = *count1;
int tempII = *count3;   
string tempS = *swap1;


*count1 = *count2;
*count3 = *count4;
*swap1 = *swap2;

*count2 = tempI;
*count4 = tempII;
*swap2 = tempS;

}


void MinHeap::readAndBuildStruct(string fileName)
{	

	ifstream file(fileName);

	
	int count = 0;
		if(file.is_open())
		{		//if file is open parse
			
			string line;	
			string one;
			file>>one;
			
			while(file>>line)
				{	
					stringstream ss;
					ss<<line;
					string item;

					getline(ss, item, ',');
					string name = item;

					getline(ss,item,',');
					//cout<<item<<endl;
					int priority = stoi(item);

					getline(ss, item, ',');
					int treatment = stoi(item);

					count++;
                    //cout<<"Name "<<name<<endl;
                    insertKey(Data{priority,treatment,name});

				}	
		
		}
		else
			cout<<"File Error"<<endl;

file.close();
}


void MinHeap::sortStruct()
{
    int size = heap_size;
    for(int i =0; i<size;i++)
    {
        sorted[i] = extractMin();
        //cout<<i+1<<". "<<sorted[i].name<<", "<<sorted[i].priority<<",  "<<sorted[i].treatment<<endl;
        //cout<<i+1<<". "<<harr[i].name<<", "<<harr[i].priority<<",  "<<harr[i].treatment<<endl;

    }



}

void MinHeap::pop()
{
    if(heap_size != 0)
    {
         sorted[DATA_SIZE - heap_size] = extractMin();
         cout<<heap_size<<". "<<sorted[DATA_SIZE - heap_size].name<<", "<<sorted[DATA_SIZE - heap_size].priority<<",  "<<sorted[DATA_SIZE - heap_size].treatment<<endl;
    }
    else
        cout<<"Empty"<<endl;
}
