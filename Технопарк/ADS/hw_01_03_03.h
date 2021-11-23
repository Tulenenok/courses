#ifndef SEM_HW_01_03_03_H
#define SEM_HW_01_03_03_H

template<class T>
class DynamExpandArray {
public:
    DynamExpandArray();
    DynamExpandArray( const DynamExpandArray& ) = delete;
    ~DynamExpandArray();

    DynamExpandArray& operator = ( const DynamExpandArray& ) = delete;

    void PushBack( const T& value );
    T PopBack();
    void PushFront( const T& value );
    T PopFront();
    void Print();
    T TakeElemByIndex(int i);
    T *TakePointerByIndex(int i);
    void FillByArray( const T *arr, int size);

    int Size() const { return size; }
    bool IsEmpty() const { return Size() == 0; }

private:
    int size = 0;
    int maxSize = 4;
    T *array;

    void Expand();
};

template<class T>
class Stack {
public:
    Stack() = default;                         //  конструктор
    Stack( const Stack& ) = delete;
    ~Stack() = default;                        // деструктор

    Stack& operator = ( const Stack& ) = delete;

    void PushFront( const T& value );
    T PopFront();
    void Print();

    int Size() const { return size; }
    bool IsEmpty() const { return Size() == 0; }

private:
    DynamExpandArray<T> data;
    int size = 0;
};

template<class T>
class Queue {
public:
    Queue() = default;
    Queue( const Queue& ) = delete;
    ~Queue() = default;
    Queue& operator = ( const Queue& ) = delete;

    void PushBack( const T& value );
    T PopFront();

    int Size() const { return size;  }
    bool IsEmpty() const { return Size() == 0; }

private:
    int size = 0;
    Stack<T> StackIn;
    Stack<T> StackOut;

    void StackInToStackOut();
};

#endif //SEM_HW_01_03_03_H
