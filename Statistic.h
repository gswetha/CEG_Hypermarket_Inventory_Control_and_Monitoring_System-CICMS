#ifndef _STATISTIC_H_
#define _STATISTIC_H_
#include <string>
#include <vector>
#include "Product.h"
#include "ListBase.h"
class statistic
{
private:
	struct storepointers
	{
		Product* prdptr;
		int n;
	};
	int listsize;
	storepointers* storeptrs;

public:
	void constructstruct(int x, storepointers* &strctptr);
	bool topx(ListBase<Product*>* thislist, int x, Product**&, int& size);
	bool bestsellingprd(ListBase<Product*>* thislist,string category, string& result);
	void bestmanufacture(ListBase<Product*>* thislist, string& S);
	void copytostruct(ListBase<Product*>*, int x);
	void sortfunction( int low, int high, int ind);
	void mergefunction(int low,int mid, int high, int ind);
	void sortsetpricerank();
	void sortsetstockrank();
	void sortsetworthrank();
	void returnpointer(Product** &returnptr);
	
};
#endif
