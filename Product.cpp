
#include "Product.h"

Product::Product(string name, string category, string barcode, double price, string manu, int stocknum, int salesnum)
{
	_name=name;
	_category=category;
	_barcode=barcode;
	_price=price;
	_manu=manu;
	_stocknum=stocknum;
	_salesnum = salesnum;
}
string Product:: getname()
{
	return _name;
}
string Product:: getcategory()
{
	return _category;
}
string Product:: getbarcode()
{
	return _barcode;
}
double Product:: getprice()
{
	return _price;
}
double Product::getworth()
{return getdiscountedprice()*_stocknum;}
string Product::getmanufacturer()
{
	return _manu;
}
int Product::getnumstock()
{
	return _stocknum;
}
int Product:: getnumsold()
{
	return _salesnum;
}
int Product::getpricerank()
{return _pricerank;}
int Product::getstockrank()
{return _stockrank;}
int Product::getworthrank()
{return _worthrank;}
int Product::gettotalrank()
{return getstockrank()+getpricerank();}
void Product:: setname(string name)
{
	_name = name;
}
void Product:: setcategory(string category)
{
	_category = category;
}
void Product:: setbarcode(string barcode)
{
	_barcode = barcode;
}
void Product:: setprice(double price)
{
	_price = price;
}
void Product:: setmanufacturer(string manu)
{
	_manu = manu;
}
void Product:: setnumstock(int stocknum)
{
	_stocknum=stocknum;
}
void Product:: setnummonth(int salesnum)
{
	_salesnum=salesnum;
}
void Product::setstockrank(int stockrank)
{_stockrank=stockrank;}
void Product::setpricerank(int pricerank)
{_pricerank = pricerank;}
void Product::setworthrank(int worthrank)
{_worthrank = worthrank;}
double Product::getrevenue()
{
	return (_price*_salesnum);
}
double Product::getdiscountedprice()
{return _price;}
string  Product::getexpirydate()
{return "haha";}
double  Product::getdiscount()
{return 0;}
void  Product::setexpirydate(string date)
{}
void  Product:: setdiscount(double discountamt)
{}
void Product:: printpdtinfo()
{
	cout<<"Name: "<<_name<<endl;
	cout<<"Category: "<<_category<<endl;
	cout<<"Barcode number: "<<_barcode<<endl;
	cout<<"Price: $"<<_price<<endl;
	cout<<"Manufacturer: "<<_manu<<endl;
	cout<<"Number in stock: "<<_stocknum<<endl;
	cout<<"Number sold: "<<_salesnum<<endl;
	cout<<"revenue!!!!:"<<getrevenue()<<endl;
	cout<<"\n"<<endl;
}