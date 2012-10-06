#ifndef _JOB_RESTOCK_H
#define _JOB_RESTOCK_H
#include"job.h"
#include "Hypermarket.h"
#include <string>
using namespace std;
class _restock: public job
{
private:
	int num;
public:
	_restock(string,string,int);
	bool execute(Hypermarket* a);
	string jobname();
	string error();
};
#endif