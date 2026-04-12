// vector.c
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>


void vector_init(Vector* vector, int element_size)
{
    vector->element_size = element_size;
    vector->capacity = 1;
    vector->size = 0;

    int *arr = malloc(element_size);
    if (!arr) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    vector->data = arr;
}