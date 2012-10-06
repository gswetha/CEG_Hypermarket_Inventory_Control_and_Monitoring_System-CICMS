#ifndef _JOB_ADD_H
#define _JOB_ADD_H
#include <string>
#include "job.h"
#include <iostream>
#include "Hypermarket.h"
using namespace std;
class add: public job
{
private:
	string _name;
	string _category;
	double _price;
	string _manufacturer;
	int _numinstock;
public:
	add(string,string, string,string,double,string,int);
	bool execute(Hypermarket* a);
	string jobname();
	
};

#endif