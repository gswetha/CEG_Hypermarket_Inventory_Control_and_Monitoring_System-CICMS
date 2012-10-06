#ifndef _UI_H_
#define _UI_H_

#include "BP.h"
#include <iostream>
#include <string>
#include "Hypermarket.h"
using namespace std;

class UI
{
private:
	BP* myBP;
	Hypermarket *myhyper;
	
public:
	UI();
	void perform ();
	void addproductmenu();
	void deleteproductmenu();
	void resetmenu();
	void salerestockmenu();
	void generatestatisticmenu();
	void searchmenu();
	void checkexpirymenu();
	void batchprocessingmenu();
	void printworthrank();
	void quitmenu();
};
#endif