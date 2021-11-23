#include <iostream>

typedef struct
{
    int x;
    int y;
    int z;
    int V;
} box_t;

typedef struct
{
    int count_boxes;
    box_t *data;
    int *indexes;
} boxes_t;

box_t input_box()
{
    box_t new_box = { 0 };
    std::cin >> new_box.x >> new_box.y >> new_box.z;
    new_box.V = new_box.x * new_box.y * new_box.z;
    return new_box;
}

boxes_t input_boxes()
{
    boxes_t new_boxes = { 0 };
    std::cin >> new_boxes.count_boxes;

    new_boxes.data = new box_t[new_boxes.count_boxes];
    new_boxes.indexes = new int[new_boxes.count_boxes];

    for(int i = 0; i < new_boxes.count_boxes; i++)
    {
        new_boxes.data[i] = input_box();
        new_boxes.indexes[i] = i;
    }

    return new_boxes;
}

void simple_insertion(boxes_t *boxes)
{
    for(int i = 1; i < boxes->count_boxes; i++)
    {
        box_t tmp = boxes->data[i];
        int j = i - 1;

        for(; j >= 0 && tmp.V < boxes->data[j].V; j--)
        {
            boxes->data[j + 1] = boxes->data[j];
            boxes->indexes[j + 1] = boxes->indexes[j];
        }
        boxes->data[j + 1] = tmp;
        boxes->indexes[j + 1] = i;
    }
}

void print_indexes(boxes_t *boxes)
{
    for(int i = 0; i < boxes->count_boxes; i++)
        std::cout << boxes->indexes[i] << " ";
}

int main()
{
    boxes_t boxes = input_boxes();

    simple_insertion(&boxes);

    print_indexes(&boxes);
    return EXIT_SUCCESS;
}
