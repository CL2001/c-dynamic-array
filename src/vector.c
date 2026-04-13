// vector.c
#include "vector.h"


void vector_init(Vector* v, int elem_size)
{
    v->elem_size = elem_size;
    v->capacity = 1;
    v->size = 0;

    void* data = malloc(elem_size);
    if (!data)
    {
        fprintf(stderr, "vector_init: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    v->data = data;
}


void vector_free(Vector* v)
{
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}
