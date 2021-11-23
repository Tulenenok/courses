#include <iostream>

#define INVALID_INPUT_FIRST_ARRAY 2
#define INVALID_INPUT_SECOND_ARRAY 3

int input_array(int n, int a[])
{
    for(int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        if (i != 0 && a[i - 1] > a[i])
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void exp_search(int n, const int a[], int elem, int *left, int *right)
{
    for(; *right < n && a[*right] < elem; *right *= 2)
        *left = *right;
}
int bin_search(int n, const int a[], int elem)
{
    if(elem > a[n - 1])
        return n;

    int left = 0, right = 1;
    exp_search(n, a, elem, &left, &right);

    int pos = -1;

    while (left <= right)
    {
        int middle = (right + left) / 2;

        if (a[middle] < elem)
            left = middle + 1;
        else if (a[middle] > elem)
            right = middle - 1;
        else {
            pos = middle;
            right = middle - 1;
        }
    }
    return pos;
}

void print_intersection(int n, const int a[], int m, const int b[])
{
    for(int i = 0, pos = -1; i < m && pos < n; i++)
    {
        n -= pos * (pos != -1);
        a += pos * (pos != -1);

        pos = bin_search(n, a, b[i]);
        if(pos != -1 && pos != n)
            std::cout << b[i] << " ";
    }
}
int main()
{
    int n = 0, m = 0;
    std::cin >> n >> m;

    if(n <= m || n > 10000 || m > 10000)
        return EXIT_FAILURE;

    int a[n], b[m];

    if(input_array(n, a))
        return INVALID_INPUT_FIRST_ARRAY;

    if(input_array(m, b))
        return INVALID_INPUT_SECOND_ARRAY;

    print_intersection(n, a, m, b);
    return EXIT_SUCCESS;
}