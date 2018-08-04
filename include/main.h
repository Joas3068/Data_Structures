
#ifndef MAIN_H
#define MAIN_H

#include <iostream>

#define DATA_SIZE (880)

struct Data
{

	int priority;
	int treatment;
	std::string name;
    Data(){}
    Data(int p,int t, std::string n)
    {
    	priority = p;
    	treatment = t;
    	name = n;
    }
        bool operator<(const Data &o) const
    {
        if(priority == o.priority)
        {
            return treatment > o.treatment;
        }
        else
        return priority > o.priority;
    }


};


#endif 