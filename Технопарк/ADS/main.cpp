/*
 * Дан массив строк. Количество строк не больше 105.
 * Отсортировать массив методом поразрядной сортировки MSD по символам.
 */

/* In              ---->             Out
 * ab                                 a
 * a                                  aa
 * aaa                                aaa
 * aa                                 ab
 */

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>

#define COUNT_SYMBOLS 256

using namespace std;

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

///////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void print_array(T* arr, int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << "\n";
}

template <class T>
void print_vector(vector<T> arr, int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << "\n";
}
void create_new_null_array(int **c, int k)
{
    *c = new int[k];
    for(int i = 0; i < k; i++)
        (*c)[i] = 0;
}

void my_sort(string *a, int l, int r, int pos)
{
    if(r - l <= 1)
        return ;

    int k = COUNT_SYMBOLS;

    int *arr_with_ends, *arr_with_counts;
    create_new_null_array(&arr_with_ends, k);
    create_new_null_array(&arr_with_counts, k);

    for(int i = l; i < r; i++)
        ++arr_with_counts[(int)a[i][pos]];

    memcpy(arr_with_ends, arr_with_counts, k * sizeof(int));
    for(int i = 1; i < k; i++)
        arr_with_ends[i] += arr_with_ends[i - 1];

    string *b = new string[r - l];
    for(int i = r - 1; i >= l; i--)
        b[--(arr_with_ends[(int)a[i][pos]])] = a[i];

    for(int i = l, j = 0; i < r; i++, j++)
        a[i] = b[j];

    for(int i = 0; i < k - 1; i++)
        if(arr_with_ends[i + 1] - arr_with_ends[i] > 1)
            my_sort(a, arr_with_ends[i], arr_with_ends[i + 1], pos + 1);

    delete []b;
    delete []arr_with_ends;
}

void my_sort_with_vector(vector<string> *a, int l, int r, int pos)
{
    if(r - l <= 1)
        return ;

    int k = COUNT_SYMBOLS;

    int *arr_with_ends, *arr_with_counts;
    create_new_null_array(&arr_with_ends, k);
    create_new_null_array(&arr_with_counts, k);

    for(int i = l; i < r; i++)
        ++arr_with_counts[(int)(*a)[i][pos]];

    memcpy(arr_with_ends, arr_with_counts, k * sizeof(int));
    for(int i = 1; i < k; i++)
        arr_with_ends[i] += arr_with_ends[i - 1];

    string *b = new string[r - l];
    for(int i = r - 1; i >= l; i--)
        b[--(arr_with_ends[(int)(*a)[i][pos]])] = (*a)[i];

    for(int i = l, j = 0; i < r; i++, j++)
        (*a)[i] = b[j];

    for(int i = 0; i < k - 1; i++)
        if(arr_with_ends[i + 1] - arr_with_ends[i] > 1)
            my_sort_with_vector(a, arr_with_ends[i], arr_with_ends[i + 1], pos + 1);

    delete []b;
    delete []arr_with_ends;
}

int main()
{
    int base_size = 5;
    string *arr = new string[base_size];

    int n = 0;
//    for(; !cin.eof(); n++)
//    {
//        if(n == base_size)
//        {
//            base_size *= 2;
//            string *t = new string[base_size];
//
//            for(int i = 0; i < n; i++)
//                t[i] = arr[i];
//
//            delete []arr;
//            arr = t;
//        }
//        getline(cin, arr[n]);
//    }

    for(; !cin.eof(); n++)
        getline(cin, arr[n]);

    cout << "Before\n";
    print_array(arr, n);
    my_sort(arr, 0, n, 0);

    cout << "After\n";
    print_array(arr, n);

    delete []arr;

//    vector<string> arr;
//
//    int n = 0;
//    for(; !cin.eof(); n++)
//    {
//        string t;
//        getline(cin, t);
//        arr.push_back(t);
//    }
//
//    cout << "Before\n";
//    print_vector(arr, n);
//    my_sort_with_vector(&arr, 0, n, 0);
//
//    cout << "After\n";
//    print_vector(arr, n);
}