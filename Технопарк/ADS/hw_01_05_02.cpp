/*
 * Группа людей называется современниками если был такой момент, когда они могли собраться вместе.
 * Для этого в этот момент каждому из них должно было  уже исполниться 18 лет, но ещё не исполниться 80 лет.
 * Дан список Жизни Великих Людей. Необходимо получить максимальное количество современников.
 * В день 18летия человек уже может принимать участие в собраниях, а в день 80летия и в день смерти уже не может.
 * Замечание. Человек мог не дожить до 18-летия, либо умереть в день 18-летия. В этих случаях принимать участие в собраниях он не мог.
 */

#include <iostream>
#include <cassert>
#include <cstring>
#include <sstream>

#define ADD_PERSON 1
#define DELETE_PERSON -1

typedef struct
{
    int day;
    int month;
    int year;
} date_t;

typedef struct
{
    date_t date;
    int diff;
} point_t;

typedef struct
{
    int count_points;
    point_t *data;
} points_t;

int cmp_dates(date_t const *const x, date_t const *const y)
{
    if(x->year != y->year)
        return x->year - y->year;
    if(x->month != y->month)
        return x->month - y->month;
    return x->day - y->day;
}

void print_date(date_t *date)
{
    std::cout << "(" << date->day << ", " << date->month << ", " << date->year << ")";
}

void print_point(point_t *p)
{
    print_date(&p->date);
    std::cout << "  " << p->diff << "\n";
}

void add_point_to_points(points_t *points, date_t *date, int diff)
{
    points->data[points->count_points].date = *date;
    points->data[points->count_points].diff = diff;
    points->count_points++;
}

points_t input_persons(std::istream& input, int count_persons)
{
    points_t points = {.count_points = 0,
            .data = new point_t[count_persons * 2]};

    for(int i = 0; i < count_persons; ++i)
    {
        date_t birthday, death;
        input >> birthday.day >> birthday.month >> birthday.year;
        input >> death.day >> death.month >> death.year;

        birthday.year += 18;                                // Получили дату 18-летия человека
        if(cmp_dates(&birthday, &death) >= 0)
            continue;

        add_point_to_points(&points, &birthday, ADD_PERSON);

        birthday.year += 62;                                // Получили дату 80-летия человека
        if(cmp_dates(&birthday, &death) >= 0)               // Человеку не дожил до 80-ти летия
            add_point_to_points(&points, &death, DELETE_PERSON);
        else
            add_point_to_points(&points, &birthday, DELETE_PERSON);
    }

    return points;
}

bool cmp_points(point_t const p1, point_t const p2)
{
    return cmp_dates(&p1.date, &p2.date) < 0;
}

void print_points(points_t *p)
{
    std::cout << "Count points = " << p->count_points << "\n";
    for(int i = 0; i < p->count_points; i++)
        print_point(&p->data[i]);
}

template<class T>
void merge(T *left_array, int left_len, T *right_array, int right_len, T *new_array, bool (*_isLess)(const T, const T))
{
    int left_i = 0, right_i = 0, new_i = 0;

    for(; new_i < left_len + right_len && left_i < left_len && right_i < right_len; new_i++)
    {
        if(_isLess(left_array[left_i], right_array[right_i]))
            new_array[new_i] = left_array[left_i++];
        else
            new_array[new_i] = right_array[right_i++];
    }

    for(; left_i < left_len; left_i++)
        new_array[new_i++] = left_array[left_i];

    for(; right_i < right_len; right_i++)
        new_array[new_i++] = right_array[right_i];
}

template<class T>
void merge_sort(T *array, int count_elems, bool (*_isLess)(const T, const T))
{
    if(count_elems <= 1)
        return ;

    int left_len = count_elems / 2;
    int right_len = count_elems - left_len;
    merge_sort(array, left_len, _isLess);
    merge_sort(array + left_len, right_len, _isLess);

    T *c = new T[count_elems];
    merge(array, left_len, array + left_len, right_len, c, _isLess);
    memcpy(array, c, sizeof(T) * count_elems);
    delete []c;
}

int find_max(points_t *p)
{
//    print_points(p);
    int now_len = 0, max_len = 0;
    for(int i = 0; i < p->count_points; i++)
    {
        now_len += p->data[i].diff;
        int j = i + 1;
        for(; j < p->count_points && !cmp_dates(&p->data[j - 1].date, &p->data[j].date); j++)
            now_len += p->data[j].diff;
        max_len = std::max(now_len, max_len);
        i = j - 1;
    }
    return max_len;
}

void run(std::istream& input, std::ostream& output)
{
    int n;
    input >> n;
    assert( n >= 0 );

    points_t points = input_persons(input, n);
    merge_sort(points.data, points.count_points, cmp_points);

    output << find_max(&points);

    delete []points.data;
}

void test()
{
    {
        std::stringstream input;
        std::stringstream output;
        input << "3 ";
        input << "2 5 1980 13 11 2055 ";
        input << "1 1 1982 1 1 2030 ";
        input << "2 1 1920 2 1 2000 ";
        run( input, output );
        if(output.str() == "3")
            std::cout << "TEST 1 ---> PASSED\n";
        else
            std::cout << "TEST 1 ---> FAILURE\n";
    }
    {
        std::stringstream input;
        std::stringstream output;
        input << "3 ";
        input << "1 1 2000 1 1 2018 ";
        input << "1 1 2018 1 1 2036 ";
        input << "1 1 2036 1 1 2036 ";
        run( input, output );
        if(output.str() == "0")
            std::cout << "TEST 2 ---> PASSED\n";
        else
            std::cout << "TEST 2 ---> FAILURE\n";
    }
    {
        std::stringstream input;
        std::stringstream output;
        input << "3 ";
        input << "1 1 2000 2 1 2018 ";
        input << "2 1 2018 3 1 2036 ";
        input << "3 1 2036 1 1 2036 ";
        run( input, output );
        if(output.str() == "1")
            std::cout << "TEST 3 ---> PASSED\n";
        else
            std::cout << "TEST 3 ---> FAILURE\n";
    }
    {
        std::stringstream input;
        std::stringstream output;
        input << "2 ";
        input << "1 1 2000 2 1 2018 ";
        input << "2 1 2000 3 1 2036 ";
        run( input, output );
        if(output.str() == "1")
            std::cout << "TEST 4 ---> PASSED\n";
        else
            std::cout << "TEST 4 ---> FAILURE\n";
    }
}

int main()
{
    test();
}