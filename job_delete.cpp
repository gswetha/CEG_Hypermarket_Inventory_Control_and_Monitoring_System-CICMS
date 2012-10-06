
#include"job_delete.h"
#include "job.h"
jobdelete::jobdelete(string person,string bar)
{
	personname=person;
	_barcode=bar;
}
bool jobdelete::execute(Hypermarket* myhyper)
{
	Product** temp;
	int haha;
	if(!(myhyper->searchbarcode(_barcode,temp,haha)))
		return false;
	myhyper->removeproduct(_barcode);
	return true;
}
string jobdelete::jobname()
{
	return "DELETE";
}
