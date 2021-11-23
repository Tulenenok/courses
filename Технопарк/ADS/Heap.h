#ifndef SEM_HEAP_H
#define SEM_HEAP_H

template<class T>
class Heap {
public:
    Heap( bool (*_isLess)(const T, const T) );
    Heap( const T *arr, int size, bool (*_isLess)(const T, const T));
    Heap( const Heap& ) = delete;
    ~Heap() = default;

    Heap& operator=( const Heap& h ) = delete;

    void Insert( const T& elem );

    const T& PeekMax() const;

    T ExtractMax() const;

    int Size() const;

    void Print();

private:
    int size = 0;
    bool (*isLess)(const T, const T);
    DynamExpandArray<T> data;

    void buildHeap();
    void siftDown( int i );
    void siftUp( int i );
};

#endif //SEM_HEAP_H
