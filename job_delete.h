#ifndef _JOB_DELETE_H
#define _JOB_DELETE_H
#include"job.h"
#include "Hypermarket.h"
#include <string>
using namespace std;

class jobdelete: public job
{
public:
	jobdelete(string,string);
	bool execute(Hypermarket* a);
	string jobname();
	string error();
};
#endif                          