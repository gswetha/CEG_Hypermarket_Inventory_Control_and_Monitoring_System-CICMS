#include"job_restock.h"
_restock::_restock(string person,string bar,int number)
{
	personname=person;
	_barcode=bar;
	num=number;
}
string _restock::jobname()
{
	return "RESTOCK";
}
bool _restock::execute(Hypermarket* myhyper)
{
	Product** temp;
	int haha;
	if(!(myhyper->searchbarcode(_barcode,temp,haha)))
	{		return false;}
	myhyper->restock(num,_barcode);
	return true;
}