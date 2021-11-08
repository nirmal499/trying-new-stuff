#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int int_compare(void const *x, void const *y);
int string_compare(const void *x, const void *y);
typedef int (*compare_function)(void const *, void const *);

bool is_sorted(void const *array,
               size_t len, size_t obj_size,
               compare_function cmp);

void swap(void *a, void *b, size_t obj_size);
void reverse(void *array, int n, size_t size);

void insertion_sort(void *array,
                    size_t len, size_t obj_size,
                    compare_function cmp);

void swap_down(char *start, char *current,
               size_t obj_size,
               compare_function cmp);

int main(void)
{
    int int_array[] = {10, 5, 30, 15, 20, 30};
    int int_array_length = sizeof int_array / sizeof *int_array;

    if (is_sorted(int_array, int_array_length,
                  sizeof *int_array, int_compare))
    {
        printf("int_array is sorted\n");
    }
    else
    {
        printf("int_array is not sorted\n");
    }
    qsort(int_array, int_array_length,
          sizeof *int_array, int_compare);
    if (is_sorted(int_array, int_array_length,
                  sizeof *int_array, int_compare))
    {
        printf("int_array is sorted\n");
    }
    else
    {
        printf("int_array is not sorted\n");
    }

    char *string_array[] = {"foo", "bar", "baz"};
    int string_array_length =
        sizeof string_array / sizeof *string_array;
    if (is_sorted(string_array, string_array_length,
                  sizeof *string_array, string_compare))
    {
        printf("string_array is sorted\n");
    }
    else
    {
        printf("string_array is not sorted\n");
    }
    qsort(string_array, string_array_length,
          sizeof *string_array, string_compare);
    if (is_sorted(string_array, string_array_length,
                  sizeof *string_array, string_compare))
    {
        printf("string_array is sorted\n");
    }
    else
    {
        printf("string_array is not sorted\n");
    }
    return 0;
}

int int_compare(void const *x, void const *y)
{
    int const *a = x;
    int const *b = y;

    return *a - *b;
}

int string_compare(const void *x, const void *y)
{
    char *const *a = x;
    char *const *b = y;

    return strcmp(*a, *b);
}

bool is_sorted(void const *array,
               size_t len, size_t obj_size,
               compare_function cmp)
{
    for (int i = 1; i < len; i++)
    {
        void const *a = (char *)array + (i - 1) * obj_size;
        void const *b = (char *)array + i * obj_size;
        if (cmp(a, b) > 0)
        {
            // a is larger than b, so the array is not sorted
            return false;
        }
    }
    return true;
}

void swap(void *a, void *b, size_t obj_size)
{
    char tmp[obj_size];
    memcpy(&tmp, a, obj_size);
    memcpy(a, b, obj_size);
    memcpy(b, &tmp, obj_size);
}

void reverse(void *array, int n, size_t size)
{
    if (n <= 0)
        return; // avoid right underflow
    char *left = array;
    char *right = left + size * (n - 1);
    //char tmp[size];
    while (left < right)
    {
        swap(left, right, size);
        left += size;
        right -= size;
    }
}

void insertion_sort(void *array,
                    size_t len, size_t obj_size,
                    compare_function cmp)
{
    char *start = array;
    for (int i = 1; i < len; i++)
    {
        swap_down(start, start + i * obj_size, obj_size, cmp);
    }
}

void swap_down(char *start, char *current,
               size_t obj_size,
               compare_function cmp)
{
    while (current != start)
    {
        char *prev = current - obj_size;
        if (cmp(prev, current) <= 0)
            break; // done swapping
        swap(prev, current, obj_size);
        current = prev;
    }
}