#ifndef _JOB_DISPOSE_H
#define _JOB_DISPOSE_H
#include"job.h"
#include "Hypermarket.h"
#include <string>
using namespace std;
class dispose: public job
{
private:
	string _curdate;
public:
	dispose(string,string,string);
	bool execute(Hypermarket* a);
	string jobname();
	string error();
};
#endif