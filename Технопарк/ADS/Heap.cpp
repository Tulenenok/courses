//
// Created by nataa on 17.11.2021.
//

#include "Heap.h"

bool intIsLess(const int x, const int y)
{
    return x < y;
}

template<class T>
Heap<T>::Heap( bool (*_isLess)(const T, const T) )
{
    isLess = _isLess;
}

template<class T>
Heap<T>::Heap( const T *arr, int _size, bool (*_isLess)(const T, const T))
{
    isLess = _isLess;
    data.FillByArray(arr, _size);
    size = _size;

    buildHeap();
}

template<class T>
void Heap<T>::siftDown( int i )
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max = i;

    if( (left < size) && isLess( data.TakeElemByIndex(i), data.TakeElemByIndex(left) ))
        max = left;

    if( (right < size) && isLess( data.TakeElemByIndex(i), data.TakeElemByIndex(right) ))
        max = right;

    if(max != i)
    {
        T tmp = data.TakeElemByIndex(i);
        *data.TakePointerByIndex(i) = data.TakeElemByIndex(max);
        *data.TakePointerByIndex(max) = tmp;

        siftDown( max );
    }
}

template<class T>
void Heap<T>::siftUp( int i )
{
    while(i > 0)
    {
        int parent = ( i - 1 ) / 2;
        if( isLess({ data.TakeElemByIndex(i), data.TakeElemByIndex(parent) }) )
            return ;
        T tmp = data.TakeElemByIndex(i);
        *data.TakePointerByIndex(i) = data.TakeElemByIndex(parent);
        *data.TakePointerByIndex(parent) = tmp;
        i = parent;
    }
}

template<class T>
void Heap<T>::buildHeap()
{
    for(int i = size / 2 - 1; i >= 0; i--)
        siftDown( i );
}

template<class T>
void Heap<T>::Print()
{
    for(int i = 0; i < size; i++)
        std::cout << data.TakeElemByIndex(i) << " ";
    std::cout << "\n";
}

void testHeap()
{
    int arr[] = {3, 7, 9, 6, 8, 4};

    Heap<int> n(arr, 6, intIsLess);
    n.Print();
}

int main()
{
    testHeap();
}
