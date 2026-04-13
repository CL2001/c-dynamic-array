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


void vector_push_back(Vector* v, void* elem)
{
    if (v->size >= v->capacity)
    {
        v->capacity *= 2;
        v->data = realloc(v->data, v->elem_size * v->capacity);
        if (!v->data)
        {
            fprintf(stderr, "vector_push_back: realloc failed\n");
            exit(EXIT_FAILURE);
        }
    }
    memcpy((char*)v->data + v->size * v->elem_size, elem, v->elem_size);
    v->size++;
}


void* vector_get(Vector* v, int i)
{
    if (i < 0 || i >= v->size)
    {
        fprintf(stderr, "vector_get: index %d out of bounds (size=%d)\n", i, v->size);
        exit(EXIT_FAILURE);
    }

    return (char*)v->data + i * v->elem_size;
}
