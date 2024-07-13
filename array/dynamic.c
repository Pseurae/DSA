#include <stdio.h>
#include "array.h"

#define ASSERT(_cond, ...) \
    do { if (!(_cond)) { \
        printf(__VA_ARGS__); \
        return; \
    } } while (0)

array_t(int) my_array = NULL;

static void construct_array(void)
{
    unsigned int size;
    printf("Enter no. of elements: ");
    scanf("%u", &size);

	array_free(my_array);

    for (unsigned int i = 0; i < size; ++i)
    {
        int number;
        printf("Enter a number: ");
        scanf("%i", &number);

		array_push(my_array, number);
    }
}

static void display_array(void)
{
	ASSERT(array_size(my_array) > 0, "Array is empty!\n");
    printf("my_array: [");
    for (unsigned int i = 0; i < array_size(my_array) - 1; ++i)
        printf("%i, ", my_array[i]);
    printf("%i]\n", my_array[array_size(my_array) - 1]);
}

static void insert_into_array(void)
{
    int number;
    printf("Enter a number: ");
    scanf("%i", &number);

	array_push(my_array, number);
}

static void delete_from_array(void)
{
	ASSERT(array_size(my_array) > 0, "Array is empty!\n");
	array_pop(my_array);
}

static void search_in_array(void)
{
    long found = -1;

    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    for (unsigned int i = 0; i < array_size(my_array); ++i)
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
    int choice;

    printf(
        "1. Create\n"
        "2. Display\n"
        "3. Insert\n"
        "4. Delete\n"
        "5. Search\n"
        "6. Exit\n"
    );

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

	array_free(my_array);
    return 0;
}
