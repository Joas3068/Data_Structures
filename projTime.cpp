
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <stdio.h>
#include "priorityQueueLL.h"
#include "main.h"
#include "priorityQ.h"
#include "minHeap.h"
#include <chrono>
#include <ctime>

using namespace std;



void runTest(string readfile,ofstream&,string writeFile,priorityLL LL , PriorityQ qLib, MinHeap h, int build_delete_number, int build_delete_iterations );


void deleteCheck(string filename)
{
    if( remove( "inputD.csv" ) != 0 )
    perror( "Error deleting file" );
  else
  {
    cout<<"Previous "<<filename;
    puts( " successfully deleted" );
  }   
}


int main(int argc, char const *argv[]) {

//output file
string writeCSV = "inputD.csv"; //output filename


deleteCheck(writeCSV);  //check if exists

priorityLL LL;     //data structs to test
PriorityQ qLib;
MinHeap h(DATA_SIZE);

//input files
string rfile_100 = "patientData_100.csv";  //input test files
string rfile_300 = "patientData_300.csv";
string rfile_500 = "patientData_500.csv";
string rfile_880 = "patientData2270.csv";


ofstream  myfile;                  //create and open output file
myfile.open (writeCSV); 



int test_Iter_Nums = 5;   //number of times to run tests....nnumber of rows
int test_Nums = 600;         //number of times to queue and dequeue

cout<<"Testing..."<<endl;

runTest(rfile_880,myfile,writeCSV,LL,qLib,h,test_Nums,test_Iter_Nums);

myfile<<endl;

myfile<<"AVERAGE";
myfile <<","<<"=AVERAGE(B"<<2<<":"<<"B"<<test_Iter_Nums+1<<")"<<",";
myfile <<"=AVERAGE(C"<<2<<":"<<"C"<<test_Iter_Nums+1<<")"<<",";
myfile <<"=AVERAGE(D"<<2<<":"<<"D"<<test_Iter_Nums+1<<")"<<endl;

myfile<<"STDEV";
myfile <<","<<"=STDEV.P(B"<<2<<":"<<"B"<<test_Iter_Nums+1<<")"<<",";
myfile <<"=STDEV.p(C"<<2<<":"<<"C"<<test_Iter_Nums+1<<")"<<",";
myfile <<"=STDEV.P(D"<<2<<":"<<"D"<<test_Iter_Nums+1<<")"<<endl;
myfile << "File "<<rfile_880<<" tested"<<endl;


myfile.close();







// LL.buildLL(file);    
// LL.printLL();    
// LL.dequeuePatient(1);
// LL.deleteALL();
// qLib.readAndBuildQueue(file);
// qLib.printPop();
// qLib.dequeuePatient();
// h.readAndBuildStruct(file);
// h.sortStruct();
// h.pop();

// myfile<<"AVERAGE";
// myfile <<","<<"=AVERAGE(B"<<2<<":"<<"B"<<test_Iter_Nums+1<<")"<<",";
// myfile <<"=AVERAGE(C"<<2<<":"<<"C"<<test_Iter_Nums+1<<")"<<",";
// myfile <<"=AVERAGE(D"<<2<<":"<<"D"<<test_Iter_Nums+1<<")"<<endl;

// myfile<<"STDEV";
// myfile <<","<<"=STDEV.P(B"<<2<<":"<<"B"<<test_Iter_Nums+1<<")"<<",";
// myfile <<"=STDEV.p(C"<<2<<":"<<"C"<<test_Iter_Nums+1<<")"<<",";
// myfile <<"=STDEV.P(D"<<2<<":"<<"D"<<test_Iter_Nums+1<<")"<<endl;
    return 0;
}
















void runTest(string readfile,ofstream& myfile,string writeFile,priorityLL LL , PriorityQ qLib, MinHeap h, int build_delete_number, int build_delete_iterations )
{




myfile<<","<<"Heap Time"<<","<<"Queue Time"<<","<<"LL Time"<<endl;



for(int j = 0;j<build_delete_iterations;j++)
{
     auto start_heap = std::chrono::system_clock::now();

        
        for(int i = 0;i<build_delete_number;i++)
        {
  
        // LL.buildLL(file);
        // LL.deleteALL();
        // qLib.readAndBuildQueue(file);
        // qLib.printPop();
        h.readAndBuildStruct(readfile);
        h.sortStruct();
        }   

        auto end_heap = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds_heap = end_heap-start_heap;


      


        auto start_QUEUE = std::chrono::system_clock::now();
        for(int i = 0;i<build_delete_number;i++)
        {

        // LL.buildLL(file);
        // LL.deleteALL();
        
        qLib.readAndBuildQueue(readfile);
         //cout<<"LINKED "<<i<<endl;
        qLib.printPop();

        // h.readAndBuildStruct(file);
        // h.sortStruct();
        }   

        auto end_QUEUE = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds_QUEUE = end_QUEUE-start_QUEUE;

        
       
        auto start_LL = std::chrono::system_clock::now();
        for(int i = 0;i<build_delete_number;i++)
        {

        LL.buildLL(readfile);   ///getting stuck
        
        
        LL.deleteALL();
        // qLib.readAndBuildQueue(readfile);
        // qLib.printPop();
        // h.readAndBuildStruct(file);
        // h.sortStruct();
        }  

        auto end_LL = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds2 = end_LL-start_LL;

         // cout << "elapsed time: " << elapsed_seconds.count()*1000000 << "s\n";
        //auto milli_heap = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_seconds_heap).count();

        myfile << "Test "<<j+1<<",";
        myfile << elapsed_seconds_heap.count()*1000<<","<<elapsed_seconds_QUEUE.count()*1000<<","<<elapsed_seconds2.count()*1000;
        //myfile << milli_heap<<","<<elapsed_seconds_QUEUE.count()<<","<<elapsed_seconds2.count();
        myfile << "\n";
        cout<<"Done "<<j+1<<endl;

}

}
