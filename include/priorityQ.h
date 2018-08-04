#ifndef PRIORITYQ_H
#define PRIORITYQ_H
#include "main.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;




class PriorityQ
{
	public:
		void readAndBuildQueue(string fileName);
		void printPop();
		void dequeuePatient();
	private:
		priority_queue<Data> q;
};











#endif 