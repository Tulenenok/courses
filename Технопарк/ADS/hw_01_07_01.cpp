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

#define COUNT_SYMBOLS 256

using namespace std;

template <class T>
void print_array(T* arr, int n)
{
    int i = 0;
    for(; i < n - 1; i++)
        cout << arr[i] << "\n";
    cout << arr[i];
}

void create_new_null_array(int **c, int k)
{
    *c = new int[k];
    for(int i = 0; i < k; i++)
        (*c)[i] = 0;
}

void print_not_null_elems(int *a, int n, string name = "print array")
{
    cout << name << "\n";
    for(int i = 0; i < n; i++)
        if(a[i] != 0)
            if(i == 0 || (i > 1 && a[i] != a[i - 1]))
                cout << "char = " << char(i) << "; count = " << a[i] << "\n";

    cout << "\n";
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

int main()
{
    int n = 0;
    cin >> n;

    string *arr = new string[n];
    string t;
    getline(cin, t);

    for(int i = 0; i < n; i++)
        getline(cin, arr[i]);

    my_sort(arr, 0, n, 0);

    print_array(arr, n);

    delete []arr;
}

