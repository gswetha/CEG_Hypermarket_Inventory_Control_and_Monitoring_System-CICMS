#ifndef _PERISHABLEPRODUCT_H_
#define _PERISHABLEPRODUCT_H_
#include <iostream>
#include <string>
#include "Product.h"
using namespace std;

class PerishableProduct : public Product
{
private:
	string _expirydate;
	double _discount;
public:
	PerishableProduct(string name, string category, string barcode, double price, string manu, int stock, int numsold, string expirydate, double discount);
	//methods
	string getexpirydate();
	double getdiscount();
	void setexpirydate(string date);
	void setdiscount(double discountamt);
	double getdiscountedprice();
	void printpdtinfo();
};
#endif