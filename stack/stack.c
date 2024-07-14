#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_CAPACITY 20

#define ASSERT(_cond, ...) \
    do { if (!(_cond)) { \
        printf(__VA_ARGS__); \
        return; \
    } } while (0)

unsigned int stack_size = 0;
unsigned int stack_capacity = DEFAULT_CAPACITY;
int *my_stack = NULL;

/* Stack Operations */

static void stack_push(int i)
{
    ASSERT(my_stack, "Stack is not initialized!\n");
    if (stack_size + 1 >= stack_capacity)
    {
        stack_capacity *= 2;
        my_stack = (int *)realloc(my_stack, sizeof(int) * stack_capacity);
    }

    my_stack[stack_size++] = i;
}

static void stack_pop(void)
{
    ASSERT(my_stack, "Stack is not initialized!\n");
    stack_size--;
}

/* Demo Program */

static void construct_stack(void)
{
    ASSERT(!my_stack, "Stack is already constructed!\n");
    my_stack = malloc(sizeof(int) * stack_capacity);
    printf("Constructed stack!\n");
}

static void display_stack(void)
{
    ASSERT(my_stack, "Stack is not initialized!\n");
    ASSERT(stack_size > 0, "Stack is empty!\n");

    printf("my_stack: [");
    for (unsigned int i = 0; i < stack_size - 1; ++i)
        printf("%i, ", my_stack[i]);
    printf("%i]\n", my_stack[stack_size - 1]);
}

static void push_into_stack(void)
{
    ASSERT(my_stack, "Stack is not initialized!\n");

    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    stack_push(number);
}

static void pop_from_stack(void)
{
    ASSERT(my_stack, "Stack is not initialized!\n");
    ASSERT(stack_size > 0, "Stack is empty!\n");
    int number = my_stack[stack_size - 1];
    stack_pop();

    printf("Stack popped: %i\n", number);
}

static void search_in_stack(void)
{
    ASSERT(my_stack, "Stack is not initialized!\n");
    ASSERT(stack_size > 0, "Stack is empty!\n");

    long found = -1;

    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    for (unsigned int i = 0; i < stack_size; ++i)
    {
        if (my_stack[stack_size - i - 1] == number)
        {
            found = i;
            break;
        }
    }

    if (found == -1) printf("Stack does not contain %i!\n", number);
    else printf("%i found at position %lu from top.\n", number, found);
}

int main(int argc, char *argv[])
{
    printf(
        "1. Create\n"
        "2. Display\n"
        "3. Push\n"
        "4. Pop\n"
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
            construct_stack();
            break;
        case 2:
            display_stack();
            break;
        case 3:
            push_into_stack();
            break;
        case 4:
            pop_from_stack();
            break;
        case 5:
            search_in_stack();
            break;
        default:
            printf("Invalid option!\n");
            break;
        }
    }

    if (my_stack) free(my_stack);
    return 0;
}