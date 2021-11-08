#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

/* Define the type list_t */
typedef struct
{
    size_t size;
    int *items;
} list_t;

/* Guard for heap allocator */
static void *H_GAURD(void *ptr)
{
    if (ptr == NULL)
    {
        fprintf(stderr, "out of memory\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

/* A private behavior which checks if the list is full */
static bool __list_is_full(list_t *list)
{
    return (list->size == MAX_SIZE);
}

/* Another private behavior which checks the index */
static bool __check_index(list_t *list, const int index)
{
    return (index >= 0 && index <= list->size);
}

/* Allocates memory for a list object */
list_t *list_malloc()
{
    return H_GAURD(malloc(sizeof(list_t)));
}

/* Constructor of a list object */
void list_init(list_t *list)
{
    list->size = 0;
    // Allocates from the heap memory
    list->items = H_GAURD(malloc(MAX_SIZE * sizeof(int)));
}

/* Destructor of a list object */
void list_destroy(list_t *list)
{
    /* Deallocates the allocated memory */
    free(list->items);
}

int list_add(list_t *list, const int item)
{
    /* The usage of the private behavior */
    if (__list_is_full(list))
    {
        return -1;
    }
    list->items[list->size++] = item;
    return 0;
}

int list_get(list_t *list, const int index, int *result)
{
    /* The usage of the private behavior */
    if (__check_index(list, index))
    {
        *result = list->items[index];
        return 0;
    }
    return -1;
}

void list_clear(list_t *list)
{
    list->size = 0;
}

size_t list_size(list_t *list)
{
    return list->size;
}

void list_print(list_t *list)
{
    printf("[");
    for (size_t i = 0; i < list->size; i++)
    {
        printf("%d ", list->items[i]);
    }
    printf("]\n");
}