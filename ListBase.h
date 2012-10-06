#ifndef LISTBASE_H
#define LISTBASE_H
#include <iostream>
using namespace std;

template <typename T>
class ListBase
{
protected:
	int _size;
	T* type ;
public:      
	ListBase() { _size = 0; }
	virtual ~ListBase(){}                 
	bool isEmpty() { return (_size == 0);}
	int getLength() { return _size;}
	virtual bool insert(int index, T& newItem)=0;
	virtual bool remove(int index)=0;
	virtual bool retrieve(int index, T& dataItem)=0;
	virtual T returnitem(int i){return 0;}
	virtual void copy(T* &temptype){};
}; 

template <typename T>
class ListDLL : public ListBase<T>
{
private:
	
	struct ListNode
	{
		T item;
		ListNode* prev;
		ListNode* next;
	};
	 ListNode* traverseTo(int index) 
	{
		if ( (index < 1) || (index > getLength()) )
        return NULL;
		else  // count from the beginning of the list.
		{  
			ListNode*cur = head;
			for (int skip = 0; skip < index-1; ++skip)
            cur = cur->next;
			return cur;
		}  // end if
	 }

	ListNode* head;
public:


ListDLL(): ListBase<T>(),head(NULL)

{
}

~ListDLL(){}
bool insert(int userIdx, T& newItem)
{
	int newLength = getLength() + 1;
	if ( (userIdx < 1) || (userIdx > newLength) )
		return false;
	else 
	{  
		ListNode *newPtr = new ListNode;
		newPtr->item = newItem;
		newPtr->next = NULL;
		newPtr->prev = NULL;
		_size = newLength;
		if (userIdx == 1)			
		{   
			if(_size==1)
			{
				newPtr->next = newPtr;
				newPtr->prev = newPtr;
				head=newPtr;
			}
			else
			{
					
				newPtr->prev = head->prev;
				newPtr->next = head;
				newPtr->prev->next=newPtr;
				newPtr->next->prev=newPtr;
				head=newPtr;
			}

		} 
		else 
		{  
			ListNode *previous = traverseTo(userIdx-1);
			// insert new node after node
			// to which prev points
			newPtr->next = previous->next;
			newPtr->prev = previous;
			previous->next=newPtr;
			newPtr->next->prev=newPtr;
		}  // end if

	}  //end if
	     return true;
}


bool remove(int userIdx)
{
	ListNode *cur;
	if ( (userIdx < 1) || (userIdx > getLength()) )
		return false;
	else {  
			--_size;
			if (userIdx == 1) 
			{  
				cur = head;
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
				head = head->next;

			} 
			else 
			{			
				ListNode *previous = traverseTo(userIdx - 1);
				cur = previous->next;  // save pointer to node
				previous->next = cur->next;
				cur->next->prev=previous;
			}  // end if
			delete cur;
			cur = NULL;
		}  // end if
	return true;
}



bool retrieve(int userIdx,T &dataItem)
{
	if ( (userIdx < 1) || (userIdx > getLength()) )
		return false;
	else
	{  // get pointer to node, then data in node
		ListNode *cur = traverseTo(userIdx);
		dataItem = cur->item;
	}  // end if
	return true;
}




T returnitem(int i)
{
	ListNode* myptr=traverseTo(i);
		return (myptr->item);
}

};
template <typename T>
class ListArr : public ListBase<T> 
{
private:
	T* _items;
	int _maxlist;
public:
	ListArr(int n)
	{
		_maxlist = n;
		_items= new T[_maxlist];
		_size=0;
	}
	bool insert(int userindex,  T&newItem)
	{
		
		int index = userindex- 1; 

		if(_size == _maxlist/2)
		{
			recopy();
			insert(index,newItem);}
		if (_size >= _maxlist)	{return false;}
	
		if ( (index< 0) || (index >= _size + 1) ){return false;}

		for ( int pos = _size-1; pos >= index; pos-- )
		{
			_items[pos+1] = _items[pos];
		}
		_items[index] = newItem;
		_size++;		
		return true;
	}
	bool remove(int userindex)
	{
		int index = userindex -1;
		if ((index < 0) || (index >= _size)){return false;}
		for ( int pos = index; pos < _size-1; pos++ )
		{
			_items[pos] = _items[pos+1];
		}
		_size--;
		return true;
	}
	bool retrieve(int userindex, T& dataItem)
	{
		int index = userindex -1;
		if ((index < 0) || (index >= _size)){return false;}
	
		dataItem = _items[index];
		return true;
	}	
	T returnitem(int i)
	{
		
		return _items[i-1];
	}
	int getLength() { return _size;};
	void recopy()
{
	_maxlist *=2;
	T *temp;
	int tempsize=(_maxlist/2);
	temp = new T[tempsize]; 
	for(int i=0;i<_size;i++)
	{
		temp[i]=_items[i];
	}
	
	_items=temp;

	
}
};
template <typename T>
class ListLL : public ListBase <T>
{
private:  
        struct ListNode 
		{
            T item;         
            ListNode *next;
        };
		ListNode*_head;
        ListNode* traverseTo(int index) 
		{
			if ( (index < 1) || (index > getLength()) )
				return NULL;
			else  
			{  
				ListNode*cur = _head;
				for (int skip = 1; skip < index; ++skip)
					cur = cur->next;
				return cur;
			}  
		}
	public:
        ListLL()
		{_head=NULL;_size=0;}
		~ListLL(){}
		bool insert(int userIdx,  T& newItem) 
		{
			int newLength = getLength() + 1;
			if ( (userIdx < 1) || (userIdx > newLength) )
				return false;
			else {  
				ListNode *newPtr = new ListNode;
				newPtr->item = newItem;
				newPtr->next = NULL;
				_size = newLength;
				if (userIdx == 1)
				{  
					newPtr->next = _head;
					_head = newPtr;
				} else {  
					ListNode *prev = traverseTo(userIdx-1);
					newPtr->next = prev->next;
					prev->next = newPtr;
				}  
			} 
			return true;
		}
       bool   remove(int userIdx) 
		{

			ListNode *cur;
			if ( (userIdx < 1) || (userIdx > getLength()) )
				return false;
			else {  
				--_size;
				if (userIdx == 1) {  
					cur = _head;  
					_head = _head->next;
				} else {
					ListNode *prev = traverseTo(userIdx - 1);
					cur = prev->next;  
					prev->next = cur->next;
				} 
				delete cur;
				cur = NULL;
			}  
			return true;
		}
		bool retrieve(int userIdx, T& dataItem) 
		{
			if ( (userIdx < 1) || (userIdx > getLength()) )
				return false;
			else
			{  
				ListNode *cur = traverseTo(userIdx);
				dataItem = cur->item;
			}  
			return true;
		}
               
        T returnitem(int i)
		{
			ListNode* ptr;
			ptr=traverseTo(i);
		    return ptr->item;
		}

		void copy(T* &temptype)
		{
			temptype= new T[_size];
			ListNode*ptr= _head;
			for(int i=0;i<_size;i++)
			{

				temptype[i]=ptr->item;
				ptr=ptr->next;
				
			}
		}
			
		
}; 
#endif