#ifndef _BP_H_
#define _BP_H_
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "job.h"
#include "job_add.h"
#include "job_delete.h"
#include "job_dispose.h"
#include "job_restock.h"
#include "job_sale.h"
#include "stackbase.h"
#include "Queuebase.h"
#include "Hypermarket.h"
using namespace std;
class BP
{
private:
	StackBase<QueueBase<job*>*>* mystack;
	QueueBase<job*>** USER; 
public:
	BP();
	void readandexecutejob(Hypermarket*);
};

#endif