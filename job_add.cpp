#include "job_add.h"
#include "job.h"
#include <string>
#include<iostream>
#include "Hypermarket.h"
#include"ListBase.h"
#include"Product.h"
using namespace std;
add::add(string person,string name,string category,string barcode,double price,string manu, int numinstock)
{
	personname=person;
	_name=name;
	_category=category;
	_barcode=barcode;
	_price=price;
	_manufacturer=manu;
	_numinstock=numinstock;
}
bool add::execute(Hypermarket* myhyper)
{
	Product** temp;
	int haha;
	if(myhyper->searchbarcode(_barcode,temp,haha))
		return false;
	myhyper->addproduct(_name,_category,_barcode,_price,_manufacturer,_numinstock,0);
	return true;	
}
string add::jobname()
{
	return "ADD";
}
