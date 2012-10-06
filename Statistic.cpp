#include "Statistic.h"

using namespace std;

bool statistic::topx(ListBase<Product*>*thislist, int x, Product**& myptr, int& size)
{
	copytostruct(thislist,thislist->getLength());
	sortfunction(0,listsize-1,1);
	Product** ptr;
	int i;
	int ctr=0;
	if(x>listsize)
		return false;
	else{
		for ( i=1;i<listsize;i++)
		{	
			if(storeptrs[i-1].prdptr->getrevenue()!=storeptrs[i].prdptr->getrevenue())
			{
				ctr++;		
			}
			if(ctr==x||i==listsize)
				{break;}		
		}
	
	ptr=new Product*[i];
	for(int j=1;j<i+1;j++)
		{
			ptr[j-1]=storeptrs[j-1].prdptr;
		}
	myptr=ptr;
	size=i;}
	return true;
}
bool statistic::bestsellingprd(ListBase<Product*>* thislist,string category, string& result)
{
	copytostruct(thislist,thislist->getLength());
	sortfunction(0,listsize-1,1);
	for(int i=0;i<thislist->getLength();i++)
	{
		if(storeptrs[i].prdptr->getcategory()==category)
			{result=storeptrs[i].prdptr->getname();
		return true;}
	}
	return false;
}
void statistic::bestmanufacture(ListBase<Product*>* thislist, string& S)
{
	copytostruct(thislist,thislist->getLength());
	
	int maxi;
	int ctr=0;
	struct manufactnode
	{
		string manufactname;
	    double totalprofit;
		manufactnode* next;
	 };
	int size=0;
	manufactnode* head=NULL;
	manufactnode *newNode;
	for(int i=1;i<thislist->getLength()+1;i++)
	{	ctr=0;
		newNode=new manufactnode;
		newNode->manufactname=storeptrs[i-1].prdptr->getmanufacturer();
		newNode->totalprofit=storeptrs[i-1].prdptr->getrevenue();
		if(head==NULL)
			{
				head=newNode;
				ctr=1;
				size++;
			}	
		else {
			manufactnode* cur=head;
			for(int j=0;j<size;j++)
			{	
				
				if(cur->manufactname==storeptrs[i-1].prdptr->getmanufacturer())
						{
							(cur->totalprofit)+=(storeptrs[i-1].prdptr->getrevenue());
								ctr=1;
								break;
						}
				cur=cur->next;
			}
			}
			if(ctr==0)
			{
				manufactnode* temp=head;
				head=newNode;
				newNode->next=temp;
			    size++;}
			
	}
			double max=0;
			manufactnode* current=head;
			int j;
			manufactnode* result;
			for (j=0;j<size;j++)
			{
				double curprof=current->totalprofit;
				if (curprof>=max)
					{
						max=curprof;
						maxi=j;
						result=current;
					}
				current=current->next;

			}

			S=result->manufactname;
}
void statistic::constructstruct(int x, storepointers* &strctptrs)
{
	strctptrs = new storepointers[x];
}
void statistic::copytostruct(ListBase<Product*> *thislist,int size)
{
	listsize = size;
	constructstruct(size,storeptrs);
	Product** temp = new Product*[listsize];
	thislist->copy(temp);
	for(int i=0;i<listsize;i++)
	{
		storeptrs[i].prdptr=temp[i];
	}
	delete[]temp;
}
void statistic::sortfunction( int low, int high, int ind)
{
		if(low<high)
	{
		int mid = (low+high)/2;
		sortfunction(low,mid,ind);
		sortfunction(mid+1,high,ind);
		mergefunction(low,mid,high,ind);
	}
}
void statistic::mergefunction(int low, int mid, int high, int ind)
{
	int n = high-low+1;
	storepointers* b = new storepointers[n];
	int left= low, right = mid+1,bidx=0;
	
	switch(ind)
	{

		case 1://for revenue
			{
				while(left<= mid && right <= high)
				{
					if(storeptrs[left].prdptr->getrevenue()>=storeptrs[right].prdptr->getrevenue())
					b[bidx++]=storeptrs[left++];
					else
					b[bidx++]=storeptrs[right++];
				}
				while(left<=mid)
					b[bidx++]=storeptrs[left++];
				while(right<=high)
					b[bidx++]=storeptrs[right++];
				for(int k=0; k<n;k++)
					{storeptrs[low+k]=b[k];	}
				delete[]b;
			}
			break;

			case 2://for discountedprice
			{
				while(left<= mid && right <= high)
				{
					if(storeptrs[left].prdptr->getdiscountedprice()<=storeptrs[right].prdptr->getdiscountedprice())
					b[bidx++]=storeptrs[left++];
					else
					b[bidx++]=storeptrs[right++];
				}
				while(left<=mid)
					b[bidx++]=storeptrs[left++];
				while(right<=high)
					b[bidx++]=storeptrs[right++];
				for(int k=0; k<n;k++)
					{storeptrs[low+k]=b[k];	}
				delete[]b;
			}
			break;

			case 3://for stockrank
			{
				while(left<= mid && right <= high)
				{
					if(storeptrs[left].prdptr->getnumstock()<=storeptrs[right].prdptr->getnumstock())
					b[bidx++]=storeptrs[left++];
					else
					b[bidx++]=storeptrs[right++];
				}
				while(left<=mid)
					b[bidx++]=storeptrs[left++];
				while(right<=high)
					b[bidx++]=storeptrs[right++];
				for(int k=0; k<n;k++)
					{storeptrs[low+k]=b[k];	}
				delete[]b;
			}
			break;

			case 4://for worthrank
			{
				while(left<= mid && right <= high)
				{
					if(storeptrs[left].n<=storeptrs[right].n)
					b[bidx++]=storeptrs[left++];
					else
					b[bidx++]=storeptrs[right++];
				}
				while(left<=mid)
					b[bidx++]=storeptrs[left++];
				while(right<=high)
					b[bidx++]=storeptrs[right++];
				for(int k=0; k<n;k++)
					{storeptrs[low+k]=b[k];	}
				delete[]b;
			}
			break;
	}
	}
void statistic::sortsetpricerank()
{
	sortfunction(0,listsize-1,2);
	for(int i=1;i<listsize+1;i++)
	{
		storeptrs[i-1].n+=i;
	}
}
void statistic::sortsetstockrank()
{
	sortfunction(0,listsize-1,3);
	for(int i=1;i<listsize+1;i++)
	{
		storeptrs[i-1].n=i;
	}
}
void statistic::sortsetworthrank()
{
	sortsetstockrank();
	sortsetpricerank();
	sortfunction(0,listsize-1,4);

}
void statistic::returnpointer(Product** &returnptr)
{
	Product**arrptr = new Product*[listsize];
	for(int i=0;i<listsize;i++)
	{
		arrptr[i]=storeptrs[i].prdptr;
	}
	returnptr = arrptr;
}