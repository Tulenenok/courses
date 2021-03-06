#include <iostream>
#include <cassert>
#include <cstring>
#include <sstream>

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
    const T& TakeElemByIndex(int i);
    T *TakePointerByIndex(int i);
    void FillByArray( const T *arr, int size);

    int Size() const { return size; }
    bool IsEmpty() const { return Size() == 0; }
    void reduceSizeByOne();

private:
    int size = 0;
    int maxSize = 4;
    T *array;

    void Expand();
};

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
const T& DynamExpandArray<T>::TakeElemByIndex(int i)
{
    return array[i];
}

template<class T>
T *DynamExpandArray<T>::TakePointerByIndex(int i)
{
    return array + i;
}

template<class T>
void DynamExpandArray<T>::reduceSizeByOne()
{
    --size;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool intIsLess(const int x, const int y)
{
    return x < y;
}

void intPrint( const int& x)
{
    std::cout << x;
}

template<class T>
class Heap {
public:
    Heap( bool (*_isLess)(const T, const T), void (*_printElem)( const T&) );
    Heap( const T *arr, int size, bool (*_isLess)(const T, const T), void (*_printElem)( const T&));
    Heap( const Heap& ) = delete;
    ~Heap() = default;

    Heap& operator=( const Heap& h ) = delete;

    void Insert( const T& elem );
    const T& TakeMaxElem();
    T ExtractMax();
    int Size() const { return size; }
    void Print();
    void SetLastElem(const T& newElem);

private:
    int size = 0;
    bool (*isLess)(const T, const T);
    void (*printELem)( const T&);
    DynamExpandArray<T> data;

    void buildHeap();
    void siftDown( int i );
    void siftUp( int i );
};


template<class T>
Heap<T>::Heap( bool (*_isLess)(const T, const T), void (*_printElem)( const T&) )
{
    isLess = _isLess;
    printELem = _printElem;
}

template<class T>
Heap<T>::Heap( const T *arr, int _size, bool (*_isLess)(const T, const T), void (*_printElem)( const T&))
{
    isLess = _isLess;
    printELem = _printElem;
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

    if( (right < size) && isLess( data.TakeElemByIndex(max), data.TakeElemByIndex(right) ))
        max = right;

    if(max != i)
    {
//        std::cout << "new iter\n";
//        Print();

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
        if( isLess( data.TakeElemByIndex(i), data.TakeElemByIndex(parent) ) )
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
        printELem(data.TakeElemByIndex(i));
    std::cout << "\n";
}

template<class T>
void Heap<T>::Insert( const T& elem )
{
    data.PushBack( elem );
    siftUp( size );
    size++;
}

template<class T>
T Heap<T>:: ExtractMax()
{
    T tmp = data.TakeElemByIndex( 0 );
    *data.TakePointerByIndex( 0 ) = data.TakeElemByIndex( --size );
    data.reduceSizeByOne();
    siftDown( 0 );
    return tmp;
}

template<class T>
const T& Heap<T>::TakeMaxElem()
{
    return data.TakeElemByIndex( 0 );
}

template<class T>
void Heap<T>::SetLastElem(const T& newElem)
{
    *data.TakePointerByIndex( size - 1 ) = newElem;
    siftUp( size - 1 );
}

void testHeap()
{
    int arr[] = {3, 7, 9, 6, 8, 4};

    Heap<int> n(arr, 6, intIsLess, intPrint);
    n.Print();

    n.Insert( 10 );
    n.Print();

    n.Insert( 11 );
    n.Print();

    std::cout << n.ExtractMax() << "\n";
    n.Print();

    std::cout << n.TakeMaxElem() << "\n";
    n.Print();

    std::cout << n.Size() << "\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct
{
    int id_user;
    int attendance;
} user_t;

bool user_isLess(user_t u1, user_t u2)
{
    return u1.attendance < u2.attendance;
}

bool user_isMore(user_t u1, user_t u2)
{
    return u1.attendance > u2.attendance;
}

void user_print(const user_t& u)
{
    std::cout << u.id_user << " " << u.attendance << "\n";
}

void user_print_id(const user_t& u)
{
    std::cout << u.id_user << " ";
}

void run( std::istream& input, std::ostream& output )
{
    int n, k;

    input >> n >> k;
    assert( n >= k);

    Heap<user_t> users(user_isLess, user_print);
    for(int i = 0; i < n; i++)
    {
        user_t new_user;
        input >> new_user.id_user >> new_user.attendance;
        if(i < k + 1)
            users.Insert(new_user);
        else
            users.SetLastElem(new_user);
    }

    int *id_k_users = new int[k];
    for(int i = 0; i < k; i++)
        id_k_users[i] = users.ExtractMax().id_user;


    for(int i = k; i > 0; i--)
    {
        output << id_k_users[i - 1] << " ";
        std::cout << id_k_users[i - 1] << " ";
    }

    delete [] id_k_users;
}

void test_Heap()
{
    {
        std::stringstream input;
        std::stringstream output;
        input << "5 3 1 100 2 200 3 300 4 400 5 500";
        run( input, output );
        if(output.str() == "3 4 5 ")
            std::cout << "TEST 1 ---> PASSED\n";
        else
            std::cout << "TEST 1 ---> FAILURE\n";
    }
    {
        std::stringstream input;
        std::stringstream output;
        input << "5 3 1 500 2 400 3 300 4 200 5 100";
        run( input, output );
        if(output.str() == "3 2 1 ")
            std::cout << "TEST 2 ---> PASSED\n";
        else
            std::cout << "TEST 2 ---> FAILURE\n";
    }
    {
        std::stringstream input;
        std::stringstream output;
        input << "3 3 1 1 2 2 3 3";
        run( input, output );
        if(output.str() == "1 2 3 ")
            std::cout << "TEST 3 ---> PASSED\n";
        else
            std::cout << "TEST 3 ---> FAILURE\n";
    }
    {
        std::stringstream input;
        std::stringstream output;
        input << "5 1 1 100 2 200 3 300 4 400 5 500";
        run( input, output );
        if(output.str() == "5 ")
            std::cout << "TEST 4 ---> PASSED\n";
        else
            std::cout << "TEST 4 ---> FAILURE\n";
    }
    {
        std::stringstream input;
        std::stringstream output;
        input << "5 2 1 100 2 500 3 400 4 300 5 200";
        run( input, output );
        if(output.str() == "3 2 ")
            std::cout << "TEST 5 ---> PASSED\n";
        else
            std::cout << "TEST 5 ---> FAILURE\n";
    }
}

//int main()
//{
//    test_Heap();
//    return 0;
//}

int main()
{
    int n, k;

    std::cin >> n >> k;
    assert( n >= k);

    Heap<user_t> users(user_isMore, user_print);
    for(int i = 0; i < n; i++)
    {
        user_t new_user;
        std::cin >> new_user.id_user >> new_user.attendance;
        if(i < k)
            users.Insert(new_user);
        else if(users.TakeMaxElem().attendance < new_user.attendance)
        {
            users.ExtractMax();
            users.Insert(new_user);
        }
    }

    for(int i = 0; i < k; i++)
        std::cout << users.ExtractMax().id_user << " ";
}