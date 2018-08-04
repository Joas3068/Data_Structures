#include "priorityQueueLL.h"
#include <iostream>
#include <fstream>
#include <fstream> 
#include <sstream> 
#include "main.h"
using namespace std;



priorityLL::priorityLL()
{

}
priorityLL::~priorityLL()
{
//head = NULL;
}

 int combineLL(int a, int b) 
 {
   int times = 1;
   while (times <= b)
      times *= 10;
   return a*times + b;
} 

void swap(string * swap1,int *count1,int *count3,string *swap2,int *count2,int *count4) //swap 1 to 2
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


void bubbleSort(int size,Data d[])
{
   //int i, j;
   bool swapped;
   for (int i = 0; i < size-1; i++)
   {
     swapped = false;
     //cout<<"level 1"<<endl;
     for (int j = 0; j < size-i-1; j++)
     {

        if (combineLL(d[j].priority,d[j].treatment) > combineLL(d[j+1].priority,d[j+1].treatment))
        {  
        	
           swap(&d[j].name,&d[j].priority,&d[j].treatment,&d[j+1].name,&d[j+1].priority,&d[j+1].treatment);

           swapped = true;
        }

     }
    
 //cout<<"level 2"<<endl;	
     
     if (swapped == false)
        break;
   }


}

void priorityLL::readAndBuildFile(string fileName, Data d[])
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
					d[count].name = item;

					getline(ss,item,',');
					//cout<<item<<endl;
					d[count].priority = stoi(item);

					getline(ss, item, ',');
					d[count].treatment = stoi(item);

					count++;

				}	
		
		}
		else
			cout<<"File Error"<<endl;



file.close();

}
void priorityLL::buildLL(string file)
{	
	

	Data d[DATA_SIZE];

	readAndBuildFile(file,d);


	bubbleSort(DATA_SIZE,d);


	// for(int i =0 ;i<DATA_SIZE;i++)
	// 	cout<<i+1<<":  "<<d[i].name<<", "<<d[i].priority<<", "<<d[i].treatment<<endl;

	//if(head->next == NULL)   

		linkedList *temp = new linkedList("",-1,-1,NULL,NULL);
		
		head = temp;
	
	if(head->next == NULL)  //ADD head of next condition for first and new null condition etc.....
	{
	
		
		
		head->name = d[0].name;
		head->priority = d[0].priority;
		head->treatment = d[0].treatment;
		head->previous = NULL;
	}	

	
	
	int count = 1;

	while(count != DATA_SIZE)  //add data based on DATA_SIZE
	{
		addLL(d,count);
		count++;
	}		
	
}

void priorityLL::addLL(Data d[], int index)
{

	linkedList *temp = new linkedList("",-1,-1,NULL,NULL);
	temp = head;
	

		while(temp->next != NULL)
		{	//cout<<"pass";
			temp = temp->next;
		}

	linkedList *newNode = new linkedList();

	
	newNode->next = temp->next;
	temp->next = newNode;
	newNode->previous = temp;
	newNode->next = NULL;

	newNode->name = d[index].name;
	newNode->priority = d[index].priority;
	newNode->treatment = d[index].treatment;

}

void priorityLL::printLL()
{
	linkedList *temp = new linkedList();
	temp = head;

	if(temp == NULL)
		cout<<"Empty List";
	else
	{	int count = 0;
		while(temp->next != NULL)
		{	

			cout<<count+1<<". "<<temp->name<<", "<<temp->priority<<", "<<temp->treatment<<endl;

		
			count++;
			temp = temp->next;
		
		}
		
		
		cout<<count+1<<". "<<temp->name<<", "<<temp->priority<<", "<<temp->treatment<<endl;

	}
	
}

void priorityLL::dequeuePatient(int count)
{	
	int total = count;
	while(count !=0 && head->next !=NULL)
	{
		cout<<"Patient "<<total -count+1<<". "<<head->name<<" removed."<<endl;
		linkedList *temp = new linkedList();

		temp = head->next;

		temp->previous = NULL;
		head = temp;

		temp = NULL;
		free(temp);

		count--;
	}

	if(head->next == NULL)
	{
		cout<<"Patient "<<total -count+1<<". "<<head->name<<" removed."<<endl;
		head = NULL;
		
	}

     cout<<total<<" "<<"Patients dequed"<<endl;

	
}

void priorityLL::deletePatient(string name)
{
	linkedList *temp = new linkedList();
	linkedList *temp2 = new linkedList();
	temp = head;	

	while(temp->name != name && temp != NULL) //find node to delete
	{

		temp = temp->next;

	}
	//cout<<temp<<" "<<temp->next<<" "<<temp->name<<endl;


	if (temp == head)
	{

		head = temp->next;
		head->previous = NULL;

	}

	else if(temp->next == NULL && temp->name == name)
	{
		cout<<"Tail"<<endl;
		//linkedList * temp2 = new linkedList();

		//temp->previous = temp2;
		//temp2= NULL;
		temp->previous->next = NULL ;
		

		free(temp);
		delete temp ;

		free(temp2);
		delete temp2 ;
		
		
	}
	else if(temp != NULL && temp->name == name)
	{
		//linkedList *temp2 = new linkedList();

		temp2 = temp->previous;
		temp2->next = temp->next;

		temp->previous = NULL;
		temp->next = NULL;
		
		temp = NULL;

        free(temp);	
        delete temp ;
  //       free(temp2);
		// delete temp2 ;
        
	}
}

void priorityLL::deleteALL()
{
		

	linkedList * tempH = new linkedList();

	tempH = head;
	int rank = 1;
	cout<<"Rank     "<<"patient,  "<<"Priority,  "<<"Treatment"<<endl;

	while(tempH->next != NULL )
	{

		cout<<rank<<":     "<<tempH->name<<":    "<<tempH->priority<<", "<<tempH->treatment<<endl;
		free (tempH);
		tempH = tempH->next;
		
		rank++;

	}
	cout<<rank<<":     "<<tempH->name<<":    "<<tempH->priority<<", "<<tempH->treatment<<endl;
//cout<<count<<", "<<"deleting "<<tempH->name<<endl;
// free(tempH);
// tempH = tempH->next;

head = NULL;
// free (tempH);


}

