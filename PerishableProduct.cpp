#include <iostream>
#include <string>
#include "PerishableProduct.h"
using namespace std;

PerishableProduct::PerishableProduct(string name, string category, string barcode, double price, string manu, int stock, int numsold, string date, double discountamt)
	:Product (name, category, barcode, price, manu, stock, numsold) 
{
	_expirydate = date;
	_discount = discountamt;
}

string PerishableProduct::getexpirydate()
{
	return _expirydate;
}
double PerishableProduct::getdiscount()
{
	return _discount;
}
void PerishableProduct::setexpirydate(string date)
{
	_expirydate = date;
}
void PerishableProduct::setdiscount(double discountamt)
{
	_discount = discountamt;

}
double PerishableProduct::getdiscountedprice()
{
	double discountedprice = _price*(1-(_discount/100));
	return discountedprice;
}
void PerishableProduct::printpdtinfo()
{
	cout<<"Name: "<<_name<<endl;
	cout<<"Category: "<<_category<<endl;
	cout<<"Barcode number: "<<_barcode<<endl;
	cout<<"Price: $"<<_price<<endl;
	cout<<"Manufacturer: "<<_manu<<endl;
	cout<<"Number in stock: "<<_stocknum<<endl;
	cout<<"Number sold: "<<_salesnum<<endl;
	cout<<"Expiry Date(DDMMYYYY): "<<_expirydate<<endl;
	cout<<"Discount percentage: "<<_discount<<endl;
	cout<<"\n"<<endl;
}