#ifndef _JOB_H_
#define _JOB_H_
#include <string>
#include <iostream>
#include"Hypermarket.h"
using namespace std;
class job
{
protected:
	string personname;
	string _barcode;
public:
	job(){}
	virtual bool execute(Hypermarket* a)=0;
	virtual string jobname()=0;
	string error()
	{
		string S=jobname();
		string space=" ";
		return _barcode+space+S+space+personname;
	}
};
#endif