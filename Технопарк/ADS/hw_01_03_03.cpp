#include "hw_01_03_03.h"

/*
 * Реализовать очередь с помощью двух стеков. Использовать стек, реализованный с помощью динамического буфера.
 * Обрабатывать команды push back и pop front.
 *
 * В первой строке количество команд n. n ≤ 1000000.
 * Каждая команда задаётся как 2 целых числа: a b.
 *
 * a = 2 - pop front
 * a = 3 - push back
 *
 * Если дана команда pop front, то число b - ожидаемое значение.
 * Если команда pop front вызвана для пустой структуры данных, то ожидается “-1”.
 */

#include <cassert>
#include <iostream>
#include <cstring>

#define MODE_PUSH_BACK 3
#define MODE_POP_FRONT 2

template<class T>
DynamExpandArray<T>::DynamExpandArray()
{
    array = new T[maxSize];
}

template<class T>
void DynamExpandArray<T>::FillByArray(const T *arr, int _size)
{
    while(_size > maxSize)
        Expand();

    assert( memmove(array, arr, _size * sizeof(T)) );
    size = _size;
}

template<class T>
DynamExpandArray<T>::~DynamExpandArray()
{
    delete [] array;
}

template<class T>
void DynamExpandArray<T>::Expand()
{
    maxSize *= 2;
    T *tmp = new T[maxSize];
    assert( memmove(tmp, array, size * sizeof(T)) );
    delete [] array;
    array = tmp;
}

template<class T>
void DynamExpandArray<T>::PushBack( const T& value )
{
    if(size >= maxSize)
        Expand();

    array[size++] = value;
}

template<class T>
T DynamExpandArray<T>::PopBack()
{
    assert( !IsEmpty() );
    return array[--size];
}

template<class T>
void DynamExpandArray<T>::PushFront( const T& value )
{
    if(size >= maxSize)
        Expand();

    size++;
    for(int i = size; i > 0; i--)
        array[i] = array[i - 1];

    array[0] = value;
}

template<class T>
T DynamExpandArray<T>::PopFront()
{
    assert( !IsEmpty() );

    T tmp = array[0];
    for(int i = 0; i < size; i++)
        array[i] = array[i + 1];

    size--;
    return tmp;
}

template<class T>
void DynamExpandArray<T>::Print()
{
    for(int i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

template<class T>
T DynamExpandArray<T>::TakeElemByIndex(int i)
{
    return array[i];
}

template<class T>
T *DynamExpandArray<T>::TakePointerByIndex(int i)
{
    return array + i;
}

template<class T>
void Stack<T>::PushFront( const T& value )
{
    data.PushBack(value);
    size++;
}

template<class T>
T Stack<T>::PopFront()
{
    assert( !IsEmpty() );

    size--;
    return data.PopBack();
}

template<class T>
void Stack<T>::Print()
{
    data.Print();
}

void test_Stack()
{
    Stack<int> St;
    St.PushFront(1);
    St.PushFront(2);
    St.Print();
    St.PushFront(3);
    St.PushFront(4);
    St.PushFront(5);
    St.PushFront(6);
    St.Print();
    St.PopFront();
    St.Print();
    St.PopFront();
    St.PopFront();
    St.Print();
}


template<class T>
void Queue<T>::PushBack( const T& value )
{
    StackIn.PushFront(value);
    ++size;
}

template<class T>
T Queue<T>::PopFront()
{
    assert(size);

    if(StackOut.IsEmpty())
        StackInToStackOut();

    --size;
    return StackOut.PopFront();
}

template<class T>
void Queue<T>::StackInToStackOut()
{
    assert(StackOut.IsEmpty());

    while(StackIn.Size())
        StackOut.PushFront(StackIn.PopFront());
};

/*
int main()
{
    Queue<int> queue;
    int n = 0;
    std::cin >> n;
    bool result = true;

    for(int i = 0; i < n; i++) {
        int command = 0;
        int value = 0;

        std::cin >> command >> value;
        if(MODE_POP_FRONT == command)
            if(queue.IsEmpty())
                result = result && value == -1;
            else
                result = result && queue.PopFront() == value;
        else if(MODE_PUSH_BACK == command)
            queue.PushBack(value);
    }
    std::cout << (result ? "YES" : "NO");
    return 0;
}
*/