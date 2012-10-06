#include"job_dispose.h"
dispose::dispose(string person,string bar,string curdate)
{
	personname=person;
	_curdate=curdate;
	_barcode=bar;
}
bool dispose::execute(Hypermarket* myhyper)
{
	Product** temp;
	int haha;
	if(!(myhyper->searchbarcode(_barcode,temp,haha)))
	{return false;}
	else if(temp[0]->getexpirydate()=="haha")
	{return false;}
	else if(!(myhyper->hasexpired(_barcode,_curdate)))
	{return false;}
	myhyper->reset(_barcode);
	return true;
}
string dispose::jobname()
{
	return "DISPOSE";
}