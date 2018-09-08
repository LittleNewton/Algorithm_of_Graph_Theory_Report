#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Dynamic_Array.h"

#define INITIAL_CAPACITY (256)

// Create a new empty dynamic array.
Dynamic_Array *Dynamic_Array_init(void) {
    Dynamic_Array *ans = (Dynamic_Array *)calloc(1, sizeof(Dynamic_Array));
    if (ans == NULL) {
        printf("fatal error: FUNCTION calloc can't get memory.\n");
        return NULL;
    }

    any *tmp = (any *)calloc(INITIAL_CAPACITY, sizeof(any));
    ans->A = tmp;
    ans->capacity = INITIAL_CAPACITY;
    ans->n = 0;

    return ans;
}

// Get the element located in n.
// Take care, n is the natural location, so it need to minus 
// one during the locating process.
any Dynamic_Array_get_Element(Dynamic_Array *d, int n) {
    return *(d->A + n - 1);
}

// Output this dynamic array as a normal array.
void Dynamic_Array_print(Dynamic_Array *d, Function_dynamic_array f, char c) {

    // confirm what kind of format should be used to output.
    char format[10] = "%";
    char apart[2] = "\t";
    strcat(format, &c);
    strcat(format, apart);

    int i = 1;
    for (; i <= d->n; i++) {
        printf(format, f(Dynamic_Array_get_Element(d, i)));
    }
    printf("\n");
}

// double the capacity of this data structure.
void Dynamic_Array_resize(Dynamic_Array *D) {
    int i = 0;
    any *tmp = (any *)calloc(2 * D->capacity, sizeof(any));
    if (tmp == NULL) {
        printf("Cannot get memory, crash!\n");
        return;
    }
    for (i = 0; i < D->capacity; i++) {
        *(tmp + i) = *(D->A + i);
    }
    D->A = tmp;
    D->capacity *= 2;
}

// Add one more element to the given dynamic array
void Dynamic_Array_append(Dynamic_Array *D, any e) {
    if (D->n == D->capacity) {
        Dynamic_Array_resize(D);
    }
    *(D->A + D->n) = e;
    D->n += 1;
}

// Generate a new dynamic array to contain the answer, the source dynamic array
// won't be changed.
// The index of dynamic array begins from 1 rather zero.
Dynamic_Array *Dynamic_Array_quick_Sort(Dynamic_Array *a, Function_dynamic_array f) {

    Dynamic_Array *less = Dynamic_Array_init();
    Dynamic_Array *more = Dynamic_Array_init();
    Dynamic_Array *eq = Dynamic_Array_init();

    int i;
    if (a->n <= 1) {
        return a;
    }
    else {
        for (i = 0; i < a->n; i++) {
            double pivot = f(*(a->A));
            if (f(*(a->A + i)) > pivot) {
                Dynamic_Array_append(more, *(a->A + i));
            }
            else {
                if (f(*(a->A + i)) < pivot) {
                    Dynamic_Array_append(less, *(a->A + i));
                }
                else {
                    Dynamic_Array_append(eq, *(a->A + i));
                }
            }
        }
    }
    less = Dynamic_Array_quick_Sort(less, f);
    more = Dynamic_Array_quick_Sort(more, f);
    for (i = 0; i < eq->n; i++) {
        Dynamic_Array_append(less, *(eq->A + i));
    }
    for (i = 0; i < more->n; i++) {
        Dynamic_Array_append(less, *(more->A + i));
    }
    return less;
}

// Find the minimum value's index.
int Dynamic_Array_min(Dynamic_Array *d, Function_dynamic_array f) {
    Dynamic_Array *sorted = Dynamic_Array_quick_Sort(d, f);
    double pivot = f(Dynamic_Array_get_Element(sorted, 1));
    int i = 0;
    for (; i < d->n; i++) {
        if (f(*(d->A + i)) == pivot) {
            return i + 1;
        }
    }
}

// Find the maximal value's index.
int Dynamic_Array_max(Dynamic_Array *d, Function_dynamic_array f) {
    Dynamic_Array *sorted = Dynamic_Array_quick_Sort(d, f);
    double pivot = f(Dynamic_Array_get_Element(sorted, sorted->n));
    int i = 0;
    for (; i < d->n; i++) {
        if (f(*(d->A + i)) == pivot) {
            return i + 1;
        }
    }
}