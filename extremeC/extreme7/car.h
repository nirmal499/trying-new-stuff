#ifndef EXTREME_7_CAR
#define EXTREME_7_CAR

struct car_t;

/* Memory allocator */
struct car_t *car_new();

/* Constructor */
void car_ctor(struct car_t *);

/* Destructor */
void car_dtor(struct car_t *);

/* Behavior functions */
void car_start(struct car_t *);
void car_stop(struct car_t *);
double car_get_engine_temperature(struct car_t *);

#endif