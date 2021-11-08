#ifndef EXTREME_8_GUN_H
#define EXTREME_8_GUN_H
#include <stdbool.h>

// Type forward declarations
struct gun_t;

// Memory allocator
struct gun_t *gun_new();

// Constructor
void gun_ctor(struct gun_t *, int);

// Destructor
void gun_dtor(struct gun_t *);

// Behavior functions
bool gun_has_bullets(struct gun_t *);
void gun_trigger(struct gun_t *);
void gun_refill(struct gun_t *);
#endif