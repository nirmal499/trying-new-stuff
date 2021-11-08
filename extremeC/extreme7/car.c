#include <stdio.h>
#include <stdlib.h>
/* Car is only able to work with the public interface of Engine */
#include "engine.h"

typedef struct
{
    /* Composition happens because of this attribute */
    struct engine_t *engine;
} car_t;

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

car_t *car_new()
{
    return H_GAURD(malloc(sizeof(car_t)));
}

void car_ctor(car_t *car)
{
    /* Allocate memory for the engine object */
    car->engine = engine_new();
    /* Construct the engine object */
    engine_ctor(car->engine);
}

void car_dtor(car_t *car)
{
    /* Destruct the engine object */
    engine_dtor(car->engine);
    /* Free the memory allocated for the engine object */
    free(car->engine);
}

void car_start(car_t *car)
{
    engine_turn_on(car->engine);
}

void car_stop(car_t *car)
{
    engine_turn_off(car->engine);
}

double car_get_engine_temperature(car_t *car)
{
    return engine_get_temperature(car->engine);
}
