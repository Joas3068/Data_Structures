#include <iostream>
#include <fstream>
#include <string>     // std::string, std::stoi
#include "priorityQueueLL.h"
#include "main.h"
#include "priorityQ.h"
#include "minHeap.h"
#include <iostream>
#include <vector>
#include <sstream> //string stream
using namespace std;


int printMenu(int quitNumber)
{

int input = 0;
bool pass = false;


//cout << "======Main Menu======" << endl;
cout<<endl;
cout << "----Linked List----"<<endl;
cout << "1. Read and Build Linked List" << endl;
cout << "2. Print  Linked List" << endl;
cout << "3. Dequeue Linked List " << endl;
cout << "4. Delete Linked List"<<endl;
cout<<endl;
cout << "----Priority Queue----"<<endl;
cout << "5. Build Priority Queue"<<endl;
cout << "6. Print and Pop"<<endl;
cout << "7. Dequeue Patient"<<endl;
cout<<endl;
cout << "----Heap----"<<endl;
cout << "8. Build Heap"<<endl;
cout << "9. Pop & sort"<<endl;
cout << "10. Pop Single"<< endl;
cout << "11. Quit" << endl;
cout << "**********************************"<<endl;

while(pass == false)
{
cout<<"Input: ";
cin>>input;


	if(input>quitNumber || input<1)
		{
		
			
			break;
			
		}
	else if(input>0 && input<=quitNumber)
		pass = true;
	else
		pass = false;
}


return input;

}

















int main()
{

priorityLL LL;	//LL class comms with build class
PriorityQ qLib;
MinHeap h(DATA_SIZE);

string file = "patientData2270.csv";    ///command line after implementation
//string file = "data.csv";

int i =0;
string deqCount;
int num = 0;
int quitNum = 11;

while(i != quitNum)
{


i =printMenu(quitNum);


switch(i)
	{
		case 1: 		
				// build.readAndBuildFile(file);  //read build and sort
				// build.bubbleSort(DATA_SIZE);
				LL.buildLL(file);			//builds linked list from build class
				break;

		case 2:
				LL.printLL();		     
				break;

        case 3:

            cout << "How many patients to dequeue? " << endl;
            
            cin.ignore(256,'\n');
            getline(cin,deqCount);

       		num = stoi(deqCount);


           	LL.dequeuePatient(num);
            break;

        case 4:

			LL.deleteALL();
            break;

        case 5:

        	qLib.readAndBuildQueue(file);
        	break;

        case 6:

        	qLib.printPop();
        	break;

        case 7:

        	qLib.dequeuePatient();

        	break;

        case 8:
        	h.readAndBuildStruct(file);
        	

        	break;

        case 9:
        	h.sortStruct();

        	break;
        case 10:
        	h.pop();
        	break;

        case 11:
            
            cout << "Goodbye!" << endl;
            break;


		default:cout<<endl<<"derp"<<endl;
				i = 4;
				break;

	}
	

}






// MinHeap heap(DATA_SIZE);

// heap.print();
// heap.readAndBuildStruct(file);
// heap.sortStruct();


	return 0;
}