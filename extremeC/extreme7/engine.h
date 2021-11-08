#ifndef EXTREME_7_ENGINE
#define EXTREME_7_ENGINE

struct engine_t;

/* Memory allocator */
struct engine_t *engine_new();

/* Constructor */
void engine_ctor(struct engine_t *);

/* Destructor */
void engine_dtor(struct engine_t *);

/* Behavior functions */
void engine_turn_on(struct engine_t *);
void engine_turn_off(struct engine_t *);
double engine_get_temperature(struct engine_t *);

#endif