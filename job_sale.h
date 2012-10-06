#ifndef _JOB_SALE_H
#define _JOB_SALE_H
#include"job.h"
#include "Hypermarket.h"
#include <string>
using namespace std;
class _sale: public job
{
private:
	int num;
public:
	_sale(string,string, int);
	bool execute(Hypermarket* a);
	string jobname();
	string error();
};
#endif