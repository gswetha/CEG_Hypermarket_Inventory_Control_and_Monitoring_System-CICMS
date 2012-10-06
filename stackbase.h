#ifndef _STACKBASE_H_
#define _STACKBASE_H_
#include <vector>
using namespace std;
template <typename T>
class StackBase{
    protected:
        int _size;
    public:
        StackBase() { _size = 0; } 
        virtual ~StackBase() {   }
        virtual bool isEmpty() { return (_size == 0); }
        virtual int size(){ return _size; }
        virtual bool push(const T& newItem ) = 0;
        virtual bool pop( T& stackTop ) = 0; 
        virtual bool getTop(T& stackTop) = 0;

};
template <typename T>
class StackV: public StackBase<T>{
private:
	vector<T> _items;
public:
	bool isEmpty(){return _items.empty();}
	int size(){return _items.size();}
	bool push(const T& newItem)
	{
		_items.push_back(newItem);
		_size++;
		return true;
	}
	bool pop(T& stackTop)
	{
		if ( _items.empty() )
			return false;
		else {
			stackTop = _items.back();
			_items.pop_back();
			_size--;
			}
		return true;
	}
	bool getTop(T& stackTop)
	{
		if ( _items.empty() )
			return false;
		else
			stackTop = _items.back();          
		return true;
	}
};

#endif
