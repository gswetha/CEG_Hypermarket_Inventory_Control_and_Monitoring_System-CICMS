#include"UI.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
UI::UI()
{

	myhyper=new Hypermarket;
	myBP= new BP;
}
void UI::perform()
{
	cout<<"***********************************************************"<<endl;
	cout<<"**CEG Hypermarket Inventory Control and Monitoring System**"<<endl;
	cout<<"***********************************************************"<<endl;
	cout<<endl<<endl<<endl<<endl<<"*********************Loading the system********************"<<endl<<endl<<endl<<endl;
	cout<<"                 Starting up the programmes..."<<endl;
	myhyper->readfromfile();	

	while(1)
	{		
		system("cls");
		cout<<"***********************************************************"<<endl;
		cout<<"**CEG Hypermarket Inventory Control and Monitoring System**"<<endl;
		cout<<"***********************************************************"<<endl;
		cout<<"1. Add New Product"<<endl;
		cout<<"2. Delete Product"<<endl;
		cout<<"3. Reset Product Sales"<<endl;
		cout<<"4. Sale/Restock Transaction"<<endl;
		cout<<"5. Generate Statistics"<<endl;
		cout<<"6. Search For One Product"<<endl;
		cout<<"7. Check if One Product has Expired"<<endl;
		cout<<"8. Batch Processing"<<endl;
		cout<<"9. Print Worth Rank to txt.file"<<endl;
		cout<<"10. Exit"<<endl;
		cout<<endl<<"What would you like to do? [Please enter number]"<<endl;
		int choice;
		cin>>choice;
		switch (choice)
		{
			case 1:
				addproductmenu();
				system("pause");
				continue;
			case 2:
				deleteproductmenu();
				system("pause");
				continue;
			case 3:
				resetmenu();
				system("pause");
				continue;
			case 4:
				salerestockmenu();
				system("pause");
				continue;
			case 5:
				generatestatisticmenu();
				system("pause");
				continue;
			case 6:
				searchmenu();
				system("pause");
				continue;
			case 7:
				checkexpirymenu();
				system("pause");
				continue;
			case 8:
				batchprocessingmenu();
				system("pause");
				continue;
			
			case 9:
				printworthrank();
				system("pause");
				continue;
			case 10:
				quitmenu();
				system("pause");
				continue;
		}
	}
}
void UI::addproductmenu()
{
	system("cls");
	getchar();
	string name,category,barcode,manu,date;
	int stock,numsold;
	double price,rate;
	char choice;
	cout<<"Please enter the name of the product:"<<endl;
	getline(cin,name);
	cout<<"Please enter the category:"<<endl;
	getline(cin,category);
	cout<<"Please enter the barcode:"<<endl;
	getline(cin, barcode);
	cout<<"Please enter the price:"<<endl;
	cin>>price;
	getchar();
	cout<<"Please enter the name of the manufacturer:"<<endl;
	getline(cin, manu);
	cout<<"Please enter the stock number:"<<endl;cin>>stock;
	cout<<"Please enter the sales number:"<<endl;cin>>numsold;
	cout<<"perishable? Y/N"<<endl;cin>>choice;
	if(choice=='Y'||choice=='y')
	{
		getchar();
		cout<<"Please enter the expiry date of the Perishable Product:"<<endl;getline(cin,date);
		cout<<"Please enter the discount rate of the Perishable Product:"<<endl;cin>>rate;
		myhyper->addperishablepdt(name,category,barcode,price,manu,stock,numsold,date,rate);
		return;
	}
    if(choice=='N'||choice=='n')
	{myhyper->addproduct(name,category,barcode,price,manu,stock,numsold);}
	cout<<endl<<"Product has been added!!"<<endl;
}
void UI::deleteproductmenu()
{
	system("cls");
	string name;
	getchar();
	cout<<"Please enter the name of the product that you want to delete";getline(cin,name);
	Product** myptr;
	int size;
	if(myhyper->searchname(name,myptr,size))
	{
		if(size==1)
		{
			myhyper->removeproduct(myptr[0]->getbarcode());
		}
		else
		{
			cout<<"The following products have the same name";
			for(int i=0;i<size;i++)
			{
				myptr[i]->printpdtinfo();
			}
			cout<<"Please enter the barcode of the product you want to delete"<<endl;
			string bar;
			getchar();
			getline(cin, bar);
			myhyper->removeproduct(bar);
		}
		cout<<"The product has beed removed!!";
	}
	else
		cout<<"There is noo such name";
}
void UI::resetmenu()
{
	system("cls");
	cout<<"Please enter the product name you want to reset."<<endl;
	getchar();
	string name;
	getline(cin,name);
	Product** myptr;
	int size,check;
	check = myhyper->searchname(name,myptr,size);
	if(!check)
		cout<<"There is no such product! Please try again!"<<endl;
	else
	{if(size==1)
	{
		myhyper->reset(myptr[0]->getbarcode());
	}
	else
	{
		cout<<"The following products have the same name:"<<endl;
		for(int i=0;i<size;i++)
		{
			myptr[i]->printpdtinfo();
		}
		cout<<"enter the barcode of the product you want to delete"<<endl;
		string bar;
		cin>>bar;
		myhyper->reset(bar);
	}
	cout<<"The sales of the product has been reseted."<<endl;
	}
}
void UI::salerestockmenu()
{
	system("cls");
	cout<<"Which operations would you like to perform? Please key in the respective number"<<endl<<endl;
	cout<<"1.Sale"<<endl<<"2.Restock"<<endl;
	int choice;
	cin>>choice;
	switch(choice)
	{
	case 1:
	   {	int num;
			string name;
			getchar();
			cout<<"Please enter the product name you want to sell "<<endl;getline(cin,name);	
			Product** myptr;
			int size, check;
			check=myhyper->searchname(name,myptr,size);
			if(!check)
				cout<<"There is no such product. Please try again."<<endl;
			else
			{
				cout<<"Please enter the amount you want to sale"; cin>>num;
				if(size==1)
				{
					int check1;
					check1 = myhyper->sale(num,myptr[0]->getbarcode());
					if (!check1)cout<<endl<<"The number you've keyed in is greater than the stock number! Please try again."<<endl;
					else cout<<"Product sold for "<<num<<" !"<<endl;
				}
				else
				{
					cout<<"The following product have the same name";
					for(int i=0;i<size;i++)
					{
						myptr[i]->printpdtinfo();
					}
					cout<<"Please enter the barcode of the product you want to sale"<<endl;
					string bar;
					cin>>bar;
					int check2;
					check2=myhyper->sale(num,bar);
					if(check2){cout<<endl<<"The Products have been sold!"<<endl;}
					else{cout<<"The number you've keyed in is greater than the stock number! Please try again."<<endl;}
				}
			}
	   }
	   break;
	case 2:
		{string name;
			int num,check;
			getchar();
			cout<<"Please enter the product name you want to restock. "<<endl;
			getline(cin,name);
			
			Product** myptr;
			int size;
			check=myhyper->searchname(name,myptr,size);
			if(!check)
				cout<<"There is no such product. Please try again."<<endl;
			else
			{
				cout<<"Please enter the number you want to restock"<<endl;cin>>num;
				if(size==1)
				{
					myhyper->restock(num,myptr[0]->getbarcode());
				}
				else
				{
					cout<<"The following products have the same name."<<endl;
					for(int i=0;i<size;i++)
					{
						myptr[i]->printpdtinfo();
					}
					cout<<"Please enter the barcode of the product you want to restock"<<endl;
					string bar;
					cin>>bar;
					myhyper->restock(num,bar);
				}
				cout<<"products have been restocked!"<<endl;
			}
		break;
		}
	}
}
void UI::generatestatisticmenu()
{
	system("cls");
	cout<<"Which statistics do you want to view? Please key in the respective number."<<endl<<endl;
	cout<<"1.Top x Product According to Revenue"<<endl;
	cout<<"2.The best product in one given category"<<endl;
	cout<<"3.The best manufacture"<<endl;
	int num;
	cin>>num;
	switch(num)
	{
	case 1:
		{
			cout<<"Please enter the number x"<<endl;
			int x;
			cin>>x;
			Product** tempprd;
			int size, check;
			check = myhyper->topproduct(x,tempprd,size);
			if(!check)
				{cout<<endl<<"The number X is greater than the total number of products in CICMS Hypermarket!"<<endl<<endl;
			break;}
			else
			{
					cout<<endl<<"The Top "<<x<< "Selling products are: "<<endl;
					for(int i=0;i<size;i++)
					{
						cout<<i+1<<" "<<tempprd[i]->getname()<<endl<<"Revenue: "<<tempprd[i]->getrevenue()<<endl<<endl;
					}
				
			delete[] tempprd;
			tempprd= NULL;
			
			}
		break;
		}
	case 2:
		{
			int check;
			getchar();
			cout<<"Please enter the category name"<<endl;
			string name;
			getline(cin,name);
			string prd;
			check = myhyper->bestselling(name,prd);
			if(!check)
				cout<<"There is no such category!"<<endl;
			else
			{
				cout<<"The best selling product in ";
				cout<<name<<" is "<<prd<<endl;
			}
		}break;
	case 3:
		{
			string manu;
			myhyper->bestmanu(manu);
			cout<<"The best manufacturer is "<<manu<<endl;
		}break;
	}	
}
void UI::searchmenu()
{
	system("cls");
	cout<<"1.Search by name"<<endl;
	cout<<"2.Search by manufacturer"<<endl;
	cout<<"3.Search by barcode"<<endl;
	cout<<"4.Search by category"<<endl;
	cout<<"<enter a number>"<<endl;
	int num;
	cin >>num;
	string S;
	switch(num)
	{
	case 1:
		{
			int check;
			getchar();
			cout<<"Please enter the name of the product"<<endl;
			getline(cin,S);
			Product** myptr;
			int size;
			check = myhyper->searchname(S,myptr,size);
			if(!check)
				cout<<"There is no such product!"<<endl;
			else	
				{
					for(int i=0;i<size;i++)
					{myptr[i]->printpdtinfo();}
				}
			
		}
		break;
	case 2:
		{
			getchar();
			cout<<"Please enter the manufacturer name of the product"<<endl;
			getline(cin,S);
			Product** myptr;
			int size, check;
			check=myhyper->searchmanufacturer(S,myptr,size);
			if(!check)
				cout<<"There is no such manufacturer!"<<endl;
			else
			{
				for(int i=0;i<size;i++)
				{
					myptr[i]->printpdtinfo();
				}
			}
		}
		break;
	case 3:
		{
			getchar();
			cout<<"Please enter the barcode of the product"<<endl;
			getline(cin,S);
			Product** myptr;
			int size,check;
			check=myhyper->searchbarcode(S,myptr,size);
			if(!check)
				cout<<"There is no such barcode! Please try again!"<<endl;
			else
			{
				for(int i=0;i<size;i++)
				{myptr[i]->printpdtinfo();}
			}
		}
		break;
	case 4:
		{
			getchar();
			cout<<"Please enter the category of the product"<<endl;
			getline(cin,S);
			Product** myptr;
			int size,check;
			check=myhyper->searchcategory(S,myptr,size);
			if(!check)
				cout<<"There is no such category!"<<endl;
			else
			{
				for(int i=0;i<size;i++)
				{myptr[i]->printpdtinfo();}
			}
		}
		break;
	}
}
void UI::checkexpirymenu()
{
	system("cls");
	string cur;
	cout<<"Please type in the current date in the format of <<DDMMYYYY>>"<<endl;
	cin>>cur;
	getchar();
	cout<<"Please enter the name of the product that you want to check"<<endl;
	string name;
	getline(cin,name);
	Product** myptr;
	int size,check;
	check=myhyper->searchname(name,myptr,size);
	if(!check)
		cout<<"There is no such product!"<<endl;
	else{
		if(size==1)
		{
			string barcode=myptr[0]->getbarcode();
			if(myhyper->hasexpired(barcode,cur))
				cout<<"The product has expired!"<<endl;
			else
				cout<<"The product has not expired yet! Safe to consume!"<<endl;
		}
		else
		{
			cout<<"The following products have the same name."<<endl<<endl;
			for(int i=0;i<size;i++)
			{
				myptr[i]->printpdtinfo();
			}
			cout<<endl<<endl;
			cout<<"Please enter the barcode of the product you want to check"<<endl;
			string bar;
			cin>>bar;
			if(myhyper->hasexpired(bar,cur))
				cout<<"The product has expired!"<<endl;
			else
				cout<<"The product has not expired yet!"<<endl;				
		}
	}
}
void UI::batchprocessingmenu()
{
	system("cls");
	char choice;
	cout<<"Do you want to execute the jobs in the file?  Y/N"<<endl;
	cin>>choice;
	cout<<endl;
	if(choice=='Y'||choice=='y')
	{
		cout<<"Please wait a while, the system is processing and executing the jobs."<<endl;
		cout<<"Loading...."<<endl;
		myBP->readandexecutejob(myhyper);
		cout<<endl<<endl<<endl<<endl;
		cout<<"The jobs have been executed. Another log file of has been generated."<<endl;
	}
}
void UI::printworthrank()
{
	cout<<"Loading... The files are now being written."<<endl;
	cout<<"Printing..."<<endl;
	myhyper->writeworthrank();
	cout<<"The barcode of the products worthrank are printed accordingly."<<endl;
	cout<<"Check your directory for the txt files."<<endl;


}
void UI::quitmenu()
{
	myhyper->writetofile();
	exit(1);
	system("cls");
}

