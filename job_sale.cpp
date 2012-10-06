#include"job_sale.h"
_sale::_sale(string person,string bar, int number)
{
	personname=person;
	_barcode=bar;
	num=number;
}
bool _sale::execute(Hypermarket* myhyper)
{
	Product** temp;
	int haha;
	if(!(myhyper->searchbarcode(_barcode,temp,haha)))
		return false;
	if(temp[0]->getnumstock()<num)
		return false;
	myhyper->sale(num,_barcode);
	return true;
}
string _sale::jobname()
{
	return "SALE";
}