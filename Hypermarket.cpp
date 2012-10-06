#include "Hypermarket.h"
#include <ctime>
int imple;
Hypermarket::Hypermarket() {
	mylist=new ListLL<Product*>();
}

void Hypermarket::addproduct(string name, string category,string barcode, double price, string manu, int stock, int numsold)
{	
	Product* newPtr=new Product(name, category, barcode,price,manu,stock, numsold);
	mylist->insert(1,newPtr);

}
void Hypermarket::addperishablepdt(string name, string category, string barcode, double price, string manu, int stock, int numsold, string expirydate, double discount)
{	Product* newPtr=new PerishableProduct(name, category, barcode,price,manu,stock, numsold,expirydate,discount);
		{mylist->insert(1,newPtr);}
}
bool Hypermarket::removeproduct(string barcode)
{
	for(int i=1;i<=(mylist->getLength()+1);i++)
	{
		if(mylist->returnitem(i)->getbarcode()==barcode)
		{
			mylist->remove(i);
			return true;
		}
	}
	return false;
}
bool Hypermarket::reset(string barcode)
{
	for(int i=1;i<=mylist->getLength()+1;i++)
	{
		if(mylist->returnitem(i)->getbarcode()==barcode)
		{
			mylist->returnitem(i)->setnummonth(0);
			Product* temp=mylist->returnitem(i);
			mylist->remove(i);
			mylist->insert(mylist->getLength()+1,temp);
			return true;
		}
	}
	return false;
}
bool Hypermarket::sale(int num, string barcode)
{
	for(int i=1;i<mylist->getLength()+1;i++)
	{
		
		if(mylist->returnitem(i)->getbarcode()==barcode)
		{
			int tem=mylist->returnitem(i)->getnumsold();
			int tem1=mylist->returnitem(i)->getnumstock();
			if(num>tem1)
			{return false;}
			else
				
				mylist->returnitem(i)->setnummonth(tem+num);
				mylist->returnitem(i)->setnumstock(tem1-num);

		}
	}
	return true;
}
bool Hypermarket::restock(int num, string barcode)
{
	for(int i=1;i<mylist->getLength()+1;i++)
	{
		if(mylist->returnitem(i)->getbarcode()==barcode)
		{
			int tem=mylist->returnitem(i)->getnumstock();
			mylist->returnitem(i)->setnumstock(tem+num);
		}
	}
	return true;
}
void Hypermarket::change(string &T)
{
	string D;
	string M;
	string Y;
	D=T.substr(0,2);
	M=T.substr(2,2);
	Y=T.substr(4,4);
	T=Y+M+D;
}
bool Hypermarket::hasexpired(string barcode, string cur)
{
	
	change(cur);
	for(int i=1;i<mylist->getLength()+1;i++)
	{
		if(mylist->returnitem(i)->getbarcode()==barcode)
		{
			string temp=mylist->returnitem(i)->getexpirydate();
			change(temp);
			if (temp>cur)
			{return false;}
		
		}
		
	}
	return true;
}
bool  Hypermarket::searchname(string name, Product**& myptr,int& size)
{
	Product** ptr;
	Product** tempptr;
	mystatistic.copytostruct(mylist,mylist->getLength());
	mystatistic.returnpointer(tempptr);
	
	int num=0;
	int j=0;
	for(int i=1;i<mylist->getLength()+1;i++)
	{
		if((tempptr[i-1]->getname())==name)
		{
			num++;
		}
	}
	ptr=new Product*[num];
	for(int i=1;i<mylist->getLength()+1&&j<num+1;i++)
	{
		
		Product* pt;
		pt=tempptr[i-1];
		if((pt->getname())==name)
		{
			ptr[j]=pt;
			j++;
		}
	}
	myptr=ptr;
	size=num;
	if(num==0){return false;}
	else{return true;}
}
bool  Hypermarket::searchbarcode(string barcode, Product**& myptr,int& size)
{
	Product** ptr;
	Product** tempptr;
	mystatistic.copytostruct(mylist,mylist->getLength());
	mystatistic.returnpointer(tempptr);
	int num=0;
	int j=0;
	for(int i=1;i<mylist->getLength()+1;i++)
	{
		if((tempptr[i-1]->getbarcode())==barcode)
		{
			num++;
		}
	}
	ptr=new Product*[num];
	for(int i=1;i<mylist->getLength()+1&&j<num+1;i++)
	{
		
		Product* pt;
		pt=tempptr[i-1];
		if((pt->getbarcode())==barcode)
		{
			ptr[j]=pt;
			j++;
		}
	}
	myptr=ptr;
	size=num;
	if(num==0){return false;}
	else{return true;}

}
bool  Hypermarket::searchcategory(string category, Product**& myptr,int& size)
{
	Product** ptr;
	int num=0;
	int j=0;
	for(int i=1;i<mylist->getLength()+1;i++)
	{
		if((mylist->returnitem(i)->getcategory())==category)
		{
			num++;
		}
	}
	ptr=new Product*[num];
	for(int i=1;i<mylist->getLength()+1&&j<num+1;i++)
	{
		
		Product* pt;
		pt=mylist->returnitem(i);
		if((pt->getcategory())==category)
		{
			ptr[j]=pt;
			j++;
		}
	}
	myptr=ptr;
	size=num;
	if(num==0){return false;}
	else{return true;}
}
bool  Hypermarket::searchmanufacturer(string manufacture, Product**& myptr,int& size)
{
	Product** ptr;
	Product**tempptr;
	mystatistic.copytostruct(mylist,mylist->getLength());
	mystatistic.returnpointer(tempptr);
	int num=0;
	int j=0;
	for(int i=1;i<mylist->getLength()+1;i++)
	{
		if((tempptr[i-1]->getmanufacturer())==manufacture)
		{
			num++;
		}
	}
	ptr=new Product*[num];
	for(int i=1;i<mylist->getLength()+1&&j<num+1;i++)
	{
		
		Product* pt;
		pt=tempptr[i-1];
		if((pt->getmanufacturer())==manufacture)
		{
			ptr[j]=pt;
			j++;
		}
	}
	myptr=ptr;
	size=num;
	if(num==0){return false;}
	else{return true;}
}
bool Hypermarket::topproduct(int x, Product**& a, int& mysize)
{
	if(x>mylist->getLength())
		return false;
	else
		 mystatistic.topx( mylist,x,a,mysize );
		return true;
}
bool Hypermarket::bestselling(string category,string& S)
{	
	if(mystatistic.bestsellingprd(mylist,category,S))
	return true;	
	else
	{return false;}
}
void Hypermarket::bestmanu(string& T)
{	
	mystatistic.bestmanufacture( mylist,T);
}
void Hypermarket::readfromfile()
	{			
		    ifstream Infile("data-xs.txt");
			bool readLine= false;
			int filesize, i;
			string name, category, manufacturer,barcode,expiry;
			int stock, sales;
			//int  tempDate;
			double price, discount;
			string temp;//use to store the blank line
			Infile >> filesize;
			getline( Infile, temp );//to avoid the blank line
			for( i = 0; i < filesize ; i++ )
			{
				if(!readLine)
				getline( Infile, temp );
				getline( Infile, name );
				getline( Infile, category );
				Infile >> barcode;
				Infile >> price;
				getline( Infile, temp );

				getline( Infile, manufacturer );
				Infile >> stock;
				Infile >> sales;
				getline( Infile, temp );//to avoid the "enter key"
				getline(Infile,temp);
				if( temp == "")
				{
					readLine = true;
					addproduct(name, category, barcode, price, manufacturer, stock, sales);
				}
				else
				{
					istringstream iss( temp );
					iss>>expiry;
					readLine = false;
					Infile >> discount;
					getline( Infile, temp );
					addperishablepdt(name,category, barcode, price, manufacturer, stock, sales, expiry, discount);
				}							
			} Infile.close();
	}
void Hypermarket::writetofile()
{
	Product* temp;
	ofstream writeFile("data-xs.txt");
	int num=mylist->getLength();
	writeFile<<num;
	writeFile<<endl;
	writeFile<<endl;
	for(int j=num;j>0;j--)
	{
		temp=mylist->returnitem(j);
		// this is to decrease the travesal time of linked list, each and everytime we use mylist->returnitem(i)
		writeFile<<temp->getname()<<endl;
		writeFile<<temp->getcategory()<<endl;
		writeFile<<temp->getbarcode()<<endl;
		writeFile<<temp->getprice()<<endl;
		writeFile<<temp->getmanufacturer()<<endl;
		writeFile<<temp->getnumstock()<<endl;
		writeFile<<temp->getnumsold()<<endl;
		if(!(temp->getexpirydate()=="haha"))
		{
			writeFile<<temp->getexpirydate()<<endl;
			writeFile<<temp->getdiscount()<<endl;
		}
		writeFile<<endl;
	}

}
void Hypermarket::writeworthrank()
{
	int size = mylist->getLength();
	Product **temp;
	mystatistic.copytostruct(mylist,size);
	mystatistic.sortsetworthrank();
	mystatistic.returnpointer(temp);
	ofstream writeFile("sorted-xl-myversion.txt");

	for(int i=0;i<size;i++)
	{
		writeFile<<temp[i]->getbarcode()<<endl;
	}

	writeFile.close();
	delete [] temp;
	temp = NULL;

}

