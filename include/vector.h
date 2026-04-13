// vector.h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    void* data;
    int elem_size;
    int size;
    int capacity;
} Vector;


void vector_init(Vector*, int);

void vector_free(Vector*);

void vector_push_back(Vector*, void*);

void* vector_get(Vector*, int);

void vector_set(Vector*, int, void*);

void* vector_pop(Vector*);

void* vector_back(Vector*);

void* vector_front(Vector*);

void vector_reserve(Vector*, int);
