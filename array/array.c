#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 5
#define MIN(_A, _B) ((_A) > (_B) ? (_B) : (_A))

static int my_array[MAX_ELEMENTS];
static int array_size = 0;

#define ASSERT(_cond, ...) \
    do { if (!(_cond)) { \
        printf(__VA_ARGS__); \
        return; \
    } } while (0)

static void construct_array(void)
{
    int size;
    printf("Enter no. of elements: ");
    scanf("%i", &size);

    ASSERT(size > 0 && size <= MAX_ELEMENTS, "Size of the array should be between 1 and %i.\n", MAX_ELEMENTS);

    for (unsigned int i = 0; i < size; ++i)
    {
        printf("Enter a number: ");
        scanf("%i", &my_array[i]);
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
    ASSERT(array_size + 1 <= MAX_ELEMENTS, "Array is full!\n");

    int pos;
    printf("Enter the position: ");
    scanf("%i", &pos);

    ASSERT(pos >= 0 && pos < MAX_ELEMENTS, "Position should be between 0 and %i.\n", MAX_ELEMENTS - 1);

    pos = MIN(pos, array_size);

    int number;
    printf("Enter a number: ");
    scanf("%i", &number);

    if (array_size - pos > 0) memmove(my_array + pos + 1, my_array + pos, (array_size - pos) * sizeof(int));
    my_array[pos] = number;
    array_size++;
}

static void delete_from_array(void)
{
    ASSERT(array_size > 0, "Array is empty!\n");

    int pos;
    printf("Enter the position: ");
    scanf("%i", &pos);

    ASSERT(pos >= 0 && pos < MAX_ELEMENTS, "Position should be between 0 and %i.\n", MAX_ELEMENTS - 1);

    if (array_size - pos - 1 > 0) memmove(my_array + pos, my_array + pos + 1, (array_size - pos - 1) * sizeof(int));
 
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

    while (1)
    {
        int choice;
        printf("Enter choice: ");
        scanf("%i", &choice);

        if (choice == 6) break;

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
            printf("Invalid option!\n");
            break;
        }
    }
    return 0;
}