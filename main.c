#include "vector.h"
#include <stdio.h>

int main() {
    Vector vec;
    vector_init(&vec, sizeof(int));

    printf("Vector initialized\n");

    /*

    for (int i = 0; i < 10; i++) {
        vector_push_back(&vec, &i);
    }

    for (size_t i = 0; i < vec.size; i++) {
        printf("%d ", *(int*)vector_get(&vec, i));
    }

    vector_free(&vec);
    return 0;
    */
}