 ///
 /// @file    heap.cc
 /// @author  WildFiretobee(Danderous@email.com)
 /// @date    2018-04-24 22:10:04
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#define SWAP(a,b) { Type temp;temp = a; a=b; b=temp;}

template<typename Type,typename Compare=std::less<Type>>
class HeapSort
{
public:
	HeapSort(Type *arr, int size)
	: _arr(new Type[size]())
	, _size(size)
	{
		strcpy(_arr,arr);
	}
	void heapAdjust(Type & arr,int i,int size);
	void sort(Type & arr);

private:
	Type * _arr;
	int _size;
};


template<typename Type,typename Compare=std::less<Type>>
void HeapSort<Type>::heapAdjust(Type & a,int i,int size)
{
	int dad,son;
	dad=i;
	son=2*dad+1;
	while(son<size)
	{
		if(son+1<size&&a[son]<a[son+1])
		{
			son++;
		}
		if(a[dad]<a[son])
		{
			SWAP(a[dad],a[son]);
			dad=son;
			son=2*dad+1;
		}else{
			break;
		}
	}
}

template<typename Type,typename Compare=std::less<Type>>
void HeapSort<Type>::sort(Type & arr)
{
	int i=0;
	for(i=_size/2-1;i>=0;i--)
	{
		heapAdjust(arr,i,_size);
	}
	SWAP(a[0],a[_size-1]);

	for(i = _size-1; i>0; i--)
	{
		heapAdjust(arr, 0, _size);
		SWAP(a[0],a[i-1]);
	}
}

int main()
{
	int *a;
	for(int i=0;i<10;i++)
	{
		a[i]=i;
	}
	HeapSort heap(a,10);

	cout << "heap success" << endl;
	return 0;
}


