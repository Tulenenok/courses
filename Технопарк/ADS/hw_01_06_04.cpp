/*
 * Дано множество целых чисел из [0..10^9] размера n.
 * Используя алгоритм поиска k-ой порядковой статистики, требуется найти следующие параметры множества:
 * 10% перцентиль
 * медиана
 * 90% перцентиль
 *
 *  Реализуйте стратегию выбора опорного элемента “случайный элемент”.
 *  Функцию Partition реализуйте методом прохода двумя итераторами от конца массива к началу.
 */

#include <iostream>
#include <cstdlib>
#include <cassert>

template <class T>
int partition(T *arr, int left, int right, int (*cmp_T)(const T, const T))
{
    assert( left < right );

    int pivot_pos = left + rand() % (right - left);
    std::swap(arr[left], arr[pivot_pos]);
    pivot_pos = left;

    int i = right - 1;      // начало элементов строго больше опорного
    int j = right - 1;      // первый не рассмотренный элемент

    for(; j > left; j--)
        if(cmp_T(arr[j], arr[pivot_pos]) > 0)
        {
            std::swap(arr[j], arr[i]);
            i--;
        }
    std::swap(arr[left], arr[i]);
    return i;
}

template <class T>
void print_array(int n, T *a)
{
    for(int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << "\n";
}

template <class T>
T find_k_stat(T *arr, int left, int right, int k_stat, int (*cmp_T)(const T, const T))
{
    int pivot_pos = partition(arr, left, right, cmp_T);
    while(k_stat != pivot_pos)
    {
        if(k_stat < pivot_pos)
            right = pivot_pos;
        else
            left = pivot_pos + 1;
        pivot_pos = partition(arr, left, right, cmp_T);
    }
    return arr[k_stat];
}

int cmp_int(int x, int y)
{
    return x - y;
}

int main()
{
    int n;
    std::cin >> n;

    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        std::cin >> arr[i];

    std::cout  << find_k_stat(arr, 0, n, n / 10, cmp_int) << "\n";
    std::cout  << find_k_stat(arr, 0, n, n / 2, cmp_int) << "\n";
    std::cout  << find_k_stat(arr, 0, n, n * 9 / 10, cmp_int) << "\n";

    delete []arr;
}