// vector.h

typedef struct {
    void* data;
    int element_size;
    int size;
    int capacity;
} Vector;


void vector_init(Vector*, int);