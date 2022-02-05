#include "vector.h"
#include <stdlib.h>

vector createVector(size_t n) {
    int *a = (int *) malloc(sizeof(int) * n);
    if (a != NULL) {
        return (vector) {a, 0, n};
    }
    fprintf(stderr, "bad alloc");
    exit(1);
}

void reserve(vector *v, size_t newCapacity) {
    v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    if (newCapacity <= 0)
        v->data = NULL;
    else if (newCapacity < v->size)
        v->size = newCapacity;
    else
        v->capacity = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->data = (int *) realloc(v->data, sizeof(int) * v->size);
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    v->capacity = v->size;
}

void deleteVector(vector *v) {
    free(v);
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->capacity == v->size;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i - 1];
}

void pushBack(vector *v, int x) {
    if (v->capacity != 0 && isFull(v))
        reserve(v, v->capacity * 2);
    else if (v->capacity == 0)
        v->capacity = 1;
    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) {
    if (isEmpty(v))
        printf("1");
    else
        (v->size)--;
}

int* atVector(vector *v, size_t index) {
    if (v->size > index && index >=0)
        return &v->data[index];
    else
        printf("IndexError: a[%lld] is not exists", index);
    return NULL;
}

int* back(vector *v) {
    return isEmpty(v) ? NULL :  &v->data[v->size - 1];
}

int* front(vector *v) {
    return isEmpty(v) ? NULL :  &v->data[0];
}


