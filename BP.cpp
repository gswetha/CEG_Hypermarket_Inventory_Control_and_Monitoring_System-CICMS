#include"BP.h"
BP::BP()
{
	mystack= new StackV<QueueBase<job*>*>;
	USER=NULL;
}
void BP::readandexecutejob(Hypermarket* hyper)
{
	ifstream Infile("batchjobs-m.txt");
	int personnum;
	string personname;
	int jobnum;
	string temp;
	string namejob;
	string prdname;
	string barcode;
	string category;
	double price;
	string manu;
	int numrestock;
	int numsold;
	string date;
	Infile>>personnum;
	USER= new QueueBase<job*>* [personnum];
	getline(Infile,temp);
	getline(Infile,temp);
	for(int i=1;i<=personnum;i++)
	{
		getline(Infile,personname);
		Infile>>jobnum;
		getline(Infile,temp);
		getline(Infile,temp);
		USER[i-1]=new QueueLL<job*>;
		for(int j=1;j<=jobnum;j++)
		{
			job* myjob;
			Infile>>namejob;
			if(namejob=="ADD")
			{
				getline(Infile,temp);
				getline(Infile,prdname);
				getline(Infile,category);
				getline(Infile,barcode);
				Infile>>price;
				getline(Infile,temp);
				getline(Infile,manu);
				Infile>>numrestock;
				getline(Infile,temp);
				myjob=new add(personname,prdname,category,barcode,price,manu,numrestock);
			}
			else if(namejob=="DELETE")
			{
				getline(Infile,temp);
				getline(Infile,barcode);
				myjob= new jobdelete(personname,barcode);
			}
			else if(namejob=="RESTOCK")
			{
				getline(Infile,temp);
				Infile>>barcode;
				Infile>>numrestock;
				getline(Infile,temp);
				myjob=new _restock(personname,barcode,numrestock);
			}
			else if(namejob=="DISPOSE")
			{
				getline(Infile,temp);
				Infile>>barcode;
				Infile>>date;
				getline(Infile,temp);
				myjob= new dispose(personname,barcode,date);					
			}
			else if(namejob=="SALE")
			{
				Infile>>barcode;
				Infile>>numsold;
				getline(Infile,temp);
				myjob=new _sale(personname,barcode,numsold);
			}			
			USER[i-1]->enqueue(myjob);
			getline(Infile,temp);
		}
		mystack->push(USER[i-1]);
	}
	int stacksize;
	int queuesize;
	job* thisjob;
	QueueBase<job*>* temp1; 
	stacksize=mystack->size();
	ofstream writeFile("log_m.txt");
	for(int i=stacksize-1;i>=0;i--)
	{
		queuesize=USER[i]->size();
		for(int j=0;j<queuesize;j++)
		{
			USER[i]->getFront(thisjob);
			if(!(thisjob->execute(hyper)))
			{
				writeFile<<thisjob->error();
				writeFile<<endl;
			}
			USER[i]->dequeue(thisjob);
		}
		mystack->pop(temp1);
	}
}
