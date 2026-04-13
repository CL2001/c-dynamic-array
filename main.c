#include <stdio.h>
#include "vector.h"


typedef struct {
    char name[32];
    float gpa;
    int   age;
} Student;


void demo_int(void)
{
    Vector v;
    vector_init(&v, sizeof(int));

    printf("Pushing squares: ");
    for (int i = 1; i <= 8; i++)
    {
        int val = i * i;
        vector_push_back(&v, &val);
        printf("%d ", val);
    }
    printf("\n");

    printf("Setting vect[3] = 999: ");
    int replacement = 999;
    vector_set(&v, 3, &replacement);
    for (int i = 0; i < v.size; i++)
        printf("%d ", *(int*)vector_get(&v, i));
    printf("\n");

    printf("front=%d  back=%d\n",
           *(int*)vector_front(&v),
           *(int*)vector_back(&v));

    printf("Popping: ");
    for (int k = 0; k < 3; k++)
        printf("%d ", *(int*)vector_pop(&v));
    printf("\n");

    printf("Remainder after popping: ");
    for (int i = 0; i < v.size; i++)
        printf("%d ", *(int*)vector_get(&v, i));
    printf("\n");

    vector_free(&v);
}


void demo_double(void)
{
    Vector v;
    vector_init(&v, sizeof(double));

    double running_sum = 0.0;
    for (int i = 1; i <= 10; i++)
    {
        double term = 1.0 / i;
        running_sum += term;
        vector_push_back(&v, &running_sum);
    }

    printf("Running harmonic sums:\n");
    for (int i = 0; i < v.size; i++)
        printf("  H(%2d) = %.6f\n", i + 1, *(double*)vector_get(&v, i));

    printf("Capacity after 10 pushes: %d\n",
           v.capacity);

    vector_free(&v);
}


void demo_char(void)
{
    Vector v;
    vector_init(&v, sizeof(char));

    const char* words[] = { "Vector", "Library", "Demo" };
    for (int w = 0; w < 3; w++) {
        const char* word = words[w];
        for (int c = 0; word[c]; c++)
            vector_push_back(&v, (void*)(word + c));
        if (w < 2)
        {
            char space = ' ';
            vector_push_back(&v, &space);
        }
    }
    char nul = '\0';
    vector_push_back(&v, &nul);

    printf("Assembled string: \"%s\"\n", (char*)vector_front(&v));
    printf("Length (excl. NUL): %d\n", v.size - 1);

    vector_free(&v);
}


void demo_struct(void)
{
    Student roster[] = {
        { "Alice",   3.92f, 20 },
        { "Bob",     3.41f, 22 },
        { "Carol",   3.87f, 21 },
        { "Dave",    2.95f, 23 },
        { "Eve",     3.99f, 19 },
    };
    int n = sizeof(roster) / sizeof(roster[0]);

    Vector v;
    vector_init(&v, sizeof(Student));
    vector_reserve(&v, n);

    for (int i = 0; i < n; i++)
        vector_push_back(&v, &roster[i]);

    for (int i = 0; i < v.size - 1; i++)
    {
        for (int j = 0; j < v.size - i - 1; j++) {
            Student* a = (Student*)vector_get(&v, j);
            Student* b = (Student*)vector_get(&v, j + 1);
            if (a->gpa < b->gpa)
            {
                Student tmp = *a;
                vector_set(&v, j,     b);
                vector_set(&v, j + 1, &tmp);
            }
        }
    }

    printf("%-6s  %-10s  %s\n", "Rank", "Name", "GPA");
    for (int i = 0; i < v.size; i++) {
        Student* s = (Student*)vector_get(&v, i);
        printf("  #%d    %-10s  %.2f  (age %d)\n",
               i + 1, s->name, s->gpa, s->age);
    }

    vector_free(&v);
}


void demo_ptr(void)
{
    const char* langs[] = {
        "C", "C++", "Rust", "Zig", "Go", "Odin", "Ada"
    };
    int n = sizeof(langs) / sizeof(langs[0]);

    Vector v;
    vector_init(&v, sizeof(char*));

    for (int i = 0; i < n; i++)
        vector_push_back(&v, &langs[i]);

    printf("Languages in reverse:\n  ");
    for (int i = v.size - 1; i >= 0; i--)
        printf("%s ", *(char**)vector_get(&v, i));
    printf("\n");

    int found = -1;
    for (int i = 0; i < v.size; i++)
    {
        const char* lang = *(char**)vector_get(&v, i);
        if (lang[0] == 'R')
        {
            found = i;
            break;
        }
    }
    if (found >= 0)
        printf("First 'R' language: %s\n", *(char**)vector_get(&v, found));

    vector_free(&v);
}


void demo_nested(void)
{
    Vector rows;
    vector_init(&rows, sizeof(Vector));

    for (int i = 1; i <= 4; i++)
    {
        Vector row;
        vector_init(&row, sizeof(double));

        for (int j = 1; j <= i; j++)
        {
            double val = (double)(i * j);
            vector_push_back(&row, &val);
        }

        vector_push_back(&rows, &row);
    }

    printf("Nested vectors (row i = i * [1..i]):\n");
    for (int i = 0; i < rows.size; i++)
    {
        Vector* row = (Vector*)vector_get(&rows, i);
        printf("  row %d: ", i + 1);
        for (int j = 0; j < row->size; j++)
            printf("%.1f ", *(double*)vector_get(row, j));
        printf("\n");
    }

    for (int i = 0; i < rows.size; i++)
    {
        Vector* row = (Vector*)vector_get(&rows, i);
        vector_free(row);
    }
    vector_free(&rows);
}


int main(void)
{
    printf("Generic Vector Library Demo\n");

    demo_int();
    demo_double();
    demo_char();
    demo_struct();
    demo_ptr();
    demo_nested();

    printf("\nAll demos complete — no leaks (every vector_init has a vector_free).\n");
    return 0;
}