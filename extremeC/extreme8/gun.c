#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// Attribute structure
typedef struct
{
    int bullets;
} gun_t;

static void *H_GAURD(void *ptr)
{
    if (ptr == NULL)
    {
        fprintf(stderr, "Out of memory\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// Memory allocator
gun_t *gun_new()
{
    return H_GAURD(malloc(sizeof(gun_t)));
}

// Constructor
void gun_ctor(gun_t *gun, int initial_bullets)
{
    gun->bullets = 0;
    if (initial_bullets > 0)
    {
        gun->bullets = initial_bullets;
    }
}

// Destructor
void gun_dtor(gun_t *gun)
{
    // Nothing to do
}

// Behavior functions
bool gun_has_bullets(gun_t *gun)
{
    return (gun->bullets > 0);
}

void gun_trigger(gun_t *gun)
{
    gun->bullets--;
}

void gun_refill(gun_t *gun)
{
    gun->bullets = 7;
}