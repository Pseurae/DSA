#include <stdio.h>

#define MAX_ELEMENTS 20

static int my_array[MAX_ELEMENTS] = {};
static int array_size = 0;

#define ASSERT(_cond, ...) \
    do { if (!(_cond)) { \
        printf(__VA_ARGS__); \
        return; \
    } } while (0)

static void construct_array(void)
{
    unsigned int size;
    printf("Enter no. of elements: ");
    scanf("%u", &size);

    ASSERT(size < MAX_ELEMENTS, "Size of the array cannot be more than %i.\n", MAX_ELEMENTS);

    for (unsigned int i = 0; i < size; ++i)
    {
        int number;
        printf("Enter a number: ");
        scanf("%i", &number);

        my_array[i] = number;
    }

    array_size = size;
}

static void display_array(void)
{
    ASSERT(array_size > 0, "No content in array to display.\n");

    printf("my_array: [");
    for (unsigned int i = 0; i < array_size - 1; ++i)
        printf("%i, ", my_array[i]);
    printf("%i]\n", my_array[array_size - 1]);
}

static void insert_into_array(void)
{
    ASSERT(array_size + 1 < MAX_ELEMENTS, "Array is full!\n");

    int number;
    printf("Enter a number: ");
    scanf("%i", &number);

    my_array[array_size++] = number;
}

static void delete_from_array(void)
{
    ASSERT(array_size > 0, "Array is empty!\n");
    array_size--;
}

static void search_in_array(void)
{
    ASSERT(array_size > 0, "Array is empty!\n");

    long found = -1;

    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    for (unsigned int i = 0; i < array_size; ++i)
    {
        if (my_array[i] == number)
        {
            found = i;
            break;
        }
    }

    if (found == -1) printf("Array does not contain %i!\n", number);
    else printf("%i found at index %lu in array.\n", number, found);
}

int get_input(int *choice)
{
    int i = 0;

    while (i < 1 || i > 6)
    {
        printf("Enter choice: ");
        scanf("%d", &i);
    }

    *choice = i;

    return i != 6;
}

int main(int argc, char *argv[])
{
    printf(
        "1. Create\n"
        "2. Display\n"
        "3. Insert\n"
        "4. Delete\n"
        "5. Search\n"
        "6. Exit\n"
    );

    int choice;

    while (get_input(&choice))
    {
        switch (choice)
        {
        case 1:
            construct_array();
            break;
        case 2:
            display_array();
            break;
        case 3:
            insert_into_array();
            break;
        case 4:
            delete_from_array();
            break;
        case 5:
            search_in_array();
            break;
        default:
            break;
        }
    }
    return 0;
}