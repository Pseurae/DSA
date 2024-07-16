#include <stdio.h>
#include <stdlib.h>

#define ASSERT(_cond, ...) \
    do { if (!(_cond)) { \
        printf(__VA_ARGS__); \
        return; \
    } } while (0)

#define MAX_ELEMENTS 5

int my_queue[MAX_ELEMENTS];
int queue_front = 0, queue_rear = 0, queue_size = 0;

void create_queue(void)
{
    int size;
    printf("Enter no. of elements: ");
    scanf("%i", &size);

    ASSERT(size > 0 && size <= MAX_ELEMENTS, "Size of the queue should be between 1 and %i.\n", MAX_ELEMENTS);

    for (unsigned int i = 0; i < size; ++i)
    {
        printf("Enter a number: ");
        scanf("%i", &my_queue[i]);
    }

    queue_rear = size;
    queue_size = size;
}

void display_queue(void)
{
    ASSERT(queue_size > 0, "Queue is empty!\n");
    printf("my_queue: [");
    for (unsigned int i = 0; i < queue_size; ++i)
    {
        printf("%i", my_queue[(queue_front + i) % MAX_ELEMENTS]);
        if (i != queue_size - 1) printf(", ");
    }
    printf("]\n");
}

void enqueue(void)
{
    ASSERT(queue_size + 1 <= MAX_ELEMENTS, "Queue is full!\n");
    int number;
    printf("Enter a number: ");
    scanf("%i", &number);

    my_queue[queue_rear++ % MAX_ELEMENTS] = number;
    queue_size++;
}

void dequeue(void)
{
    ASSERT(queue_size > 0 , "Queue is empty!\n");
    printf("Queue dequeued: %i\n", my_queue[queue_front++ % MAX_ELEMENTS]);
    queue_size--;
}

static void search_in_queue(void)
{
    ASSERT(queue_size > 0, "Queue is empty!\n");

    long found = -1;

    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    for (unsigned int i = 0; i < queue_size; ++i)
    {
        if (my_queue[(queue_front + i) % MAX_ELEMENTS] == number)
        {
            found = i;
            break;
        }
    }

    if (found == -1) printf("Array does not contain %i!\n", number);
    else printf("%i found at index %lu in queue.\n", number, found);
}

int main(int argc, char *argv[])
{
    printf(
        "1. Create\n"
        "2. Display\n"
        "3. Enqueue\n"
        "4. Dequeue\n"
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
            create_queue();
            break;
        case 2:
            display_queue();
            break;
        case 3:
            enqueue();
            break;
        case 4:
            dequeue();
            break;
        case 5:
            search_in_queue();
            break;
        default:
            printf("Invalid option!\n");
            break;
        }
    }

    return 0;
}