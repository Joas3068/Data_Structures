#include "main.h"
#include "priorityQ.h"
#include <iostream>
#include <fstream> 
#include <sstream> 
using namespace std;


// PriorityQ::PriorityQ(){}
// PriorityQ::~PriorityQ(){}

void PriorityQ::readAndBuildQueue(string fileName)
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
					string name1 = item; 

					getline(ss,item,',');
					//cout<<item<<endl;
					int priority1 = stoi(item);

					getline(ss, item, ',');
					int treatment1 = stoi(item);

					count++;
					//cout<<"Adding "<<name1<<", "<<priority1<<", "<<treatment1<<endl;
					q.push(Data{priority1,treatment1,name1});

				}	
		
		}
		else
			cout<<"File Error"<<endl;

file.close();
//cout<<q.size()<<" Patients Added"<<endl;
}


void PriorityQ::printPop()
{
	 if(q.empty())
	 	cout<<"Empty"<<endl;
	 else
	 {
	 	int rank = 0;
	 	cout<<"Rank     "<<"patient,  "<<"Priority,  "<<"Treatment"<<endl;
		 while(!q.empty()) 
	 
	    {
	    	rank++;
	    	Data a = q.top();
	    	cout<<rank<<":     "<<a.name<<":    "<<a.priority<<", "<<a.treatment<<endl;
	        q.pop();
	    }
	  }  
}

void PriorityQ::dequeuePatient()
{

	if(!q.empty())
	{

		Data a =q.top();

		cout<<"Patient "<<a.name<<", "<<a.priority<<", "<<a.treatment<<" removed."<<endl;
		q.pop();

		cout<<"There are "<<q.size()<<" patients left."<<endl;
	}
	else
		cout<<"Empty"<<endl;




}
