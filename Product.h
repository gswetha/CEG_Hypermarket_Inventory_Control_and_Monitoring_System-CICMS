#ifndef PRODUCT_H
#define PRODUCT_H
#include  <iostream>
#include <string>
using namespace std;

class Product
{
protected:
	string _name;
	string _category;
	string _barcode;
	double _price;
	string _manu;
	int _stocknum;
	int _salesnum;
	int _stockrank;
	int _pricerank;
	int _worthrank;
	double worth;
public:
	Product(string name,string category, string barcode, double price, string manu,int stocknum, int salesnum);
	virtual string getname();
	virtual string getcategory();
	virtual string getbarcode();
	virtual double getprice();
	virtual string getmanufacturer();
	virtual int getnumstock();
	virtual int getnumsold();
	virtual double getrevenue();
	virtual double getdiscountedprice();
	virtual int getstockrank();
	virtual int getpricerank();
	virtual int getworthrank();
	virtual int gettotalrank();
	virtual void setname(string T);
	virtual void setcategory(string T);
	virtual void setbarcode(string T);
	virtual void setprice(double T);
	virtual void setmanufacturer(string T);
	virtual void setnumstock(int T);
	virtual void setnummonth(int T);
	virtual void setpricerank(int pricerank);
	virtual void setstockrank(int stockrank);
	virtual void setworthrank(int worthrank);
	virtual void printpdtinfo();
	virtual string getexpirydate();
	virtual double getdiscount();
	virtual void setexpirydate(string date);
	virtual void setdiscount(double discountamt);
	virtual double getworth();
};
#endif