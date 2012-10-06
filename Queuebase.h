#ifndef _QUEUEBASE_H_
#define _QUEUEBASE_H_
#include <iostream>
using namespace std;
template <typename T>
class QueueBase {
	protected:
		int _size;
	public:
		QueueBase() {_size = 0;}
		virtual ~QueueBase() {}
		virtual bool isempty() {return(_size==0);}
		virtual int size(){return _size;}
		virtual bool enqueue(const T& newItem)=0;
		virtual bool dequeue(T& queueFront) = 0;
		virtual bool getFront(T& queueFront) = 0;
};
template <typename T>
class QueueLL: public QueueBase<T>
{
private:
	struct ListNode{
		T item;
		ListNode* next;
	};
	ListNode* _tail;
public:
	QueueLL()
	{
		_size=0;
		_tail=NULL;
	}
	~QueueLL(){}
	bool enqueue(const T& newItem)
	{
		ListNode* newnode;
		newnode = new ListNode;
		newnode->item= newItem;
		newnode->next=NULL;
		if(_size==0)
		{
			_tail=newnode;
			newnode->next=newnode;
			_size++;
		}
		else {
			ListNode* temp;
			temp=_tail->next;
			_tail->next=newnode;
			newnode->next=temp;
			_tail=newnode;
			_size++;

		}
		return true;
	}
	bool getFront(T& queuefront)
	{
		if(_size==0)
			return false;
		queuefront= _tail->next->item;
		return true;
	}
	bool dequeue(T& queuefront)
	{
		if(_size==0)
			return false;
		if(_size==1)
		{
			queuefront=_tail->item;
			delete _tail;
			_tail=NULL;
			_size--;}
		else{
			queuefront=_tail->next->item;
			ListNode* temp;
			temp=_tail->next;
			_tail->next=_tail->next->next;
			delete temp;
			_size--;
		}
		return true;
	}
};
#endif
