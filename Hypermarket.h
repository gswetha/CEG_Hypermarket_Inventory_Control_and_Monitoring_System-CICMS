#ifndef _HYPERMARKET_H_
#define _HYPERMARKET_H_
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "PerishableProduct.h"
#include "Product.h"
//#include "statistic.h"
#include "ListBase.h"
#include "Statistic.h"
using namespace std;
class Hypermarket
{

private:
	statistic mystatistic;
	ListBase<Product*>* mylist;

public:
	Hypermarket();
	
	void addproduct(string name, string category, string barcode, double price, string manu, int stock, int numsold);
	void addperishablepdt(string name, string category, string barcode, double price, string manu, int stock, int numsold, string expirydate, double discount);
	bool removeproduct(string barcode);
	bool reset(string barcode);
	bool sale(int num, string barcode);
	bool restock(int num, string barcode);
	bool topproduct(int x, Product**&, int&);
	bool bestselling(string category,string &S);
	void bestmanu(string& T);
	bool hasexpired(string barcode,  string cur);
	void change(string &T);
	void readfromfile();
	void writetofile ();
	bool searchcategory(string name,Product**&,int& size);
	bool searchbarcode(string name, Product**&,int& size);
	bool searchmanufacturer(string name, Product**&,int& size);
	bool searchname(string name, Product**&,int& size);
	void writeworthrank();
};
#endif