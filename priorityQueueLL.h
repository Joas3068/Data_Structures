
#ifndef PRIORITYQUEUELL_H
#define PRIORITYQUEUELL_H

#include <iostream>
#include "main.h"
using namespace std;

struct linkedList
{
    std::string name;
    int priority;
    int treatment;
    linkedList *next;
    linkedList *previous;

    linkedList(){}; // default constructor

    linkedList(std::string initName,int initPriority,int initTreatment, linkedList *initNext, linkedList *initPrevious)
    {
        name = initName;
        next = initNext;
        previous = initPrevious;
        priority = initPriority;
        treatment = initTreatment;
    }
};


class priorityLL
{
public:

    priorityLL();
   ~priorityLL();

    void buildLL( std::string file);
    void addLL(Data d[],int index);
    void printLL();

    void deletePatient(string name);
    void dequeuePatient(int count);
    void deleteALL();
    void readAndBuildFile(string fileName, Data d[]);
protected:
private:
    linkedList *head = new  linkedList("",-1,-1,NULL, NULL);
    int LL_size = DATA_SIZE;
    //City *tail = new City("", NULL, NULL, "");

    
};











#endif // COMMUNICATIONNETWORK_H